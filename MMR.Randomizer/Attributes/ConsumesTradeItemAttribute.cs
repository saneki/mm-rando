using MMR.Randomizer.GameObjects;
using System;

namespace MMR.Randomizer.Attributes
{
    /// <summary>
    /// Describes a <see cref="Item"/> which consumes a trade item.
    /// </summary>
    public class ConsumesTradeItemAttribute : Attribute
    {
        /// <summary>
        /// Trade item which is consumed.
        /// </summary>
        public ProvidedItem TradeItem { get; }

        public ConsumesTradeItemAttribute(ProvidedItem tradeItem)
        {
            TradeItem = tradeItem;
        }
    }
}
