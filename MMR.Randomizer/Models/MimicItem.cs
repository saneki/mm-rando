using MMR.Randomizer.Attributes;
using MMR.Randomizer.Extensions;
using MMR.Randomizer.GameObjects;
using System;

namespace MMR.Randomizer.Models
{
    public class MimicItem : IEquatable<MimicItem>
    {
        /// <summary>
        /// Underlying item used as mimic.
        /// </summary>
        public Item Item { get; }

        /// <summary>
        /// Mimic item name.
        /// </summary>
        public string Name { get; }

        /// <summary>
        /// Fake shop name.
        /// </summary>
        public string ShopName { get; set; }

        /// <summary>
        /// Chest type override.
        /// </summary>
        public ChestTypeAttribute.ChestType? ChestType { get; set; }

        public MimicItem(Item item, string name)
        {
            this.Item = item;
            this.Name = name;
        }

        /// <summary>
        /// Resolve <see cref="ItemGraphic"/> from <see cref="RomData"/> get-item list using index.
        /// </summary>
        /// <returns>Resolved item graphic.</returns>
        public ItemGraphic ResolveGraphic()
        {
            var index = this.Item.GetItemIndex().Value;
            var getItem = RomData.GetItemList[index];
            return new ItemGraphic(getItem.Index, (ushort)getItem.Object);
        }

        public override int GetHashCode()
        {
            return Name.GetHashCode();
        }

        public override bool Equals(object obj)
        {
            return obj is MimicItem && Equals((MimicItem)obj);
        }

        public bool Equals(MimicItem other)
        {
            return Name.Equals(other.Name);
        }
    }
}
