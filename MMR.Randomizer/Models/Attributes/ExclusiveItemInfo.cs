#nullable enable

using System;
using MMR.Randomizer.Attributes;
using MMR.Randomizer.Models.Rom;

namespace MMR.Randomizer.Models.Attributes
{
    public readonly struct ExclusiveItemInfo
    {
        public readonly GetItemEntry Entry;

        public ExclusiveItemInfo(
            ExclusiveItemAttribute attribute,
            ExclusiveItemGraphicAttribute graphicAttribute,
            ExclusiveItemMessageAttribute messageAttribute)
        {
            Entry = new GetItemEntry
            {
                ItemGained = attribute.Item,
                Flag = attribute.Flags,
                Index = graphicAttribute.Graphic,
                Type = attribute.Type,
                Message = (short)messageAttribute.Id,
                Object = (short)graphicAttribute.Object,
            };
        }

        /// <summary>
        /// Create using the necessary <see cref="Attribute"/> inputs, or return <see cref="null"/> if any inputs are null.
        /// </summary>
        /// <param name="attribute"></param>
        /// <param name="graphicAttribute"></param>
        /// <param name="messageAttribute"></param>
        /// <returns></returns>
        public static ExclusiveItemInfo? CreateOrNull(
            ExclusiveItemAttribute? attribute,
            ExclusiveItemGraphicAttribute? graphicAttribute,
            ExclusiveItemMessageAttribute? messageAttribute)
        {
            if (attribute != null && graphicAttribute != null && messageAttribute != null)
            {
                return new ExclusiveItemInfo(attribute, graphicAttribute, messageAttribute);
            }
            return null;
        }
    }
}
