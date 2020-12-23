#include "gfx.h"
#include "util.h"
#include "z2.h"

#define text_max_chars 256
#define text_bucket_count 6
#define text_bucket_size 18

typedef struct {
    uint32_t c : 8;
    uint32_t left : 12;
    uint32_t top : 12;
    z2_color_rgba8_t color;
} text_char_t;

static text_char_t *text_end = NULL;
static text_char_t *text_buf = NULL;

void text_init(void) {
    text_buf = heap_alloc(text_max_chars * sizeof(text_char_t));
    text_end = text_buf;
}

void text_print_with_color(const char *s, int left, int top, z2_color_rgba8_t color) {
    char c;
    while (c = *(s++)) {
        if (text_end >= text_buf + text_max_chars) {
            break;
        }
        text_end->c = c;
        text_end->left = left;
        text_end->top = top;
        text_end->color = color;
        text_end++;
        left += font_sprite.tile_w;
    }
}

void text_print(const char *s, int left, int top) {
    z2_color_rgba8_t color = { 0xFF, 0xFF, 0xFF, 0xFF };
    text_print_with_color(s, left, top, color);
}

void text_flush(DispBuf *db) {
    for (int i = 0; i < text_bucket_count; i++) {
        sprite_load(db, &font_sprite,
                i * text_bucket_size, text_bucket_size);

        text_char_t *text_p = text_buf;
        while (text_p < text_end) {
            char c = text_p->c;
            int left = text_p->left;
            int top = text_p->top;
            z2_color_rgba8_t color = text_p->color;
            text_p++;

            int bucket = (c - 32) / text_bucket_size;
            if (bucket != i) continue;

            // Apply text color.
            gDPSetPrimColor(db->p++, 0, 0, color.r, color.g, color.b, color.a);

            int tile_index = (c - 32) % text_bucket_size;
            sprite_draw(db, &font_sprite, tile_index,
                    left, top,
                    font_sprite.tile_w, font_sprite.tile_h - 1);
        }
    }

    text_end = text_buf;
}
