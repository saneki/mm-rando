using MMR.Randomizer.Skulltula.Models.Rom;
using System.Collections.Generic;
using System.Linq;

namespace MMR.Randomizer.Skulltula.Models.Json
{
    /// <summary>
    /// Document describing single Skullwalltula location.
    /// </summary>
    public class SpiderLocationJson
    {
        /// <summary>
        /// Name of location.
        /// </summary>
        public string Name;

        /// <summary>
        /// Description of location.
        /// </summary>
        public string Description;

        /// <summary>
        /// Raw path node values.
        /// </summary>
        public List<ushort[][]> Path;

        /// <summary>
        /// Optional pool index for scene-relative pool.
        /// </summary>
        public byte? Pool;

        /// <summary>
        /// Optional room index.
        /// </summary>
        public byte? Room;

        /// <summary>
        /// Optional initial rotation value for Y axis.
        /// </summary>
        public ushort? Rotation;

        /// <summary>
        /// Convert raw path node values to <see cref="ActorPath"/> paths.
        /// </summary>
        /// <returns>Actor paths.</returns>
        public List<ActorPath> GetActorPaths()
        {
            var list = new List<ActorPath>();
            foreach (var nodeValues in this.Path)
            {
                // Convert value tuples to nodes.
                var nodes = nodeValues.Select(x => SPos.From(x)).ToArray();
                var path = new ActorPath(nodes);
                list.Add(path);
            }
            return list;
        }
    }
}
