using MMR.Randomizer.Models;
using MMR.Randomizer.Utils;

namespace MMR.Randomizer.Extensions
{
    public static class ItemObjectExtensions
    {
        public static string GetArticle(this ItemObject itemObject, string indefiniteArticle = null)
        {
            return MessageUtils.GetArticle(itemObject.DisplayItem, indefiniteArticle).SurroundWithCommandCheckGetItemReplaceArticle(itemObject.NewLocation.Value);
        }

        public static string NameForMessage(this ItemObject itemObject)
        {
            return itemObject.Item.NameForMessage(itemObject.NewLocation.Value, itemObject.Mimic);
        }

        public static string DisplayNameWithoutReplacement(this ItemObject itemObject)
        {
            return itemObject.Mimic?.FakeName ?? itemObject.Mimic?.Item.Name() ?? itemObject.Item.Name();
        }

        public static string AlternateNameForMessage(this ItemObject itemObject)
        {
            return MessageUtils.GetAlternateName(itemObject.DisplayItem).SurroundWithCommandCheckGetItemReplaceItemName(itemObject.NewLocation.Value);
        }

        public static string GetPronounOrAmount(this ItemObject itemObject, string it = " It")
        {
            return MessageUtils.GetPronounOrAmount(itemObject.DisplayItem, it).SurroundWithCommandCheckGetItemReplaceAmount(itemObject.NewLocation.Value);
        }

        public static string GetPronoun(this ItemObject itemObject)
        {
            return MessageUtils.GetPronoun(itemObject.DisplayItem).SurroundWithCommandCheckGetItemReplacePronoun(itemObject.NewLocation.Value);
        }

        public static string GetVerb(this ItemObject itemObject)
        {
            return MessageUtils.GetVerb(itemObject.DisplayItem).SurroundWithCommandCheckGetItemReplaceVerb(itemObject.NewLocation.Value);
        }
    }
}
