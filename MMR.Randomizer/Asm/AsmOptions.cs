﻿using MMR.Randomizer.Skulltula;

namespace MMR.Randomizer.Asm
{
    /// <summary>
    /// Core options used for Asm.
    /// </summary>
    public class AsmOptionsGameplay
    {
        /// <summary>
        /// Miscellaneous configuration.
        /// </summary>
        public MiscConfig MiscConfig { get; set; } = new MiscConfig();

        /// <summary>
        /// Miscellaneous configuration.
        /// </summary>
        public MMRConfig MMRConfig { get; set; } = new MMRConfig();

        /// <summary>
        /// World Skulltula configuration, if any.
        /// </summary>
        public Spiders SpiderConfig { get; set; }
    }

    /// <summary>
    /// Post-patch options used for Asm.
    /// </summary>
    public class AsmOptionsCosmetic
    {
        /// <summary>
        /// Hash bytes.
        /// </summary>
        public byte[] Hash { get; set; }

        /// <summary>
        /// D-Pad configuration.
        /// </summary>
        public DPadConfig DPadConfig { get; set; } = new DPadConfig();

        /// <summary>
        /// HUD colors configuration.
        /// </summary>
        public HudColorsConfig HudColorsConfig { get; set; } = new HudColorsConfig();
    }
}
