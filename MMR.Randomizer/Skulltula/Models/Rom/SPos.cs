namespace MMR.Randomizer.Skulltula.Models.Rom
{
    /// <summary>
    /// Position with signed 16-bit coordinate values.
    /// </summary>
    public struct SPos
    {
        /// <summary>
        /// X coordinate value.
        /// </summary>
        public short X { get; }

        /// <summary>
        /// Y coordinate value.
        /// </summary>
        public short Y { get; }

        /// <summary>
        /// Z coordinate value.
        /// </summary>
        public short Z { get; }

        /// <summary>
        /// Get X, Y and Z coordinate values in array.
        /// </summary>
        public short[] Values => new short[] { X, Y, Z };

        public SPos(short x, short y, short z) => (X, Y, Z) = (x, y, z);

        public static SPos From(short[] values)
        {
            return new SPos(values[0], values[1], values[2]);
        }

        public static SPos From(ushort[] values)
        {
            return new SPos((short)values[0], (short)values[1], (short)values[2]);
        }

        public static SPos From((short, short, short) values)
        {
            return new SPos(values.Item1, values.Item2, values.Item3);
        }

        public static SPos From((ushort, ushort, ushort) values)
        {
            return new SPos((short)values.Item1, (short)values.Item2, (short)values.Item3);
        }

        public byte[] ToBytes()
        {
            var result = new byte[6];
            result[0] = (byte)(this.X >> 8);
            result[1] = (byte)(this.X & 0xFF);
            result[2] = (byte)(this.Y >> 8);
            result[3] = (byte)(this.Y & 0xFF);
            result[4] = (byte)(this.Z >> 8);
            result[5] = (byte)(this.Z & 0xFF);
            return result;
        }
    }
}
