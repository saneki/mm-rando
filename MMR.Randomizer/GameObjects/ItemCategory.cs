using System.ComponentModel;

namespace MMR.Randomizer.GameObjects
{
    public enum ItemCategory
    {
        Fake = -1,
        None,

        [Description("Enable Song of Soaring being placed in the randomization pool.")]
        SongOfSoaring,

        [Description("Randomize Pieces of Heart and Heart Containers.")]
        PiecesOfHeart,

        [Description("Randomize small keys and boss keys.")]
        DungeonKeys,

        [Description("Randomize Great Fairy rewards including Magic Power, Great Spin Attack, Extended Magic Power, Double Defense, Great Fairy's Sword and Great Fairy's Mask.")]
        GreatFairyRewards,

        [Description("Randomize shops including Milk Bar, Tingle and Scrubs.")]
        ShopItems,

        [Description("Randomize miscellaneous items. Currently this only includes the Seahorse.")]
        Misc,

        [Description("Randomize bottle scoops.")]
        CaughtBottleContents,

        [Description("Randomize locations that require glitches. Includes:\n\n* The Deku Nut chest beneath Clock Town.")]
        GlitchesRequired,

        [Description("Randomize milk from cows.\n\nOne inaccessible ranch cow is not included for Casual logic.")]
        CowMilk,

        [Description("Randomize starting Sword, Shield, and two Heart Containers.")]
        CrazyStartingItems,

        [Description("Randomize golden skulltula tokens. Tokens will not reset to 0 after Song of Time.")]
        SkulltulaTokens,

        [Description("Randomize stray fairies including the Clock Town stray fairy. Stray fairies will not reset to 0 after Song of Time.")]
        StrayFairies,

        [Description("Randomize Gold Rupees within chests, rewarded by NPCs and dropped by enemies.")]
        GoldRupees,

        [Description("Randomize Silver Rupees within chests.")]
        SilverRupees,

        [Description("Randomize Purple Rupees within chests, rewarded by NPCs and from jars.")]
        PurpleRupees,

        [Description("Randomize Red Rupees within chests, rewarded by NPCs and freestanding ones.")]
        RedRupees,

        [Description("Randomize Blue Rupees within chests, rewarded by NPCs, from jars and freestanding ones.")]
        BlueRupees,

        [Description("Randomize Green Rupees from jars and freestanding ones.")]
        GreenRupees,

        [Description("Randomize ammo (including Bombs, Arrows, Deku Nuts, Deku Sticks and Magic Bean) from chests, jars and grass.")]
        Ammo,

        [Description("Randomize Bombchu.")]
        Bombchu,
    }
}
