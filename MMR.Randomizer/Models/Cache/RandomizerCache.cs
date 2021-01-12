using MMR.Randomizer.GameObjects;
using System.Collections.ObjectModel;

namespace MMR.Randomizer.Models.Cache
{
    public class RandomizerCache
    {
        // TODO: Have a Task to initialize cache and set default.
        public static readonly RandomizerCache Default = Create();

        /// <summary>
        /// Cached information about items.
        /// </summary>
        public readonly ReadOnlyCollection<CachedItem> Items;

        /// <summary>
        /// Cached information about locations.
        /// </summary>
        public readonly ReadOnlyCollection<CachedLocation> Locations;

        public RandomizerCache(CachedItem[] items, CachedLocation[] locations)
        {
            Items = new ReadOnlyCollection<CachedItem>(items);
            Locations = new ReadOnlyCollection<CachedLocation>(locations);
        }

        /// <summary>
        /// Create <see cref="RandomizerCache"/> via reflection.
        /// </summary>
        /// <returns></returns>
        public static RandomizerCache Create()
        {
            var items = CachedItem.Build();
            var locations = CachedLocation.Build(items);
            return new RandomizerCache(items, locations);
        }

        public CachedItem GetItem(ProvidedItem key)
        {
            return Items[(int)key];
        }

        public CachedLocation GetLocation(Item key)
        {
            return Locations[(int)key];
        }
    }
}
