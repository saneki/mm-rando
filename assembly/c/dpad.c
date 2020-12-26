#include <stdbool.h>
#include "buttons.h"
#include "dpad.h"
#include "gfx.h"
#include "hud_colors.h"
#include "reloc.h"
#include "util.h"
#include "z2.h"

// D-Pad configuration structure that can be set by a randomizer.
struct dpad_config DPAD_CONFIG = {
    .magic = DPAD_CONFIG_MAGIC,
    .version = 0,
    .items = {
        { .values = { Z2_ITEM_NONE, Z2_ITEM_NONE, Z2_ITEM_NONE, Z2_ITEM_NONE } },
        { .values = { Z2_ITEM_NONE, Z2_ITEM_NONE, Z2_ITEM_NONE, Z2_ITEM_NONE } },
        { .values = { Z2_ITEM_NONE, Z2_ITEM_NONE, Z2_ITEM_NONE, Z2_ITEM_NONE } },
        { .values = { Z2_ITEM_NONE, Z2_ITEM_NONE, Z2_ITEM_NONE, Z2_ITEM_NONE } },
    },
    .state = DPAD_STATE_TYPE_DEFAULTS,
    .display = DPAD_DISPLAY_LEFT,
    .reserved = { 0 },
};

// Default D-Pad values that will be used if config values undefined.
const static u8 g_dpad_default[4] = {
    Z2_ITEM_DEKU_MASK,
    Z2_ITEM_ZORA_MASK,
    Z2_ITEM_OCARINA,
    Z2_ITEM_GORON_MASK,
};

// Indicates which item textures are currently loaded into our buffer.
static u8 g_texture_items[4] = {
    Z2_ITEM_NONE,
    Z2_ITEM_NONE,
    Z2_ITEM_NONE,
    Z2_ITEM_NONE,
};

// Position of D-Pad texture.
const static u16 g_position[2][2] = {
    { 30,  60 },  // Left
    { 270, 75 },  // Right
};

// Positions of D-Pad item textures, relative to main texture.
const static s16 g_positions[4][2] = {
    { 1, -16 },
    { 15, 0 },
    { 1, 13 },
    { -15, 0 },
};

// Whether or not D-Pad items are usable, according to z2_UpdateButtonUsability.
static bool g_usable[4];

// Whether the previous frame was a "minigame" frame.
static bool g_was_minigame = false;

static bool has_inventory_item(u8 item) {
    for (int i = 0; i < 0x18; i++) {
        if (z2_file.perm.inv.items[i] == item || z2_file.perm.inv.masks[i] == item) {
            return true;
        }
    }
    return false;
}

static bool have_any(u8 *dpad) {
    for (int i = 0; i < 4; i++) {
        if (has_inventory_item(dpad[i]))
            return true;
    }

    return false;
}

static bool try_use_item(GlobalContext *game, ActorPlayer *link, u8 item) {
    // Try to find slot in item or mask inventories.
    if (has_inventory_item(item)) {
        z2_UseItem(game, link, item);
        return true;
    } else {
        return false;
    }
}

/**
 * Helper function used to check if C buttons are disabled due to the current entrance.
 **/
static bool dpad_are_c_items_disabled_by_entrance(GlobalContext *game) {
    // Hardcoded entrance checks to disable C buttons, normally performed by function 0x80111CB4:
    // Id 0x8E10: Beaver Race
    // Id 0xD010: Goron Race
    // Checks execute state to prevent fading D-Pad when loading scene with entrance.
    return (z2_file.perm.entrance.value == 0x8E10 || z2_file.perm.entrance.value == 0xD010) && game->state.running != 0;
}

static void get_dpad_item_usability(GlobalContext *game, bool *dest) {
    for (int i = 0; i < 4; i++) {
        if (dpad_are_c_items_disabled_by_entrance(game)) {
            dest[i] = false;
        } else {
            dest[i] = buttons_check_c_item_usable(game, DPAD_CONFIG.primary.values[i]);
        }
    }
}

static bool is_any_item_usable(const u8 *dpad, const bool *usable) {
    for (int i = 0; i < 4; i++) {
        if (has_inventory_item(dpad[i]) && usable[i])
            return true;
    }

    return false;
}

static void load_texture(u8 *buf, int idx, int length, u8 item) {
    u32 phys = z2_GetFilePhysAddr(ItemTextureFileVROM);
    u8 *dest = buf + (idx * length);
    z2_LoadFileFromArchive(phys, item, dest, length);
    g_texture_items[idx] = item;
}

static void load_texture_from_sprite(sprite_t *sprite, int idx, u8 item) {
    int tilelen = sprite_bytes_per_tile(sprite);
    load_texture(sprite->buf, idx, tilelen, item);
}

static u16 update_y_position(u16 x, u16 y, u16 padding) {
    u16 heart_count = z2_file.perm.unk24.maxLife / 0x10;

    // Check if we have second row of hearts
    bool hearts = heart_count > 10;
    // Check if we have magic
    bool magic = z2_file.perm.unk24.hasMagic != 0;
    // Check if there's a timer
    bool timer = IS_TIMER_VISIBLE(z2_file.extra.timers[Z2_TIMER_INDEX_POE_SISTERS]) ||
                 IS_TIMER_VISIBLE(z2_file.extra.timers[Z2_TIMER_INDEX_TREASURE_CHEST_GAME]) ||
                 IS_TIMER_VISIBLE(z2_file.extra.timers[Z2_TIMER_INDEX_DROWNING]);

    // If on left-half of screen
    if (x < 160) {
        // Calculate a minimum y position based on heart rows and magic
        // This is to avoid the D-Pad textures interfering with the hearts/magic UI
        u16 minimum = 50 + padding;
        if (hearts)
            minimum += 10;
        if (magic)
            minimum += 16;
        if (timer) {
            if (magic) {
                minimum += 10;
            } else {
                minimum += 26;
            }
        }
        y = (y > minimum ? y : minimum);
    }

    return y;
}

static bool is_minigame_frame(void) {
    bool result = false;

    if (g_was_minigame)
        result = true;

    // Note on state 6:
    // If on Epona, and holding "B" for bow, then press "A" while holding "B", the game state
    // will go from: 0xC, 0x6, 0x32, 0xC. Thus we need to mark 0x6 as a "minigame frame" as well.
    // Riding Epona to a new area: 0xC, 0x32, 0x6, 0x1, 0x1...
    //
    // Note on state 1 (transition):
    // In the Deku playground, can go from 0xC to 0x1 when cutscene-transitioning to the business scrub.
    // Thus, if the minigame state goes directly to the transition state, consider that a minigame frame.
    g_was_minigame = (z2_file.extra.buttonsState.state == Z2_BUTTONS_STATE_MINIGAME ||
                      (g_was_minigame && z2_file.extra.buttonsState.state == Z2_BUTTONS_STATE_TRANSITION) ||
                      z2_file.extra.buttonsState.state == 6);
    return result || g_was_minigame;
}

void dpad_before_player_actor_update(ActorPlayer *link, GlobalContext *game) {
    // If disabled, do nothing
    if (DPAD_CONFIG.state == DPAD_STATE_TYPE_DISABLED)
        return;

    // Update usability flags for later use in draw_dpad
    get_dpad_item_usability(game, g_usable);
}

void dpad_clear_item_textures(void) {
    for (int i = 0; i < 4; i++) {
        g_texture_items[i] = Z2_ITEM_NONE;
    }
}

void dpad_init(void) {
    // If using default values, overwrite DPAD_CONFIG items with defaults
    if (DPAD_CONFIG.state == DPAD_STATE_TYPE_DEFAULTS) {
        for (int i = 0; i < 4; i++) {
            DPAD_CONFIG.primary.values[i] = g_dpad_default[i];
        }
    }
}

bool dpad_is_enabled(void) {
    return (DPAD_CONFIG.state == DPAD_STATE_TYPE_ENABLED)
        || (DPAD_CONFIG.state == DPAD_STATE_TYPE_DEFAULTS);
}

/**
 * Hook function used to check whether or not to call z2_UseItem.
 *
 * Checks D-Pad input for whether or not to use an item, and if so returns true to exit the caller
 * function early.
 **/
bool dpad_handle(ActorPlayer *link, GlobalContext *game) {
    InputPad pad_pressed = game->state.input[0].pressEdge.buttons;

    // If disabled, do nothing
    if (DPAD_CONFIG.state == DPAD_STATE_TYPE_DISABLED)
        return false;

    // Check general buttons state to know if we can use C buttons at all
    // Note: After collecting a stray fairy (and possibly in other cases) the state flags are set
    // to 0 despite the game running normally.
    if (z2_file.extra.buttonsState.state != Z2_BUTTONS_STATE_NORMAL &&
        z2_file.extra.buttonsState.state != Z2_BUTTONS_STATE_BLACK_SCREEN)
        return false;

    // Make sure certain Link state flags are cleared before processing D-Pad input.
    u32 flags1 = Z2_ACTION_STATE1_HOLD | Z2_ACTION_STATE1_MOVE_SCENE | Z2_ACTION_STATE1_EPONA;
    if ((link->stateFlags.state1 & flags1) != 0) {
        return false;
    }

    if (pad_pressed.du && g_usable[0]) {
        return try_use_item(game, link, DPAD_CONFIG.primary.du);
    } else if (pad_pressed.dr && g_usable[1]) {
        return try_use_item(game, link, DPAD_CONFIG.primary.dr);
    } else if (pad_pressed.dd && g_usable[2]) {
        return try_use_item(game, link, DPAD_CONFIG.primary.dd);
    } else if (pad_pressed.dl && g_usable[3]) {
        return try_use_item(game, link, DPAD_CONFIG.primary.dl);
    }

    return false;
}

/**
 * Hook function called directly before drawing triangles and item textures on C buttons.
 *
 * Draws D-Pad textures to the overlay display list.
 **/
void dpad_draw(GlobalContext *game) {
    bool is_minigame = is_minigame_frame();

    // If disabled or hiding, don't draw
    if (DPAD_CONFIG.state == DPAD_STATE_TYPE_DISABLED || DPAD_CONFIG.display == DPAD_DISPLAY_NONE)
        return;

    // If we don't have any D-Pad items, draw nothing
    if (!have_any(DPAD_CONFIG.primary.values))
        return;

    // Check for minigame frame, and do nothing unless transitioning into minigame
    // In which case the C-buttons alpha will be used instead for fade-in
    if (is_minigame && z2_file.extra.buttonsState.previousState != Z2_BUTTONS_STATE_MINIGAME)
        return;

    // Check if C button items are disabled for a specific entrance.
    // Used to prevent drawing D-Pad during 1 frame before Goron Race.
    if (dpad_are_c_items_disabled_by_entrance(game) && game->interfaceCtx.alphas.buttonCLeft == 0)
        return;

    // Use minimap alpha by default for fading textures out
    u8 prim_alpha = game->interfaceCtx.alphas.minimap & 0xFF;
    // If in minigame, the C buttons fade out and so should the D-Pad
    if (z2_file.extra.buttonsState.state == Z2_BUTTONS_STATE_MINIGAME ||
        z2_file.extra.buttonsState.state == Z2_BUTTONS_STATE_BOAT_ARCHERY ||
        z2_file.extra.buttonsState.state == Z2_BUTTONS_STATE_SWORDSMAN_GAME ||
        is_minigame)
        prim_alpha = game->interfaceCtx.alphas.buttonCLeft & 0xFF;

    // Check if any items shown on the D-Pad are usable
    // If none are, draw main D-Pad sprite faded
    if (!is_any_item_usable(DPAD_CONFIG.primary.values, g_usable) && prim_alpha > 0x4A)
        prim_alpha = 0x4A;

    // Show faded while flying as a Deku
    ActorPlayer *link = Z2_LINK(game);
    if (((link->stateFlags.state3 & Z2_ACTION_STATE3_DEKU_AIR) != 0) && prim_alpha > 0x4A)
        prim_alpha = 0x4A;

    // Get index of main sprite position (left or right)
    u8 posidx = (DPAD_CONFIG.display == DPAD_DISPLAY_LEFT) ? 0 : 1;

    // Main sprite position
    u16 x = g_position[posidx][0];
    u16 y = g_position[posidx][1];
    y = update_y_position(x, y, 10);

    // Main sprite color
    ColorRGBA8 color = HUD_COLOR_CONFIG.dpad;

    DispBuf *db = &(game->state.gfxCtx->overlay);
    gSPDisplayList(db->p++, &setup_db);
    gDPPipeSync(db->p++);
    gDPSetPrimColor(db->p++, 0, 0, color.r, color.g, color.b, prim_alpha);
    gDPSetCombineMode(db->p++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    sprite_load(db, &dpad_sprite, 0, 1);
    sprite_draw(db, &dpad_sprite, 0, x, y, 16, 16);

    sprite_t *sprite = gfx_get_item_textures_sprite();
    for (int i = 0; i < 4; i++) {
        u8 value = DPAD_CONFIG.primary.values[i];

        // Calculate x/y from relative positions
        u16 ix = x + g_positions[i][0];
        u16 iy = y + g_positions[i][1];

        // Show nothing if not in inventory
        if (!has_inventory_item(value))
            continue;

        // Draw faded
        u8 alpha = prim_alpha;
        if (!g_usable[i] && alpha > 0x4A)
            alpha = 0x4A;
        gDPSetPrimColor(db->p++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);

        // If D-Pad item has changed, load new texture on the fly.
        if (g_texture_items[i] != value) {
            load_texture_from_sprite(sprite, i, value);
        }

        sprite_load(db, sprite, i, 1);
        sprite_draw(db, sprite, 0, ix, iy, 16, 16);
    }

    gDPPipeSync(db->p++);
}

/**
 * Hook function used to determine whether or not to skip the transformation cutscene based on input.
 *
 * Allows D-Pad input to also skip the cutscene if the D-Pad is enabled.
 **/
u16 dpad_skip_transformation_check(ActorPlayer *link, GlobalContext *game, u16 cur) {
    InputPad pad;
    pad.value = 0;

    // Set flags for original buttons: A, B, C buttons (0xC00F)
    pad.a = pad.b = pad.cd = pad.cl = pad.cr = pad.cu = 1;

    if (dpad_is_enabled()) {
        // Set flags for D-Pad (0xCF0F)
        pad.dd = pad.dl = pad.dr = pad.du = 1;
    }

    return cur & pad.value;
}
