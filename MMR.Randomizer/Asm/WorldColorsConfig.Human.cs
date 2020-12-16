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
            // Write colors for blue sword spin energy, uses offsets of specific Display Lists.
            var blueOffset1 = 0x25850;
            Colors.SwordEnergyBlueEnv1.ToBytesRGB(0x80).CopyTo(data.Slice(blueOffset1 + 0xA4));
            var blueOffset2 = 0x25970;
            Colors.SwordEnergyBlueEnv2.ToBytesRGB(0x80).CopyTo(data.Slice(blueOffset2 + 0xA4));

            // Write colors for red sword spin energy, uses offsets of specific Display Lists.
            var redOffset1 = 0x25DD0;
            Colors.SwordEnergyRedEnv1.ToBytesRGB(0x80).CopyTo(data.Slice(redOffset1 + 0xA4));
            var redOffset2 = 0x25EF0;
            Colors.SwordEnergyRedEnv2.ToBytesRGB(0x80).CopyTo(data.Slice(redOffset2 + 0xA4));
        }

        /// <summary>
        /// Update Human energy colors from given base colors.
        /// </summary>
        /// <param name="blueColor">Blue sword spin energy color.</param>
        /// <param name="redColor">Red sword spin energy color.</param>
        public void SetHumanEnergyColor(Color blueColor, Color redColor)
        {
            var converter = new ColorSpaceConverter();

            // Update color for normal spin.
            var blueHsv = converter.ToHsv(ToRgb(blueColor));
            var blueAdjustedHsv = new Hsv(blueHsv.H, Math.Min(blueHsv.S * 3f, 1f), blueHsv.V);
            var blueAdjusted = FromRgb(converter.ToRgb(blueAdjustedHsv));
            Colors.SwordEnergyBlueEnv1 = blueColor;
            Colors.SwordEnergyBlueEnv2 = blueAdjusted;
            Colors.SwordEnergyBluePrim = Color.White;

            // Update color for greater spin.
            var redHsv = converter.ToHsv(ToRgb(redColor));
            var redAdjustedHsv = new Hsv(redHsv.H, Math.Min(redHsv.S * 3f, 1f), redHsv.V);
            var redAdjusted = FromRgb(converter.ToRgb(redAdjustedHsv));
            Colors.SwordEnergyRedEnv1 = redColor;
            Colors.SwordEnergyRedEnv2 = redAdjusted;
            Colors.SwordEnergyRedPrim = Color.White;
        }
    }
}
