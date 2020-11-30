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
        /// Flags byte.
        /// </summary>
        public byte Flags { get; }

        /// <summary>
        /// Initial rotation value for Y axis.
        /// </summary>
        public ushort Rotation { get; }

        public SpiderInfo(byte room, ushort rotation, SpiderTime time)
        {
            this.Room = room;
            this.Rotation = rotation;

            // Build flags.
            byte flags = 0;
            flags |= (byte)((time == SpiderTime.Night ? 1 : 0) << 7);
            this.Flags = flags;
        }

        /// <summary>
        /// Create <see cref="SpiderInfo"/> from an existing <see cref="SpiderLocation"/>.
        /// </summary>
        /// <param name="location">Skullwalltula location.</param>
        /// <returns><see cref="SpiderInfo"/>.</returns>
        public static SpiderInfo From(SpiderLocation location)
        {
            var room = location.Room;
            var rotation = location.Rotation;
            var time = location.Time;
            return new SpiderInfo(room, rotation, time);
        }

        public byte[] ToBytes()
        {
            return new byte[4] {
                this.Room,
                this.Flags,
                (byte)(this.Rotation >> 8),
                (byte)(this.Rotation & 0xFF),
            };
        }
    }
}
