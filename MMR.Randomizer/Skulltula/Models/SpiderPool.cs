namespace MMR.Randomizer.Skulltula.Models
{
    public class SpiderPool
    {
        /// <summary>
        /// Pool identifier, relative to scene.
        /// </summary>
        public byte Id { get; }

        /// <summary>
        /// Max number of Skullwalltula locations which can be chosen from this pool by default.
        /// </summary>
        public byte MaxAmount { get; }

        /// <summary>
        /// Name of pool.
        /// </summary>
        public string Name { get; }

        public SpiderPool(byte id, byte maxAmount, string name)
            => (Id, MaxAmount, Name) = (id, maxAmount, name);
    }
}
