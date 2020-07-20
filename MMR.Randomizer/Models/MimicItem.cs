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
        /// Mimic item graphic.
        /// </summary>
        public ItemGraphic Graphic { get; }

        /// <summary>
        /// Mimic item name.
        /// </summary>
        public string Name { get; }

        /// <summary>
        /// Fake shop name.
        /// </summary>
        public string ShopName { get; set; }

        public MimicItem(Item item, string name, ItemGraphic graphic)
        {
            this.Item = item;
            this.Name = name;
            this.Graphic = graphic;
        }

        public override int GetHashCode()
        {
            return Graphic.GetHashCode();
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
