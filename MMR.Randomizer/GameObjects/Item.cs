using MMR.Randomizer.Attributes;
using MMR.Randomizer.Attributes.Entrance;
using MMR.Randomizer.Models.Settings;

namespace MMR.Randomizer.GameObjects
{
    public enum Item
    {
        // free
        [ProvidesItem(ProvidedItem.DekuMask)]
        [LocationName("Starting Item"), Region(Region.Misc)]
        [GossipLocationHint("a new file", "a quest's inception")]
        [GetItemIndex(0x78)]
        MaskDeku,

        // items
        [ProvidesItem(ProvidedItem.Bow)]
        [LocationName("Hero's Bow Chest"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("Woodfall Temple", "the sleeping temple")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x02223000 + 0xAA, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x22)]
        ItemBow,

        [ProvidesItem(ProvidedItem.FireArrow)]
        [LocationName("Fire Arrow Chest"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("Snowhead Temple", "an icy gale")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x02336000 + 0xCA, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x25)]
        ItemFireArrow,

        [ProvidesItem(ProvidedItem.IceArrow)]
        [LocationName("Ice Arrow Chest"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("Great Bay Temple", "the ocean temple")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x0292F000 + 0x11E, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x26)]
        ItemIceArrow,

        [ProvidesItem(ProvidedItem.LightArrow)]
        [LocationName("Light Arrow Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x0212B000 + 0xB2, ChestAttribute.AppearanceType.AppearsSwitch, 0x02192000 + 0x8E)]
        [GetItemIndex(0x27)]
        ItemLightArrow,

        [ProvidesItem(ProvidedItem.BombBag)]
        [LocationName("Bomb Bag Purchase"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town shop")]
        [ShopRoom(ShopRoomAttribute.Room.BombShop, 0x48)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.BombShop, 0)]
        [GetItemIndex(0x1B)]
        ItemBombBag,

        [ProvidesItem(ProvidedItem.MagicBean)]
        [Repeatable, Temporary, CycleRepeatable]
        [LocationName("Bean Man"), Region(Region.DekuPalace)]
        [GossipLocationHint("a hidden merchant", "a gorging merchant")]
        [GetItemIndex(0x11E)]
        ItemMagicBean,

        [ProvidesItem(ProvidedItem.PowderKeg)]
        [Repeatable, CycleRepeatable]
        [LocationName("Powder Keg Challenge"), Region(Region.GoronVillage)]
        [GossipLocationHint("a large goron")]
        [GetItemIndex(0x123)]
        ItemPowderKeg,

        [ProvidesItem(ProvidedItem.Pictobox)]
        [LocationName("Koume"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a witch")]
        [GetItemIndex(0x43)]
        ItemPictobox,

        [ProvidesItem(ProvidedItem.LensOfTruth)]
        [LocationName("Lens of Truth Chest"), Region(Region.GoronVillage)]
        [GossipLocationHint("a lonely peak")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x02EB8000 + 0x9A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x42)]
        ItemLens,

        [ProvidesItem(ProvidedItem.Hookshot)]
        [LocationName("Hookshot Chest"), Region(Region.PiratesFortressInterior)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x0238B000 + 0x14A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x41)]
        ItemHookshot,

        [ProvidesItem(ProvidedItem.Magic)]
        [LocationName("Town Great Fairy Non-Human"), Region(Region.NorthClockTown)]
        [GossipLocationHint("a magical being")]
        [GetItemIndex(0x12C)]
        FairyMagic,

        [ProvidesItem(ProvidedItem.SpinAttack)]
        [LocationName("Woodfall Great Fairy"), Region(Region.Woodfall)]
        [GossipLocationHint("a magical being"), GossipCompetitiveHint(4, nameof(GameplaySettings.AddStrayFairies), false)]
        [GetItemIndex(0x12D)]
        FairySpinAttack,

        [ProvidesItem(ProvidedItem.DoubleMagic)]
        [LocationName("Snowhead Great Fairy"), Region(Region.Snowhead)]
        [GossipLocationHint("a magical being"), GossipCompetitiveHint(4, nameof(GameplaySettings.AddStrayFairies), false)]
        [GetItemIndex(0x12E)]
        FairyDoubleMagic,

        [ProvidesItem(ProvidedItem.DoubleDefense)]
        [LocationName("Ocean Great Fairy"), Region(Region.ZoraCape)]
        [GossipLocationHint("a magical being"), GossipCompetitiveHint(4, nameof(GameplaySettings.AddStrayFairies), false)]
        [GetItemIndex(0x12F)]
        FairyDoubleDefense,

        [ProvidesItem(ProvidedItem.GreatFairySword)]
        [LocationName("Ikana Great Fairy"), Region(Region.IkanaCanyon)]
        [GossipLocationHint("a magical being"), GossipCompetitiveHint(4, nameof(GameplaySettings.AddStrayFairies), false)]
        [GetItemIndex(0x130)]
        ItemFairySword,

        [ProvidesItem(ProvidedItem.BottleWithRedPotion)]
        [Repeatable, Temporary, Overwritable] // specially handled to turn into Red Potion on subsequent times
        [LocationName("Kotake"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("the sleeping witch")]
        [GetItemIndex(0x59)]
        ItemBottleWitch,

        [ProvidesItem(ProvidedItem.BottleWithMilk)]
        [Repeatable, Temporary, Overwritable] // specially handled to turn into Milk on subsequent times
        [LocationName("Aliens Defense"), Region(Region.RomaniRanch)]
        [GossipLocationHint("the ranch girl", "a good deed")]
        [GossipCombineOrder(0), GossipCombine(MaskRomani, "Ranch Sisters Defense")]
        [GetItemIndex(0x60)]
        ItemBottleAliens,

        [ProvidesItem(ProvidedItem.BottleWithGoldDust)]
        [RupeeRepeatable]
        [Repeatable, Temporary, Overwritable] // specially handled to turn into Gold Dust on subsequent times
        [LocationName("Goron Race"), Region(Region.TwinIslands)]
        [GossipLocationHint("a sporting event"), GossipCompetitiveHint(-2)]
        [GetItemIndex(0x6A)]
        ItemBottleGoronRace,

        [ProvidesItem(ProvidedItem.EmptyBottle)]
        [LocationName("Beaver Race #1"), Region(Region.ZoraCape)]
        [GossipLocationHint("a river dweller"), GossipCompetitiveHint(-2)]
        [GossipCombineOrder(0), GossipCombine(HeartPieceBeaverRace, "Beaver Races")]
        [GetItemIndex(0x5A)]
        ItemBottleBeavers,

        [ProvidesItem(ProvidedItem.EmptyBottle)]
        [LocationName("Dampe Digging"), Region(Region.IkanaGraveyard)]
        [GossipLocationHint("a fearful basement"), GossipCompetitiveHint]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x0261E000 + 0x1FE, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x64)]
        ItemBottleDampe,

        [ProvidesItem(ProvidedItem.ChateauRomani)]
        [Repeatable, Temporary, Overwritable] // specially handled to turn into Chateau Romani on subsequent times
        [LocationName("Madame Aroma in Bar"), Region(Region.EastClockTown)]
        [GossipLocationHint("an important lady")]
        [GetItemIndex(0x6F)]
        ItemBottleMadameAroma,

        [ProvidesItem(ProvidedItem.Notebook)]
        [LocationName("Bombers' Hide and Seek"), Region(Region.NorthClockTown)]
        [GossipLocationHint("a group of children", "a town game")]
        [GetItemIndex(0x50)]
        ItemNotebook,

        //upgrades
        [ProvidesItem(ProvidedItem.RazorSword)]
        [LocationName("Mountain Smithy Day 1"), Region(Region.MountainVillage)]
        [GossipLocationHint("the mountain smith")]
        [GetItemIndex(0x38)]
        UpgradeRazorSword,

        [ProvidesItem(ProvidedItem.GildedSword)]
        [LocationName("Mountain Smithy Day 2"), Region(Region.MountainVillage)]
        [GossipLocationHint("the mountain smith")]
        [GetItemIndex(0x39)]
        UpgradeGildedSword,

        [ProvidesItem(ProvidedItem.MirrorShield)]
        [LocationName("Mirror Shield Chest"), Region(Region.BeneathTheWell)]
        [GossipLocationHint("a hollow ground")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x029FE000 + 0x1AA, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x33)]
        UpgradeMirrorShield,

        [ProvidesItem(ProvidedItem.BigQuiver)]
        [RupeeRepeatable]
        [LocationName("Town Archery #1"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town activity")]
        [GossipCombineOrder(0), GossipCombine(HeartPieceTownArchery, "Town Archery")]
        [GetItemIndex(0x23)]
        UpgradeBigQuiver,

        [ProvidesItem(ProvidedItem.BiggestQuiver)]
        [RupeeRepeatable]
        [LocationName("Swamp Archery #1"), Region(Region.RoadToSouthernSwamp)]
        [GossipLocationHint("a swamp game")]
        [GossipCombineOrder(0), GossipCombine(HeartPieceSwampArchery, "Swamp Archery")]
        [GetItemIndex(0x24)]
        UpgradeBiggestQuiver,

        [ProvidesItem(ProvidedItem.BigBombBag)]
        [LocationName("Big Bomb Bag Purchase"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town shop")]
        [ShopRoom(ShopRoomAttribute.Room.BombShop, 0x52)]
        [ShopRoom(ShopRoomAttribute.Room.CuriosityShop, 0x44)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.BombShop, 1)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.CuriosityShop, 2)]
        [GetItemIndex(0x1C)]
        UpgradeBigBombBag,

        [ProvidesItem(ProvidedItem.BiggestBombBag)]
        [Purchaseable]
        [LocationName("Biggest Bomb Bag Purchase"), Region(Region.GoronVillage)]
        [GossipLocationHint("a northern merchant")]
        [GetItemIndex(0x1D)]
        UpgradeBiggestBombBag,

        [ProvidesItem(ProvidedItem.AdultWallet)]
        [LocationName("Bank Reward #1"), Region(Region.WestClockTown)]
        [GossipLocationHint("a keeper of wealth")]
        [GetItemIndex(0x08)]
        UpgradeAdultWallet,

        [ProvidesItem(ProvidedItem.GiantWallet)]
        [LocationName("Ocean Spider House Day 1 Reward"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a gold spider"), GossipCompetitiveHint(0, nameof(GameplaySettings.AddSkulltulaTokens), false)]
        [GossipCombineOrder(0), GossipCombine(MundaneItemOceanSpiderHouseDay2PurpleRupee, "Ocean Spider House"), GossipCombine(MundaneItemOceanSpiderHouseDay3RedRupee, "Ocean Spider House")]
        [GetItemIndex(0x09)]
        UpgradeGiantWallet,

        //trades
        [Visible]
        [ProvidesItem(ProvidedItem.MoonTear)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Astronomy Telescope"), Region(Region.TerminaField)]
        [GossipLocationHint("a falling star")]
        [GetItemIndex(0x96)]
        TradeItemMoonTear,

        [ProvidesItem(ProvidedItem.LandDeed)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Clock Town Scrub Trade"), Region(Region.SouthClockTown)]
        [GossipLocationHint("a town merchant")]
        [GetItemIndex(0x97)]
        TradeItemLandDeed,

        [ProvidesItem(ProvidedItem.SwampDeed)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Swamp Scrub Trade"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a southern merchant")]
        [GetItemIndex(0x98)]
        TradeItemSwampDeed,

        [ProvidesItem(ProvidedItem.MountainDeed)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Mountain Scrub Trade"), Region(Region.GoronVillage)]
        [GossipLocationHint("a northern merchant")]
        [GetItemIndex(0x99)]
        TradeItemMountainDeed,

        [ProvidesItem(ProvidedItem.OceanDeed)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Ocean Scrub Trade"), Region(Region.ZoraHall)]
        [GossipLocationHint("a western merchant")]
        [GetItemIndex(0x9A)]
        TradeItemOceanDeed,

        [ProvidesItem(ProvidedItem.RoomKey)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Inn Reservation"), Region(Region.StockPotInn)]
        [GossipLocationHint("checking in", "check-in")]
        [GetItemIndex(0xA0)]
        TradeItemRoomKey,

        [ProvidesItem(ProvidedItem.KafeiLetter)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Midnight Meeting"), Region(Region.StockPotInn)]
        [GossipLocationHint("a late meeting")]
        [GetItemIndex(0xAA)]
        TradeItemKafeiLetter,

        [ProvidesItem(ProvidedItem.Pendant)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Kafei"), Region(Region.LaundryPool)]
        [GossipLocationHint("a posted letter")]
        [GetItemIndex(0xAB)]
        TradeItemPendant,

        [ProvidesItem(ProvidedItem.MamaLetter)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Curiosity Shop Man #2"), Region(Region.LaundryPool)]
        [GossipLocationHint("a shady gentleman", "a dodgy seller", "a shady dealer")]
        [GetItemIndex(0xA1)]
        TradeItemMamaLetter,

        //notebook hp
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Mayor"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town leader", "an upstanding figure")]
        [GetItemIndex(0x03)]
        HeartPieceNotebookMayor,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Postman's Game"), Region(Region.WestClockTown)]
        [GossipLocationHint("a hard worker", "a delivery person")]
        [GetItemIndex(0xCE)]
        HeartPieceNotebookPostman,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Rosa Sisters"), Region(Region.WestClockTown)]
        [GossipLocationHint("traveling sisters", "twin entertainers")]
        [GetItemIndex(0x2B)]
        HeartPieceNotebookRosa,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Toilet Hand"), Region(Region.StockPotInn)]
        [GossipLocationHint("a mystery appearance", "a strange palm")]
        [GetItemIndex(0x2C)]
        HeartPieceNotebookHand,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Grandma Short Story"), Region(Region.StockPotInn)]
        [GossipLocationHint("an old lady")]
        [GetItemIndex(0x2D)]
        HeartPieceNotebookGran1,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Grandma Long Story"), Region(Region.StockPotInn)]
        [GossipLocationHint("an old lady")]
        [GetItemIndex(0x2F)]
        HeartPieceNotebookGran2,

        //other hp
        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Keaton Quiz"), Region(Region.NorthClockTown)]
        [GossipLocationHint("the ghost of a fox", "a mysterious fox")]
        [GetItemIndex(0x30)]
        HeartPieceKeatonQuiz,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Deku Playground Three Days"), Region(Region.NorthClockTown)]
        [GossipLocationHint("a game for scrubs", "a playground", "a town game"), GossipCompetitiveHint]
        [GossipCombineOrder(1), GossipCombine(MundaneItemDekuPlaygroundPurpleRupee, "Deku Playground")]
        [GetItemIndex(0x31)]
        HeartPieceDekuPlayground,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Town Archery #2"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town game"), GossipCompetitiveHint(1)]
        [GossipCombineOrder(1), GossipCombine(UpgradeBigQuiver, "Town Archery")]
        [GetItemIndex(0x90)]
        HeartPieceTownArchery,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Honey and Darling Three Days"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town game"), GossipCompetitiveHint(-2)]
        [GossipCombineOrder(1), GossipCombine(MundaneItemHoneyAndDarlingPurpleRupee, "Honey and Darling")]
        [GetItemIndex(0x94)]
        HeartPieceHoneyAndDarling,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Swordsman's School"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town game")]
        [GetItemIndex(0x9F)]
        HeartPieceSwordsmanSchool,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Postbox"), Region(Region.SouthClockTown)]
        [GossipLocationHint("an information carrier", "a correspondence box")]
        [GetItemIndex(0xA2)]
        HeartPiecePostBox,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Gossip Stones"), Region(Region.TerminaField)]
        [GossipLocationHint("mysterious stones"), GossipCompetitiveHint(-2)]
        [GetItemIndex(0xA3)]
        HeartPieceTerminaGossipStones,

        [Purchaseable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Business Scrub Purchase"), Region(Region.TerminaField)]
        [GossipLocationHint("a hidden merchant")]
        [GetItemIndex(0xA5)]
        HeartPieceTerminaBusinessScrub,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Swamp Archery #2"), Region(Region.RoadToSouthernSwamp)]
        [GossipLocationHint("a swamp game"), GossipCompetitiveHint(1)]
        [GossipCombineOrder(1), GossipCombine(UpgradeBiggestQuiver, "Swamp Archery")]
        [GetItemIndex(0xA6)]
        HeartPieceSwampArchery,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Pictograph Contest Winner"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a swamp game")]
        [GetItemIndex(0xA7)]
        HeartPiecePictobox,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Boat Archery"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a swamp game"), GossipCompetitiveHint]
        [GetItemIndex(0xA8)]
        HeartPieceBoatArchery,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Frog Choir"), Region(Region.MountainVillage)]
        [GossipLocationHint("a reunion", "a chorus", "an amphibian choir"), GossipCompetitiveHint(3)]
        [GetItemIndex(0xAC)]
        HeartPieceChoir,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Beaver Race #2"), Region(Region.ZoraCape)]
        [GossipLocationHint("a river dweller", "a race in the water"), GossipCompetitiveHint(1)]
        [GossipCombineOrder(1), GossipCombine(ItemBottleBeavers, "Beaver Races")]
        [GetItemIndex(0xAD)]
        HeartPieceBeaverRace,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Seahorses"), Region(Region.PinnacleRock)]
        [GossipLocationHint("a reunion"), GossipCompetitiveHint(-2)]
        [GetItemIndex(0xAE)]
        HeartPieceSeaHorse,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Fisherman Game"), Region(Region.GreatBayCoast), GossipCompetitiveHint(-2)]
        [GossipLocationHint("an ocean game")]
        [GetItemIndex(0xAF)]
        HeartPieceFishermanGame,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Evan"), Region(Region.ZoraHall)]
        [GossipLocationHint("a muse", "a composition", "a musician", "plagiarism")]
        [GetItemIndex(0xB0)]
        HeartPieceEvan,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Dog Race"), Region(Region.RomaniRanch)]
        [GossipLocationHint("a sporting event")]
        [GetItemIndex(0xB1)]
        HeartPieceDogRace,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Poe Hut"), Region(Region.IkanaCanyon)]
        [GossipLocationHint("a game of ghosts")]
        [GetItemIndex(0xB2)]
        HeartPiecePoeHut,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Treasure Chest Game Goron"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town game")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x00F43F10 + 0xFAA, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x17)]
        HeartPieceTreasureChestGame,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Peahat Grotto"), Region(Region.TerminaField)]
        [GossipLocationHint("a hollow ground")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02ED3000 + 0x76, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x18)]
        HeartPiecePeahat,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Dodongo Grotto"), Region(Region.TerminaField)]
        [GossipLocationHint("a hollow ground")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02EBD000 + 0x76, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x20)]
        HeartPieceDodong,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Woodfall Bridge Chest"), Region(Region.Woodfall)]
        [GossipLocationHint("the swamp lands", "an exposed chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02884000 + 0x252, ChestAttribute.AppearanceType.Normal, 0x02884000 + 0xA52)]
        [GetItemIndex(0x29)]
        HeartPieceWoodFallChest,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Twin Islands Underwater Ramp Chest"), Region(Region.TwinIslands)]
        [GossipLocationHint("a spring treasure", "a defrosted land", "a submerged chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02C23000 + 0x2B6, ChestAttribute.AppearanceType.Normal, 0x02C34000 + 0x19A)]
        [GetItemIndex(0x2E)]
        HeartPieceTwinIslandsChest,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Ocean Spider House Chest"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("the strange masks", "coloured faces")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x024DB000 + 0x76, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x14)]
        HeartPieceOceanSpiderHouse,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Iron Knuckle Chest"), Region(Region.IkanaGraveyard)]
        [GossipLocationHint("a hollow ground")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x01FAB000 + 0xBA, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x44)]
        HeartPieceKnuckle,

        //mask
        [ProvidesItem(ProvidedItem.PostmanHat)]
        [LocationName("Postman's Freedom Reward"), Region(Region.EastClockTown)]
        [GossipLocationHint("a special delivery", "one last job")]
        [GetItemIndex(0x84)]
        MaskPostmanHat,

        [ProvidesItem(ProvidedItem.AllNightMask)]
        [LocationName("All Night Mask Purchase"), Region(Region.WestClockTown)]
        [GossipLocationHint("a shady gentleman", "a dodgy seller", "a shady dealer"), GossipCompetitiveHint(0, nameof(GameplaySettings.UpdateShopAppearance), false)]
        [ShopRoom(ShopRoomAttribute.Room.CuriosityShop, 0x54)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.CuriosityShop, 0)]
        [GetItemIndex(0x7E)]
        MaskAllNight,

        [ProvidesItem(ProvidedItem.BlastMask)]
        [LocationName("Old Lady"), Region(Region.NorthClockTown)]
        [GossipLocationHint("a good deed", "an old lady's struggle")]
        [GetItemIndex(0x8D)]
        MaskBlast,

        [ProvidesItem(ProvidedItem.StoneMask)]
        [LocationName("Invisible Soldier"), Region(Region.RoadToIkana)]
        [GossipLocationHint("a hidden soldier", "a stone circle")]
        [GetItemIndex(0x8B)]
        MaskStone,

        [ProvidesItem(ProvidedItem.GreatFairyMask)]
        [LocationName("Town Great Fairy"), Region(Region.NorthClockTown)]
        [GossipLocationHint("a magical being")]
        [GetItemIndex(0x131)]
        MaskGreatFairy,

        [ProvidesItem(ProvidedItem.KeatonMask)]
        [LocationName("Curiosity Shop Man #1"), Region(Region.LaundryPool)]
        [GossipLocationHint("a shady gentleman", "a dodgy seller", "a shady dealer")]
        [GetItemIndex(0x80)]
        MaskKeaton,

        [ProvidesItem(ProvidedItem.BremenMask)]
        [LocationName("Guru Guru"), Region(Region.LaundryPool)]
        [GossipLocationHint("a musician", "an entertainer")]
        [GetItemIndex(0x8C)]
        MaskBremen,

        [ProvidesItem(ProvidedItem.BunnyHood)]
        [LocationName("Grog"), Region(Region.RomaniRanch)]
        [GossipLocationHint("an ugly but kind heart", "a lover of chickens")]
        [GetItemIndex(0x7F)]
        MaskBunnyHood,

        [ProvidesItem(ProvidedItem.DonGeroMask)]
        [LocationName("Hungry Goron"), Region(Region.MountainVillage)]
        [GossipLocationHint("a hungry goron", "a person in need")]
        [GetItemIndex(0x88)]
        MaskDonGero,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.MaskOfScents)]
        [LocationName("Butler"), Region(Region.DekuPalace)]
        [GossipLocationHint("a servant of royalty", "the royal servant"), GossipCompetitiveHint(-1)]
        [GetItemIndex(0x8E)]
        MaskScents,

        [ProvidesItem(ProvidedItem.RomaniMask)]
        [LocationName("Cremia"), Region(Region.RomaniRanch)]
        [GossipLocationHint("the ranch lady", "an older sister"), GossipCompetitiveHint]
        [GossipCombineOrder(1), GossipCombine(ItemBottleAliens, "Ranch Sisters Defense")]
        [GetItemIndex(0x82)]
        MaskRomani,

        [ProvidesItem(ProvidedItem.CircusLeaderMask)]
        [LocationName("Gorman"), Region(Region.EastClockTown)]
        [GossipLocationHint("an entertainer", "a miserable leader")]
        [GetItemIndex(0x83)]
        MaskCircusLeader,

        [ProvidesItem(ProvidedItem.KafeiMask)]
        [LocationName("Madame Aroma in Office"), Region(Region.EastClockTown)]
        [GossipLocationHint("an important lady", "an esteemed woman")]
        [GetItemIndex(0x8F)]
        MaskKafei,

        [ProvidesItem(ProvidedItem.CoupleMask)]
        [LocationName("Anju and Kafei"), Region(Region.StockPotInn)]
        [GossipLocationHint("a reunion", "a lovers' reunion"), GossipCompetitiveHint(3)]
        [GetItemIndex(0x85)]
        MaskCouple,

        [ProvidesItem(ProvidedItem.MaskOfTruth)]
        [LocationName("Swamp Spider House Reward"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a gold spider"), GossipCompetitiveHint(0, nameof(GameplaySettings.AddSkulltulaTokens), false)]
        [GetItemIndex(0x8A)]
        MaskTruth,

        [ProvidesItem(ProvidedItem.KamaroMask)]
        [LocationName("Kamaro"), Region(Region.TerminaField)]
        [GossipLocationHint("a ghostly dancer", "a dancer")]
        [GetItemIndex(0x89)]
        MaskKamaro,

        [ProvidesItem(ProvidedItem.GibdoMask)]
        [LocationName("Pamela's Father"), Region(Region.IkanaCanyon)]
        [GossipLocationHint("a healed spirit", "a lost father")]
        [GetItemIndex(0x87)]
        MaskGibdo,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.GaroMask)]
        [LocationName("Gorman Bros Race"), Region(Region.MilkRoad)]
        [GossipLocationHint("a sporting event")]
        [GetItemIndex(0x81)]
        MaskGaro,

        [ProvidesItem(ProvidedItem.CaptainHat)]
        [LocationName("Captain Keeta's Chest"), Region(Region.IkanaGraveyard)]
        [GossipLocationHint("a ghostly battle", "a skeletal leader")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x0280D000 + 0x392, ChestAttribute.AppearanceType.Normal, 0x0280D000 + 0x6FA)]
        [GetItemIndex(0x7C)]
        MaskCaptainHat,

        [ProvidesItem(ProvidedItem.GiantMask)]
        [LocationName("Giant's Mask Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x020F1000 + 0x1C2, ChestAttribute.AppearanceType.AppearsSwitch, 0x02164000 + 0x19E)]
        [GetItemIndex(0x7D)]
        MaskGiant,

        [ProvidesItem(ProvidedItem.GoronMask)]
        [LocationName("Darmani"), Region(Region.MountainVillage)]
        [GossipLocationHint("a healed spirit", "the lost champion")]
        [GetItemIndex(0x79)]
        MaskGoron,

        [ProvidesItem(ProvidedItem.ZoraMask)]
        [LocationName("Mikau"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a healed spirit", "a fallen guitarist")]
        [GetItemIndex(0x7A)]
        MaskZora,

        //song
        [ProvidesItem(ProvidedItem.SongOfHealing)]
        [LocationName("Starting Song"), Region(Region.Misc)]
        [GossipLocationHint("a new file", "a quest's inception")]
        [GetItemIndex(0x124)]
        SongHealing,

        [ProvidesItem(ProvidedItem.SongOfSoaring)]
        [LocationName("Swamp Music Statue"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a stone tablet")]
        [GetItemIndex(0x70)]
        SongSoaring,

        [RupeeRepeatable]
        [ProvidesItem(ProvidedItem.EponaSong)]
        [LocationName("Romani's Game"), Region(Region.RomaniRanch)]
        [GossipLocationHint("a reunion")]
        [GetItemIndex(0x71)]
        SongEpona,

        [ProvidesItem(ProvidedItem.SongOfStorms)]
        [LocationName("Day 1 Grave Tablet"), Region(Region.IkanaGraveyard)]
        [GossipLocationHint("a hollow ground", "a stone tablet")]
        [GetItemIndex(0x72)]
        SongStorms,

        [ProvidesItem(ProvidedItem.SonataOfAwakening)]
        [LocationName("Imprisoned Monkey"), Region(Region.DekuPalace)]
        [GossipLocationHint("a prisoner", "a false imprisonment")]
        [GetItemIndex(0x73)]
        SongSonata,

        [ProvidesItem(ProvidedItem.GoronLullaby)]
        [LocationName("Baby Goron"), Region(Region.GoronVillage)]
        [GossipLocationHint("a lonely child", "an elder's son")]
        [GetItemIndex(0x74)]
        SongLullaby,

        [ProvidesItem(ProvidedItem.NewWaveBossaNova)]
        [LocationName("Baby Zoras"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("the lost children", "the pirates' loot"), GossipCompetitiveHint(2, nameof(GameplaySettings.AddSongs), true)]
        [GetItemIndex(0x75)]
        SongNewWaveBossaNova,

        [ProvidesItem(ProvidedItem.ElegyOfEmptiness)]
        [LocationName("Ikana King"), Region(Region.IkanaCastle)]
        [GossipLocationHint("a fallen king", "a battle in darkness")]
        [GetItemIndex(0x1CB)] // 0x76 is a special value used for ice traps in chests
        SongElegy,

        [Visible]
        [ProvidesItem(ProvidedItem.OathToOrder)]
        [LocationName("Boss Blue Warp"), Region(Region.Misc)]
        [GossipLocationHint("cleansed evil", "a fallen evil")]
        [GetItemIndex(0x77)]
        SongOath,

        //areas/other
        AreaSouthAccess,

        [EntranceName("Woodfall")]
        [DungeonEntrance(DungeonEntrance.EntranceWoodfallTempleFromWoodfall, DungeonEntrance.EntranceWoodfallFromWoodfallTempleEntrance)]
        AreaWoodFallTempleAccess,

        [DungeonEntrance(DungeonEntrance.EntranceWoodfallTemplePrisonFromOdolwasLair)]
        AreaWoodFallTempleClear,
        AreaNorthAccess,

        [EntranceName("Snowhead")]
        [DungeonEntrance(DungeonEntrance.EntranceSnowheadTempleFromSnowhead, DungeonEntrance.EntranceSnowheadFromSnowheadTemple)]
        AreaSnowheadTempleAccess,

        [DungeonEntrance(DungeonEntrance.EntranceMountainVillageFromSnowheadClear)]
        AreaSnowheadTempleClear,
        OtherEpona,
        AreaWestAccess,
        AreaPiratesFortressAccess,

        [EntranceName("Great Bay")]
        [DungeonEntrance(DungeonEntrance.EntranceGreatBayTempleFromZoraCape, DungeonEntrance.EntranceZoraCapeFromGreatBayTemple)]
        AreaGreatBayTempleAccess,

        [DungeonEntrance(DungeonEntrance.EntranceZoraCapeFromGreatBayTempleClear)]
        AreaGreatBayTempleClear,
        AreaEastAccess,
        AreaIkanaCanyonAccess,
        AreaStoneTowerTempleAccess,

        [EntranceName("Inverted Stone Tower")]
        [DungeonEntrance(DungeonEntrance.EntranceStoneTowerTempleInvertedFromStoneTowerInverted, DungeonEntrance.EntranceStoneTowerInvertedFromStoneTowerTempleInverted)]
        AreaInvertedStoneTowerTempleAccess,

        [DungeonEntrance(DungeonEntrance.EntranceIkanaCanyonFromIkanaClear)]
        AreaStoneTowerClear,
        OtherExplosive,
        OtherArrow,
        AreaWoodfallNew,
        AreaSnowheadNew,
        AreaGreatBayNew,
        AreaLANew, // ??
        AreaInvertedStoneTowerNew, // Seemingly not used

        //keysanity items
        [ProvidesItem(ProvidedItem.WoodfallMap)]
        [LocationName("Woodfall Map Chest"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("Woodfall Temple", "the sleeping temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x0221F000 + 0x12A, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x3E)]
        ItemWoodfallMap,

        [ProvidesItem(ProvidedItem.WoodfallCompass)]
        [LocationName("Woodfall Compass Chest"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("Woodfall Temple", "the sleeping temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02215000 + 0xFA, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x3F)]
        ItemWoodfallCompass,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.WoodfallBossKey)]
        [LocationName("Woodfall Boss Key Chest"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("Woodfall Temple", "the sleeping temple")]
        [ChestType(ChestTypeAttribute.ChestType.BossKey), Chest(0x02227000 + 0x11A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x3D)]
        ItemWoodfallBossKey,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.WoodfallSmallKey)]
        [LocationName("Woodfall Small Key Chest"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("Woodfall Temple", "the sleeping temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02218000 + 0x1CA, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x3C)]
        ItemWoodfallKey1,

        [ProvidesItem(ProvidedItem.SnowheadMap)]
        [LocationName("Snowhead Map Chest"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("Snowhead Temple", "an icy gale")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02346000 + 0x13A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x54)]
        ItemSnowheadMap,

        [ProvidesItem(ProvidedItem.SnowheadCompass)]
        [LocationName("Snowhead Compass Chest"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("Snowhead Temple", "an icy gale")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x022F2000 + 0x1BA, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x57)]
        ItemSnowheadCompass,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.SnowheadBossKey)]
        [LocationName("Snowhead Boss Key Chest"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("Snowhead Temple", "an icy gale")]
        [ChestType(ChestTypeAttribute.ChestType.BossKey), Chest(0x0230C000 + 0x57A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x4E)]
        ItemSnowheadBossKey,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.SnowheadSmallKey)]
        [LocationName("Snowhead Block Room Chest"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("Snowhead Temple", "an icy gale")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02306000 + 0x12A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x46)]
        ItemSnowheadKey1,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.SnowheadSmallKey)]
        [LocationName("Snowhead Icicle Room Chest"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("Snowhead Temple", "an icy gale")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0233A000 + 0x23A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x47)]
        ItemSnowheadKey2,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.SnowheadSmallKey)]
        [LocationName("Snowhead Bridge Room Chest"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("Snowhead Temple", "an icy gale")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x022F9000 + 0x19A, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x48)]
        ItemSnowheadKey3,

        [ProvidesItem(ProvidedItem.GreatBayMap)]
        [LocationName("Great Bay Map Chest"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("Great Bay Temple", "the ocean temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02905000 + 0x19A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x55)]
        ItemGreatBayMap,

        [ProvidesItem(ProvidedItem.GreatBayCompass)]
        [LocationName("Great Bay Compass Chest"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("Great Bay Temple", "the ocean temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02914000 + 0x21A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x58)]
        ItemGreatBayCompass,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.GreatBayBossKey)]
        [LocationName("Great Bay Boss Key Chest"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("Great Bay Temple", "the ocean temple")]
        [ChestType(ChestTypeAttribute.ChestType.BossKey), Chest(0x02914000 + 0x1FA, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x4F)]
        ItemGreatBayBossKey,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.GreatBaySmallKey)]
        [LocationName("Great Bay Small Key Chest"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("Great Bay Temple", "the ocean temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02914000 + 0x20A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x40)]
        ItemGreatBayKey1,

        [ProvidesItem(ProvidedItem.StoneTowerMap)]
        [LocationName("Stone Tower Map Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x0210F000 + 0x222, ChestAttribute.AppearanceType.Normal, 0x02182000 + 0x21E)]
        [GetItemIndex(0x56)]
        ItemStoneTowerMap,

        [ProvidesItem(ProvidedItem.StoneTowerCompass)]
        [LocationName("Stone Tower Compass Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02104000 + 0x292, ChestAttribute.AppearanceType.Normal, 0x02177000 + 0x2DE)]
        [GetItemIndex(0x6C)]
        ItemStoneTowerCompass,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.StoneTowerBossKey)]
        [LocationName("Stone Tower Boss Key Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.BossKey), Chest(0x02130000 + 0x82, ChestAttribute.AppearanceType.Normal, 0x02198000 + 0xCE)]
        [GetItemIndex(0x53)]
        ItemStoneTowerBossKey,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.StoneTowerSmallKey)]
        [LocationName("Stone Tower Armor Room Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0210F000 + 0x202, ChestAttribute.AppearanceType.AppearsSwitch, 0x02182000 + 0x1FE)]
        [GetItemIndex(0x49)]
        ItemStoneTowerKey1,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.StoneTowerSmallKey)]
        [LocationName("Stone Tower Eyegore Room Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x020F1000 + 0x1D2, ChestAttribute.AppearanceType.Normal, 0x02164000 + 0x1AE)]
        [GetItemIndex(0x4A)]
        ItemStoneTowerKey2,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.StoneTowerSmallKey)]
        [LocationName("Stone Tower Updraft Room Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02104000 + 0x282, ChestAttribute.AppearanceType.AppearsSwitch, 0x02177000 + 0x2CE)]
        [GetItemIndex(0x4B)]
        ItemStoneTowerKey3,

        [Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.StoneTowerSmallKey)]
        [LocationName("Stone Tower Death Armos Maze Chest"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("Stone Tower Temple", "the cursed temple")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x020FC000 + 0x252, ChestAttribute.AppearanceType.Normal, 0x0216E000 + 0x1CE)]
        [GetItemIndex(0x4D)]
        ItemStoneTowerKey4,

        //shop items
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [ProvidesItem(ProvidedItem.RedPotion)]
        [LocationName("Trading Post Red Potion"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant", "a convenience store", "a market")]
        [ShopRoom(ShopRoomAttribute.Room.TradingPost, 0x42)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostMain, 7)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostPartTimer, 7)]
        [GetItemIndex(0xCD)]
        ShopItemTradingPostRedPotion,

        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [ProvidesItem(ProvidedItem.GreenPotion)]
        [LocationName("Trading Post Green Potion"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant", "a convenience store", "a market")]
        [ShopRoom(ShopRoomAttribute.Room.TradingPost, 0x62)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostMain, 2)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostPartTimer, 3)]
        [GetItemIndex(0xBB)]
        ShopItemTradingPostGreenPotion,

        [Repeatable, CycleRepeatable]
        [ProvidesItem(ProvidedItem.HeroShield)]
        [LocationName("Trading Post Hero's Shield"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant", "a convenience store", "a market")]
        [ShopRoom(ShopRoomAttribute.Room.TradingPost, 0x44)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostMain, 3)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostPartTimer, 6)]
        [GetItemIndex(0xBC)]
        ShopItemTradingPostShield,

        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [ProvidesItem(ProvidedItem.Fairy)]
        [LocationName("Trading Post Fairy"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant", "a convenience store", "a market")]
        [ShopRoom(ShopRoomAttribute.Room.TradingPost, 0x5C)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostMain, 0)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostPartTimer, 0)]
        [GetItemIndex(0xBD)]
        ShopItemTradingPostFairy,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.DekuStick)]
        [LocationName("Trading Post Deku Stick"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant", "a convenience store", "a market")]
        [ShopRoom(ShopRoomAttribute.Room.TradingPost, 0x48)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostMain, 4)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostPartTimer, 5)]
        [GetItemIndex(0xBE)]
        ShopItemTradingPostStick,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Arrow30)]
        [LocationName("Trading Post 30 Arrows"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant", "a convenience store", "a market")]
        [ShopRoom(ShopRoomAttribute.Room.TradingPost, 0x4A)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostMain, 5)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostPartTimer, 1)]
        [GetItemIndex(0xBF)]
        ShopItemTradingPostArrow30,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.DekuNut10)]
        [LocationName("Trading Post 10 Deku Nuts"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant", "a convenience store", "a market")]
        [ShopRoom(ShopRoomAttribute.Room.TradingPost, 0x46)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostMain, 6)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostPartTimer, 4)]
        [GetItemIndex(0xC0)]
        ShopItemTradingPostNut10,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Arrow50)]
        [LocationName("Trading Post 50 Arrows"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant", "a convenience store", "a market")]
        [ShopRoom(ShopRoomAttribute.Room.TradingPost, 0x64)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostMain, 1)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.TradingPostPartTimer, 2)]
        [GetItemIndex(0xC1)]
        ShopItemTradingPostArrow50,

        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [ProvidesItem(ProvidedItem.BluePotion)]
        [LocationName("Witch Shop Blue Potion"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a sleeping witch", "a southern merchant")]
        [ShopRoom(ShopRoomAttribute.Room.WitchShop, 0x42)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.WitchShop, 2)]
        [GetItemIndex(0xC2)]
        ShopItemWitchBluePotion,

        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [ProvidesItem(ProvidedItem.RedPotion)]
        [LocationName("Witch Shop Red Potion"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a sleeping witch", "a southern merchant")]
        [ShopRoom(ShopRoomAttribute.Room.WitchShop, 0x48)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.WitchShop, 0)]
        [GetItemIndex(0xC3)]
        ShopItemWitchRedPotion,

        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [ProvidesItem(ProvidedItem.GreenPotion)]
        [LocationName("Witch Shop Green Potion"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a sleeping witch", "a southern merchant")]
        [ShopRoom(ShopRoomAttribute.Room.WitchShop, 0x4A)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.WitchShop, 1)]
        [GetItemIndex(0xC4)]
        ShopItemWitchGreenPotion,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bomb10)]
        [LocationName("Bomb Shop 10 Bombs"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant")]
        [ShopRoom(ShopRoomAttribute.Room.BombShop, 0x44)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.BombShop, 3)]
        [GetItemIndex(0xC5)]
        ShopItemBombsBomb10,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu10)]
        [LocationName("Bomb Shop 10 Bombchu"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town merchant")]
        [ShopRoom(ShopRoomAttribute.Room.BombShop, 0x42)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.BombShop, 2)]
        [GetItemIndex(0xC6)]
        ShopItemBombsBombchu10,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bomb10)]
        [LocationName("Goron Shop 10 Bombs"), Region(Region.GoronVillage)]
        [GossipLocationHint("a northern merchant", "a bored goron")]
        [ShopRoom(ShopRoomAttribute.Room.GoronShop, 0x48)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.GoronShop, 0)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.GoronShopSpring, 0)]
        [GetItemIndex(0xC7)]
        ShopItemGoronBomb10,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Arrow10)]
        [LocationName("Goron Shop 10 Arrows"), Region(Region.GoronVillage)]
        [GossipLocationHint("a northern merchant", "a bored goron")]
        [ShopRoom(ShopRoomAttribute.Room.GoronShop, 0x44)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.GoronShop, 1)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.GoronShopSpring, 1)]
        [GetItemIndex(0xC8)]
        ShopItemGoronArrow10,

        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [ProvidesItem(ProvidedItem.RedPotion)]
        [LocationName("Goron Shop Red Potion"), Region(Region.GoronVillage)]
        [GossipLocationHint("a northern merchant", "a bored goron")]
        [ShopRoom(ShopRoomAttribute.Room.GoronShop, 0x46)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.GoronShop, 2)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.GoronShopSpring, 2)]
        [GetItemIndex(0xC9)]
        ShopItemGoronRedPotion,

        [Repeatable, CycleRepeatable]
        [ProvidesItem(ProvidedItem.HeroShield)]
        [LocationName("Zora Shop Hero's Shield"), Region(Region.ZoraHall)]
        [GossipLocationHint("a western merchant", "an aquatic shop")]
        [ShopRoom(ShopRoomAttribute.Room.ZoraShop, 0x4A)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.ZoraShop, 0)]
        [GetItemIndex(0xCA)]
        ShopItemZoraShield,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Arrow10)]
        [LocationName("Zora Shop 10 Arrows"), Region(Region.ZoraHall)]
        [GossipLocationHint("a western merchant", "an aquatic shop")]
        [ShopRoom(ShopRoomAttribute.Room.ZoraShop, 0x44)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.ZoraShop, 1)]
        [GetItemIndex(0xCB)]
        ShopItemZoraArrow10,

        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [ProvidesItem(ProvidedItem.RedPotion)]
        [LocationName("Zora Shop Red Potion"), Region(Region.ZoraHall)]
        [GossipLocationHint("a western merchant", "an aquatic shop")]
        [ShopRoom(ShopRoomAttribute.Room.ZoraShop, 0x46)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.ZoraShop, 2)]
        [GetItemIndex(0xCC)]
        ShopItemZoraRedPotion,

        //bottle catch
        [LocationName("Bottle: Fairy"), Region(Region.BottleCatch)]
        [GossipLocationHint("a wandering healer")]
        [GetBottleItemIndices(0x00, 0x0D)]
        BottleCatchFairy,

        [LocationName("Bottle: Deku Princess"), Region(Region.BottleCatch)]
        [GossipLocationHint("a captured royal", "an imprisoned daughter")]
        [GetBottleItemIndices(0x08)]
        BottleCatchPrincess,

        [LocationName("Bottle: Fish"), Region(Region.BottleCatch)]
        [GossipLocationHint("a swimming creature", "a water dweller")]
        [GetBottleItemIndices(0x01)]
        BottleCatchFish,

        [LocationName("Bottle: Bug"), Region(Region.BottleCatch)]
        [GossipLocationHint("an insect", "a scuttling creature")]
        [GetBottleItemIndices(0x02, 0x03)]
        BottleCatchBug,

        [LocationName("Bottle: Poe"), Region(Region.BottleCatch)]
        [GossipLocationHint("a wandering ghost")]
        [GetBottleItemIndices(0x0B)]
        BottleCatchPoe,

        [LocationName("Bottle: Big Poe"), Region(Region.BottleCatch)]
        [GossipLocationHint("a huge ghost")]
        [GetBottleItemIndices(0x0C)]
        BottleCatchBigPoe,

        [LocationName("Bottle: Spring Water"), Region(Region.BottleCatch)]
        [GossipLocationHint("a common liquid")]
        [GetBottleItemIndices(0x04)]
        BottleCatchSpringWater,

        [LocationName("Bottle: Hot Spring Water"), Region(Region.BottleCatch)]
        [GossipLocationHint("a hot liquid", "a boiling liquid")]
        [GetBottleItemIndices(0x05, 0x06)]
        BottleCatchHotSpringWater,

        [LocationName("Bottle: Zora Egg"), Region(Region.BottleCatch)]
        [GossipLocationHint("a lost child")]
        [GetBottleItemIndices(0x07)]
        BottleCatchEgg,

        [LocationName("Bottle: Mushroom"), Region(Region.BottleCatch)]
        [GossipLocationHint("a strange fungus")]
        [GetBottleItemIndices(0x0A)]
        BottleCatchMushroom,

        //other chests and grottos
        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Lens Cave Invisible Chest"), Region(Region.GoronVillage)]
        [GossipLocationHint("a lonely peak")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02EB8000 + 0xAA, ChestAttribute.AppearanceType.Invisible)]
        [GetItemIndex(0xDD)]
        ChestLensCaveRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Lens Cave Rock Chest"), Region(Region.GoronVillage)]
        [GossipLocationHint("a lonely peak")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02EB8000 + 0xDA, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xF4)]
        ChestLensCavePurpleRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Bean Grotto"), Region(Region.DekuPalace)]
        [GossipLocationHint("a merchant's cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02ECC000 + 0xFA, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xDE)]
        ChestBeanGrottoRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Hot Spring Water Grotto"), Region(Region.TwinIslands)]
        [GossipLocationHint("a steaming cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02ED7000 + 0xC6, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xDF)]
        ChestHotSpringGrottoRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Day 1 Grave Bats"), Region(Region.IkanaGraveyard)]
        [GossipLocationHint("a cloud of bats")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x01F97000 + 0xCE, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0xF5)]
        ChestBadBatsGrottoPurpleRupee,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu5)]
        [LocationName("Secret Shrine Grotto"), Region(Region.IkanaCanyon)]
        [GossipLocationHint("a waterfall cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x02080000 + 0x93, 0x02080000 + 0x1E3, 0x02080000 + 0x2EB)]
        [GetItemIndex(0xD1)]
        ChestIkanaSecretShrineGrotto,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pirates' Fortress Interior Lower Chest"), Region(Region.PiratesFortressInterior)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x020A2000 + 0x256, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE0)]
        ChestPiratesFortressRedRupee1,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pirates' Fortress Interior Upper Chest"), Region(Region.PiratesFortressInterior)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x020A2000 + 0x266, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE1)]
        ChestPiratesFortressRedRupee2,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pirates' Fortress Interior Tank Chest"), Region(Region.PiratesFortressInterior)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x023B7000 + 0x66, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE2)]
        ChestInsidePiratesFortressTankRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Pirates' Fortress Interior Guard Room Chest"), Region(Region.PiratesFortressInterior)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x023BB000 + 0x56, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xFB)]
        ChestInsidePiratesFortressGuardSilverRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pirates' Fortress Cage Room Shallow Chest"), Region(Region.PiratesFortressSewer)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x023E6000 + 0x24E, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE3)]
        ChestInsidePiratesFortressHeartPieceRoomRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.BlueRupee)]
        [LocationName("Pirates' Fortress Cage Room Deep Chest"), Region(Region.PiratesFortressSewer)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x023E6000 + 0x25E, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x105)]
        ChestInsidePiratesFortressHeartPieceRoomBlueRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pirates' Fortress Maze Chest"), Region(Region.PiratesFortressSewer)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x023F0000 + 0xDE, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE4)]
        ChestInsidePiratesFortressMazeRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pinnacle Rock Lower Chest"), Region(Region.PinnacleRock)]
        [GossipLocationHint("a marine trench")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02428000 + 0x24E, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE5)]
        ChestPinacleRockRedRupee1,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pinnacle Rock Upper Chest"), Region(Region.PinnacleRock)]
        [GossipLocationHint("a marine trench")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02428000 + 0x25E, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE6)]
        ChestPinacleRockRedRupee2,

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Bombers' Hideout Chest"), Region(Region.EastClockTown)]
        [GossipLocationHint("a secret hideout")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x024F1000 + 0x1DE, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xFC)]
        ChestBomberHideoutSilverRupee,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu)]
        [LocationName("Termina Field Pillar Grotto"), Region(Region.TerminaField)]
        [GossipLocationHint("a hollow pillar")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x025C5000 + 0x583)]
        [GetItemIndex(0xD7)]
        ChestTerminaGrottoBombchu,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Termina Field Grass Grotto"), Region(Region.TerminaField)]
        [GossipLocationHint("a grassy cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x025C5000 + 0x593)]
        [GetItemIndex(0xDC)]
        ChestTerminaGrottoRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Termina Field Underwater Chest"), Region(Region.TerminaField)]
        [GossipLocationHint("a sunken chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x025C5000 + 0xD52, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE7)]
        ChestTerminaUnderwaterRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Termina Field Grass Chest"), Region(Region.TerminaField)]
        [GossipLocationHint("a grassy chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x025C5000 + 0xD62, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE8)]
        ChestTerminaGrassRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Termina Field Stump Chest"), Region(Region.TerminaField)]
        [GossipLocationHint("a tree's chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x025C5000 + 0xD72, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xE9)]
        ChestTerminaStumpRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Great Bay Coast Grotto"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a beach cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x026DE000 + 0x43F, 0x026DE000 + 0xFE3)]
        [GetItemIndex(0xD4)]
        ChestGreatBayCoastGrotto, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Zora Cape Ledge Without Tree Chest"), Region(Region.ZoraCape)]
        [GossipLocationHint("a high place")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02715000 + 0x42A, ChestAttribute.AppearanceType.Normal, 0x02715000 + 0xB16)]
        [GetItemIndex(0xEA)]
        ChestGreatBayCapeLedge1, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Zora Cape Ledge With Tree Chest"), Region(Region.ZoraCape)]
        [GossipLocationHint("a high place")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02715000 + 0x43A, ChestAttribute.AppearanceType.Normal, 0x02715000 + 0xB26)]
        [GetItemIndex(0xEB)]
        ChestGreatBayCapeLedge2, //contents?

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu)]
        [LocationName("Zora Cape Grotto"), Region(Region.ZoraCape)]
        [GossipLocationHint("a beach cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x02715000 + 0x45B, 0x02715000 + 0xB47)]
        [GetItemIndex(0xD2)]
        ChestGreatBayCapeGrotto, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Zora Cape Underwater Chest"), Region(Region.ZoraCape)]
        [GossipLocationHint("a sunken chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02715000 + 0x48A, ChestAttribute.AppearanceType.Normal, 0x02715000 + 0xB56)]
        [GetItemIndex(0xF6)]
        ChestGreatBayCapeUnderwater, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pirates' Fortress Exterior Log Chest"), Region(Region.PiratesFortressExterior)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02740000 + 0x196, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xEC)]
        ChestPiratesFortressEntranceRedRupee1,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pirates' Fortress Exterior Sand Chest"), Region(Region.PiratesFortressExterior)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02740000 + 0x1A6, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xED)]
        ChestPiratesFortressEntranceRedRupee2,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pirates' Fortress Exterior Corner Chest"), Region(Region.PiratesFortressExterior)]
        [GossipLocationHint("the home of pirates")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02740000 + 0x1B6, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xEE)]
        ChestPiratesFortressEntranceRedRupee3,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Path to Swamp Grotto"), Region(Region.RoadToSouthernSwamp)]
        [GossipLocationHint("a southern cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x027C1000 + 0x33B)]
        [GetItemIndex(0xDB)]
        ChestToSwampGrotto, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Doggy Racetrack Roof Chest"), Region(Region.RomaniRanch)]
        [GossipLocationHint("a day at the races")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x027D4000 + 0xB6, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xF7)]
        ChestDogRacePurpleRupee,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu5)]
        [LocationName("Ikana Graveyard Grotto"), Region(Region.IkanaGraveyard)]
        [GossipLocationHint("a circled cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x0280D000 + 0x353, 0x0280D000 + 0x54B)]
        [GetItemIndex(0xD5)]
        ChestGraveyardGrotto, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Near Swamp Spider House Grotto"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a southern cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x01F3A000 + 0x227, 0x02855000 + 0x2AF)]
        [GetItemIndex(0xDA)]
        ChestSwampGrotto,  //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.BlueRupee)]
        [LocationName("Behind Woodfall Owl Chest"), Region(Region.Woodfall)]
        [GossipLocationHint("a swamp chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02884000 + 0x232, ChestAttribute.AppearanceType.Normal, 0x02884000 + 0xA62)]
        [GetItemIndex(0x106)]
        ChestWoodfallBlueRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Entrance to Woodfall Chest"), Region(Region.Woodfall)]
        [GossipLocationHint("a swamp chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02884000 + 0x242, ChestAttribute.AppearanceType.Normal, 0x02884000 + 0xA32)]
        [GetItemIndex(0xEF)]
        ChestWoodfallRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Well Right Path Chest"), Region(Region.BeneathTheWell)]
        [GossipLocationHint("a frightful exchange")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x029EA000 + 0xE6, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0xF8)]
        ChestWellRightPurpleRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Well Left Path Chest"), Region(Region.BeneathTheWell)]
        [GossipLocationHint("a frightful exchange")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x029F0000 + 0x106, ChestAttribute.AppearanceType.Invisible)]
        [GetItemIndex(0xF9)]
        ChestWellLeftPurpleRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Mountain Waterfall Chest"), Region(Region.MountainVillage)]
        [GossipLocationHint("the springtime")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02BDD000 + 0x2E2, ChestAttribute.AppearanceType.Invisible, 0x02BDD000 + 0x946)]
        [GetItemIndex(0xF0)]
        ChestMountainVillage, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Mountain Spring Grotto"), Region(Region.MountainVillage)]
        [GossipLocationHint("the springtime")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x02BFC000 + 0x1F3, 0x02BFC000 + 0x2B3)]
        [GetItemIndex(0xD8)]
        ChestMountainVillageGrottoRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Path to Ikana Pillar Chest"), Region(Region.RoadToIkana)]
        [GossipLocationHint("a high chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02B34000 + 0x442, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xF1)]
        ChestToIkanaRedRupee,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu)]
        [LocationName("Path to Ikana Grotto"), Region(Region.RoadToIkana)]
        [GossipLocationHint("a blocked cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x02B34000 + 0x523)]
        [GetItemIndex(0xD3)]
        ChestToIkanaGrotto, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Inverted Stone Tower Right Chest"), Region(Region.StoneTower)]
        [GossipLocationHint("a sky below")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02BC9000 + 0x236, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xFD)]
        ChestInvertedStoneTowerSilverRupee,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu10)]
        [LocationName("Inverted Stone Tower Middle Chest"), Region(Region.StoneTower)]
        [GossipLocationHint("a sky below")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02BC9000 + 0x246, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x10A)]
        ChestInvertedStoneTowerBombchu10,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.MagicBean)]
        [LocationName("Inverted Stone Tower Left Chest"), Region(Region.StoneTower)]
        [GossipLocationHint("a sky below")]
        [ChestType(ChestTypeAttribute.ChestType.LargeGold), Chest(0x02BC9000 + 0x256, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x109)]
        ChestInvertedStoneTowerBean,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Path to Snowhead Grotto"), Region(Region.PathToSnowhead)]
        [GossipLocationHint("a snowy cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x02C04000 + 0xAF, 0x02C04000 + 0x487)]
        [GetItemIndex(0xD0)]
        ChestToSnowheadGrotto, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Twin Islands Cave Chest"), Region(Region.TwinIslands)]
        [GossipLocationHint("the springtime")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02C34000 + 0x13A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xF2)]
        ChestToGoronVillageRedRupee,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Secret Shrine Final Chest"), Region(Region.SecretShrine)]
        [GossipLocationHint("a secret place")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02C57000 + 0xB6, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x107)]
        ChestSecretShrineHeartPiece,

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Secret Shrine Dinolfos Chest"), Region(Region.SecretShrine)]
        [GossipLocationHint("a secret place")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02C61000 + 0x9A, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0xFE)]
        ChestSecretShrineDinoGrotto,

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Secret Shrine Wizzrobe Chest"), Region(Region.SecretShrine)]
        [GossipLocationHint("a secret place")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02C69000 + 0xB2, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0xFF)]
        ChestSecretShrineWizzGrotto,

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Secret Shrine Wart Chest"), Region(Region.SecretShrine)]
        [GossipLocationHint("a secret place")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02C71000 + 0xA6, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x100)]
        ChestSecretShrineWartGrotto,

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Secret Shrine Garo Master Chest"), Region(Region.SecretShrine)]
        [GossipLocationHint("a secret place")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02C75000 + 0x76, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x101)]
        ChestSecretShrineGaroGrotto,

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Inn Staff Room Chest"), Region(Region.StockPotInn)]
        [GossipLocationHint("an employee room")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02CAB000 + 0x10E, ChestAttribute.AppearanceType.Normal, 0x02CAB000 + 0x242)]
        [GetItemIndex(0x102)]
        ChestInnStaffRoom, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("Inn Guest Room Chest"), Region(Region.StockPotInn)]
        [GossipLocationHint("a guest bedroom")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02CB1000 + 0xDA, ChestAttribute.AppearanceType.Normal, 0x02CB1000 + 0x212)]
        [GetItemIndex(0x103)]
        ChestInnGuestRoom, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Mystery Woods Grotto"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a mystery cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x02CFC000 + 0x5B)]
        [GetItemIndex(0xD9)]
        ChestWoodsGrotto, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.SilverRupee)]
        [LocationName("East Clock Town Chest"), Region(Region.EastClockTown)]
        [GossipLocationHint("a shop roof")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02DE4000 + 0x442, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x104)]
        ChestEastClockTownSilverRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("South Clock Town Straw Roof Chest"), Region(Region.SouthClockTown)]
        [GossipLocationHint("a straw roof")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02E5C000 + 0x342, ChestAttribute.AppearanceType.Normal, 0x02E5C000 + 0x806)]
        [GetItemIndex(0xF3)]
        ChestSouthClockTownRedRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("South Clock Town Final Day Chest"), Region(Region.SouthClockTown)]
        [GossipLocationHint("a carnival tower")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02E5C000 + 0x352, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0xFA)]
        ChestSouthClockTownPurpleRupee,

        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Bank Reward #3"), Region(Region.WestClockTown)]
        [GossipLocationHint("being rich"), GossipCompetitiveHint(-2)]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x108)]
        HeartPieceBank,

        //standing HPs
        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Clock Tower Entrance"), Region(Region.SouthClockTown)]
        [GossipLocationHint("the tower doors")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x10B)]
        HeartPieceSouthClockTown,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("North Clock Town Tree"), Region(Region.NorthClockTown)]
        [GossipLocationHint("a town playground")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x10C)]
        HeartPieceNorthClockTown,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Path to Swamp Tree"), Region(Region.RoadToSouthernSwamp)]
        [GossipLocationHint("a tree of bats")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x10D)]
        HeartPieceToSwamp,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Swamp Tourist Center Roof"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a tourist centre")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x10E)]
        HeartPieceSwampScrub,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Deku Palace West Garden"), Region(Region.DekuPalace)]
        [GossipLocationHint("the home of scrubs")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x10F)]
        HeartPieceDekuPalace,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Goron Village Ledge"), Region(Region.GoronVillage)]
        [GossipLocationHint("a cold ledge")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x110)]
        HeartPieceGoronVillageScrub,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Bio Baba Grotto"), Region(Region.TerminaField)]
        [GossipLocationHint("a beehive")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x111)]
        HeartPieceZoraGrotto,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Lab Fish"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("feeding the fish"), GossipCompetitiveHint(0, nameof(GameplaySettings.SpeedupLabFish), false)]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x112)]
        HeartPieceLabFish,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Zora Cape Like-Like"), Region(Region.ZoraCape)]
        [GossipLocationHint("a shield eater")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x113)]
        HeartPieceGreatBayCapeLikeLike,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Pirates' Fortress Cage"), Region(Region.PiratesFortressSewer)]
        [GossipLocationHint("a timed door")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x114)]
        HeartPiecePiratesFortress,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Lulu's Room Ledge"), Region(Region.ZoraHall)]
        [GossipLocationHint("the singer's room")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x115)]
        HeartPieceZoraHallScrub,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Path to Snowhead Pillar"), Region(Region.PathToSnowhead)]
        [GossipLocationHint("a cold platform")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x116)]
        HeartPieceToSnowhead,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Great Bay Coast Ledge"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a rock face")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x117)]
        HeartPieceGreatBayCoast,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Ikana Canyon Ledge"), Region(Region.IkanaCanyon)]
        [GossipLocationHint("a thief's doorstep")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x118)]
        HeartPieceIkana,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Ikana Castle Pillar"), Region(Region.IkanaCastle)]
        [GossipLocationHint("a fiery pillar")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [GetItemIndex(0x119)]
        HeartPieceCastle,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartContainer)]
        [LocationName("Odolwa Heart Container"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a masked evil")]
        [GetItemIndex(0x11A)]
        HeartContainerWoodfall,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartContainer)]
        [LocationName("Goht Heart Container"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a masked evil")]
        [GetItemIndex(0x11B)]
        HeartContainerSnowhead,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartContainer)]
        [LocationName("Gyorg Heart Container"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a masked evil")]
        [GetItemIndex(0x11C)]
        HeartContainerGreatBay,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartContainer)]
        [LocationName("Twinmold Heart Container"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a masked evil")]
        [GetItemIndex(0x11D)]
        HeartContainerStoneTower,

        //maps
        [Purchaseable]
        [ProvidesItem(ProvidedItem.TingleMapTown)]
        [LocationName("Clock Town Map Purchase"), Region(Region.NorthClockTown)]
        [GossipLocationHint("a map maker", "a forest fairy")]
        [GetItemIndex(0xB4)]
        ItemTingleMapTown,

        [Purchaseable]
        [ProvidesItem(ProvidedItem.TingleMapWoodfall)]
        [LocationName("Woodfall Map Purchase"), Region(Region.RoadToSouthernSwamp)]
        [GossipLocationHint("a map maker", "a forest fairy")]
        [GetItemIndex(0xB5)]
        ItemTingleMapWoodfall,

        [Purchaseable]
        [ProvidesItem(ProvidedItem.TingleMapSnowhead)]
        [LocationName("Snowhead Map Purchase"), Region(Region.RoadToSouthernSwamp)]
        [GossipLocationHint("a map maker", "a forest fairy")]
        [GetItemIndex(0xB6)]
        ItemTingleMapSnowhead,

        [Purchaseable]
        [ProvidesItem(ProvidedItem.TingleMapRanch)]
        [LocationName("Romani Ranch Map Purchase"), Region(Region.MilkRoad)]
        [GossipLocationHint("a map maker", "a forest fairy")]
        [GetItemIndex(0xB7)]
        ItemTingleMapRanch,

        [Purchaseable]
        [ProvidesItem(ProvidedItem.TingleMapGreatBay)]
        [LocationName("Great Bay Map Purchase"), Region(Region.MilkRoad)]
        [GossipLocationHint("a map maker", "a forest fairy")]
        [GetItemIndex(0xB8)]
        ItemTingleMapGreatBay,

        [Purchaseable]
        [ProvidesItem(ProvidedItem.TingleMapStoneTower)]
        [LocationName("Stone Tower Map Purchase"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a map maker", "a forest fairy")]
        [GetItemIndex(0xB9)]
        ItemTingleMapStoneTower,

        //oops I forgot one
        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu)]
        [LocationName("Goron Racetrack Grotto"), Region(Region.TwinIslands)]
        [GossipLocationHint("a hidden cave")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), GrottoChest(0x02C23000 + 0x2D7, 0x02C34000 + 0x1DB)]
        [GetItemIndex(0xD6)]
        ChestToGoronRaceGrotto, //contents?

        [Repeatable]
        [ProvidesItem(ProvidedItem.GoldRupee)]
        [LocationName("Canyon Scrub Trade"), Region(Region.IkanaCanyon)]
        [GossipLocationHint("an eastern merchant")]
        [GetItemIndex(0x125)]
        IkanaScrubGoldRupee,

        //moon items
        OtherOneMask,
        OtherTwoMasks,
        OtherThreeMasks,
        OtherFourMasks,
        AreaMoonAccess,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Deku Trial Bonus"), Region(Region.TheMoon)]
        [GossipLocationHint("a masked child's game")]
        [GetItemIndex(0x11F)]
        HeartPieceDekuTrial,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Goron Trial Bonus"), Region(Region.TheMoon)]
        [GossipLocationHint("a masked child's game")]
        [GetItemIndex(0x120)]
        HeartPieceGoronTrial,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Zora Trial Bonus"), Region(Region.TheMoon)]
        [GossipLocationHint("a masked child's game")]
        [GetItemIndex(0x121)]
        HeartPieceZoraTrial,

        [Visible]
        [ProvidesItem(ProvidedItem.HeartPiece)]
        [LocationName("Link Trial Bonus"), Region(Region.TheMoon)]
        [GossipLocationHint("a masked child's game")]
        [GetItemIndex(0x122)]
        HeartPieceLinkTrial,

        [ProvidesItem(ProvidedItem.FierceDeityMask)]
        [LocationName("Majora Child"), Region(Region.TheMoon)]
        [GossipLocationHint("the lonely child")]
        [GetItemIndex(0x7B)]
        MaskFierceDeity,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Arrow30)]
        [LocationName("Link Trial Garo Master Chest"), Region(Region.TheMoon)]
        [GossipLocationHint("a masked child's game")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02D4B000 + 0x76, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x126)]
        ChestLinkTrialArrow30,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.Bombchu10)]
        [LocationName("Link Trial Iron Knuckle Chest"), Region(Region.TheMoon)]
        [GossipLocationHint("a masked child's game")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x02D4E000 + 0xC6, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x127)]
        ChestLinkTrialBombchu10,

        [Repeatable, Temporary, CycleRepeatable]
        [ProvidesItem(ProvidedItem.DekuNut10)]
        [LocationName("Pre-Clocktown Chest"), Region(Region.BeneathClocktown)]
        [GossipLocationHint("the first chest")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x021D2000 + 0x102, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x128)]
        ChestPreClocktownDekuNut,

        [ProvidesItem(ProvidedItem.KokiriSword)]
        [LocationName("Starting Sword"), Region(Region.Misc)]
        [GossipLocationHint("a new file", "a quest's inception")]
        [GetItemIndex(0x37)]
        StartingSword,

        [Repeatable, CycleRepeatable]
        [ProvidesItem(ProvidedItem.HeroShield)]
        [LocationName("Starting Shield"), Region(Region.Misc)]
        [GossipLocationHint("a new file", "a quest's inception")]
        [GetItemIndex(0x129)]
        StartingShield,

        [ProvidesItem(ProvidedItem.HeartContainer)]
        [LocationName("Starting Heart Container #1"), Region(Region.Misc)]
        [GossipLocationHint("a new file", "a quest's inception")]
        [GetItemIndex(0x12A)]
        StartingHeartContainer1,

        [ProvidesItem(ProvidedItem.HeartContainer)]
        [LocationName("Starting Heart Container #2"), Region(Region.Misc)]
        [GossipLocationHint("a new file", "a quest's inception")]
        [GetItemIndex(0x12B)]
        StartingHeartContainer2,

        [ProvidesItem(ProvidedItem.Milk)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Ranch Cow #1"), Region(Region.RomaniRanch)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x132)]
        ItemRanchBarnMainCowMilk,

        [ProvidesItem(ProvidedItem.Milk)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Ranch Cow #2"), Region(Region.RomaniRanch)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x182)]
        ItemRanchBarnOtherCowMilk1,

        [ProvidesItem(ProvidedItem.Milk)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Ranch Cow #3"), Region(Region.RomaniRanch)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1A2)]
        ItemRanchBarnOtherCowMilk2,

        [ProvidesItem(ProvidedItem.Milk)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Cow Beneath the Well"), Region(Region.BeneathTheWell)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x135)]
        ItemWellCowMilk,

        [ProvidesItem(ProvidedItem.Milk)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Termina Grotto Cow #1"), Region(Region.TerminaField)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x136)]
        ItemTerminaGrottoCowMilk1,

        [ProvidesItem(ProvidedItem.Milk)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Termina Grotto Cow #2"), Region(Region.TerminaField)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x137)]
        ItemTerminaGrottoCowMilk2,

        [ProvidesItem(ProvidedItem.Milk)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Great Bay Coast Grotto Cow #1"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x138)]
        ItemCoastGrottoCowMilk1,

        [ProvidesItem(ProvidedItem.Milk)]
        [Repeatable, Temporary, CycleRepeatable, Overwritable]
        [LocationName("Great Bay Coast Grotto Cow #2"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x139)]
        ItemCoastGrottoCowMilk2,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Main Room Near Ceiling"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x13A)]
        CollectibleSwampSpiderToken1,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Gold Room Near Ceiling"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x13B)]
        CollectibleSwampSpiderToken2,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Monument Room Torch"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x13C)]
        CollectibleSwampSpiderToken3,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Gold Room Pillar"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x13E)]
        CollectibleSwampSpiderToken4,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Pot Room Jar"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x13F)]
        CollectibleSwampSpiderToken5,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Tree Room Grass 1"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x140)]
        CollectibleSwampSpiderToken6,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Tree Room Grass 2"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x141)]
        CollectibleSwampSpiderToken7,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Main Room Water"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x142)]
        CollectibleSwampSpiderToken8,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Main Room Lower Left Soft Soil"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x143)]
        CollectibleSwampSpiderToken9,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Monument Room Crate 1"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x144)]
        CollectibleSwampSpiderToken10,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Main Room Upper Soft Soil"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x145)]
        CollectibleSwampSpiderToken11,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Main Room Lower Right Soft Soil"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x146)]
        CollectibleSwampSpiderToken12,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Monument Room Lower Wall"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x147)]
        CollectibleSwampSpiderToken13,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Monument Room On Monument"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x148)]
        CollectibleSwampSpiderToken14,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Main Room Pillar"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x149)]
        CollectibleSwampSpiderToken15,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Pot Room Pot 1"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x14A)]
        CollectibleSwampSpiderToken16,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Pot Room Pot 2"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x14B)]
        CollectibleSwampSpiderToken17,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Gold Room Hive"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x14C)]
        CollectibleSwampSpiderToken18,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Main Room Upper Pillar"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x14D)]
        CollectibleSwampSpiderToken19,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Pot Room Behind Vines"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x14E)]
        CollectibleSwampSpiderToken20,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Tree Room Tree 1"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x14F)]
        CollectibleSwampSpiderToken21,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Pot Room Wall"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x150)]
        CollectibleSwampSpiderToken22,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Pot Room Hive 1"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x151)]
        CollectibleSwampSpiderToken23,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Tree Room Tree 2"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x152)]
        CollectibleSwampSpiderToken24,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Gold Room Wall"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x153)]
        CollectibleSwampSpiderToken25,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Tree Room Hive"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x154)]
        CollectibleSwampSpiderToken26,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Monument Room Crate 2"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x155)]
        CollectibleSwampSpiderToken27,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Pot Room Hive 2"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x156)]
        CollectibleSwampSpiderToken28,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Tree Room Tree 3"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x157)]
        CollectibleSwampSpiderToken29,

        [Visible]
        [ProvidesItem(ProvidedItem.SwampSpiderToken)]
        [LocationName("Swamp Skulltula Main Room Jar"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x158)]
        CollectibleSwampSpiderToken30,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Storage Room Behind Boat"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x159)]
        CollectibleOceanSpiderToken1,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Library Hole Behind Picture"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x15A)]
        CollectibleOceanSpiderToken2,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Library Hole Behind Cabinet"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x15B)]
        CollectibleOceanSpiderToken3,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Library On Corner Bookshelf"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x15C)]
        CollectibleOceanSpiderToken4,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Ceiling Edge"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x15D)]
        CollectibleOceanSpiderToken5,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Ceiling Plank"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x15E)]
        CollectibleOceanSpiderToken6,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Colored Skulls Ceiling Edge"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x15F)]
        CollectibleOceanSpiderToken7,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Library Ceiling Edge"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x160)]
        CollectibleOceanSpiderToken8,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Storage Room Ceiling Web"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x161)]
        CollectibleOceanSpiderToken9,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Storage Room Behind Crate"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x162)]
        CollectibleOceanSpiderToken10,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Jar"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x163)]
        CollectibleOceanSpiderToken11,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Entrance Right Wall"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x164)]
        CollectibleOceanSpiderToken12,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Entrance Left Wall"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x165)]
        CollectibleOceanSpiderToken13,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Webbed Hole"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x166)]
        CollectibleOceanSpiderToken14,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Entrance Web"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x167)]
        CollectibleOceanSpiderToken15,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Colored Skulls Chandelier 1"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x168)]
        CollectibleOceanSpiderToken16,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Colored Skulls Chandelier 2"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x169)]
        CollectibleOceanSpiderToken17,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Colored Skulls Chandelier 3"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x16A)]
        CollectibleOceanSpiderToken18,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Colored Skulls Behind Picture"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x16B)]
        CollectibleOceanSpiderToken19,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Library Behind Picture"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x16C)]
        CollectibleOceanSpiderToken20,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Library Behind Bookcase 1"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x16D)]
        CollectibleOceanSpiderToken21,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Storage Room Crate"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x16E)]
        CollectibleOceanSpiderToken22,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Webbed Pot"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x16F)]
        CollectibleOceanSpiderToken23,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Upper Pot"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x170)]
        CollectibleOceanSpiderToken24,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Colored Skulls Pot"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x171)]
        CollectibleOceanSpiderToken25,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Storage Room Jar"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x172)]
        CollectibleOceanSpiderToken26,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Lower Pot"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x173)]
        CollectibleOceanSpiderToken27,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula Library Behind Bookcase 2"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x174)]
        CollectibleOceanSpiderToken28,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Behind Skull 1"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x175)]
        CollectibleOceanSpiderToken29,

        [Visible]
        [ProvidesItem(ProvidedItem.OceanSpiderToken)]
        [LocationName("Ocean Skulltula 2nd Room Behind Skull 2"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a golden spider")]
        [GetItemIndex(0x176)]
        CollectibleOceanSpiderToken30,

        [Visible]
        [ProvidesItem(ProvidedItem.ClockTownStrayFairy)]
        [LocationName("Clock Town Stray Fairy"), Region(Region.LaundryPool)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x3B)]
        //[GetItemIndex(0x1A1)] // used as a flag to track if the actual fairy has been collected.
        CollectibleStrayFairyClockTown,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Pre-Boss Lower Right Bubble"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x177)]
        CollectibleStrayFairyWoodfall1,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Entrance Fairy"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x178)]
        CollectibleStrayFairyWoodfall2,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Pre-Boss Upper Left Bubble"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x179)]
        CollectibleStrayFairyWoodfall3,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Pre-Boss Pillar Bubble"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x17A)]
        CollectibleStrayFairyWoodfall4,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Deku Baba"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x17B)]
        CollectibleStrayFairyWoodfall5,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Poison Water Bubble"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x17C)]
        CollectibleStrayFairyWoodfall6,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Main Room Bubble"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x17D)]
        CollectibleStrayFairyWoodfall7,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Skulltula"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x17E)]
        CollectibleStrayFairyWoodfall8,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Pre-Boss Upper Right Bubble"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x17F)]
        CollectibleStrayFairyWoodfall9,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Main Room Switch"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x021FB000 + 0x28A, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x184)]
        CollectibleStrayFairyWoodfall10,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Entrance Platform"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02204000 + 0x23A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x185)]
        CollectibleStrayFairyWoodfall11,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Dark Room"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0222E000 + 0x1AA, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x186)]
        CollectibleStrayFairyWoodfall12,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Jar Fairy"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x189)]
        CollectibleStrayFairyWoodfall13,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Bridge Room Hive"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x18A)]
        CollectibleStrayFairyWoodfall14,

        [Visible]
        [ProvidesItem(ProvidedItem.WoodfallStrayFairy)]
        [LocationName("Woodfall Platform Room Hive"), Region(Region.WoodfallTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x18B)]
        CollectibleStrayFairyWoodfall15,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Snow Room Bubble"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x18C)]
        CollectibleStrayFairySnowhead1,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Ceiling Bubble"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x18D)]
        CollectibleStrayFairySnowhead2,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Dinolfos 1"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x18E)]
        CollectibleStrayFairySnowhead3,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Bridge Room Ledge Bubble"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x190)]
        CollectibleStrayFairySnowhead4,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Bridge Room Pillar Bubble"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x191)]
        CollectibleStrayFairySnowhead5,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Dinolfos 2"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x192)]
        CollectibleStrayFairySnowhead6,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Map Room Fairy"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x193)]
        CollectibleStrayFairySnowhead7,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Map Room Ledge"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02346000 + 0x12A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x194)]
        CollectibleStrayFairySnowhead8,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Basement"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0230C000 + 0x56A, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x195)]
        CollectibleStrayFairySnowhead9,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Twin Block"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02306000 + 0x11A, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x196)]
        CollectibleStrayFairySnowhead10,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Icicle Room Wall"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0233A000 + 0x22A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x197)]
        CollectibleStrayFairySnowhead11,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Main Room Wall"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0230C000 + 0x58A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x198)]
        CollectibleStrayFairySnowhead12,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Pillar Freezards"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0232E000 + 0x20A, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x199)]
        CollectibleStrayFairySnowhead13,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Ice Puzzle"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x022F2000 + 0x1AA, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x19A)]
        CollectibleStrayFairySnowhead14,

        [Visible]
        [ProvidesItem(ProvidedItem.SnowheadStrayFairy)]
        [LocationName("Snowhead Crate"), Region(Region.SnowheadTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x19F)]
        CollectibleStrayFairySnowhead15,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Skulltula"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1A7)]
        CollectibleStrayFairyGreatBay1,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Pre-Boss Room Underwater Bubble"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1A4)]
        CollectibleStrayFairyGreatBay2,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Water Control Room Underwater Bubble"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1A5)]
        CollectibleStrayFairyGreatBay3,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Pre-Boss Room Bubble"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1A6)]
        CollectibleStrayFairyGreatBay4,

        // A8 empty

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Waterwheel Room Upper"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02940000 + 0x23A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x1A9)]
        CollectibleStrayFairyGreatBay5,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Green Valve"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02959000 + 0x18E, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x1AA)]
        CollectibleStrayFairyGreatBay6,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Seesaw Room"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02945000 + 0x24A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x1AB)]
        CollectibleStrayFairyGreatBay7,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Waterwheel Room Lower"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02940000 + 0x24A, ChestAttribute.AppearanceType.Normal)]
        [GetItemIndex(0x1AC)]
        CollectibleStrayFairyGreatBay8,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Entrance Torches"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02962000 + 0x1F2, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x1AD)]
        CollectibleStrayFairyGreatBay9,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Bio Babas"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02911000 + 0xDA, ChestAttribute.AppearanceType.AppearsClear)]
        [GetItemIndex(0x1AE)]
        CollectibleStrayFairyGreatBay10,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Underwater Barrel"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1AF)]
        CollectibleStrayFairyGreatBay11,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Whirlpool Jar"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1B0)]
        CollectibleStrayFairyGreatBay12,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Whirlpool Barrel"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1B1)]
        CollectibleStrayFairyGreatBay13,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Dexihands Jar"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1B2)]
        CollectibleStrayFairyGreatBay14,

        [Visible]
        [ProvidesItem(ProvidedItem.GreatBayStrayFairy)]
        [LocationName("Great Bay Ledge Jar"), Region(Region.GreatBayTemple)]
        [GossipLocationHint("a lost creature")]
        [GetItemIndex(0x1B3)]
        CollectibleStrayFairyGreatBay15,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Mirror Sun Block"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02119000 + 0x282, ChestAttribute.AppearanceType.Normal, 0x0218B000 + 0x8A)]
        [GetItemIndex(0x1B4)]
        CollectibleStrayFairyStoneTower1,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Eyegore"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x020F1000 + 0x1A2, ChestAttribute.AppearanceType.AppearsSwitch, 0x02164000 + 0x17E)]
        [GetItemIndex(0x1B5)]
        CollectibleStrayFairyStoneTower2,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Lava Room Fire Ring"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02122000 + 0x1F6, ChestAttribute.AppearanceType.Normal, 0x02191000 + 0x7A)]
        [GetItemIndex(0x1B6)]
        CollectibleStrayFairyStoneTower3,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Updraft Fire Ring"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02104000 + 0x252, ChestAttribute.AppearanceType.AppearsSwitch, 0x02177000 + 0x29E)]
        [GetItemIndex(0x1B7)]
        CollectibleStrayFairyStoneTower4,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Mirror Sun Switch"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02119000 + 0x272, ChestAttribute.AppearanceType.AppearsSwitch, 0x0218B000 + 0x7A)]
        [GetItemIndex(0x1B8)]
        CollectibleStrayFairyStoneTower5,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Boss Warp"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x020E2000 + 0x162, ChestAttribute.AppearanceType.AppearsSwitch, 0x02156000 + 0xFA)]
        [GetItemIndex(0x1B9)]
        CollectibleStrayFairyStoneTower6,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Wizzrobe"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0210F000 + 0x1F2, ChestAttribute.AppearanceType.AppearsSwitch, 0x02182000 + 0x1EE)]
        [GetItemIndex(0x1BA)]
        CollectibleStrayFairyStoneTower7,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Death Armos"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x020E2000 + 0x172, ChestAttribute.AppearanceType.AppearsSwitch, 0x02156000 + 0x10A)]
        [GetItemIndex(0x1BB)]
        CollectibleStrayFairyStoneTower8,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Updraft Frozen Eye"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02104000 + 0x262, ChestAttribute.AppearanceType.AppearsSwitch, 0x02177000 + 0x2AE)]
        [GetItemIndex(0x1BC)]
        CollectibleStrayFairyStoneTower9,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Thin Bridge"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0211D000 + 0x1E2, ChestAttribute.AppearanceType.AppearsSwitch, 0x0218C000 + 0x25E)]
        [GetItemIndex(0x1BD)]
        CollectibleStrayFairyStoneTower10,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Basement Ledge"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x0210F000 + 0x212, ChestAttribute.AppearanceType.Normal, 0x02182000 + 0x20E)]
        [GetItemIndex(0x1BE)]
        CollectibleStrayFairyStoneTower11,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Statue Eye"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x020E2000 + 0x182, ChestAttribute.AppearanceType.AppearsSwitch, 0x02156000 + 0x11A)]
        [GetItemIndex(0x1BF)]
        CollectibleStrayFairyStoneTower12,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Underwater"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02104000 + 0x272, ChestAttribute.AppearanceType.AppearsSwitch, 0x02177000 + 0x2BE)]
        [GetItemIndex(0x1C0)]
        CollectibleStrayFairyStoneTower13,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Bridge Crystal"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x020F1000 + 0x1B2, ChestAttribute.AppearanceType.AppearsSwitch, 0x02164000 + 0x18E)]
        [GetItemIndex(0x1C1)]
        CollectibleStrayFairyStoneTower14,

        [Visible]
        [ProvidesItem(ProvidedItem.StoneTowerStrayFairy)]
        [LocationName("Stone Tower Lava Room Ledge"), Region(Region.StoneTowerTemple)]
        [GossipLocationHint("a lost creature")]
        [ChestType(ChestTypeAttribute.ChestType.SmallGold), Chest(0x02122000 + 0x206, ChestAttribute.AppearanceType.Normal, 0x02191000 + 0x8A)]
        [GetItemIndex(0x1C2)]
        CollectibleStrayFairyStoneTower15,

        [Purchaseable, Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Lottery"), Region(Region.WestClockTown)]
        [GossipLocationHint("a town game")]
        [GetItemIndex(0x86)]
        MundaneItemLotteryPurpleRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.BlueRupee)]
        [LocationName("Bank Reward #2"), Region(Region.WestClockTown)]
        [GossipLocationHint("interest")]
        [GetItemIndex(0x13D)]
        MundaneItemBankBlueRupee,

        [CycleRepeatable, Overwritable, Purchaseable, Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.ChateauRomani)]
        [LocationName("Milk Bar Chateau"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town shop")]
        [GetItemIndex(0x180)]
        ShopItemMilkBarChateau,

        [CycleRepeatable, Overwritable, Purchaseable, Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.Milk)]
        [LocationName("Milk Bar Milk"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town shop")]
        [GetItemIndex(0x181)]
        ShopItemMilkBarMilk,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Deku Playground Any Day"), Region(Region.NorthClockTown)]
        [GossipLocationHint("a game for scrubs", "a playground", "a town game")]
        [GossipCombineOrder(0), GossipCombine(HeartPieceDekuPlayground, "Deku Playground")]
        [GetItemIndex(0x133)]
        MundaneItemDekuPlaygroundPurpleRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Honey and Darling Any Day"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town game")]
        [GossipCombineOrder(0), GossipCombine(HeartPieceHoneyAndDarling, "Honey and Darling")]
        [GetItemIndex(0x183)]
        MundaneItemHoneyAndDarlingPurpleRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Kotake Mushroom Sale"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a sleeping witch", "a southern merchant")]
        [GetItemIndex(0x187)]
        MundaneItemKotakeMushroomSaleRedRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.BlueRupee)]
        [LocationName("Pictograph Contest Standard Photo"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a swamp game")]
        [GetItemIndex(0x188)]
        MundaneItemPictographContestBlueRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Pictograph Contest Good Photo"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a swamp game")]
        [GetItemIndex(0x18F)]
        MundaneItemPictographContestRedRupee,

        [CycleRepeatable, Purchaseable, Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.MagicBean)]
        [LocationName("Swamp Scrub Purchase"), Region(Region.SouthernSwamp)]
        [GossipLocationHint("a southern merchant")]
        [GetItemIndex(0x19B)]
        ShopItemBusinessScrubMagicBean,

        [CycleRepeatable, Overwritable, Purchaseable, Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.GreenPotion)]
        [LocationName("Ocean Scrub Purchase"), Region(Region.ZoraHall)]
        [GossipLocationHint("a western merchant")]
        [GetItemIndex(0x19C)]
        ShopItemBusinessScrubGreenPotion,

        [CycleRepeatable, Overwritable, Purchaseable, Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.BluePotion)]
        [LocationName("Canyon Scrub Purchase"), Region(Region.IkanaCanyon)]
        [GossipLocationHint("an eastern merchant")]
        [GetItemIndex(0x19D)]
        ShopItemBusinessScrubBluePotion,

        [Repeatable]
        [ProvidesItem(ProvidedItem.BlueRupee)]
        [LocationName("Zora Hall Stage Lights"), Region(Region.ZoraHall)]
        [GossipLocationHint("a good deed")]
        [GetItemIndex(0x19E)]
        MundaneItemZoraStageLightsBlueRupee,

        [CycleRepeatable, Overwritable, Purchaseable, Repeatable, Temporary]
        [ProvidesItem(ProvidedItem.Milk)]
        [LocationName("Gorman Bros Milk Purchase"), Region(Region.MilkRoad)]
        [GossipLocationHint("a shady gentleman", "a dodgy seller", "a shady dealer")]
        [GetItemIndex(0x1A0)]
        ShopItemGormanBrosMilk,

        [Repeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Ocean Spider House Day 2 Reward"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a gold spider"), GossipCompetitiveHint(0, nameof(GameplaySettings.AddSkulltulaTokens), false)]
        [GossipCombineOrder(1), GossipCombine(UpgradeGiantWallet, "Ocean Spider House"), GossipCombine(MundaneItemOceanSpiderHouseDay3RedRupee, "Ocean Spider House")]
        [GetItemIndex(0x134)]
        MundaneItemOceanSpiderHouseDay2PurpleRupee,

        [Repeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Ocean Spider House Day 3 Reward"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a gold spider"), GossipCompetitiveHint(0, nameof(GameplaySettings.AddSkulltulaTokens), false)]
        [GossipCombineOrder(2), GossipCombine(MundaneItemOceanSpiderHouseDay2PurpleRupee, "Ocean Spider House"), GossipCombine(UpgradeGiantWallet, "Ocean Spider House")]
        [GetItemIndex(0x1A3)]
        MundaneItemOceanSpiderHouseDay3RedRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.BlueRupee)]
        [LocationName("Bad Pictograph of Lulu"), Region(Region.ZoraHall)]
        [GossipLocationHint("a fan")]
        [GetItemIndex(0x1A8)]
        MundaneItemLuluBadPictographBlueRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Good Pictograph of Lulu"), Region(Region.ZoraHall)]
        [GossipLocationHint("a fan")]
        [GetItemIndex(0x1C3)]
        MundaneItemLuluGoodPictographRedRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Treasure Chest Game Human"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town game")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x00F43F10 + 0xFA8, ChestAttribute.AppearanceType.AppearsSwitch, 0x00F43F10 + 0xFB0)]
        [GetItemIndex(0x1C4)]
        MundaneItemTreasureChestGamePurpleRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Treasure Chest Game Zora"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town game")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x00F43F10 + 0xFAC, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x1C5)]
        MundaneItemTreasureChestGameRedRupee,

        [CycleRepeatable, Repeatable, RupeeRepeatable, Temporary]
        [ProvidesItem(ProvidedItem.DekuNut10)]
        [LocationName("Treasure Chest Game Deku"), Region(Region.EastClockTown)]
        [GossipLocationHint("a town game")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden), Chest(0x00F43F10 + 0xFAE, ChestAttribute.AppearanceType.AppearsSwitch)]
        [GetItemIndex(0x1C6)]
        MundaneItemTreasureChestGameDekuNuts,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.BlueRupee)]
        [LocationName("Curiosity Shop Blue Rupee"), Region(Region.WestClockTown)]
        [GossipLocationHint("a shady gentleman", "a dodgy seller", "a shady dealer")]
        [GetItemIndex(0x1C7)]
        MundaneItemCuriosityShopBlueRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.RedRupee)]
        [LocationName("Curiosity Shop Red Rupee"), Region(Region.WestClockTown)]
        [GossipLocationHint("a shady gentleman", "a dodgy seller", "a shady dealer")]
        [GetItemIndex(0x1C8)]
        MundaneItemCuriosityShopRedRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.PurpleRupee)]
        [LocationName("Curiosity Shop Purple Rupee"), Region(Region.WestClockTown)]
        [GossipLocationHint("a shady gentleman", "a dodgy seller", "a shady dealer")]
        [GetItemIndex(0x1C9)]
        MundaneItemCuriosityShopPurpleRupee,

        [Repeatable, RupeeRepeatable]
        [ProvidesItem(ProvidedItem.GoldRupee)]
        [LocationName("Curiosity Shop Gold Rupee"), Region(Region.WestClockTown)]
        [GossipLocationHint("a shady gentleman", "a dodgy seller", "a shady dealer")]
        [GetItemIndex(0x1CA)]
        MundaneItemCuriosityShopGoldRupee,

        [Overwritable, Purchaseable, Repeatable, Temporary, Visible]
        [ProvidesItem(ProvidedItem.Seahorse)]
        [LocationName("Fisherman Pictograph"), Region(Region.GreatBayCoast)]
        [GossipLocationHint("a fisherman")]
        [GetItemIndex(0x95)]
        MundaneItemSeahorse,

        //[GetItemIndex(0x1A1)]

        GossipTerminaSouth,
        GossipSwampPotionShop,
        GossipMountainSpringPath,
        GossipMountainPath,
        GossipOceanZoraGame,
        GossipCanyonRoad,
        GossipCanyonDock,
        GossipCanyonSpiritHouse,
        GossipTerminaMilk,
        GossipTerminaWest,
        GossipTerminaNorth,
        GossipTerminaEast,
        GossipRanchTree,
        GossipRanchBarn,
        GossipMilkRoad,
        GossipOceanFortress,
        GossipSwampRoad,
        GossipTerminaObservatory,
        GossipRanchCuccoShack,
        GossipRanchRacetrack,
        GossipRanchEntrance,
        GossipCanyonRavine,
        GossipMountainSpringFrog,
        GossipSwampSpiderHouse,
        GossipTerminaGossipLarge,
        GossipTerminaGossipGuitar,
        GossipTerminaGossipPipes,
        GossipTerminaGossipDrums,

        [ProvidesItem(ProvidedItem.IceTrap)]
        IceTrap = -1,

        [ItemName("Recovery Heart")]
        [GossipItemHint("health")]
        [ChestType(ChestTypeAttribute.ChestType.SmallWooden)]
        [ShopText("Replenishes a small amount of your life energy.")]
        [GetItemIndex(0x0A)]
        RecoveryHeart = -2,
    }
}
