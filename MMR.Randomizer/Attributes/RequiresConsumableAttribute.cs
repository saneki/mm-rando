using MMR.Randomizer.GameObjects;
using System;

namespace MMR.Randomizer.Attributes
{
    /// <summary>
    /// Describes consumables required for a specific <see cref="Item"/> if bring-your-own-ammo is enabled.
    /// </summary>
    public class RequiresConsumableAttribute : Attribute
    {
        public int Amount { get; }
        public ConsumableType Type { get; }

        public RequiresConsumableAttribute(ConsumableType type, int amount)
        {
            Amount = amount;
            Type = type;
        }
    }
}
