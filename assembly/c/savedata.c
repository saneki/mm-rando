#include <stdbool.h>
#include "quest_items.h"
#include "save_file.h"
#include "z2.h"

static bool is_owl_save_size(size_t size) {
    return size == 0x3CA0;
}

/**
 * Hook function called after some savedata has been loaded into SaveContext.
 **/
void savedata_after_load(GlobalContext *game, Camera *camera, SaveContext *file, const u8 *buffer, size_t size) {
    // Read our struct from buffer with flash data
    bool owl_save = is_owl_save_size(size);
    u32 offset = save_file_get_flash_section_offset(owl_save);
    const u8 *src = buffer + offset;
    save_file_read(src);
}

/**
 * Hook function called after savedata prepared (inventory & flags cleared via Song of Time).
 **/
void savedata_after_prepare(GlobalContext *game) {
    QuestItems_AfterSongOfTimeClear();
}

/**
 * Hook function called after writing SaveContext to buffer, which is to be written to flash.
 **/
void savedata_after_write(u8 *buffer, SaveContext *file, size_t size, bool owl_save) {
    u32 offset = save_file_get_flash_section_offset(owl_save);
    u8 *dest = buffer + offset;
    save_file_write(dest);
}
