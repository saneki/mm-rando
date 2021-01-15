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
    /// Cached record describing a <see cref="Item"/> using information provided via reflection.
    /// </summary>
    public sealed record CachedLocation
    {
        public readonly ChestAttribute? Chest;
        public readonly ChestType? ChestType;
        public readonly CachedItem? ConsumesTradeItem;
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
        public readonly CachedItem? ProvidedItem;
        public readonly Item Id;
        public readonly ReadOnlyCollection<string> LocationHints;
        public readonly string? LocationName;
        public readonly Region? Region;
        public readonly RequiresConsumableAttribute? RequiresConsumable;
        public readonly ReadOnlyCollection<ShopInventoryAttribute> ShopInventory;
        public readonly ReadOnlyCollection<ShopRoomAttribute> ShopRoom;

        /// <summary>
        /// Whether or not this <see cref="CachedLocation"/> consumes toilet paper.
        /// </summary>
        public bool ConsumesToiletPaper => Id == Item.HeartPieceNotebookHand;

        /// <summary>
        /// Get <see cref="GameObjects.DungeonEntrance"/> values.
        /// </summary>
        public IList<DungeonEntrance>? DungeonEntrances => DungeonEntrance?.Entrances();

        /// <summary>
        /// Get <see cref="GetItemInfo"/> of attached <see cref="CachedItem"/>.
        /// </summary>
        public GetItemInfo? GetItem => ProvidedItem?.GetItem;

        /// <summary>
        /// Whether or not this location has an attached <see cref="CachedItem"/> which is downgradable.
        /// </summary>
        public bool IsDowngradable => ProvidedItem != null && ProvidedItem.IsDowngradable;

        /// <summary>
        /// Whether or not this location has an attached <see cref="CachedItem"/> which has a <see cref="GetItemInfo"/>.
        /// </summary>
        public bool HasGetItem => ProvidedItem != null && ProvidedItem.GetItem != null;

        /// <summary>
        /// Whether or not this location has an attached <see cref="CachedItem"/>.
        /// </summary>
        public bool IsFake => ProvidedItem == null;

        /// <summary>
        /// Whether or not this location has an attached <see cref="CachedItem"/> which is progressive.
        /// </summary>
        public bool IsProgressive => ProvidedItem != null && ProvidedItem.IsProgressive;

        /// <summary>
        /// Whether or not this location has any <see cref="ShopRoomAttribute"/> attributes.
        /// </summary>
        public bool IsShop => ShopRoom.Count > 0;

        /// <summary>
        /// Get hints of attached <see cref="CachedItem"/>.
        /// </summary>
        public ReadOnlyCollection<string>? ItemHints => ProvidedItem?.Hints;

        /// <summary>
        /// Get the name of attached <see cref="CachedItem"/>.
        /// </summary>
        public string? Name => ProvidedItem?.Name;

        /// <summary>
        /// Get <see cref="ShopTextAttribute"/> of attached <see cref="CachedItem"/>.
        /// </summary>
        public ShopTextAttribute? ShopTexts => ProvidedItem?.ShopText;

        public CachedLocation(Item location, ReadOnlyCollection<CachedItem> items)
        {
            Id = location;
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
                    case ConsumesTradeItemAttribute attr:
                        ConsumesTradeItem = items[(int)attr.TradeItem];
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
                        ProvidedItem = items[(int)attr.Item];
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

        public bool Equals(CachedLocation? other) => other != null ? Id == other.Id : false;

        public override int GetHashCode() => (int)Id;

        /// <summary>
        /// Get the progressive upgrade name if progressive upgrades are enabled. If not enabled or not a progressive upgrade, return the location name.
        /// </summary>
        /// <param name="progressiveUpgradesEnabled">Whether or not progressive upgrades are enabled.</param>
        /// <returns></returns>
        public string? ProgressiveUpgradeName(bool progressiveUpgradesEnabled)
        {
            if (progressiveUpgradesEnabled && ProvidedItem != null && ProvidedItem.Upgrade != null)
            {
                return ProvidedItem.Upgrade.Type switch
                {
                    UpgradeType.BombBag => "Bomb Bag Upgrade",
                    UpgradeType.BowQuiver => "Bow Upgrade",
                    UpgradeType.Magic => "Magic Upgrade",
                    UpgradeType.Sword => "Sword Upgrade",
                    UpgradeType.Wallet => "Wallet Upgrade",
                    _ => ProvidedItem.Name,
                };
            }
            return ProvidedItem?.Name;
        }
    }
}
