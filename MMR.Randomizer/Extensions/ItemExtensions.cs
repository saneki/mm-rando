using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MMR.Randomizer.Attributes;
using MMR.Randomizer.GameObjects;
using MMR.Common.Extensions;

namespace MMR.Randomizer.Extensions
{
    public static class ItemExtensions
    {
        public static ushort? GetItemIndex(this Item item)
        {
            return item.GetAttribute<GetItemIndexAttribute>()?.Index;
        }

        public static int[] GetBottleItemIndices(this Item item)
        {
            return item.GetAttribute<GetBottleItemIndicesAttribute>()?.Indices;
        }

        public static string Name(this Item item)
        {
            return item.GetAttribute<ItemNameAttribute>()?.Name;
        }

        public static string ProgressiveUpgradeName(this Item item, bool progressiveUpgradesEnabled)
        {
            if (progressiveUpgradesEnabled)
            {
                if (item == Item.StartingSword || item == Item.UpgradeRazorSword || item == Item.UpgradeGildedSword)
                {
                    return "Sword Upgrade";
                }
                if (item == Item.FairyMagic || item == Item.FairyDoubleMagic)
                {
                    return "Magic Power Upgrade";
                }
                if (item == Item.UpgradeAdultWallet || item == Item.UpgradeGiantWallet)
                {
                    return "Wallet Upgrade";
                }
                if (item == Item.ItemBombBag || item == Item.UpgradeBigBombBag || item == Item.UpgradeBiggestBombBag)
                {
                    return "Bomb Bag Upgrade";
                }
                if (item == Item.ItemBow || item == Item.UpgradeBigQuiver || item == Item.UpgradeBiggestQuiver)
                {
                    return "Bow Upgrade";
                }
            }
            return item.Name();
        }

        public static string Location(this Item item)
        {
            return item.GetAttribute<LocationNameAttribute>()?.Name;
        }

        public static Region? Region(this Item item)
        {
            return item.GetAttribute<RegionAttribute>()?.Region;
        }

        public static string Entrance(this Item item)
        {
            return item.GetAttribute<EntranceNameAttribute>()?.Name;
        }

        public static ShopTextAttribute ShopTexts(this Item item)
        {
            return item.GetAttribute<ShopTextAttribute>();
        }

        public static string[] ItemHints(this Item item)
        {
            return item.GetAttribute<GossipItemHintAttribute>().Values;
        }

        public static string[] LocationHints(this Item item)
        {
            return item.GetAttribute<GossipLocationHintAttribute>().Values;
        }

        public static bool IsRepeatable(this Item item)
        {
            return item.HasAttribute<RepeatableAttribute>();
        }

        public static bool IsCycleRepeatable(this Item item)
        {
            return item.HasAttribute<CycleRepeatableAttribute>();
        }

        public static bool IsRupeeRepeatable(this Item item)
        {
            return item.HasAttribute<RupeeRepeatableAttribute>();
        }

        public static bool IsDowngradable(this Item item)
        {
            return item.HasAttribute<DowngradableAttribute>();
        }

        public static bool IsTemporary(this Item item)
        {
            return item.HasAttribute<TemporaryAttribute>();
        }

        public static bool IsFake(this Item item)
        {
            return item.Name() == null;
        }

        public static bool IsOverwritable(this Item item)
        {
            return item.HasAttribute<OverwritableAttribute>();
        }
    }
}
