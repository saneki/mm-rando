#nullable enable

using MMR.Common.Extensions;
using MMR.Randomizer.Attributes;
using MMR.Randomizer.GameObjects;
using MMR.Randomizer.Models.Attributes;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;

namespace MMR.Randomizer.Models.Cache
{
    /// <summary>
    /// Cached struct describing a <see cref="ProvidedItem"/> using information provided via reflection.
    /// </summary>
    public sealed record CachedItem
    {
        public readonly ChestType? ChestType;
        public readonly ProvidesConsumableAttribute? Consumable;
        public readonly GetItemInfo? GetItem;
        public readonly ReadOnlyCollection<string> Hints;
        public readonly bool IsDowngradable;
        public readonly bool IsProgressive;
        public readonly bool IsToiletPaper;
        public readonly ProvidedItem Id;
        public readonly string? Name;
        public readonly ShopTextAttribute? ShopText;
        public readonly ReadOnlyCollection<StartingItemAttribute> StartingItems;
        public readonly ReadOnlyCollection<byte> StartingItemIds;
        public readonly TingleMap? StartingTingleMap;
        public readonly ProvidesUpgradeAttribute? Upgrade;

        public CachedItem(ProvidedItem item)
        {
            Id = item;
            Hints = new List<string>().AsReadOnly();

            // Iterate attributes to update fields.
            var startingItems = new List<StartingItemAttribute>();
            var startingItemIds = new List<byte>();
            foreach (var attribute in item.GetAttributes())
            {
                switch (attribute)
                {
                    case ChestTypeAttribute attr:
                        ChestType = attr.Type;
                        break;
                    case GetItemEntryAttribute attr:
                        GetItem = new GetItemInfo(attr);
                        break;
                    case DowngradableAttribute:
                        IsDowngradable = true;
                        break;
                    case GossipItemHintAttribute attr:
                        Hints = new ReadOnlyCollection<string>(attr.Values);
                        break;
                    case ItemNameAttribute attr:
                        Name = attr.Name;
                        break;
                    case ProgressiveAttribute:
                        IsProgressive = true;
                        break;
                    case ProvidesConsumableAttribute attr:
                        Consumable = attr;
                        break;
                    case ProvidesToiletPaperAttribute:
                        IsToiletPaper = true;
                        break;
                    case ProvidesUpgradeAttribute attr:
                        Upgrade = attr;
                        break;
                    case ShopTextAttribute attr:
                        ShopText = attr;
                        break;
                    case StartingItemAttribute attr:
                        startingItems.Add(attr);
                        break;
                    case StartingItemIdAttribute attr:
                        startingItemIds.Add(attr.ItemId);
                        break;
                    case StartingTingleMapAttribute attr:
                        StartingTingleMap = attr.TingleMap;
                        break;
                }
            }

            StartingItems = startingItems.AsReadOnly();
            StartingItemIds = startingItemIds.AsReadOnly();
        }

        public static CachedItem[] Build()
        {
            return Enumerate().ToArray();
        }

        static IEnumerable<CachedItem> Enumerate()
        {
            foreach (var value in Enum.GetValues(typeof(ProvidedItem)))
            {
                var item = (ProvidedItem)value;
                var cached = new CachedItem(item);
                yield return cached;
            }
        }

        public bool Equals(CachedItem? other) => other != null ? Id == other.Id : false;

        public override int GetHashCode() => (int)Id;
    }
}
