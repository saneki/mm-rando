using MMR.Randomizer.GameObjects;
using MMR.Randomizer.Models.Settings;
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
        /// Apply energy colors for a specific <see cref="TransformationForm"/>.
        /// </summary>
        /// <param name="form">Transformation form.</param>
        /// <param name="colors">Energy colors to apply.</param>
        void ApplyEnergyColors(TransformationForm form, Color[] colors)
        {
            if (form == TransformationForm.Human)
            {
                SetHumanEnergyColor(colors[0], colors[1]);
            }
            else if (form == TransformationForm.Goron)
            {
                var options = new GoronColorOptions(colors[0], colors[1], colors[2]);
                SetGoronRollEnergyColors(options);
            }
            else if (form == TransformationForm.Zora)
            {
                SetZoraEnergyColor(colors[0]);
            }
        }

        /// <summary>
        /// Finalize colors given a <see cref="CosmeticSettings"/>.
        /// </summary>
        /// <param name="settings">Cosmetic settings.</param>
        public void FinalizeSettings(CosmeticSettings settings)
        {
            foreach (var kvp in settings.UseEnergyColors)
            {
                var form = kvp.Key;
                var useColors = kvp.Value;
                if (useColors)
                {
                    // Get and apply energy colors for specific transformation form.
                    var colors = settings.EnergyColors[form];
                    ApplyEnergyColors(form, colors);
                }
            }
        }

        /// <summary>
        /// Patch object data for new color values.
        /// </summary>
        public void PatchObjects()
        {
            PatchHumanEnergyColors(ObjUtils.GetObjectData(1));
            PatchGoronEnergyColors(ObjUtils.GetObjectData(0x14C));
            PatchZoraEnergyColors(ObjUtils.GetObjectData(0x14D));
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
