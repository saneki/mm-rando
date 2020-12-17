using MMR.Randomizer.Extensions;
using System;
using System.Drawing;

namespace MMR.Randomizer.Asm
{
    public partial class WorldColorsConfig
    {
        /// <summary>
        /// Patch Player Actor file data to write Fierce Deity energy colors.
        /// </summary>
        /// <param name="playerActorData">Player Actor file data.</param>
        public void PatchFierceDeityEnergyColors(Span<byte> playerActorData)
        {
            PatchFierceDeitySparkleColors(playerActorData);
        }

        /// <summary>
        /// Patch Fierce Deity sparkle colors.
        /// </summary>
        /// <param name="playerActorData">Player Actor file data.</param>
        void PatchFierceDeitySparkleColors(Span<byte> playerActorData)
        {
            var offset = 0x2F964;
            Colors.FierceDeitySparklesInner.ToBytesRGB(0).CopyTo(playerActorData.Slice(offset + 0));
            Colors.FierceDeitySparklesOuter.ToBytesRGB(0).CopyTo(playerActorData.Slice(offset + 4));
        }

        /// <summary>
        /// Update Fierce Deity energy colors from given base color.
        /// </summary>
        /// <param name="color">Sword beam energy color.</param>
        public void SetFierceDeityEnergyColors(Color color)
        {
            // Update sword beam energy colors.
            Colors.SwordBeamEnergyEnv = color;
            Colors.SwordBeamEnergyPrim = Color.White;
            // Update sparkle colors.
            Colors.FierceDeitySparklesInner = color.Brighten(0.5f);
            Colors.FierceDeitySparklesOuter = color;
        }
    }
}
