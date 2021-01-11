using MMR.Common.Extensions;
using MMR.Randomizer.Attributes;
using MMR.Randomizer.GameObjects;
using MMR.Randomizer.Models.Rom;
using System.Collections.Generic;

namespace MMR.Randomizer.Extensions
{
    public static class ProvidedItemExtensions
    {
        public static ChestTypeAttribute.ChestType ChestType(this ProvidedItem item)
        {
            return item.GetAttribute<ChestTypeAttribute>().Type;
        }

        public static GetItemEntry ExclusiveItemEntry(this ProvidedItem item)
        {
            return new GetItemEntry
            {
                ItemGained = item.GetAttribute<ExclusiveItemAttribute>().Item,
                Flag = item.GetAttribute<ExclusiveItemAttribute>().Flags,
                Index = item.GetAttribute<ExclusiveItemGraphicAttribute>().Graphic,
                Type = item.GetAttribute<ExclusiveItemAttribute>().Type,
                Message = (short)item.GetAttribute<ExclusiveItemMessageAttribute>().Id,
                Object = (short)item.GetAttribute<ExclusiveItemGraphicAttribute>().Object,
            };
        }

        public static string ExclusiveItemMessage(this ProvidedItem item)
        {
            return item.GetAttribute<ExclusiveItemMessageAttribute>().Message;
        }

        public static string[] Hints(this ProvidedItem item)
        {
            return item.GetAttribute<GossipItemHintAttribute>().Values;
        }

        public static bool IsDowngradable(this ProvidedItem item)
        {
            return item.HasAttribute<DowngradableAttribute>();
        }

        public static bool IsExclusiveItem(this ProvidedItem item)
        {
            return item.HasAttribute<ExclusiveItemAttribute>();
        }

        public static bool IsProgressive(this ProvidedItem item)
        {
            return item.HasAttribute<ProgressiveAttribute>();
        }

        public static string Name(this ProvidedItem item)
        {
            return item.GetAttribute<ItemNameAttribute>()?.Name;
        }

        public static bool IsStarting(this ProvidedItem item)
        {
            return item.HasAttribute<StartingItemAttribute>()
                || item.HasAttribute<StartingItemIdAttribute>()
                || item.HasAttribute<StartingTingleMapAttribute>();
        }

        public static ShopTextAttribute ShopTexts(this ProvidedItem item)
        {
            return item.GetAttribute<ShopTextAttribute>();
        }

        public static IEnumerable<StartingItemAttribute> StartingItems(this ProvidedItem item)
        {
            return item.GetAttributes<StartingItemAttribute>();
        }

        public static StartingTingleMapAttribute StartingTingleMap(this ProvidedItem item)
        {
            return item.GetAttribute<StartingTingleMapAttribute>();
        }
    }
}
