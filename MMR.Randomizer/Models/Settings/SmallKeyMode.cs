using MMR.Randomizer.Attributes;
using System;

namespace MMR.Randomizer.Models
{
    [Flags]
    public enum SmallKeyMode
    {
        Default,

        /// <summary>
        /// Small Key Doors should be modified to assume they have been opened.
        /// Small Keys in the item pool will be replaced with other items.
        /// </summary>
        [HackContent(nameof(Resources.mods.key_small_open))]
        DoorsOpen,

        /// <summary>
        /// Randomization algorithm should place any randomized Small Keys into a location within the same region.
        /// Even if the Small Key has been replaced via another SmallKeyMode.
        /// </summary>
        KeepWithinDungeon,
    }
}
