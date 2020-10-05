using MMR.Randomizer.Models;
using MMR.Randomizer.Utils;

namespace MMR.Randomizer.Extensions
{
    public static class ItemObjectExtensions
    {
        public static string GetArticle(this ItemObject itemObject, string indefiniteArticle = null)
        {
            return MessageUtils.GetArticle(itemObject.Item, indefiniteArticle).SurroundWithCommandCheckGetItemReplaceArticle(itemObject.NewLocation.Value);
        }

        public static string NameForMessage(this ItemObject itemObject)
        {
            return itemObject.Item.Name().SurroundWithCommandCheckGetItemReplaceItemName(itemObject.NewLocation.Value);
        }

        public static string AlternateNameForMessage(this ItemObject itemObject)
        {
            return MessageUtils.GetAlternateName(itemObject.Item).SurroundWithCommandCheckGetItemReplaceItemName(itemObject.NewLocation.Value);
        }

        public static string GetPronounOrAmount(this ItemObject itemObject, string it = " It")
        {
            return MessageUtils.GetPronounOrAmount(itemObject.Item, it).SurroundWithCommandCheckGetItemReplaceAmount(itemObject.NewLocation.Value);
        }

        public static string GetPronoun(this ItemObject itemObject)
        {
            return MessageUtils.GetPronoun(itemObject.Item).SurroundWithCommandCheckGetItemReplacePronoun(itemObject.NewLocation.Value);
        }

        public static string GetVerb(this ItemObject itemObject)
        {
            return MessageUtils.GetVerb(itemObject.Item).SurroundWithCommandCheckGetItemReplaceVerb(itemObject.NewLocation.Value);
        }
    }
}
