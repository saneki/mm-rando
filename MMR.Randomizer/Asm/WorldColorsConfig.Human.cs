using MMR.Randomizer.Extensions;
using SixLabors.ImageSharp.ColorSpaces;
using SixLabors.ImageSharp.ColorSpaces.Conversion;
using System;
using System.Drawing;

namespace MMR.Randomizer.Asm
{
    public partial class WorldColorsConfig
    {
        /// <summary>
        /// Patch GameplayKeep object data to write new energy colors.
        /// </summary>
        /// <param name="data">GameplayKeep object data.</param>
        public void PatchHumanEnergyColors(Span<byte> data)
        {
            PatchSwordSpinEnergyColors(data);
        }

        /// <summary>
        /// Patch colors used for sword spin energy effect.
        /// </summary>
        /// <param name="data">GameplayKeep object data.</param>
        void PatchSwordSpinEnergyColors(Span<byte> data)
        {
            var offset1 = 0x25850;
            Colors.SwordEnergyBlueEnv2.ToBytesRGB(0x80).CopyTo(data.Slice(offset1 + 0xA4));

            var offset2 = 0x25970;
            Colors.SwordEnergyBlueEnv1.ToBytesRGB(0x80).CopyTo(data.Slice(offset2 + 0xA4));
        }

        /// <summary>
        /// Update Human energy colors from given base colors.
        /// </summary>
        /// <param name="color">Blue sword spin energy color.</param>
        public void SetHumanEnergyColor(Color color)
        {
            var converter = new ColorSpaceConverter();
            var hsv = converter.ToHsv(ToRgb(color));
            var adjustedHsv = new Hsv(hsv.H, Math.Min(hsv.S * 3f, 1f), hsv.V);
            var adjusted = FromRgb(converter.ToRgb(adjustedHsv));

            Colors.SwordEnergyBlueEnv1 = color;
            Colors.SwordEnergyBlueEnv2 = adjusted;
            Colors.SwordEnergyBluePrim = Color.White;
        }
    }
}
