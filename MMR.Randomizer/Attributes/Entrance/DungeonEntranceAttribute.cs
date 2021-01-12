using MMR.Randomizer.GameObjects;
using System;
using System.Collections.Generic;
using System.Text;

namespace MMR.Randomizer.Attributes.Entrance
{
    public class DungeonEntranceAttribute : Attribute
    {
        public DungeonEntrance Entrance { get; }
        public DungeonEntrance? Pair { get; }

        public DungeonEntranceAttribute(DungeonEntrance entrance)
        {
            Entrance = entrance;
        }

        public DungeonEntranceAttribute(DungeonEntrance entrance, DungeonEntrance pair)
        {
            Entrance = entrance;
            Pair = pair;
        }

        /// <summary>
        /// Get <see cref="DungeonEntrance"/> values as an <see cref="IList{DungeonEntrance}"/>.
        /// </summary>
        /// <returns></returns>
        public IList<DungeonEntrance> Entrances()
        {
            var list = new List<DungeonEntrance>();
            list.Add(Entrance);
            if (Pair.HasValue)
            {
                list.Add(Pair.Value);
            }
            return list;
        }
    }
}
