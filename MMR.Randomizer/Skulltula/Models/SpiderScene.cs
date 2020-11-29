using MMR.Randomizer.Skulltula.Models.Json;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;

namespace MMR.Randomizer.Skulltula.Models
{
    /// <summary>
    /// Container for organizing Skullwalltula locations by scene.
    /// </summary>
    public class SpiderScene
    {
        /// <summary>
        /// Scene index.
        /// </summary>
        public byte SceneIndex { get; }

        /// <summary>
        /// All Skullwalltula locations in this scene.
        /// </summary>
        public ReadOnlyCollection<SpiderLocation> Locations { get; }

        public SpiderScene(byte sceneIndex, IList<SpiderLocation> locations) =>
            (SceneIndex, Locations) = (sceneIndex, new ReadOnlyCollection<SpiderLocation>(locations));

        /// <summary>
        /// Build scene config structure for this scene.
        /// </summary>
        /// <returns>Scene config structure.</returns>
        public SpiderSceneConfigStruct BuildSceneConfig()
        {
            return new SpiderSceneConfigStruct(this.Locations);
        }

        /// <summary>
        /// Create <see cref="SpiderScene"/> from document describing Skullwalltula locations within a scene.
        /// </summary>
        /// <param name="sceneJson">Scene document</param>
        /// <returns><see cref="SpiderScene"/>.</returns>
        public static SpiderScene From(SpiderSceneJson sceneJson)
        {
            var sceneIndex = sceneJson.Index;
            var locations = sceneJson.Spiders.Select(x => SpiderLocation.From(sceneJson, x)).ToArray();
            return new SpiderScene(sceneIndex, new ReadOnlyCollection<SpiderLocation>(locations));
        }
    }
}
