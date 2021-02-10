using MMR.Randomizer.Attributes;
using System;

namespace MMR.Randomizer.Models
{
    [Flags]
    public enum BossKeyMode
    {
        Default,

        /// <summary>
        /// Boss Doors should be modified to assume they have been opened.
        /// Boss Keys in the item pool will be replaced with other items.
        /// </summary>
        [HackContent(nameof(Resources.mods.key_boss_open))]
        DoorsOpen,

        /// <summary>
        /// Randomization algorithm should place any randomized Boss Keys into a location within the same region.
        /// Even if the Boss Key has been replaced via another BossKeyMode.
        /// </summary>
        KeepWithinDungeon,
    }
}
