using MMR.Randomizer.GameObjects;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MMR.Randomizer.Attributes
{
    public class ChestAttribute : Attribute
    {
        public int[] Addresses { get; private set; }
        public ChestAppearanceType Type { get; private set; }

        public ChestAttribute(int address, ChestAppearanceType type = ChestAppearanceType.Normal, params int[] additionalAddresses)
        {
            Addresses = additionalAddresses.Concat(new[] { address }).ToArray();
            Type = type;
        }

        public static byte GetType(ChestType chestType, ChestAppearanceType appearanceType)
        {
            var type = (byte)chestType;
            type <<= 2;
            type += (byte)appearanceType;
            return type;
        }
    }

    public class GrottoChestAttribute : Attribute
    {
        public int[] Addresses { get; private set; }

        public GrottoChestAttribute(params int[] addresses)
        {
            Addresses = addresses;
        }
    }
}
