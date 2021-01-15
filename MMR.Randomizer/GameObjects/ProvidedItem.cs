using MMR.Randomizer.Attributes;

namespace MMR.Randomizer.GameObjects
{
    public enum ProvidedItem
    {
        [Progressive, ProvidesUpgrade(UpgradeType.BowQuiver, 1)]
        [StartingItem(0xC5CE25, 0x01)]
        [StartingItem(0xC5CE6F, 0x01)]
        [ItemName("Hero's Bow")]
        [GossipItemHint("a projectile", "a ranged weapon")]
        [ShopText("Use it to shoot arrows.")]
        [ChestType(ChestType.LargeGold)]
        Bow,

        [StartingItem(0xC5CE26, 0x02)]
        [ItemName("Fire Arrow")]
        [GossipItemHint("the power of fire", "a magical item")]
        [ShopText("Arm your bow with arrows that burst into flame.")]
        [ChestType(ChestType.LargeGold)]
        FireArrow,

        [StartingItem(0xC5CE27, 0x03)]
        [ItemName("Ice Arrow")]
        [GossipItemHint("the power of ice", "a magical item")]
        [ShopText("Arm your bow with arrows that freeze.")]
        [ChestType(ChestType.LargeGold)]
        IceArrow,

        [StartingItem(0xC5CE28, 0x04)]
        [ItemName("Light Arrow")]
        [GossipItemHint("the power of light", "a magical item")]
        [ShopText("Arm your bow with arrows infused with sacred light.")]
        [ChestType(ChestType.LargeGold)]
        LightArrow,

        [ItemName("Deku Stick")]
        [ProvidesConsumable(ConsumableType.DekuStick, 1)]
        [GossipItemHint("a flammable weapon", "a flimsy weapon")]
        [ShopText("Deku Sticks burn well. You can only carry 10.")]
        [ChestType(ChestType.SmallWooden)]
        DekuStick,

        //[StartingItem(0xC5CE2E, 0x0A)]
        [ItemName("Magic Bean")]
        [ProvidesConsumable(ConsumableType.MagicBean, 1)]
        [GossipItemHint("a plant seed")]
        [ShopText("Plant it in soft soil.")]
        [ChestType(ChestType.LargeGold)]
        MagicBean,

        //[StartingItem(0xC5CE30, 0x0C)]
        [ItemName("Powder Keg")]
        [ProvidesConsumable(ConsumableType.PowderKeg, 1)]
        [GossipItemHint("gunpowder", "a dangerous item", "an explosive barrel")]
        [ShopText("Both its power and its size are immense!")]
        [ChestType(ChestType.LargeGold)]
        PowderKeg,

        [StartingItem(0xC5CE31, 0x0D)]
        [ItemName("Pictobox")]
        [GossipItemHint("a light recorder", "a capture device")]
        [ShopText("Use it to snap pictographs.")]
        [ChestType(ChestType.LargeGold)]
        Pictobox,

        [StartingItem(0xC5CE32, 0x0E)]
        [ItemName("Lens of Truth")]
        [GossipItemHint("eyeglasses", "the truth", "focused vision")]
        [ShopText("Uses magic to see what the naked eye cannot.")]
        [ChestType(ChestType.LargeGold)]
        LensOfTruth,

        [StartingItem(0xC5CE33, 0x0F)]
        [ItemName("Hookshot")]
        [GossipItemHint("a chain and grapple")]
        [ShopText("Use it to grapple objects.")]
        [ChestType(ChestType.LargeGold)]
        Hookshot,

        [StartingItem(0xC5CE34, 0x10)]
        [ItemName("Great Fairy's Sword")]
        [GossipItemHint("a black rose", "a powerful blade")]
        [ShopText("The most powerful sword has black roses etched in its blade.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        GreatFairySword,

        //[StartingItem(0xC5CE36, 0x12)]
        [ItemName("Bottle with Red Potion")]
        [GossipItemHint("a vessel of health", "bottled fortitude")]
        [ShopText("Replenishes your life energy.\u0009\u0001\u0000\u0000 Comes with an Empty Bottle.\u0009\u0002")]
        [ChestType(ChestType.LargeGold)]
        BottleWithRedPotion,

        //[StartingItem(0xC5CE39, 0x12)]
        [ItemName("Empty Bottle")]
        [GossipItemHint("an empty vessel", "a glass container")]
        [ShopText("Carry various items in this.")]
        [ChestType(ChestType.LargeGold)]
        EmptyBottle,

        [ItemName("Red Potion")]
        [GossipItemHint("consumable strength", "a hearty drink", "a red drink")]
        [ShopText("Replenishes your life energy.")]
        [ChestType(ChestType.SmallGold)]
        RedPotion,

        [ItemName("Green Potion")]
        [GossipItemHint("a magic potion", "a green drink")]
        [ShopText("Replenishes your magic power.")]
        [ChestType(ChestType.SmallGold)]
        GreenPotion,

        [ItemName("Blue Potion")]
        [GossipItemHint("consumable strength", "a magic potion", "a blue drink")]
        [ShopText("Replenishes both life energy and magic power.")]
        [ChestType(ChestType.SmallGold)]
        BluePotion,

        [ItemName("Fairy")]
        [GossipItemHint("a winged friend", "a healer")]
        [ShopText("Recovers life energy. If you run out of life energy you'll automatically use this.")]
        [ChestType(ChestType.SmallGold)]
        Fairy,

        //[StartingItem(0xC5CE37, 0x12)]
        [ItemName("Bottle with Milk")]
        [GossipItemHint("a dairy product", "the produce of cows")]
        [ShopText("Recover five hearts with one drink. Contains two helpings.\u0009\u0001\u0000\u0000 Comes with an Empty Bottle.\u0009\u0002")]
        [ChestType(ChestType.LargeGold)]
        BottleWithMilk,

        //[StartingItem(0xC5CE38, 0x12)]
        [ItemName("Bottle with Gold Dust")]
        [GossipItemHint("a gleaming powder")]
        [ShopText("It's very high quality.\u0009\u0001\u0000\u0000 Comes with an Empty Bottle.\u0009\u0002")]
        [ChestType(ChestType.LargeGold)]
        BottleWithGoldDust,

        //[StartingItem(0xC5CE3B, 0x12)]
        [ItemName("Bottle with Chateau Romani")]
        [GossipItemHint("a dairy product", "an adult beverage")]
        [ShopText("Drink it to get lasting stamina for your magic power.\u0009\u0001\u0000\u0000 Comes with an Empty Bottle.\u0009\u0002")]
        [ChestType(ChestType.LargeGold)]
        BottleWithChateauRomani,

        [ItemName("Moon's Tear")]
        [GossipItemHint("a lunar teardrop", "celestial sadness")]
        [ShopText("A shining stone from the moon.")]
        [ChestType(ChestType.SmallGold)]
        MoonTear,

        [ItemName("Land Title Deed")]
        [GossipItemHint("a property deal")]
        [ShopText("The title deed to the Deku Flower in Clock Town.")]
        [ChestType(ChestType.SmallGold)]
        [ProvidesToiletPaper]
        LandDeed,

        [ItemName("Swamp Title Deed")]
        [GossipItemHint("a property deal")]
        [ShopText("The title deed to the Deku Flower in Southern Swamp.")]
        [ChestType(ChestType.SmallGold)]
        [ProvidesToiletPaper]
        SwampDeed,

        [ItemName("Mountain Title Deed")]
        [GossipItemHint("a property deal")]
        [ShopText("The title deed to the Deku Flower near Goron Village.")]
        [ChestType(ChestType.SmallGold)]
        [ProvidesToiletPaper]
        MountainDeed,

        [ItemName("Ocean Title Deed")]
        [GossipItemHint("a property deal")]
        [ShopText("The title deed to the Deku Flower in Zora Hall.")]
        [ChestType(ChestType.SmallGold)]
        [ProvidesToiletPaper]
        OceanDeed,

        [ItemName("Room Key")]
        [GossipItemHint("a door opener", "a lock opener")]
        [ShopText("With this, you can go in and out of the Stock Pot Inn at night.")]
        [ChestType(ChestType.SmallGold)]
        RoomKey,

        [ItemName("Letter to Mama")]
        [GossipItemHint("an important note", "a special delivery")]
        [ShopText("It's a parcel for Kafei's mother.")]
        [ChestType(ChestType.SmallGold)]
        [ProvidesToiletPaper]
        MamaLetter,

        [ItemName("Letter to Kafei")]
        [GossipItemHint("a lover's plight", "a lover's letter")]
        [ShopText("A love letter from Anju to Kafei.")]
        [ChestType(ChestType.SmallGold)]
        [ProvidesToiletPaper]
        KafeiLetter,

        [ItemName("Pendant of Memories")]
        [GossipItemHint("a cherished necklace", "a symbol of trust")]
        [ShopText("Kafei's symbol of trust for Anju.")]
        [ChestType(ChestType.SmallGold)]
        Pendant,

        [StartingTingleMap(TingleMap.Town)]
        [ItemName("Map of Clock Town")]
        [GossipItemHint("a world map")]
        [ShopText("Map of Clock Town.")]
        [ChestType(ChestType.SmallWooden)]
        TingleMapTown,

        [StartingTingleMap(TingleMap.Swamp)]
        [ItemName("Map of Woodfall")]
        [GossipItemHint("a world map")]
        [ShopText("Map of the south.")]
        [ChestType(ChestType.SmallWooden)]
        TingleMapWoodfall,

        [StartingTingleMap(TingleMap.Mountain)]
        [ItemName("Map of Snowhead")]
        [GossipItemHint("a world map")]
        [ShopText("Map of the north.")]
        [ChestType(ChestType.SmallWooden)]
        TingleMapSnowhead,

        [StartingTingleMap(TingleMap.Ranch)]
        [ItemName("Map of Romani Ranch")]
        [GossipItemHint("a world map")]
        [ShopText("Map of the ranch.")]
        [ChestType(ChestType.SmallWooden)]
        TingleMapRanch,

        [StartingTingleMap(TingleMap.Ocean)]
        [ItemName("Map of Great Bay")]
        [GossipItemHint("a world map")]
        [ShopText("Map of the west.")]
        [ChestType(ChestType.SmallWooden)]
        TingleMapGreatBay,

        [StartingTingleMap(TingleMap.Canyon)]
        [ItemName("Map of Stone Tower")]
        [GossipItemHint("a world map")]
        [ShopText("Map of the east.")]
        [ChestType(ChestType.SmallWooden)]
        TingleMapStoneTower,

        [StartingItem(0xC5CE41, 0x32)]
        [ItemName("Deku Mask")]
        [GossipItemHint("a woodland spirit")]
        [ShopText("Wear it to assume Deku form.")]
        [ChestType(ChestType.LargeGold)]
        DekuMask,

        [StartingItem(0xC5CE47, 0x33)]
        [ItemName("Goron Mask")]
        [GossipItemHint("a mountain spirit")]
        [ShopText("Wear it to assume Goron form.")]
        [ChestType(ChestType.LargeGold)]
        GoronMask,

        [StartingItem(0xC5CE4D, 0x34)]
        [ItemName("Zora Mask")]
        [GossipItemHint("an ocean spirit")]
        [ShopText("Wear it to assume Zora form.")]
        [ChestType(ChestType.LargeGold)]
        ZoraMask,

        [StartingItem(0xC5CE53, 0x35)]
        [ItemName("Fierce Deity's Mask")]
        [GossipItemHint("the wrath of a god")]
        [ShopText("A mask that contains the merits of all masks.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        FierceDeityMask,

        [StartingItem(0xC5CE4C, 0x36)]
        [ItemName("Mask of Truth")]
        [GossipItemHint("a piercing gaze")]
        [ShopText("Wear it to read the thoughts of Gossip Stones and animals.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        MaskOfTruth,

        [StartingItem(0xC5CE4A, 0x37)]
        [ItemName("Kafei's Mask")]
        [GossipItemHint("the mask of a missing one", "a son's mask")]
        [ShopText("Wear it to inquire about Kafei's whereabouts.", isMultiple: true)]
        [ChestType(ChestType.LargeGold)]
        KafeiMask,

        [StartingItem(0xC5CE3D, 0x38)]
        [ItemName("All Night Mask")]
        [GossipItemHint("insomnia")]
        [ShopText("When you wear it you don't get sleepy.")]
        [ChestType(ChestType.LargeGold)]
        AllNightMask,

        [StartingItem(0xC5CE44, 0x39)]
        [ItemName("Bunny Hood")]
        [GossipItemHint("the ears of the wild", "a rabbit's hearing")]
        [ShopText("Wear it to be filled with the speed and hearing of the wild.")]
        [ChestType(ChestType.LargeGold)]
        BunnyHood,

        [StartingItem(0xC5CE42, 0x3A)]
        [ItemName("Keaton Mask")]
        [GossipItemHint("a popular mask", "a fox's mask")]
        [ShopText("The mask of the ghost fox, Keaton.")]
        [ChestType(ChestType.LargeGold)]
        KeatonMask,

        [StartingItem(0xC5CE50, 0x3B)]
        [ItemName("Garo's Mask")]
        [GossipItemHint("the mask of spies")]
        [ShopText("This mask can summon the hidden Garo ninjas.")]
        [ChestType(ChestType.LargeGold)]
        GaroMask,

        [StartingItem(0xC5CE48, 0x3C)]
        [ItemName("Romani's Mask")]
        [ShopText("Wear it to show you're a member of the Milk Bar, Latte.", isMultiple: true)]
        [ChestType(ChestType.LargeGold)]
        RomaniMask,

        [StartingItem(0xC5CE49, 0x3D)]
        [ItemName("Circus Leader's Mask")]
        [GossipItemHint("a mask of sadness")]
        [ShopText("People related to Gorman will react to this.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        CircusLeaderMask,

        [StartingItem(0xC5CE3C, 0x3E)]
        [ItemName("Postman's Hat")]
        [GossipItemHint("a hard worker's hat")]
        [ShopText("You can look into mailboxes when you wear this.")]
        [ChestType(ChestType.LargeGold)]
        PostmanHat,

        [StartingItem(0xC5CE4B, 0x3F)]
        [ItemName("Couple's Mask")]
        [ShopText("When you wear it, you can soften people's hearts.")]
        [ChestType(ChestType.LargeGold)]
        CoupleMask,

        [StartingItem(0xC5CE40, 0x40)]
        [ItemName("Great Fairy's Mask")]
        [GossipItemHint("a friend of fairies")]
        [ShopText("The mask's hair will shimmer when you're close to a Stray Fairy.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        GreatFairyMask,

        [StartingItem(0xC5CE4F, 0x41)]
        [ItemName("Gibdo Mask")]
        [GossipItemHint("a mask of monsters")]
        [ShopText("Even a real Gibdo will mistake you for its own kind.")]
        [ChestType(ChestType.LargeGold)]
        GibdoMask,

        [StartingItem(0xC5CE45, 0x42)]
        [ItemName("Don Gero's Mask")]
        [GossipItemHint("a conductor's mask", "an amphibious mask")]
        [ShopText("When you wear it, you can call the Frog Choir members together.", isMultiple: true)]
        [ChestType(ChestType.LargeGold)]
        DonGeroMask,

        [StartingItem(0xC5CE4E, 0x43)]
        [ItemName("Kamaro's Mask")]
        [GossipItemHint("dance moves")]
        [ShopText("Wear this to perform a mysterious dance.", isMultiple: true)]
        [ChestType(ChestType.LargeGold)]
        KamaroMask,

        [StartingItem(0xC5CE51, 0x44)]
        [ItemName("Captain's Hat")]
        [GossipItemHint("a commanding presence")]
        [ShopText("Wear it to pose as Captain Keeta.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        CaptainHat,

        [StartingItem(0xC5CE3F, 0x45)]
        [ItemName("Stone Mask")]
        [GossipItemHint("inconspicuousness")]
        [ShopText("Become as plain as stone so you can blend into your surroundings.")]
        [ChestType(ChestType.LargeGold)]
        StoneMask,

        [StartingItem(0xC5CE43, 0x46)]
        [ItemName("Bremen Mask")]
        [GossipItemHint("a mask of leadership", "a bird's mask")]
        [ShopText("Wear it so young animals will mistake you for their leader.")]
        [ChestType(ChestType.LargeGold)]
        BremenMask,

        [StartingItem(0xC5CE3E, 0x47)]
        [ItemName("Blast Mask")]
        [GossipItemHint("a dangerous mask")]
        [ShopText("Wear it and detonate it...")]
        [ChestType(ChestType.LargeGold)]
        BlastMask,

        [StartingItem(0xC5CE46, 0x48)]
        [ItemName("Mask of Scents")]
        [ShopText("Wear it to heighten your sense of smell.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        MaskOfScents,

        [StartingItem(0xC5CE52, 0x49)]
        [ItemName("Giant's Mask")]
        [GossipItemHint("a growth spurt")]
        [ShopText("If you wear it in a certain room, you'll grow into a giant.")]
        [ChestType(ChestType.LargeGold)]
        GiantMask,

        [Progressive, ProvidesUpgrade(UpgradeType.Sword, 1)]
        [StartingItem(0xC5CE21, 0x01)]
        [StartingItem(0xC5CE00, 0x4D)]
        [ItemName("Kokiri Sword")]
        [GossipItemHint("a forest blade")]
        [ShopText("A sword created by forest folk.")]
        [ChestType(ChestType.LargeGold)]
        KokiriSword,

        [Downgradable, Progressive, ProvidesUpgrade(UpgradeType.Sword, 2)]
        [StartingItem(0xC5CE21, 0x02)]
        [StartingItem(0xC5CE00, 0x4E)]
        [ItemName("Razor Sword")]
        [GossipItemHint("a sharp blade")]
        [ShopText("A sharp sword forged at the smithy.")]
        [ChestType(ChestType.LargeGold)]
        RazorSword,

        [Downgradable, Progressive, ProvidesUpgrade(UpgradeType.Sword, 3)]
        [StartingItem(0xC5CE21, 0x03)]
        [StartingItem(0xC5CE00, 0x4F)]
        [ItemName("Gilded Sword")]
        [GossipItemHint("a sharp blade")]
        [ShopText("A very sharp sword forged from gold dust.")]
        [ChestType(ChestType.LargeGold)]
        GildedSword,

        [ItemName("Hero's Shield")]
        [GossipItemHint("a basic guard", "protection")]
        [ShopText("Use it to defend yourself.")]
        [ChestType(ChestType.LargeGold)]
        HeroShield,

        [Downgradable]
        [StartingItem(0xC5CE21, 0x20)]
        [ItemName("Mirror Shield"), LocationName("Mirror Shield Chest"), Region(Region.BeneathTheWell)]
        [GossipItemHint("a reflective guard", "echoing protection")]
        [ShopText("It can reflect certain rays of light.")]
        [ChestType(ChestType.LargeGold)]
        MirrorShield,

        [Downgradable, Progressive, ProvidesUpgrade(UpgradeType.BowQuiver, 2)]
        [StartingItem(0xC5CE25, 0x01)]
        [StartingItem(0xC5CE6F, 0x02)]
        [ItemName("Large Quiver")]
        [GossipItemHint("a projectile", "a ranged weapon")]
        [ShopText("This can hold up to a maximum of 40 arrows.")]
        [ChestType(ChestType.LargeGold)]
        BigQuiver,

        [Downgradable, Progressive, ProvidesUpgrade(UpgradeType.BowQuiver, 3)]
        [StartingItem(0xC5CE25, 0x01)]
        [StartingItem(0xC5CE6F, 0x03)]
        [ItemName("Largest Quiver")]
        [GossipItemHint("a projectile", "a ranged weapon")]
        [ShopText("This can hold up to a maximum of 50 arrows.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        BiggestQuiver,

        [Progressive, ProvidesUpgrade(UpgradeType.BombBag, 1)]
        [StartingItem(0xC5CE2A, 0x06)]
        [StartingItem(0xC5CE6F, 0x08)]
        [ItemName("Bomb Bag")]
        [GossipItemHint("an item carrier", "a vessel of explosives")]
        [ShopText("This can hold up to a maximum of 20 bombs.")]
        [ChestType(ChestType.LargeGold)]
        BombBag,

        [Downgradable, Progressive, ProvidesUpgrade(UpgradeType.BombBag, 2)]
        [StartingItem(0xC5CE2A, 0x06)]
        [StartingItem(0xC5CE6F, 0x10)]
        [ItemName("Big Bomb Bag")]
        [GossipItemHint("an item carrier", "a vessel of explosives")]
        [ShopRoom(ShopRoomAttribute.Room.BombShop, 0x52)]
        [ShopRoom(ShopRoomAttribute.Room.CuriosityShop, 0x44)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.BombShop, 1)]
        [ShopInventory(ShopInventoryAttribute.ShopKeeper.CuriosityShop, 2)]
        [ShopText("This can hold up to a maximum of 30 bombs.")]
        [ChestType(ChestType.LargeGold)]
        BigBombBag,

        [Downgradable, Progressive, ProvidesUpgrade(UpgradeType.BombBag, 3)]
        [StartingItem(0xC5CE2A, 0x06)]
        [StartingItem(0xC5CE6F, 0x18)]
        [ItemName("Biggest Bomb Bag")]
        [GossipItemHint("an item carrier", "a vessel of explosives")]
        [ShopText("This can hold up to a maximum of 40 bombs.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        BiggestBombBag,

        [Progressive, ProvidesUpgrade(UpgradeType.Wallet, 1)]
        [StartingItem(0xC5CE6E, 0x10)]
        [ItemName("Adult Wallet")]
        [GossipItemHint("a coin case", "great wealth")]
        [ShopText("This can hold up to a maximum of 200 rupees.")]
        [ChestType(ChestType.LargeGold)]
        AdultWallet,

        [Downgradable, Progressive, ProvidesUpgrade(UpgradeType.Wallet, 2)]
        [StartingItem(0xC5CE6E, 0x20)]
        [ItemName("Giant Wallet")]
        [GossipItemHint("a coin case", "great wealth")]
        [ShopText("This can hold up to a maximum of 500 rupees.")]
        [ChestType(ChestType.LargeGold)]
        GiantWallet,

        [StartingItem(0xC5CE73, 0x40)]
        [ItemName("Sonata of Awakening")]
        [GossipItemHint("a royal song", "an awakening melody")]
        [ShopText("This melody awakens those who have fallen into a deep sleep.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        SonataOfAwakening,

        [StartingItem(0xC5CE73, 0x80)]
        [ItemName("Goron Lullaby")]
        [GossipItemHint("a sleepy melody", "a father's lullaby")]
        [ShopText("This melody blankets listeners in calm while making eyelids grow heavy.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        GoronLullaby,

        [StartingItem(0xC5CE72, 0x01)]
        [ItemName("New Wave Bossa Nova")]
        [GossipItemHint("an ocean roar", "a song of newborns")]
        [ShopText("It's the melody taught by the Zora children that invigorates singing voices.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        NewWaveBossaNova,

        [StartingItem(0xC5CE72, 0x02)]
        [ItemName("Elegy of Emptiness")]
        [GossipItemHint("empty shells", "skin shedding")]
        [ShopText("It's a mystical song that allows you to shed a shell shaped in your current image.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        ElegyOfEmptiness,

        [StartingItem(0xC5CE72, 0x04)]
        [ItemName("Oath to Order")]
        [GossipItemHint("a song of summoning", "a song of giants")]
        [ShopText("This melody will call the giants at the right moment.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        OathToOrder,

        [StartingItem(0xC5CE72, 0x20)]
        [ItemName("Song of Healing")]
        [GossipItemHint("a soothing melody")]
        [ShopText("This melody will soothe restless spirits.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        SongOfHealing,

        [StartingItem(0xC5CE72, 0x40)]
        [ItemName("Epona's Song")]
        [GossipItemHint("a horse's song", "a song of the field")]
        [ShopText("This melody calls your horse, Epona.", isMultiple: true)]
        [ChestType(ChestType.LargeGold)]
        EponaSong,

        [StartingItem(0xC5CE72, 0x80)]
        [ItemName("Song of Soaring")]
        [GossipItemHint("white wings")]
        [ShopText("This melody sends you to a stone bird statue in an instant.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        SongOfSoaring,

        [StartingItem(0xC5CE71, 0x01)]
        [ItemName("Song of Storms")]
        [GossipItemHint("rain and thunder", "stormy weather")]
        [ShopText("This melody is the turbulent tune that blows curses away.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        SongOfStorms,

        [StartingItem(0xC5CE71, 0x04)]
        [ItemName("Bombers' Notebook")]
        [GossipItemHint("a handy notepad", "a quest logbook")]
        [ShopText("Allows you to keep track of people's schedules.")]
        [ChestType(ChestType.LargeGold)]
        Notebook,

        [ItemName("Swamp Skulltula Spirit")]
        [GossipItemHint("a golden token")]
        [ShopText("Collect 30 to lift the curse in the swamp spider house.")]
        [ChestType(ChestType.SmallGold)]
        SwampSpiderToken,

        [ItemName("Ocean Skulltula Spirit")]
        [GossipItemHint("a golden token")]
        [ShopText("Collect 30 to lift the curse in the ocean spider house.")]
        [ChestType(ChestType.SmallGold)]
        OceanSpiderToken,

        [StartingItem(0xC5CDE9, 0x10, true)] // add max health
        [StartingItem(0xC5CDEB, 0x10, true)] // add current health
        [StartingItem(0xC40E1B, 0x10, true)] // add respawn health
        [StartingItem(0xBDA683, 0x10, true)] // add minimum Song of Time health
        [StartingItem(0xBDA68F, 0x10, true)] // add minimum Song of Time health
        [ItemName("Heart Container")]
        [GossipItemHint("increased life")]
        [ShopText("Permanently increases your life energy.")]
        [ChestType(ChestType.LargeGold)]
        HeartContainer,

        [ItemName("Woodfall Boss Key")]
        [GossipItemHint("an important key", "entry to evil's lair")]
        [ShopText("The key for the boss room in Woodfall Temple.")]
        [ChestType(ChestType.BossKey)]
        WoodfallBossKey,

        [ItemName("Snowhead Boss Key")]
        [GossipItemHint("an important key", "entry to evil's lair")]
        [ShopText("The key for the boss room in Snowhead Temple.")]
        [ChestType(ChestType.BossKey)]
        SnowheadBossKey,

        [ItemName("Great Bay Boss Key")]
        [GossipItemHint("an important key", "entry to evil's lair")]
        [ShopText("The key for the boss room in Great Bay Temple.")]
        [ChestType(ChestType.BossKey)]
        GreatBayBossKey,

        [ItemName("Stone Tower Boss Key")]
        [GossipItemHint("an important key", "entry to evil's lair")]
        [ShopText("The key for the boss room in Stone Tower Temple.")]
        [ChestType(ChestType.BossKey)]
        StoneTowerBossKey,

        [StartingItem(0xC5CE74, 0x02)]
        [ItemName("Woodfall Compass")]
        [GossipItemHint("a navigation aid", "a magnetic needle")]
        [ShopText("The Compass for Woodfall Temple.")]
        [ChestType(ChestType.SmallWooden)]
        WoodfallCompass,

        [StartingItem(0xC5CE75, 0x02)]
        [ItemName("Snowhead Compass")]
        [GossipItemHint("a navigation aid", "a magnetic needle")]
        [ShopText("The Compass for Snowhead Temple.")]
        [ChestType(ChestType.SmallWooden)]
        SnowheadCompass,

        [StartingItem(0xC5CE76, 0x02)]
        [ItemName("Great Bay Compass")]
        [GossipItemHint("a navigation aid", "a magnetic needle")]
        [ShopText("The Compass for Great Bay Temple.")]
        [ChestType(ChestType.SmallWooden)]
        GreatBayCompass,

        [StartingItem(0xC5CE77, 0x02)]
        [ItemName("Stone Tower Compass")]
        [GossipItemHint("a navigation aid", "a magnetic needle")]
        [ShopText("The Compass for Stone Tower Temple.")]
        [ChestType(ChestType.SmallWooden)]
        StoneTowerCompass,

        [StartingItem(0xC5CE74, 0x04)]
        [ItemName("Woodfall Map")]
        [GossipItemHint("a navigation aid", "a paper guide")]
        [ShopText("The Dungeon Map for Woodfall Temple.")]
        [ChestType(ChestType.SmallWooden)]
        WoodfallMap,

        [StartingItem(0xC5CE75, 0x04)]
        [ItemName("Snowhead Map")]
        [GossipItemHint("a navigation aid", "a paper guide")]
        [ShopText("The Dungeon Map for Snowhead Temple.")]
        [ChestType(ChestType.SmallWooden)]
        SnowheadMap,

        [StartingItem(0xC5CE76, 0x04)]
        [ItemName("Great Bay Map")]
        [GossipItemHint("a navigation aid", "a paper guide")]
        [ShopText("The Dungeon Map for Great Bay Temple.")]
        [ChestType(ChestType.SmallWooden)]
        GreatBayMap,

        [StartingItem(0xC5CE77, 0x04)]
        [ItemName("Stone Tower Map")]
        [GossipItemHint("a navigation aid", "a paper guide")]
        [ShopText("The Dungeon Map for Stone Tower Temple.")]
        [ChestType(ChestType.SmallWooden)]
        StoneTowerMap,

        [ItemName("Woodfall Small Key")]
        [GossipItemHint("access to a locked door", "a useful key")]
        [ShopText("A small key for use in Woodfall Temple.")]
        [ChestType(ChestType.SmallGold)]
        WoodfallSmallKey,

        [ItemName("Snowhead Small Key")]
        [GossipItemHint("access to a locked door", "a useful key")]
        [ShopText("A small key for use in Snowhead Temple.")]
        [ChestType(ChestType.SmallGold)]
        SnowheadSmallKey,

        [ItemName("Great Bay Small Key")]
        [GossipItemHint("access to a locked door", "a useful key")]
        [ShopText("A small key for use in Great Bay Temple.")]
        [ChestType(ChestType.SmallGold)]
        GreatBaySmallKey,

        [ItemName("Stone Tower Small Key")]
        [GossipItemHint("access to a locked door", "a useful key")]
        [ShopText("A small key for use in Stone Tower Temple.")]
        [ChestType(ChestType.SmallGold)]
        StoneTowerSmallKey,

        [StartingItem(0xC5CE70, 0x10, true)]
        [ItemName("Piece of Heart")]
        [GossipItemHint("a segment of health")]
        [ShopText("Collect four to assemble a new Heart Container.")]
        [ChestType(ChestType.SmallWooden)]
        HeartPiece,

        [ItemName("Blue Rupee")]
        [ProvidesConsumable(ConsumableType.Rupee, 5)]
        [GossipItemHint("currency", "money", "cash", "wealth", "riches and stuff")]
        [ShopText("This is worth 5 rupees.")]
        [ChestType(ChestType.SmallWooden)]
        BlueRupee,

        [ItemName("Red Rupee")]
        [ProvidesConsumable(ConsumableType.Rupee, 20)]
        [GossipItemHint("currency", "money", "cash", "wealth", "riches and stuff")]
        [ShopText("This is worth 20 rupees.")]
        [ChestType(ChestType.SmallWooden)]
        RedRupee,

        [ItemName("Purple Rupee")]
        [ProvidesConsumable(ConsumableType.Rupee, 50)]
        [GossipItemHint("currency", "money", "cash", "wealth", "riches and stuff")]
        [ShopText("This is worth 50 rupees.")]
        [ChestType(ChestType.SmallWooden)]
        PurpleRupee,

        [ItemName("Silver Rupee")]
        [ProvidesConsumable(ConsumableType.Rupee, 100)]
        [GossipItemHint("currency", "money", "cash", "wealth", "riches and stuff")]
        [ShopText("This is worth 100 rupees.")]
        [ChestType(ChestType.SmallWooden)]
        SilverRupee,

        [ItemName("Gold Rupee")]
        [ProvidesConsumable(ConsumableType.Rupee, 200)]
        [GossipItemHint("currency", "money", "cash", "wealth", "riches and stuff")]
        [ShopText("This is worth 200 rupees.")]
        [ChestType(ChestType.SmallWooden)]
        GoldRupee,

        [ItemName("10 Deku Nuts")]
        [ProvidesConsumable(ConsumableType.DekuNut, 10)]
        [GossipItemHint("a flashing impact")]
        [ShopText("Its flash blinds enemies.", isMultiple: true)]
        [ChestType(ChestType.SmallWooden)]
        DekuNut10,

        [ItemName("10 Bombs")]
        [ProvidesConsumable(ConsumableType.Bomb, 10)]
        [GossipItemHint("explosives")]
        [ShopText("Explosives. You need a Bomb Bag to carry them.", isMultiple: true)]
        [ChestType(ChestType.SmallWooden)]
        Bomb10,

        [ItemName("10 Arrows")]
        [ProvidesConsumable(ConsumableType.Arrow, 10)]
        [GossipItemHint("a quiver refill", "a bundle of projectiles")]
        [ShopText("Ammo for your bow.", isMultiple: true)]
        [ChestType(ChestType.SmallWooden)]
        Arrow10,

        [ItemName("30 Arrows")]
        [ProvidesConsumable(ConsumableType.Arrow, 30)]
        [GossipItemHint("a quiver refill", "a bundle of projectiles")]
        [ShopText("Ammo for your bow.", isMultiple: true)]
        [ChestType(ChestType.SmallWooden)]
        Arrow30,

        [ItemName("50 Arrows")]
        [ProvidesConsumable(ConsumableType.Arrow, 50)]
        [GossipItemHint("a quiver refill", "a bundle of projectiles")]
        [ShopText("Ammo for your bow.", isMultiple: true)]
        [ChestType(ChestType.SmallWooden)]
        Arrow50,

        [ItemName("10 Bombchu")]
        [ProvidesConsumable(ConsumableType.Bombchu, 10)]
        [GossipItemHint("explosives")]
        [ShopText("Mouse-shaped bombs that are practical, sleek and self-propelled.", isMultiple: true)]
        [ChestType(ChestType.SmallWooden)]
        Bombchu10,

        [ItemName("Bombchu")]
        [ProvidesConsumable(ConsumableType.Bombchu, 1)]
        [GossipItemHint("explosive mice")]
        [ShopText("Mouse-shaped bomb that is practical, sleek and self-propelled.")]
        [ChestType(ChestType.SmallWooden)]
        Bombchu,

        [ItemName("5 Bombchu")]
        [ProvidesConsumable(ConsumableType.Bombchu, 5)]
        [GossipItemHint("explosive mice")]
        [ShopText("Mouse-shaped bombs that are practical, sleek and self-propelled.", isMultiple: true)]
        [ChestType(ChestType.SmallWooden)]
        Bombchu5,

        [Progressive, ProvidesUpgrade(UpgradeType.Magic, 1)]
        [StartingItem(0xC5CDED, 0x30)]
        [StartingItem(0xC5CDF4, 0x01)]
        [ItemName("Magic Power")]
        [GossipItemHint("magic power")]
        [ShopText("Grants the ability to use magic.", isMultiple: true)]
        [ChestType(ChestType.LargeGold)]
        Magic,

        [Progressive, ProvidesUpgrade(UpgradeType.Magic, 2)]
        [StartingItem(0xC5CDED, 0x60)]
        [StartingItem(0xC5CDF4, 0x01)]
        [StartingItem(0xC5CDF5, 0x01)]
        [ItemName("Extended Magic Power")]
        [GossipItemHint("magic power")]
        [ShopText("Grants the ability to use lots of magic.", isMultiple: true)]
        [ChestType(ChestType.LargeGold)]
        DoubleMagic,

        [StartingItemId(0x9C)]
        [ItemName("Spin Attack")]
        [GossipItemHint("a magic attack")]
        [ShopText("Increases the power of your spin attack.", isDefinite: true)]
        [ChestType(ChestType.LargeGold)]
        SpinAttack,

        [ItemName("Clock Town Stray Fairy")]
        [GossipItemHint("a lost fairy")]
        [ShopText("Return it to the Fairy Fountain in North Clock Town.")]
        [ChestType(ChestType.SmallGold)]
        ClockTownStrayFairy,

        [ItemName("Woodfall Stray Fairy")]
        [GossipItemHint("a lost fairy")]
        [ShopText("Collect 15 and return them to the Fairy Fountain in Woodfall.")]
        [ChestType(ChestType.SmallGold)]
        WoodfallStrayFairy,

        [ItemName("Snowhead Stray Fairy")]
        [GossipItemHint("a lost fairy")]
        [ShopText("Collect 15 and return them to the Fairy Fountain in Snowhead.")]
        [ChestType(ChestType.SmallGold)]
        SnowheadStrayFairy,

        [ItemName("Great Bay Stray Fairy")]
        [GossipItemHint("a lost fairy")]
        [ShopText("Collect 15 and return them to the Fairy Fountain in Great Bay.")]
        [ChestType(ChestType.SmallGold)]
        GreatBayStrayFairy,

        [ItemName("Stone Tower Stray Fairy")]
        [GossipItemHint("a lost fairy")]
        [ShopText("Collect 15 and return them to the Fairy Fountain in Stone Tower.")]
        [ChestType(ChestType.SmallGold)]
        StoneTowerStrayFairy,

        [StartingItem(0xC5CDF6, 0x01)]
        [StartingItem(0xC5CE87, 0x14)]
        [ItemName("Double Defense")]
        [GossipItemHint("magical defense")]
        [ShopText("Take half as much damage from enemies.", isMultiple: true)]
        [ChestType(ChestType.LargeGold)]
        DoubleDefense,

        [ItemName("Chateau Romani")]
        [GossipItemHint("a dairy product", "an adult beverage")]
        [ShopText("Drink it to get lasting stamina for your magic power.", isMultiple: true)]
        [ChestType(ChestType.SmallGold)]
        ChateauRomani,

        [ItemName("Milk")]
        [GossipItemHint("a dairy product", "the produce of cows")]
        [ShopText("Recover five hearts with one drink. Contains two helpings.", isMultiple: true)]
        [ChestType(ChestType.SmallGold)]
        Milk,

        [ItemName("Seahorse")]
        [GossipItemHint("a sea creature")]
        [ShopText("It wants to go back home to Pinnacle Rock.")]
        [ChestType(ChestType.SmallGold)]
        Seahorse,

        [ItemName("Ice Trap")]
        [GossipItemHint("a cold surprise", "an icy breeze")]
        [ChestType(ChestType.SmallWooden)]
        [GetItemEntry(0xB0, 0, 0, 0, 0x9000, 0, "\u0017You are a \u0003FOOL\u0000!\u0018\u00BF")]
        IceTrap,

        [ItemName("Recovery Heart")]
        [GossipItemHint("health")]
        [ChestType(ChestType.SmallWooden)]
        [ShopText("Replenishes a small amount of your life energy.")]
        RecoveryHeart,
    }
}
