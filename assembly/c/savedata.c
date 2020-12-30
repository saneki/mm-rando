#include <stdbool.h>
#include <z2.h>
#include "quest_items.h"
#include "save_file.h"

static bool IsOwlSaveSize(size_t size) {
    return size == 0x3CA0;
}

/**
 * Hook function called after some savedata has been loaded into SaveContext.
 **/
void Savedata_AfterLoad(GlobalContext* ctxt, Camera* camera, SaveContext* file, const u8* buffer, size_t size) {
    // Read our struct from buffer with flash data
    bool owlSave = IsOwlSaveSize(size);
    u32 offset = SaveFile_GetFlashSectionOffset(owlSave);
    const u8* src = buffer + offset;
    SaveFile_Read(src);
}

/**
 * Hook function called after savedata prepared (inventory & flags cleared via Song of Time).
 **/
void Savedata_AfterPrepare(GlobalContext* ctxt) {
    QuestItems_AfterSongOfTimeClear();
}

/**
 * Hook function called after writing SaveContext to buffer, which is to be written to flash.
 **/
void Savedata_AfterWrite(u8* buffer, SaveContext* file, size_t size, bool owlSave) {
    u32 offset = SaveFile_GetFlashSectionOffset(owlSave);
    u8* dest = buffer + offset;
    SaveFile_Write(dest);
}
