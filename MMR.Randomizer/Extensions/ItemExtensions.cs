using MMR.Randomizer.Attributes;
using MMR.Randomizer.GameObjects;
using MMR.Common.Extensions;
using MMR.Randomizer.Models.Rom;
using MMR.Randomizer.Attributes.Entrance;
using System.Collections.Generic;

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
            return item.GetProvidedItem()?.Name();
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
            return item.GetProvidedItem()?.ShopTexts();
        }

        public static string[] ItemHints(this Item item)
        {
            return item.GetProvidedItem()?.Hints();
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
            return item.GetProvidedItem().Value.IsDowngradable();
        }

        public static bool IsTemporary(this Item item)
        {
            return item.HasAttribute<TemporaryAttribute>();
        }

        public static bool IsFake(this Item item)
        {
            return item.Name() == null;
        }

        public static IList<DungeonEntrance> DungeonEntrances(this Item item)
        {
            if (!item.HasAttribute<DungeonEntranceAttribute>())
            {
                return null;
            }
            var result = new List<DungeonEntrance>();
            var attr = item.GetAttribute<DungeonEntranceAttribute>();
            result.Add(attr.Entrance);
            if (attr.Pair.HasValue)
            {
                result.Add(attr.Pair.Value);
            }
            return result;
        }

        public static bool IsOverwritable(this Item item)
        {
            return item.HasAttribute<OverwritableAttribute>();
        }

        public static bool IsShop(this Item item)
        {
            return item.HasAttribute<ShopRoomAttribute>();
        }

        public static bool IsSong(this Item item)
        {
            return (Item.SongHealing <= item && item <= Item.SongOath);
        }

        public static ChestType? ChestType(this Item item)
        {
            var chestType = item.GetAttribute<ChestTypeAttribute>()?.Type;
            return chestType.HasValue ? chestType.Value : item.GetProvidedItem()?.ChestType();
        }

        public static bool IsPurchaseable(this Item item)
        {
            return item.HasAttribute<PurchaseableAttribute>();
        }

        public static bool IsVisible(this Item item)
        {
            return item.HasAttribute<VisibleAttribute>();
        }

        public static ProvidedItem? GetProvidedItem(this Item item)
        {
            return item.GetAttribute<ProvidesItemAttribute>()?.Item;
        }

        public static IEnumerable<StartingItemAttribute> StartingItems(this Item item)
        {
            var provided = item.GetProvidedItem();
            return provided.HasValue ? provided.Value.StartingItems() : new List<StartingItemAttribute>();
        }

        public static StartingTingleMapAttribute StartingTingleMap(this Item item)
        {
            return item.GetProvidedItem()?.StartingTingleMap();
        }

        public static GetItemEntry ExclusiveItemEntry(this Item item)
        {
            return item.GetProvidedItem()?.ExclusiveItemEntry();
        }

        public static bool IsExclusiveItem(this Item item)
        {
            var provided = item.GetProvidedItem();
            return provided.HasValue ? provided.Value.IsExclusiveItem() : false;
        }

        public static bool IsProgressive(this Item item)
        {
            var provided = item.GetProvidedItem();
            return provided.HasValue ? provided.Value.IsProgressive() : false;
        }

        public static bool IsStarting(this Item item)
        {
            var provided = item.GetProvidedItem();
            return provided.HasValue ? provided.Value.IsStarting() : false;
        }
    }
}
