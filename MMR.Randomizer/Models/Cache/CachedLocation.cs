#nullable enable

using MMR.Common.Extensions;
using MMR.Randomizer.Attributes;
using MMR.Randomizer.GameObjects;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;

namespace MMR.Randomizer.Models.Cache
{
    /// <summary>
    /// Cached struct describing a <see cref="Item"/> using information provided via reflection.
    /// </summary>
    public readonly struct CachedLocation
    {
        public readonly ChestAttribute? Chest;
        public readonly ChestType? ChestType;
        public readonly ushort? GetItemIndex;
        public readonly GossipCombineAttribute? GossipCombine;
        public readonly int? GossipCombineOrder;
        public readonly GrottoChestAttribute? GrottoChest;
        public readonly bool IsCycleRepeatable;
        public readonly bool IsOverwritable;
        public readonly bool IsRepeatable;
        public readonly bool IsRupeeRepeatable;
        public readonly bool IsTemporary;
        public readonly CachedItem? Item;
        public readonly Item Location;
        public readonly ReadOnlyCollection<string> LocationHints;
        public readonly string? LocationName;
        public readonly Region? Region;
        public readonly ReadOnlyCollection<ShopInventoryAttribute> ShopInventory;
        public readonly ReadOnlyCollection<ShopRoomAttribute> ShopRoom;

        public CachedLocation(Item location, CachedItem[] items)
        {
            Chest = null;
            ChestType = null;
            GetItemIndex = null;
            GossipCombine = null;
            GossipCombineOrder = null;
            GrottoChest = null;
            IsCycleRepeatable = false;
            IsOverwritable = false;
            IsRepeatable = false;
            IsRupeeRepeatable = false;
            IsTemporary = false;
            Item = null;
            Location = location;
            LocationHints = new ReadOnlyCollection<string>(new string[0]);
            LocationName = null;
            Region = null;

            var shopInventories = new List<ShopInventoryAttribute>();
            var shopRooms = new List<ShopRoomAttribute>();
            foreach (var attribute in location.GetAttributes())
            {
                switch (attribute)
                {
                    case ChestAttribute attr:
                        Chest = attr;
                        break;
                    case ChestTypeAttribute attr:
                        ChestType = attr.Type;
                        break;
                    case CycleRepeatableAttribute:
                        IsCycleRepeatable = true;
                        break;
                    case GetItemIndexAttribute attr:
                        GetItemIndex = attr.Index;
                        break;
                    case GossipCombineAttribute attr:
                        GossipCombine = attr;
                        break;
                    case GossipCombineOrderAttribute attr:
                        GossipCombineOrder = attr.Order;
                        break;
                    case GossipLocationHintAttribute attr:
                        LocationHints = new ReadOnlyCollection<string>(attr.Values);
                        break;
                    case GrottoChestAttribute attr:
                        GrottoChest = attr;
                        break;
                    case LocationNameAttribute attr:
                        LocationName = attr.Name;
                        break;
                    case OverwritableAttribute:
                        IsOverwritable = true;
                        break;
                    case ProvidesItemAttribute attr:
                        Item = items[(int)attr.Item];
                        break;
                    case RegionAttribute attr:
                        Region = attr.Region;
                        break;
                    case RepeatableAttribute:
                        IsRepeatable = true;
                        break;
                    case RupeeRepeatableAttribute:
                        IsRupeeRepeatable = true;
                        break;
                    case ShopInventoryAttribute attr:
                        shopInventories.Add(attr);
                        break;
                    case ShopRoomAttribute attr:
                        shopRooms.Add(attr);
                        break;
                    case TemporaryAttribute:
                        IsTemporary = true;
                        break;
                };
            }

            ShopInventory = new ReadOnlyCollection<ShopInventoryAttribute>(shopInventories);
            ShopRoom = new ReadOnlyCollection<ShopRoomAttribute>(shopRooms);
        }

        public static CachedLocation[] Build(CachedItem[] items)
        {
            return Enumerate(items).ToArray();
        }

        static IEnumerable<CachedLocation> Enumerate(CachedItem[] items)
        {
            foreach (var value in Enum.GetValues(typeof(Item)))
            {
                var location = (Item)value;
                var cached = new CachedLocation(location, items);
                yield return cached;
            }
        }
    }
}
