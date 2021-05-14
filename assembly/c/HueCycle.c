#include "Color.h"
#include "HueCycle.h"

enum ColorId {
    Red,
    Green,
    Blue,
};

static inline Color_RGBA8 Color_FromRgba(u16 r, u16 g, u16 b, u8 a) {
    Color_RGBA8 color;
    color.r = r % 0x100;
    color.g = g % 0x100;
    color.b = b % 0x100;
    color.a = a;
    return color;
}

static inline u16 PercentToAmount(HueCycle cycle, f32 percent) {
    u16 delta = cycle.hi - cycle.lo;
    u16 max = delta * 6;
    u16 amount = (u16)(percent * (f32)max);
    return amount;
}

static inline u16 HueCycle_Raw_Addition(u16 value, u16 hi, u16 lo, u16 amount) {
    u16 delta = hi - lo;
    u16 max = delta * 6;
    u16 result = (value + amount) % max;
    return result;
}

static Color_RGBA8 HueCycle_Raw_ToColor(u16 value, u16 hi, u16 lo, u8 alpha) {
    u16 delta = hi - lo;
    u16 zone = value / delta;
    if (zone == 0) {
        // High, Diff, Low
        return Color_FromRgba(hi, lo + (value % delta), lo, alpha);
    } else if (zone == 1) {
        // Diff, High, Low
        return Color_FromRgba(hi - (value % delta), hi, lo, alpha);
    } else if (zone == 2) {
        // Low, High, Diff
        return Color_FromRgba(lo, hi, lo + (value % delta), alpha);
    } else if (zone == 3) {
        // Low, Diff, High
        return Color_FromRgba(lo, hi - (value % delta), hi, alpha);
    } else if (zone == 4) {
        // Diff, Low, High
        return Color_FromRgba(lo + (value % delta), lo, hi, alpha);
    } else if (zone == 5) {
        // High, Low, Diff
        return Color_FromRgba(hi, lo, hi - (value % delta), alpha);
    } else {
        // Should be unreachable, fallback.
        return Color_FromRgba(0, 0, 0, alpha);
    }
}

u16 HueCycle_Addition(HueCycle cycle, u16 amount) {
    return HueCycle_Raw_Addition(cycle.value, cycle.hi, cycle.lo, amount);
}

Color_RGBA8 HueCycle_ToColor(HueCycle cycle, u8 alpha) {
    return HueCycle_Raw_ToColor(cycle.value, cycle.hi, cycle.lo, alpha);
}

HueCycleRange HueCycle_ColorRange(Color_RGBA8 color) {
    HueCycleRange range;
    // Calculate high boundary.
    if (color.r >= color.g && color.r > color.b) {
        range.hi = color.r;
        range.hiId = Red;
    } else if (color.g >= color.b && color.g > color.r) {
        range.hi = color.g;
        range.hiId = Green;
    } else if (color.b >= color.r && color.b > color.g) {
        range.hi = color.b;
        range.hiId = Blue;
    }
    // Calculate low boundary.
    if (color.b <= color.r && color.b < color.g) {
        range.lo = color.b;
        range.loId = Blue;
    } else if (color.r <= color.g && color.r < color.b) {
        range.lo = color.r;
        range.loId = Red;
    } else if (color.g <= color.b && color.g < color.r) {
        range.lo = color.g;
        range.loId = Green;
    }
    return range;
}

HueCycle HueCycle_FromColor(Color_RGBA8 color) {
    HueCycleRange range = HueCycle_ColorRange(color);
    u16 delta = range.hi - range.lo;
    u16 value = 0;
    if (range.hiId == Red && range.loId == Blue) {
        value = color.g;
    } else if (range.hiId == Green && range.loId == Blue) {
        value = (delta - color.r) + (delta * 1);
    } else if (range.hiId == Green && range.loId == Red) {
        value = color.b + (delta * 2);
    } else if (range.hiId == Blue && range.loId == Red) {
        value = (delta - color.g) + (delta * 3);
    } else if (range.hiId == Blue && range.loId == Green) {
        value = color.r + (delta * 4);
    } else if (range.hiId == Red && range.loId == Green) {
        value = (delta - color.b) + (delta * 5);
    }
    return HueCycle_FromValues(value, range.hi, range.lo);
}

HueCycle HueCycle_FromValues(u16 value, u8 hi, u8 lo) {
    HueCycle cycle = { .value = value, .hi = hi, .lo = lo, };
    return cycle;
}

Color_RGBA8 HueCycle_Color_Add(Color_RGBA8 color, u16 amount) {
    HueCycle cycle = HueCycle_FromColor(color);
    u16 value = HueCycle_Addition(cycle, amount);
    cycle.value = value;
    return HueCycle_ToColor(cycle, color.a);
}

Color_RGBA8 HueCycle_Color_AddPercent(Color_RGBA8 color, f32 percent) {
    HueCycle cycle = HueCycle_FromColor(color);
    u16 amount = PercentToAmount(cycle, percent);
    u16 value = HueCycle_Addition(cycle, amount);
    cycle.value = value;
    return HueCycle_ToColor(cycle, color.a);
}
