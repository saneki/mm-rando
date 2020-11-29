using Newtonsoft.Json;

namespace MMR.Randomizer.Skulltula.Models.Json
{
    /// <summary>
    /// Root document for configuring Skullwalltula locations.
    /// </summary>
    public class SpiderJson
    {
        /// <summary>
        /// Info relating to scenes, including Skullwalltula locations organized by scene.
        /// </summary>
        public SpiderSceneJson[] Scenes;

        /// <summary>
        /// Deserialize <see cref="SpiderJson"/> from a JSON string.
        /// </summary>
        /// <param name="json">JSON <see cref="string"/> input</param>
        /// <returns>Deserialized <see cref="SpiderJson"/> object.</returns>
        public static SpiderJson Deserialize(string json)
        {
            return JsonConvert.DeserializeObject<SpiderJson>(json);
        }

        /// <summary>
        /// Deserialize <see cref="SpiderJson"/> from internal resource file.
        /// </summary>
        /// <returns>Deserialized <see cref="SpiderJson"/> object.</returns>
        public static SpiderJson FromResource()
        {
            return Deserialize(Resources.skulltula.spiders);
        }
    }
}
