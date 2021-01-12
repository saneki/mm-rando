#nullable enable

using MMR.Common.Extensions;
using MMR.Randomizer.Attributes;
using MMR.Randomizer.Attributes.Entrance;
using MMR.Randomizer.GameObjects;
using MMR.Randomizer.Models.Attributes;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;

namespace MMR.Randomizer.Models.Cache
{
    /// <summary>
    /// Cached record describing a <see cref="GameObjects.Item"/> using information provided via reflection.
    /// </summary>
    public sealed record CachedLocation
    {
        public readonly ChestAttribute? Chest;
        public readonly ChestType? ChestType;
        public readonly DungeonEntranceAttribute? DungeonEntrance;
        public readonly string? EntranceName;
        public readonly GetBottleItemIndicesAttribute? GetBottleItemIndices;
        public readonly ushort? GetItemIndex;
        public readonly ReadOnlyCollection<GossipCombineAttribute> GossipCombine;
        public readonly int? GossipCombineOrder;
        public readonly GossipCompetitiveHintAttribute? GossipCompetitiveHint;
        public readonly GrottoChestAttribute? GrottoChest;
        public readonly bool IsCycleRepeatable;
        public readonly bool IsOverwritable;
        public readonly bool IsRepeatable;
        public readonly bool IsRupeeRepeatable;
        public readonly bool IsTemporary;
        public readonly bool IsVisible;
        public readonly CachedItem? Item;
        public readonly Item Location;
        public readonly ReadOnlyCollection<string> LocationHints;
        public readonly string? LocationName;
        public readonly Region? Region;
        public readonly RequiresConsumableAttribute? RequiresConsumable;
        public readonly ReadOnlyCollection<ShopInventoryAttribute> ShopInventory;
        public readonly ReadOnlyCollection<ShopRoomAttribute> ShopRoom;

        /// <summary>
        /// Get <see cref="GameObjects.DungeonEntrance"/> values.
        /// </summary>
        public IList<DungeonEntrance>? DungeonEntrances => DungeonEntrance?.Entrances();

        /// <summary>
        /// Get <see cref="ExclusiveItemInfo"/> of attached <see cref="CachedItem"/>.
        /// </summary>
        public ExclusiveItemInfo? ExclusiveItem => Item?.ExclusiveItem;

        /// <summary>
        /// Whether or not this location has an attached <see cref="CachedItem"/> which is downgradable.
        /// </summary>
        public bool IsDowngradable => Item != null && Item.IsDowngradable;

        /// <summary>
        /// Whether or not this location has an attached <see cref="CachedItem"/> which has an <see cref="ExclusiveItemInfo"/>.
        /// </summary>
        public bool IsExclusiveItem => Item != null && Item.ExclusiveItem.HasValue;

        /// <summary>
        /// Whether or not this location has an attached <see cref="CachedItem"/>.
        /// </summary>
        public bool IsFake => Item == null;

        /// <summary>
        /// Whether or not this location has an attached <see cref="CachedItem"/> which is progressive.
        /// </summary>
        public bool IsProgressive => Item != null && Item.IsProgressive;

        /// <summary>
        /// Whether or not this location has any <see cref="ShopRoomAttribute"/> attributes.
        /// </summary>
        public bool IsShop => ShopRoom.Count > 0;

        /// <summary>
        /// Get hints of attached <see cref="CachedItem"/>.
        /// </summary>
        public ReadOnlyCollection<string>? ItemHints => Item?.Hints;

        /// <summary>
        /// Get the name of attached <see cref="CachedItem"/>.
        /// </summary>
        public string? Name => Item?.Name;

        /// <summary>
        /// Get <see cref="ShopTextAttribute"/> of attached <see cref="CachedItem"/>.
        /// </summary>
        public ShopTextAttribute? ShopTexts => Item?.ShopText;

        public CachedLocation(Item location, ReadOnlyCollection<CachedItem> items)
        {
            Location = location;
            LocationHints = new List<string>().AsReadOnly();

            var gossipCombine = new List<GossipCombineAttribute>();
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
                    case DungeonEntranceAttribute attr:
                        DungeonEntrance = attr;
                        break;
                    case EntranceNameAttribute attr:
                        EntranceName = attr.Name;
                        break;
                    case GetBottleItemIndicesAttribute attr:
                        GetBottleItemIndices = attr;
                        break;
                    case GetItemIndexAttribute attr:
                        GetItemIndex = attr.Index;
                        break;
                    case GossipCombineAttribute attr:
                        gossipCombine.Add(attr);
                        break;
                    case GossipCombineOrderAttribute attr:
                        GossipCombineOrder = attr.Order;
                        break;
                    case GossipCompetitiveHintAttribute attr:
                        GossipCompetitiveHint = attr;
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
                    case RequiresConsumableAttribute attr:
                        RequiresConsumable = attr;
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
                    case VisibleAttribute:
                        IsVisible = true;
                        break;
                };
            }

            GossipCombine = gossipCombine.AsReadOnly();
            ShopInventory = shopInventories.AsReadOnly();
            ShopRoom = shopRooms.AsReadOnly();
        }

        public static CachedLocation[] Build(ReadOnlyCollection<CachedItem> items)
        {
            return Enumerate(items).ToArray();
        }

        static IEnumerable<CachedLocation> Enumerate(ReadOnlyCollection<CachedItem> items)
        {
            foreach (var value in Enum.GetValues(typeof(Item)))
            {
                var location = (Item)value;
                var cached = new CachedLocation(location, items);
                yield return cached;
            }
        }

        public bool Equals(CachedLocation? other) => other != null ? Location == other.Location : false;

        public override int GetHashCode() => (int)Location;

        /// <summary>
        /// Get the progressive upgrade name if progressive upgrades are enabled. If not enabled or not a progressive upgrade, return the location name.
        /// </summary>
        /// <param name="progressiveUpgradesEnabled">Whether or not progressive upgrades are enabled.</param>
        /// <returns></returns>
        public string? ProgressiveUpgradeName(bool progressiveUpgradesEnabled)
        {
            if (progressiveUpgradesEnabled && Item != null && Item.Upgrade != null)
            {
                return Item.Upgrade.Type switch
                {
                    UpgradeType.BombBag => "Bomb Bag Upgrade",
                    UpgradeType.BowQuiver => "Bow Upgrade",
                    UpgradeType.Magic => "Magic Upgrade",
                    UpgradeType.Sword => "Sword Upgrade",
                    UpgradeType.Wallet => "Wallet Upgrade",
                    _ => Item.Name,
                };
            }
            return Item?.Name;
        }
    }
}
