﻿using MMR.Randomizer.Constants;
using System.Collections.Generic;
using MMR.Randomizer.GameObjects;
using System;
using System.Linq;
using MMR.Randomizer.Extensions;
using MMR.Randomizer.Attributes;
using System.Collections.ObjectModel;
using MMR.Randomizer.Models;
using MMR.Common.Extensions;

namespace MMR.Randomizer.Utils
{
    public static class ItemUtils
    {
        public static bool IsShopItem(Item item)
        {
            return (item >= Item.ShopItemTradingPostRedPotion
                    && item <= Item.ShopItemZoraRedPotion)
                    || item == Item.ItemBombBag
                    || item == Item.UpgradeBigBombBag
                    || item == Item.MaskAllNight
                    || item == Item.ShopItemMilkBarChateau
                    || item == Item.ShopItemMilkBarMilk
                    || item == Item.ShopItemBusinessScrubMagicBean
                    || item == Item.ShopItemBusinessScrubGreenPotion
                    || item == Item.ShopItemBusinessScrubBluePotion
                    || item == Item.ShopItemGormanBrosMilk;
        }

        public static bool IsCowItem(Item item)
        {
            return (item >= Item.ItemRanchBarnMainCowMilk && item <= Item.ItemCoastGrottoCowMilk2);
        }

        public static bool IsSkulltulaToken(Item item)
        {
            return item >= Item.CollectibleSwampSpiderToken1 && item <= Item.CollectibleOceanSpiderToken30;
        }

        public static bool IsStrayFairy(Item item)
        {
            return item >= Item.CollectibleStrayFairyClockTown && item <= Item.CollectibleStrayFairyStoneTower15;
        }

        public static int AddItemOffset(int itemId)
        {
            if (itemId >= (int)Item.AreaSouthAccess)
            {
                itemId += Items.NumberOfAreasAndOther;
            }
            if (itemId >= (int)Item.OtherOneMask)
            {
                itemId += 5;
            }
            return itemId;
        }

        public static int SubtractItemOffset(int itemId)
        {
            if (itemId >= (int)Item.OtherOneMask)
            {
                itemId -= 5;
            }
            if (itemId >= (int)Item.AreaSouthAccess)
            {
                itemId -= Items.NumberOfAreasAndOther;
            }
            return itemId;
        }

        public static bool IsBottleCatchContent(Item item)
        {
            return item >= Item.BottleCatchFairy
                   && item <= Item.BottleCatchMushroom;
        }

        public static bool IsMoonLocation(Item location)
        {
            return location >= Item.HeartPieceDekuTrial && location <= Item.ChestLinkTrialBombchu10;
        }

        public static bool IsStartingLocation(Item location)
        {
            return location == Item.MaskDeku || location == Item.SongHealing
                || (location >= Item.StartingSword && location <= Item.StartingHeartContainer2);
        }

        public static bool IsSong(Item item)
        {
            return item >= Item.SongHealing
                && item <= Item.SongOath;
        }

        // todo cache
        public static IEnumerable<Item> DowngradableItems()
        {
            return Enum.GetValues(typeof(Item))
                .Cast<Item>()
                .Where(item => item.IsDowngradable());
        }

        // todo cache
        public static IEnumerable<Item> OverwritableItems()
        {
            return Enum.GetValues(typeof(Item))
                .Cast<Item>()
                .Where(item => item.IsOverwritable());
        }

        // todo cache
        public static IEnumerable<Item> StartingItems()
        {
            return Enum.GetValues(typeof(Item))
                .Cast<Item>()
                .Where(item => item.IsStarting());
        }

        // todo cache
        public static IEnumerable<Item> AllRupees()
        {
            return Enum.GetValues(typeof(Item))
                .Cast<Item>()
                .Where(item => item.Name()?.Contains("Rupee") == true);
        }
        
        private static List<Item> _allLocations;
        public static IEnumerable<Item> AllLocations()
        {
            return _allLocations ?? (_allLocations = Enum.GetValues(typeof(Item)).Cast<Item>().Where(item => item.Location() != null).ToList());
        }

        // todo cache
        public static IEnumerable<ushort> AllGetItemIndices()
        {
            return Enum.GetValues(typeof(Item))
                .Cast<Item>()
                .Where(item => item.HasAttribute<GetItemIndexAttribute>())
                .Select(item => item.GetAttribute<GetItemIndexAttribute>().Index);
        }

        // todo cache
        public static IEnumerable<int> AllGetBottleItemIndices()
        {
            return Enum.GetValues(typeof(Item))
                .Cast<Item>()
                .Where(item => item.HasAttribute<GetBottleItemIndicesAttribute>())
                .SelectMany(item => item.GetAttribute<GetBottleItemIndicesAttribute>().Indices);
        }

        public static List<Item> JunkItems { get; private set; }
        public static void PrepareJunkItems(List<ItemObject> itemList)
        {
            JunkItems = itemList.Where(io => io.Item.ChestType() == ChestTypeAttribute.ChestType.SmallWooden && !itemList.Any(other => (other.DependsOnItems?.Contains(io.Item) ?? false) || (other.Conditionals?.Any(c => c.Contains(io.Item)) ?? false))).Select(io => io.Item).ToList();
        }
        public static bool IsJunk(Item item)
        {
            return item == Item.RecoveryHeart || JunkItems.Contains(item);
        }

        public static bool IsRequired(Item item, RandomizedResult randomizedResult)
        {
            return !item.Name().Contains("Heart")
                        && !IsStrayFairy(item)
                        && !IsSkulltulaToken(item)
                        && item != Item.IceTrap
                        && randomizedResult.ItemsRequiredForMoonAccess.Contains(item);
        }

        public static bool IsImportant(Item item, RandomizedResult randomizedResult)
        {
            return !item.Name().Contains("Heart")
                        && item != Item.IceTrap
                        && randomizedResult.ImportantItems.Contains(item);
        }

        public static readonly ReadOnlyCollection<ReadOnlyCollection<Item>> ForbiddenStartTogether = new List<List<Item>>()
        {
            new List<Item>
            {
                Item.ItemBow,
                Item.UpgradeBigQuiver,
                Item.UpgradeBiggestQuiver,
            },
            new List<Item>
            {
                Item.ItemBombBag,
                Item.UpgradeBigBombBag,
                Item.UpgradeBiggestBombBag,
            },
            new List<Item>
            {
                Item.UpgradeAdultWallet,
                Item.UpgradeGiantWallet,
            },
            new List<Item>
            {
                Item.StartingSword,
                Item.UpgradeRazorSword,
                Item.UpgradeGildedSword,
            },
            new List<Item>
            {
                Item.StartingShield,
                Item.ShopItemTradingPostShield,
                Item.ShopItemZoraShield,
                Item.UpgradeMirrorShield,
            },
            new List<Item>
            {
                Item.FairyMagic,
                Item.FairyDoubleMagic,
            },
        }.Select(list => list.AsReadOnly()).ToList().AsReadOnly();
    }
}
