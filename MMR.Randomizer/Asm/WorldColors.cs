using MMR.Randomizer.Extensions;
using MMR.Randomizer.Utils;
using System;
using System.Drawing;

namespace MMR.Randomizer.Asm
{
    /// <summary>
    /// World color values.
    /// </summary>
    public class WorldColors
    {
        public Color GoronPunchEnergyPrim { get; set; } = Color.FromArgb(0xFF, 0xC8, 0x32);
        public Color GoronPunchEnergyEnv1 { get; set; } = Color.FromArgb(0xFF, 0x00, 0x00);
        public Color GoronPunchEnergyEnv2 { get; set; } = Color.FromArgb(0xFF, 0x00, 0x00);
        public Color GoronRollInnerEnergyPrim { get; set; } = Color.FromArgb(0xFF, 0x9B, 0x00);
        public Color GoronRollInnerEnergyEnv { get; set; } = Color.FromArgb(0x9B, 0x00, 0x00);
        public Color GoronRollOuterEnergyPrim1 { get; set; } = Color.FromArgb(0xFF, 0x00, 0x00);
        public Color GoronRollOuterEnergyPrim2 { get; set; } = Color.FromArgb(0xFF, 0x9B, 0x00);
        public Color GoronRollOuterEnergyEnv1 { get; set; } = Color.FromArgb(0x64, 0x00, 0x00);
        public Color GoronRollOuterEnergyEnv2 { get; set; } = Color.FromArgb(0xC8, 0x00, 0x00);
        public Color ZoraEnergyEnv1 { get; set; } = Color.FromArgb(0x00, 0x00, 0x64);
        public Color ZoraEnergyEnv2 { get; set; } = Color.FromArgb(0x00, 0x96, 0xFF);
        public Color ZoraEnergyPrim1 { get; set; } = Color.FromArgb(0x00, 0x96, 0xFF);
        public Color ZoraEnergyPrim2 { get; set; } = Color.FromArgb(0xAA, 0xFF, 0xFF);
        public Color SwordEnergyBlueEnv1 { get; set; } = Color.FromArgb(0x00, 0x64, 0xFF);
        public Color SwordEnergyBlueEnv2 { get; set; } = Color.FromArgb(0x00, 0x00, 0xFF);
        public Color SwordEnergyBluePrim { get; set; } = Color.FromArgb(0xAA, 0xFF, 0xFF);
        public Color BlueBubble { get; set; } = Color.FromArgb(0x00, 0x00, 0xFF);

        /// <summary>
        /// Get the default set of Human energy colors.
        /// </summary>
        public static Color[] DefaultHumanEnergyColors {
            get {
                return new Color[]
                {
                    new WorldColors().SwordEnergyBlueEnv1,
                };
            }
        }

        /// <summary>
        /// Get the default set of Goron energy colors.
        /// </summary>
        public static Color[] DefaultGoronEnergyColors {
            get {
                var colors = new WorldColors();
                return new Color[] {
                    colors.GoronRollInnerEnergyPrim,
                    colors.GoronRollOuterEnergyPrim1,
                    colors.GoronRollOuterEnergyPrim2
                };
            }
        }

        /// <summary>
        /// Get the default set of Zora energy colors.
        /// </summary>
        public static Color[] DefaultZoraEnergyColors {
            get {
                return new Color[]
                {
                    new WorldColors().ZoraEnergyPrim1,
                };
            }
        }

        /// <summary>
        /// Patch Goron object data to write new outer energy colors.
        /// </summary>
        /// <param name="data">Object data.</param>
        public void PatchGoronEnergyColors(Span<byte> data)
        {
            // Patch SetPrimColor instruction for Goron punch energy color.
            var punchDListOffset = 0x11AB8;
            GoronPunchEnergyPrim.ToBytesRGB(0xFF).CopyTo(data.Slice(punchDListOffset + 0x1C));

            // Patch SetEnvColor color values for Goron punch in code file: RDRAM: 0x801BFDE0, Offset: 0x11A320.
            var punchEnvColorAddr = 0xB3C000 + 0x11A320;
            ReadWriteUtils.WriteToROM(punchEnvColorAddr, GoronPunchEnergyEnv2.ToBytesRGB(0));

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
            GoronPunchEnergyEnv1,
            GoronRollInnerEnergyEnv,
            SwordEnergyBluePrim,
            SwordEnergyBlueEnv1,
            BlueBubble,
        };
    }
}
