using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;

namespace MMR.Randomizer.Skulltula.Models.Rom
{
    /// <summary>
    /// Path used by actors, composed of zero or more <see cref="SPos"/> nodes.
    /// </summary>
    public class ActorPath
    {
        /// <summary>
        /// Nodes in path.
        /// </summary>
        public ReadOnlyCollection<SPos> Nodes { get; }

        /// <summary>
        /// Whether or not this path is empty (no nodes).
        /// </summary>
        public bool Empty => this.Nodes.Count == 0;

        /// <summary>
        /// Whether or not this path is stationary (only 1 node).
        /// </summary>
        public bool Stationary => this.Nodes.Count == 1;

        public ActorPath(IList<SPos> nodes) => (Nodes) = (new ReadOnlyCollection<SPos>(nodes));

        public byte[] ToBytes()
        {
            int expectedSize = this.Nodes.Count * 6;
            using (var memoryStream = new MemoryStream(expectedSize))
            using (var writer = new BinaryWriter(memoryStream))
            {
                // Write each node in path.
                foreach (var node in this.Nodes)
                {
                    writer.Write(node.ToBytes());
                }
                return memoryStream.ToArray();
            }
        }
    }
}
