namespace MMR.Randomizer.Skulltula.Models
{
    /// <summary>
    /// Describes information about a Skullwalltula location in scene, written to <see cref="SpiderSceneConfigStruct"/>.
    /// </summary>
    public struct SpiderInfo
    {
        /// <summary>
        /// Room index.
        /// </summary>
        public byte Room { get; }

        /// <summary>
        /// First flags byte.
        /// </summary>
        public byte Flags1 { get; }

        /// <summary>
        /// Second flags byte (currently unused).
        /// </summary>
        public byte Flags2 { get; }

        /// <summary>
        /// Third flags byte (currently unused).
        /// </summary>
        public byte Flags3 { get; }

        public SpiderInfo(byte room, SpiderTime time)
        {
            this.Room = room;

            // Build flags1.
            byte flags1 = 0;
            flags1 |= (byte)((time == SpiderTime.Night ? 1 : 0) << 7);
            this.Flags1 = flags1;

            // Set unused flags to 0.
            this.Flags2 = this.Flags3 = 0;
        }

        /// <summary>
        /// Create <see cref="SpiderInfo"/> from an existing <see cref="SpiderLocation"/>.
        /// </summary>
        /// <param name="location">Skullwalltula location.</param>
        /// <returns><see cref="SpiderInfo"/>.</returns>
        public static SpiderInfo From(SpiderLocation location)
        {
            var room = location.Room;
            var time = location.Time;
            return new SpiderInfo(room, time);
        }

        public byte[] ToBytes()
        {
            return new byte[4] {
                this.Room,
                this.Flags1,
                this.Flags2,
                this.Flags3,
            };
        }
    }
}
