#ifndef HUE_CYCLE_H
#define HUE_CYCLE_H

#include "Color.h"

typedef struct HueCycle {
    /* 0x0 */ u16 value;
    /* 0x2 */ u8 hi;
    /* 0x3 */ u8 lo;
} HueCycle; // size = 0x4

typedef struct HueCycleRange {
    /* 0x0 */ u8 hi;
    /* 0x1 */ u8 hiId;
    /* 0x2 */ u8 lo;
    /* 0x3 */ u8 loId;
} HueCycleRange; // size = 0x4

u16 HueCycle_Addition(HueCycle cycle, u16 amount);
HueCycleRange HueCycle_ColorRange(Color_RGBA8 color);
HueCycle HueCycle_FromColor(Color_RGBA8 color);
HueCycle HueCycle_FromValues(u16 value, u8 hi, u8 lo);
Color_RGBA8 HueCycle_ToColor(HueCycle cycle, u8 alpha);
Color_RGBA8 HueCycle_Color_Add(Color_RGBA8 color, u16 amount);
Color_RGBA8 HueCycle_Color_AddPercent(Color_RGBA8 color, f32 percent);

#endif // HUE_CYCLE_H
