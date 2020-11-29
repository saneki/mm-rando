using MMR.Randomizer.Asm;
using MMR.Randomizer.Utils;
using System;
using System.IO;

namespace MMR.Randomizer.Skulltula.Models
{
    /// <summary>
    /// Primary configuration structure for World Skulltula feature.
    /// </summary>
    public struct SpiderConfigStruct : IAsmConfigStruct
    {
        /// <summary>
        /// File index of directory file containing scene-specific data for spider locations.
        /// </summary>
        public uint SceneFileIndex { get; }

        /// <summary>
        /// Mapping of file indexes (within directory file) by scene index.
        /// </summary>
        public byte[] SceneFileMapping { get; }

        /// <summary>
        /// Whether or not this config is considered unused.
        /// </summary>
        public bool Unused => this.SceneFileIndex == 0;

        public SpiderConfigStruct(uint sceneFileIndex, byte[] sceneFileMapping)
        {
            this.SceneFileIndex = sceneFileIndex;
            this.SceneFileMapping = new byte[0x74];
            Buffer.BlockCopy(sceneFileMapping, 0, this.SceneFileMapping, 0, sceneFileMapping.Length);
        }

        public byte[] ToBytes()
        {
            using (var memoryStream = new MemoryStream())
            using (var writer = new BinaryWriter(memoryStream))
            {
                ReadWriteUtils.WriteU32(writer, this.SceneFileIndex);
                writer.Write(this.SceneFileMapping);
                return memoryStream.ToArray();
            }
        }
    }
}
