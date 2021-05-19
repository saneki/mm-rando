using MMR.Randomizer.Models.Rom;
using System;
using System.Runtime.CompilerServices;

namespace MMR.Randomizer.Utils
{
    public enum FileIndex : int
    {
        code = 31,
    }

    public static class PatchUtils
    {
        /// <summary>
        /// VRAM load address of <c>code</c> file.
        /// </summary>
        const uint CodeRAMStart = 0x800A5AC0;

        /// <summary>
        /// Get the <see cref="MMFile"/> at a <see cref="FileIndex"/>.
        /// </summary>
        /// <param name="index">File index.</param>
        /// <returns></returns>
        static MMFile GetFile(FileIndex index)
        {
            RomUtils.CheckCompressed((int)index);
            return RomData.MMFileList[(int)index];
        }

        /// <summary>
        /// Write a <c>NOP</c> instruction to the <c>code</c> file.
        /// </summary>
        /// <param name="vram">VRAM address within loaded <c>code</c> file.</param>
        public static void WriteCodeNOP(uint vram)
        {
            WriteCodeUInt32(vram, 0);
        }

        /// <summary>
        /// Write a 32-bit <see cref="uint"/> value to the <c>code</c> file.
        /// </summary>
        /// <param name="vram">VRAM address within loaded <c>code</c> file.</param>
        /// <param name="value">Value to write.</param>
        public static void WriteCodeUInt32(uint vram, uint value)
        {
            var offset = vram - CodeRAMStart;
            var file = GetFile(FileIndex.code);
            var span = new Span<byte>(file.Data);
            var slice = span.Slice((int)offset, 4);
            WriteUInt32(slice, value);
        }

        /// <summary>
        /// Write a 32-bit <see cref="uint"/> value to a <see cref="Span{byte}"/> in big-endian order.
        /// </summary>
        /// <param name="span">Span to write to.</param>
        /// <param name="value">Value to write.</param>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static void WriteUInt32(Span<byte> span, uint value)
        {
            span[0] = (byte)((value >> 24) & 0xFF);
            span[1] = (byte)((value >> 16) & 0xFF);
            span[2] = (byte)((value >> 8) & 0xFF);
            span[3] = (byte)(value & 0xFF);
        }
    }
}
