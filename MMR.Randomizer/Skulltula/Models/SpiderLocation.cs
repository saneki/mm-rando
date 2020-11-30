using MMR.Randomizer.Skulltula.Models.Json;
using MMR.Randomizer.Skulltula.Models.Rom;
using System.Collections.Generic;
using System.Collections.ObjectModel;

namespace MMR.Randomizer.Skulltula.Models
{
    /// <summary>
    /// Information and paths relating to specific Skullwalltula actor location.
    /// </summary>
    public class SpiderLocation
    {
        /// <summary>
        /// Description of Skulltula location and/or behavior.
        /// </summary>
        public string Description { get; }

        /// <summary>
        /// Skulltula location name.
        /// </summary>
        public string Name { get; }

        /// <summary>
        /// All paths to select from.
        /// </summary>
        public ReadOnlyCollection<ActorPath> Paths { get; }

        /// <summary>
        /// Optional pool.
        /// </summary>
        public SpiderPool Pool { get; }

        /// <summary>
        /// Room index.
        /// </summary>
        public byte Room { get; }

        /// <summary>
        /// Initial rotation value for Y axis.
        /// </summary>
        public ushort Rotation { get; }

        /// <summary>
        /// Scene index.
        /// </summary>
        public byte Scene { get; }

        /// <summary>
        /// Time of day during which Skulltula is available.
        /// </summary>
        public SpiderTime Time { get; } = SpiderTime.Any;

        public SpiderLocation(byte scene, byte room, string name, string description, IList<ActorPath> paths, SpiderPool pool, ushort rotation = 0, SpiderTime time = SpiderTime.Any) =>
            (Scene, Room, Name, Description, Paths, Pool, Rotation, Time) = (scene, room, name, description, new ReadOnlyCollection<ActorPath>(paths), pool, rotation, time);

        /// <summary>
        /// Create <see cref="SpiderLocation"/> from documents describing Skullwalltula locations.
        /// </summary>
        /// <param name="sceneJson">Scene document</param>
        /// <param name="locationJson">Location document</param>
        /// <returns><see cref="SpiderLocation"/>.</returns>
        public static SpiderLocation From(SpiderSceneJson sceneJson, SpiderLocationJson locationJson)
        {
            var scene = sceneJson.Index;
            var room = locationJson.Room.GetValueOrDefault(0);
            var name = locationJson.Name;
            var description = locationJson.Description;
            var paths = locationJson.GetActorPaths();
            var rotation = locationJson.Rotation.GetValueOrDefault(0);
            return new SpiderLocation(scene, room, name, description, paths, null, rotation);
        }
    }
}
