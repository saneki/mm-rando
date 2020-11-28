using System;

namespace MMR.Randomizer.Models.Rom
{
    /// <summary>
    /// Scene restriction value.
    /// </summary>
    /// <remarks>Table is located at 0x801BF6C0 in RDRAM.</remarks>
    public class SceneRestrictions
    {
        /// <summary>
        /// Scene Id byte.
        /// </summary>
        public byte SceneId { get; }

        /// <summary>
        /// Restriction values converted to how they are in HUD context.
        /// </summary>
        public byte[] Flags { get; } = new byte[12];

        /// <summary>
        /// Construct <see cref="SceneRestrictions"/> from a raw <see cref="uint"/> value.
        /// </summary>
        /// <param name="raw">Raw <see cref="uint"/> value</param>
        public SceneRestrictions(uint raw)
        {
            this.SceneId = (byte)(raw >> 24);
            for (int i = 0; i < this.Flags.Length; i++)
            {
                int shift = 22 - (i * 2);
                this.Flags[i] = (byte)((raw >> shift) & 3);
            }
        }

        /// <summary>
        /// Validate length of restriction flags array.
        /// </summary>
        void ValidateFlags()
        {
            if (this.Flags.Length != 12)
            {
                throw new IndexOutOfRangeException("Flags byte array length must be exactly 12");
            }
        }

        /// <summary>
        /// Convert to a raw <see cref="uint"/> value.
        /// </summary>
        /// <returns>Raw <see cref="uint"/> value.</returns>
        public uint ToUint()
        {
            // Validate flags before using to convert.
            this.ValidateFlags();

            uint result = 0;
            result |= (uint)this.SceneId << 24;
            for (int i = 0; i < this.Flags.Length; i++)
            {
                // Each flag is two bits.
                int shift = (22 - (i * 2));
                result |= ((uint)this.Flags[i] & 3) << shift;
            }
            return result;
        }
    }
}
