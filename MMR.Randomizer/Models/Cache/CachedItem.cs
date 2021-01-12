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
    public record CachedItem
    {
        public readonly ChestType? ChestType;
        public readonly ExclusiveItemInfo? ExclusiveItem;
        public readonly ReadOnlyCollection<string> Hints;
        public readonly bool IsDowngradable;
        public readonly bool IsProgressive;
        public readonly ProvidedItem Item;
        public readonly string? Name;
        public readonly ShopTextAttribute? ShopText;
        public readonly ReadOnlyCollection<StartingItemAttribute> StartingItems;
        public readonly ReadOnlyCollection<byte> StartingItemIds;
        public readonly TingleMap? StartingTingleMap;

        public CachedItem(ProvidedItem item)
        {
            Hints = new ReadOnlyCollection<string>(new string[0]);

            ExclusiveItemAttribute? exclusiveItemAttribute = null;
            ExclusiveItemGraphicAttribute? exclusiveItemGraphicAttribute = null;
            ExclusiveItemMessageAttribute? exclusiveItemMessageAttribute = null;

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
                    case DowngradableAttribute:
                        IsDowngradable = true;
                        break;
                    case ExclusiveItemAttribute attr:
                        exclusiveItemAttribute = attr;
                        break;
                    case ExclusiveItemGraphicAttribute attr:
                        exclusiveItemGraphicAttribute = attr;
                        break;
                    case ExclusiveItemMessageAttribute attr:
                        exclusiveItemMessageAttribute = attr;
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

            ExclusiveItem = ExclusiveItemInfo.CreateOrNull(exclusiveItemAttribute, exclusiveItemGraphicAttribute, exclusiveItemMessageAttribute);
            StartingItems = new ReadOnlyCollection<StartingItemAttribute>(startingItems);
            StartingItemIds = new ReadOnlyCollection<byte>(startingItemIds);
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
    }
}
