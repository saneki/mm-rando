using MMR.Randomizer.Attributes;

namespace MMR.Randomizer.Models
{
    public enum DamageMode
    {
        Default,
        Double,
        Quadruple,
        OHKO,
        Doom
    }

    public enum SmallKeyMode
    {
        Default,

        /// <summary>
        /// Small Key Doors should be modified to assume they have been opened.
        /// Small Keys in the item pool will be replaced with other items.
        /// </summary>
        //[HackContent(nameof(Resources.mods.key_small_open))]
        DoorsOpen,

        /// <summary>
        /// Randomization algorithm should place any randomized Small Keys into a location within the same region.
        /// Even if the Small Key has been replaced via another SmallKeyMode.
        /// </summary>
        KeepWithinDungeon,
    }

    public enum BossKeyMode
    {
        Default,

        /// <summary>
        /// Boss Doors should be modified to assume they have been opened.
        /// Boss Keys in the item pool will be replaced with other items.
        /// </summary>
        //[HackContent(nameof(Resources.mods.key_boss_open))]
        DoorsOpen,

        /// <summary>
        /// Randomization algorithm should place any randomized Boss Keys into a location within the same region.
        /// Even if the Boss Key has been replaced via another BossKeyMode.
        /// </summary>
        KeepWithinDungeon,
    }

    public enum StrayFairyMode
    {
        Default,

        /// <summary>
        /// Stray Fairies in the item pool will be replaced with other items.
        /// Remove non-Chest fairies (bubbles, free, beehives, etc.)
        /// Update chests constructor to change giIndex to be equal to the giIndex of the fairy that would be within.
        /// </summary>
        //[HackContent(nameof(Resources.mods.fairies_chests_only))]
        ChestsOnly,

        /// <summary>
        /// Randomization algorithm should place any randomized Stray Fairies into a location within the same region.
        /// Even if the Stray Fairy has been replaced via another StrayFairyMode.
        /// </summary>
        KeepWithinDungeon,
    }
}
