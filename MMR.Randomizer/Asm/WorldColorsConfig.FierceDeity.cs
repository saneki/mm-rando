using System.Drawing;

namespace MMR.Randomizer.Asm
{
    public partial class WorldColorsConfig
    {
        /// <summary>
        /// Update Fierce Deity energy colors from given base color.
        /// </summary>
        /// <param name="color">Sword beam energy color.</param>
        public void SetFierceDeityEnergyColors(Color color)
        {
            Colors.SwordBeamEnergyEnv = color;
            Colors.SwordBeamEnergyPrim = Color.White;
        }
    }
}
