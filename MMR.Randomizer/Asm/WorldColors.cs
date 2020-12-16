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
        public Color SwordEnergyEnv { get; set; } = Color.FromArgb(0x00, 0x64, 0xFF);
        public Color SwordEnergyPrim { get; set; } = Color.FromArgb(0xAA, 0xFF, 0xFF);
        public Color SwordEnergyBlueEnv1 { get; set; } = Color.FromArgb(0x00, 0x00, 0xFF);
        public Color SwordEnergyBlueEnv2 { get; set; } = Color.FromArgb(0x00, 0x64, 0xFF);
        public Color SwordEnergyBluePrim { get; set; } = Color.FromArgb(0xAA, 0xFF, 0xFF);
        public Color SwordEnergyRedEnv1 { get; set; } = Color.FromArgb(0xFF, 0x00, 0x00);
        public Color SwordEnergyRedEnv2 { get; set; } = Color.FromArgb(0xFF, 0x64, 0x00);
        public Color SwordEnergyRedPrim { get; set; } = Color.FromArgb(0xFF, 0xFF, 0xAA);
        public Color BlueBubble { get; set; } = Color.FromArgb(0x00, 0x00, 0xFF);

        /// <summary>
        /// Get the default set of Human energy colors.
        /// </summary>
        public static Color[] DefaultHumanEnergyColors {
            get {
                var colors = new WorldColors();
                return new Color[]
                {
                    colors.SwordEnergyBlueEnv2,
                    colors.SwordEnergyRedEnv2,
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
        /// Get colors to write in <see cref="WorldColorsConfigStruct"/> structure.
        /// </summary>
        public Color[] StructColors => new Color[]
        {
            GoronPunchEnergyEnv1,
            GoronRollInnerEnergyEnv,
            SwordEnergyBluePrim,
            SwordEnergyRedPrim,
            SwordEnergyEnv,
            SwordEnergyPrim,
            BlueBubble,
        };
    }
}
