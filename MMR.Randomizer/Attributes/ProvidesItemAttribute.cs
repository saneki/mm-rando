using MMR.Randomizer.GameObjects;
using System;

namespace MMR.Randomizer.Attributes
{
    public class ProvidesItemAttribute : Attribute
    {
        public ProvidedItem Item { get; }

        public ProvidesItemAttribute(ProvidedItem item)
        {
            Item = item;
        }
    }
}
