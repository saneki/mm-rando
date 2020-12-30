#include <z2.h>
#include "Dpad.h"
#include "FileSelect.h"
#include "HudColors.h"
#include "Misc.h"
#include "SaveFile.h"
#include "Sprite.h"
#include "Util.h"

// Enables using Z to refresh file select hash icons.
// #define FILE_HASH_DEBUG

// Number of icons to display using hash value.
const static int gIconCount = 5;

struct HashIcons HASH_ICONS = {
    .version = 0,
    .count = HASH_SYMBOL_COUNT,
    // Texture indexes to use for hash icons.
    .symbols = {
        Z2_ITEM_OCARINA,
        Z2_ITEM_BOW,
        Z2_ITEM_FIRE_ARROW,
        Z2_ITEM_ICE_ARROW,
        Z2_ITEM_LIGHT_ARROW,
        Z2_ITEM_BOMB,
        Z2_ITEM_BOMBCHU,
        Z2_ITEM_DEKU_STICK,
        Z2_ITEM_DEKU_NUT,
        Z2_ITEM_MAGIC_BEAN,
        Z2_ITEM_POWDER_KEG,
        Z2_ITEM_PICTOGRAPH,
        Z2_ITEM_LENS,
        Z2_ITEM_HOOKSHOT,
        Z2_ITEM_FAIRY_SWORD,
        Z2_ITEM_EMPTY_BOTTLE,
        Z2_ITEM_DEKU_PRINCESS,
        Z2_ITEM_BUGS,
        Z2_ITEM_BIG_POE,
        Z2_ITEM_HOT_WATER,
        Z2_ITEM_ZORA_EGG,
        Z2_ITEM_GOLD_DUST,
        Z2_ITEM_MUSHROOM,
        Z2_ITEM_SEAHORSE,
        Z2_ITEM_CHATEAU_ROMANI,
        Z2_ITEM_MOON_TEAR,
        Z2_ITEM_TOWN_DEED,
        Z2_ITEM_ROOM_KEY,
        Z2_ITEM_MAMA_LETTER,
        Z2_ITEM_KAFEI_LETTER,
        Z2_ITEM_PENDANT,
        Z2_ITEM_MAP,
        Z2_ITEM_DEKU_MASK,
        Z2_ITEM_GORON_MASK,
        Z2_ITEM_ZORA_MASK,
        Z2_ITEM_FIERCE_DEITY_MASK,
        Z2_ITEM_MASK_OF_TRUTH,
        Z2_ITEM_KAFEI_MASK,
        Z2_ITEM_ALL_NIGHT_MASK,
        Z2_ITEM_BUNNY_HOOD,
        Z2_ITEM_KEATON_MASK,
        Z2_ITEM_GARO_MASK,
        Z2_ITEM_ROMANI_MASK,
        Z2_ITEM_CIRCUS_LEADER_MASK,
        Z2_ITEM_POSTMAN_HAT,
        Z2_ITEM_COUPLE_MASK,
        Z2_ITEM_GREAT_FAIRY_MASK,
        Z2_ITEM_GIBDO_MASK,
        Z2_ITEM_DON_GERO_MASK,
        Z2_ITEM_KAMARO_MASK,
        Z2_ITEM_CAPTAIN_HAT,
        Z2_ITEM_STONE_MASK,
        Z2_ITEM_BREMEN_MASK,
        Z2_ITEM_BLAST_MASK,
        Z2_ITEM_MASK_OF_SCENTS,
        Z2_ITEM_GIANT_MASK,
        Z2_ITEM_KOKIRI_SWORD,
        Z2_ITEM_GILDED_SWORD,
        Z2_ITEM_HELIX_SWORD,
        Z2_ITEM_HERO_SHIELD,
        Z2_ITEM_MIRROR_SHIELD,
        Z2_ITEM_QUIVER_40,
        Z2_ITEM_ADULT_WALLET,
        0x61, // Bomber's Notebook
    },
};

static void LoadTexture(u8* buf, int idx, int length, u8 item) {
    u32 phys = z2_GetFilePhysAddr(ItemTextureFileVROM);
    u8* dest = buf + (idx * length);
    z2_LoadFileFromArchive(phys, item, dest, length);
}

static void UpdateTextures(void* buf, int count, int length, u32 hash) {
    for (int i = 0; i < count; i++, hash <<= 6) {
        u32 sym = (hash >> 26);
        u8 item = HASH_ICONS.symbols[sym];
        LoadTexture(buf, i, length, item);
    }
}

static void UpdateTexturesFromSprite(Sprite* sprite, int count, u32 hash) {
    int tilelen = Sprite_GetBytesPerTile(sprite);
    UpdateTextures(sprite->buf, count, tilelen, hash);
}

void FileSelect_HookAfterCtor(GlobalContext* ctxt) {
    // Consider D-Pad item textures cleared so they are reloaded next time
    Dpad_ClearItemTextures();
    // Clear data relevant to save file (including quest item storage).
    SaveFile_Clear();
    // Write icon textures
    Sprite* sprite = Sprite_GetItemTexturesSprite();
    if (sprite->buf != NULL) {
        u32 hash = MISC_CONFIG.hash.value;
        UpdateTexturesFromSprite(sprite, gIconCount, hash);
    }
}

void FileSelect_HookAfterDtor(GlobalContext* ctxt) {
    // Unused.
}

void FileSelect_BeforeDraw(GlobalContext* ctxt) {
    // Update colors for HUD elements on file select
    HudColors_FileChooseInit();

#ifdef FILE_HASH_DEBUG
    // Generate next seed
    z2_RngInt();

    // When pressing Z, update file hash to random new value
    Sprite* sprite = Sprite_GetItemTexturesSprite();
    struct misc_config* config = misc_get_config();
    z2_pad_t pad_pressed = ctxt->state.input[0].pad_pressed;
    if (pad_pressed.z && config->draw_hash && sprite->buf != NULL) {
        config->hash.value = z2_RngInt();
        update_textures_from_sprite(sprite, gIconCount, config->hash.value);
        z2_PlaySfx(0x483B);
    }
#endif
}

void FileSelect_DrawHash(GlobalContext* ctxt) {
    int iconSize = 24;
    int padding = 8;
    int width = (gIconCount * iconSize) + ((gIconCount - 1) * padding);
    int left = (Z2_SCREEN_WIDTH - width) / 2;
    int top = 12;

    if (MISC_CONFIG.flags.drawHash) {
        DispBuf* db = &ctxt->state.gfxCtx->polyOpa;

        // Call setup display list
        gSPDisplayList(db->p++, &gSetupDb);

        gDPPipeSync(db->p++);
        gDPSetCombineMode(db->p++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(db->p++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);

        Sprite* sprite = Sprite_GetItemTexturesSprite();
        for (int i = 0; i < gIconCount; i++) {
            Sprite_Load(db, sprite, i, 1);
            Sprite_Draw(db, sprite, 0, left, top, iconSize, iconSize);
            left += iconSize + padding;
        }
    }
}