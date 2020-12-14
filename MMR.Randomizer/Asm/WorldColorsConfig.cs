using MMR.Randomizer.Utils;
using SixLabors.ImageSharp.ColorSpaces;
using System.Drawing;

namespace MMR.Randomizer.Asm
{
    /// <summary>
    /// World Colors configuration.
    /// </summary>
    public partial class WorldColorsConfig : AsmConfig
    {
        /// <summary>
        /// World color values.
        /// </summary>
        public WorldColors Colors { get; set; } = new WorldColors();

        /// <summary>
        /// Patch object data for new color values.
        /// </summary>
        public void PatchObjects()
        {
            this.Colors.PatchGoronEnergyColors(ObjUtils.GetObjectData(0x14C));
        }

        static Color FromRgb(Rgb rgb)
        {
            return Color.FromArgb((byte)(rgb.R * 255f), (byte)(rgb.G * 255f), (byte)(rgb.B * 255f));
        }

        static Rgb ToRgb(Color color)
        {
            return new Rgb(color.R / 255f, color.G / 255f, color.B / 255f);
        }

        public override IAsmConfigStruct ToStruct(uint version)
        {
            return new WorldColorsConfigStruct
            {
                Version = version,
                Colors = this.Colors.StructColors,
            };
        }
    }
}
