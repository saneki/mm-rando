using System;

namespace MMR.Randomizer.Skulltula.Models.Rom
{
    /// <summary>
    /// Path entry containing node count and segmented address of path nodes.
    /// </summary>
    public struct PathEntry
    {
        /// <summary>
        /// Count of nodes in path.
        /// </summary>
        public byte Count { get; }

        /// <summary>
        /// Segmented address to path nodes.
        /// </summary>
        public uint SegmentedAddress { get; }

        public PathEntry(byte count, uint segmentedAddress) => (Count, SegmentedAddress) = (count, segmentedAddress);

        public byte[] ToBytes()
        {
            var result = new byte[8];
            // Write count byte with 0xFF,0xFF,0xFF.
            result[0] = this.Count;
            result[1] = result[2] = result[3] = 0xFF;
            // Write address to buffer as big-endian.
            var addressBytes = BitConverter.GetBytes(this.SegmentedAddress);
            result[4] = addressBytes[3];
            result[5] = addressBytes[2];
            result[6] = addressBytes[1];
            result[7] = addressBytes[0];
            return result;
        }
    }
}
