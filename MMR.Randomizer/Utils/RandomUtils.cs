using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace MMR.Randomizer.Utils
{
    public class RandomUtils
    {
        /// <summary>
        /// Select a random item from an array.
        /// </summary>
        /// <typeparam name="T">Array type</typeparam>
        /// <param name="items">Array</param>
        /// <param name="random">Random</param>
        /// <returns>Random item</returns>
        public static T Select<T>(T[] items, Random random)
        {
            var index = random.Next(items.Length);
            return items[index];
        }

        /// <summary>
        /// Select unique random items from a given array.
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="items">Source items array</param>
        /// <param name="amount">Selection amount</param>
        /// <param name="random">Random</param>
        /// <returns>Selected items</returns>
        public static T[] Select<T>(T[] items, int amount, Random random)
        {
            if (amount > items.Length)
            {
                throw new IndexOutOfRangeException("Selection amount cannot exceed array length.");
            }

            var result = new List<T>(amount);
            var source = items.ToList();
            for (int i = 0; i < amount; i++)
            {
                var index = random.Next(source.Count);
                var selected = source[index];
                result.Add(selected);
                source.RemoveAt(index);
            }

            return result.ToArray();
        }

        /// <summary>
        /// Generate a random color.
        /// </summary>
        /// <param name="random">Random</param>
        /// <returns>Color</returns>
        public static Color GetRandomColor(Random random)
        {
            var bytes = new byte[3];
            random.NextBytes(bytes);
            return Color.FromArgb(bytes[0], bytes[1], bytes[2]);
        }
    }
}
