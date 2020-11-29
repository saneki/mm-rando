using System.Linq;

namespace MMR.Randomizer.Skulltula.Models.Json
{
    /// <summary>
    /// Document for describing each Skullwalltula location in a specific scene.
    /// </summary>
    public class SpiderSceneJson
    {
        /// <summary>
        /// Scene index.
        /// </summary>
        public byte Index;

        /// <summary>
        /// Scene name.
        /// </summary>
        public string Name;

        /// <summary>
        /// Skullwalltula location documents.
        /// </summary>
        public SpiderLocationJson[] Spiders;

        /// <summary>
        /// Get all Skullwalltula locations in this scene.
        /// </summary>
        /// <returns>Skullwalltula locations.</returns>
        public SpiderLocation[] GetLocations()
        {
            return this.Spiders.Select(x => SpiderLocation.From(this, x)).ToArray();
        }
    }
}
