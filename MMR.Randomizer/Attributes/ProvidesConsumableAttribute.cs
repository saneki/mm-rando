using MMR.Randomizer.GameObjects;
using System;

namespace MMR.Randomizer.Attributes
{
    /// <summary>
    /// Describes any consumables provided by an <see cref="ProvidedItem"/>.
    /// </summary>
    public class ProvidesConsumableAttribute : Attribute
    {
        public int Amount { get; }
        public ConsumableType Type { get; }

        public ProvidesConsumableAttribute(ConsumableType type, int amount)
        {
            Amount = amount;
            Type = type;
        }
    }
}
