using MMR.Randomizer.GameObjects;
using System;

namespace MMR.Randomizer.Attributes
{
    public class ChestTypeAttribute : Attribute
    {
        public ChestType Type { get; private set; }

        public ChestTypeAttribute(ChestType type)
        {
            Type = type;
        }
    }
}
