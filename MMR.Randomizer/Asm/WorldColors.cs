﻿using MMR.Randomizer.Extensions;
using System;
using System.Drawing;

namespace MMR.Randomizer.Asm
{
    /// <summary>
    /// World color values.
    /// </summary>
    public class WorldColors
    {
        public Color GoronRollInnerEnergyPrim { get; set; } = Color.FromArgb(0xFF, 0x9B, 0x00);
        public Color GoronRollInnerEnergyEnv { get; set; } = Color.FromArgb(0x9B, 0x00, 0x00);
        public Color GoronRollOuterEnergyPrim1 { get; set; } = Color.FromArgb(0xFF, 0x00, 0x00);
        public Color GoronRollOuterEnergyPrim2 { get; set; } = Color.FromArgb(0xFF, 0x9B, 0x00);
        public Color GoronRollOuterEnergyEnv1 { get; set; } = Color.FromArgb(0x64, 0x00, 0x00);
        public Color GoronRollOuterEnergyEnv2 { get; set; } = Color.FromArgb(0xC8, 0x00, 0x00);
        public Color BlueBubble { get; set; } = Color.FromArgb(0x00, 0x00, 0xFF);

        /// <summary>
        /// Patch Goron object data to write new outer energy colors.
        /// </summary>
        /// <param name="data">Object data.</param>
        public void PatchGoronEnergyColors(Span<byte> data)
        {
            // Patch SetPrimColor instruction for interior of Goron roll energy color.
            var innerOffset = 0x127CC;
            var innerPrim = GoronRollInnerEnergyPrim.ToBytesRGB(0xFF);
            innerPrim.CopyTo(data.Slice(innerOffset));

            // Patch color table used to generate DLists for exterior of Goron roll energy effect.
            var outerOffset = 0x14660;
            var outerPrim1 = GoronRollOuterEnergyPrim1.ToBytesRGB(0xFF);
            var outerPrim2 = GoronRollOuterEnergyPrim2.ToBytesRGB(0xFF);
            var outerEnv1 = GoronRollOuterEnergyEnv1.ToBytesRGB(0xFF);
            var outerEnv2 = GoronRollOuterEnergyEnv2.ToBytesRGB(0xFF);
            outerPrim1.CopyTo(data.Slice(outerOffset + 0));
            outerPrim2.CopyTo(data.Slice(outerOffset + 5));
            outerEnv1.CopyTo(data.Slice(outerOffset + 0xC));
            outerEnv2.CopyTo(data.Slice(outerOffset + 0x10));
        }

        /// <summary>
        /// Get colors to write in <see cref="WorldColorsConfigStruct"/> structure.
        /// </summary>
        public Color[] StructColors => new Color[]
        {
            GoronRollInnerEnergyEnv,
            BlueBubble,
        };
    }
}
