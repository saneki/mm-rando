using MMR.Randomizer.Skulltula.Models.Rom;
using System.Collections.Generic;
using System.IO;

namespace MMR.Randomizer.Skulltula
{
    /// <summary>
    /// Builder for path buffers.
    /// </summary>
    public class PathBufferBuilder
    {
        private List<ActorPath> _paths = new List<ActorPath>();

        /// <summary>
        /// Add an <see cref="ActorPath"/> to the path list.
        /// </summary>
        /// <param name="path">Path</param>
        /// <returns>Index of added path.</returns>
        public int Add(ActorPath path)
        {
            var index = _paths.Count;
            _paths.Add(path);
            return index;
        }

        /// <summary>
        /// Build path entries alongside path buffer bytes.
        /// </summary>
        /// <returns>Path entries and path buffer bytes.</returns>
        public (PathEntry[], byte[]) Build()
        {
            var entries = new PathEntry[_paths.Count];
            using (var memoryStream = new MemoryStream())
            using (var writer = new BinaryWriter(memoryStream))
            {
                uint offset = 0;
                for (int i = 0; i < _paths.Count; i++)
                {
                    // Write path bytes.
                    var path = _paths[i];
                    var pathBytes = path.ToBytes();
                    writer.Write(pathBytes);
                    // Create PathEntry for this path and update offset.
                    entries[i] = new PathEntry((byte)path.Nodes.Count, offset);
                    offset += (uint)pathBytes.Length;
                }
                return (entries, memoryStream.ToArray());
            }
        }
    }
}
