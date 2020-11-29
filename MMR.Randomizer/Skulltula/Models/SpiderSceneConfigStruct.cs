using MMR.Randomizer.Asm;
using MMR.Randomizer.Skulltula.Models.Rom;
using MMR.Randomizer.Utils;
using System;
using System.Collections.Generic;
using System.IO;

namespace MMR.Randomizer.Skulltula.Models
{
    /// <summary>
    /// Scene-specific config structure for World Skulltula.
    /// </summary>
    public class SpiderSceneConfigStruct : IAsmConfigStruct
    {
        /// <summary>
        /// Maximum number of Skullwalltula actors per scene.
        /// </summary>
        public const uint MAX_SPIDERS = 0xC;

        /// <summary>
        /// Static size of path node buffer.
        /// </summary>
        public const uint BUFFER_SIZE = 0x100;

        /// <summary>
        /// Full size of config structure when serialized into bytes.
        /// </summary>
        public const uint FULL_SIZE = (MAX_SPIDERS * 12) + BUFFER_SIZE + 4;

        /// <summary>
        /// Number of Skulltula in scene.
        /// </summary>
        public uint SpiderCount;

        /// <summary>
        /// Flags for each Skulltula in scene.
        /// </summary>
        public SpiderInfo[] SpiderInfos { get; } = new SpiderInfo[MAX_SPIDERS];

        /// <summary>
        /// Path buffer bytes.
        /// </summary>
        public byte[] NodeBuffer { get; } = new byte[BUFFER_SIZE];

        /// <summary>
        /// Path entries.
        /// </summary>
        public PathEntry[] PathEntries { get; } = new PathEntry[MAX_SPIDERS];

        public SpiderSceneConfigStruct(IList<SpiderLocation> locations)
        {
            if (locations.Count > MAX_SPIDERS)
            {
                throw new Exception($"Scene cannot have more than {MAX_SPIDERS} Skullwalltula locations.");
            }

            this.SpiderCount = (uint)locations.Count;

            // Build node buffer & entries from location paths.
            var pathbuf = new PathBufferBuilder();
            for (int i = 0; i < locations.Count; i++)
            {
                var location = locations[i];
                // Add path to path buffer.
                pathbuf.Add(location.Paths[0]);
                // Build spider info for this location.
                this.SpiderInfos[i] = SpiderInfo.From(location);
            }
            var (entries, nodeBuffer) = pathbuf.Build();

            // Copy over node buffer & entries.
            Buffer.BlockCopy(nodeBuffer, 0, this.NodeBuffer, 0, nodeBuffer.Length);
            Array.Copy(entries, this.PathEntries, entries.Length);
        }

        public byte[] ToBytes()
        {
            int expectedSize = (int)FULL_SIZE;
            using (var memoryStream = new MemoryStream(expectedSize))
            using (var writer = new BinaryWriter(memoryStream))
            {
                // Write spider count.
                ReadWriteUtils.WriteU32(writer, this.SpiderCount);
                // Write spider info for each spider.
                foreach (var info in this.SpiderInfos)
                {
                    writer.Write(info.ToBytes());
                }
                // Write path buffer bytes.
                writer.Write(this.NodeBuffer);
                // Write each path entry.
                foreach (var pathEntry in this.PathEntries)
                {
                    writer.Write(pathEntry.ToBytes());
                }
                return memoryStream.ToArray();
            }
        }
    }
}
