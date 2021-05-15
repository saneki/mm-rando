#include <z64.h>

// Other Pictobox related flags:
// - s16 0x801BF884: State flag: 0 = None, 1 = Camera Mode, 2 = Processing Photo, 3 = Prompt

static const bool gMutatePrompt = true;

enum PictoFlags {
    PICTOBOX_SWAMP = 1 << 1,
    PICTOBOX_MONKEY = 1 << 2,
    PICTOBOX_BIG_OCTO = 1 << 3,
    PICTOBOX_LULU1 = 1 << 4,
    PICTOBOX_LULU2 = 1 << 5,
    PICTOBOX_LULU3 = 1 << 6,
    PICTOBOX_SCARECROW = 1 << 7,
    PICTOBOX_TINGLE = 1 << 8,
    PICTOBOX_PIRATE_GOOD = 1 << 9,
    PICTOBOX_DEKU_KING = 1 << 10,
    PICTOBOX_PIRATE_BAD = 1 << 11,
};

enum PictoMessage {
    MESSAGE_SWAMP = 0x170B,
    MESSAGE_MONKEY = 0x1711,
    MESSAGE_BIG_OCTO = 0x171C,
    MESSAGE_LULU_BAD = 0x1726,
    MESSAGE_LULU_GOOD = 0x1727,
    MESSAGE_TINGLE = 0x1731,
    MESSAGE_DEKU_KING = 0x1787,
    MESSAGE_PIRATE_BAD = 0x181B,
    MESSAGE_PIRATE_GOOD = 0x1824,
    MESSAGE_SCARECROW = 0x193A,
};

static u16 DetermineMessageId(u16 defaultId) {
    static const u32 lulu = PICTOBOX_LULU1 | PICTOBOX_LULU2 | PICTOBOX_LULU3;
    u32 cur = gSaveContext.perm.pictoFlags0;
    if ((cur & PICTOBOX_MONKEY) != 0) {
        return MESSAGE_MONKEY;
    } else if ((cur & PICTOBOX_BIG_OCTO) != 0) {
        return MESSAGE_BIG_OCTO;
    } else if ((cur & PICTOBOX_DEKU_KING) != 0) {
        return MESSAGE_DEKU_KING;
    } else if ((cur & lulu) == lulu) {
        return MESSAGE_LULU_GOOD;
    } else if ((cur & lulu) != 0) {
        return MESSAGE_LULU_BAD;
    } else if ((cur & PICTOBOX_SCARECROW) != 0) {
        return MESSAGE_SCARECROW;
    } else if ((cur & PICTOBOX_TINGLE) != 0) {
        return MESSAGE_TINGLE;
    } else if ((cur & PICTOBOX_PIRATE_GOOD) != 0) {
        return MESSAGE_PIRATE_GOOD;
    } else if ((cur & PICTOBOX_PIRATE_BAD) != 0) {
        return MESSAGE_PIRATE_BAD;
    } else if ((cur & PICTOBOX_SWAMP) != 0) {
        return MESSAGE_SWAMP;
    } else {
        return defaultId;
    }
}

/**
 * Hook function to prepare the pictograph message which prompts the player about keeping the picture.
 **/
void Pictobox_PreparePromptMessage(GlobalContext* ctxt, u16 messageId, u8 zero) {
    // Note: This is used to display the message both after taking the picture, and when viewing a previous picture.
    if (gMutatePrompt) {
        // If photo was taken, update flags before determining prompt message.
        s16 photoTakenFlag = *(s16*)(0x801BF888);
        if (photoTakenFlag == 1) {
            z2_UpdatePictoFlags(ctxt);
        }
        messageId = DetermineMessageId(messageId);
    }
    z2_ShowMessage(ctxt, messageId, zero);
}
