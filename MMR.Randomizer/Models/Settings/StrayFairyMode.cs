using MMR.Randomizer.Attributes;
using System;

namespace MMR.Randomizer.Models
{
    [Flags]
    public enum StrayFairyMode
    {
        Default,

        /// <summary>
        /// Stray Fairies in the item pool will be replaced with other items.
        /// Remove non-Chest fairies (bubbles, free, beehives, etc.)
        /// Update chests constructor to change giIndex to be equal to the giIndex of the fairy that would be within.
        /// </summary>
        [HackContent(nameof(Resources.mods.fairies_chests_only))]
        ChestsOnly,

        /// <summary>
        /// Randomization algorithm should place any randomized Stray Fairies into a location within the same region.
        /// Even if the Stray Fairy has been replaced via another StrayFairyMode.
        /// </summary>
        KeepWithinDungeon,
    }
}
