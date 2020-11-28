using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using MMR.Randomizer.Utils;

namespace MMR.Randomizer.Models.Rom
{
    /// <summary>
    /// Table of <see cref="SceneRestrictions"/>.
    /// </summary>
    public class SceneRestrictionsTable
    {
        /// <summary>
        /// Total number of scene restriction <see cref="uint"/> values in game.
        /// </summary>
        public const uint COUNT = 0x71;

        /// <summary>
        /// Offset of table in code file.
        /// </summary>
        public const int TABLE_OFFSET = 0x119C00;

        /// <summary>
        /// ROM virtual address for table.
        /// </summary>
        public const int VROM_ADDRESS = 0xB3C000 + TABLE_OFFSET;

        /// <summary>
        /// Underlying entries.
        /// </summary>
        List<SceneRestrictions> _entries = new List<SceneRestrictions>();

        SceneRestrictionsTable()
        {
        }

        /// <summary>
        /// Get <see cref="SceneRestrictions"/> for the specified scene.
        /// </summary>
        /// <param name="scene">Scene Id</param>
        /// <returns>Restrictions.</returns>
        public SceneRestrictions this[byte scene]
        {
            get { return _entries.First(x => x.SceneId == scene); }
        }

        /// <summary>
        /// Serialize to bytes.
        /// </summary>
        /// <returns>Bytes.</returns>
        public byte[] ToBytes()
        {
            int size = _entries.Count * 4;
            using (var memoryStream = new MemoryStream(size))
            using (var writer = new BinaryWriter(memoryStream))
            {
                for (int i = 0; i < _entries.Count; i++)
                {
                    var value = _entries[i].ToUint();
                    var bytes = BitConverter.GetBytes(value);
                    Array.Reverse(bytes);
                    writer.Write(bytes);
                }
                return memoryStream.ToArray();
            }
        }

        /// <summary>
        /// Write to ROM.
        /// </summary>
        /// <param name="address">ROM virtual address</param>
        public void WriteToROM(int address = VROM_ADDRESS)
        {
            var bytes = this.ToBytes();
            ReadWriteUtils.WriteToROM(address, bytes);
        }

        /// <summary>
        /// Read <see cref="SceneRestrictionsTable"/> from bytes.
        /// </summary>
        /// <param name="bytes">Bytes</param>
        /// <returns>Table.</returns>
        public static SceneRestrictionsTable FromBytes(byte[] bytes)
        {
            var table = new SceneRestrictionsTable();
            for (uint i = 0; i < bytes.Length / 4; i++)
            {
                int offset = (int)i * 4;
                uint raw = ReadWriteUtils.Arr_ReadU32(bytes, offset);
                var entry = new SceneRestrictions(raw);
                table._entries.Add(entry);
            }
            return table;
        }

        /// <summary>
        /// Read <see cref="SceneRestrictionsTable"/> from location in ROM.
        /// </summary>
        /// <param name="address">ROM virtual address</param>
        /// <param name="count">Number of entries to read</param>
        /// <returns>Table.</returns>
        public static SceneRestrictionsTable ReadFromROM(int address = VROM_ADDRESS, uint count = COUNT)
        {
            var bytes = ReadWriteUtils.ReadBytes(address, count * 4);
            return FromBytes(bytes);
        }
    }
}
