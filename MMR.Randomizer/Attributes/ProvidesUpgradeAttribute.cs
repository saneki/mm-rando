using MMR.Randomizer.GameObjects;
using System;

namespace MMR.Randomizer.Attributes
{
    /// <summary>
    /// Describes which upgrade is provided by an <see cref="ProvidedItem"/>.
    /// </summary>
    public class ProvidesUpgradeAttribute : Attribute
    {
        public int Level { get; }
        public UpgradeType Type { get; }

        public ProvidesUpgradeAttribute(UpgradeType type, int level)
        {
            Level = level;
            Type = type;
        }
    }
}
