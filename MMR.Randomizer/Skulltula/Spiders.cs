using MMR.Randomizer.Asm;
using MMR.Randomizer.Skulltula.Models;
using MMR.Randomizer.Skulltula.Models.Json;
using MMR.Randomizer.Utils;
using System.Collections.ObjectModel;
using System.Linq;

namespace MMR.Randomizer.Skulltula
{
    /// <summary>
    /// Primary configuration for World Skulltula feature.
    /// </summary>
    public class Spiders : AsmConfig
    {
        /// <summary>
        /// Root document describing all possible Skullwalltula locations.
        /// </summary>
        public SpiderJson JsonConfig { get; }

        /// <summary>
        /// Randomized Skullwalltula locations organized by scene, not currently randomized.
        /// </summary>
        public ReadOnlyCollection<SpiderScene> RandomizedScenes { get; private set; }

        /// <summary>
        /// Primary configuration structure.
        /// </summary>
        public SpiderConfigStruct ConfigStruct { get; private set; }

        public Spiders(SpiderJson jsonConfig) => JsonConfig = jsonConfig;

        /// <summary>
        /// Create <see cref="Spiders"/> using <see cref="SpiderJson"/> loaded from internal resource file.
        /// </summary>
        /// <returns><see cref="Spiders"/>.</returns>
        public static Spiders FromResource()
        {
            return new Spiders(SpiderJson.FromResource());
        }

        /// <summary>
        /// Randomly select Skullwalltula locations, not currently randomized.
        /// </summary>
        public void RandomizeLocations()
        {
            // For now, treat all data in JSON as the randomized result.
            var spiderScenes = this.JsonConfig.Scenes.Select(x => SpiderScene.From(x)).ToArray();
            this.RandomizedScenes = new ReadOnlyCollection<SpiderScene>(spiderScenes);
        }

        /// <summary>
        /// Build directory file containing scene-specific information for Skullwalltula locations.
        /// </summary>
        /// <returns>File index array mapped by scene, and directory file bytes.</returns>
        public (byte[], byte[]) BuildDirectoryFile()
        {
            // Todo: 0x71 is scene count or something.
            var fileIndexes = new byte[0x74];
            var builder = new DirectoryFileBuilder();
            foreach (var scene in this.RandomizedScenes)
            {
                var sceneConfig = scene.BuildSceneConfig();
                var fileIndex = builder.AddInnerFile(sceneConfig.ToBytes());
                // Write file index for specific scene in table.
                fileIndexes[scene.SceneIndex] = (byte)(fileIndex + 1);
            }
            var fullBytes = builder.Build();
            return (fileIndexes, fullBytes);
        }

        /// <summary>
        /// Build and append scene directory file to file list, and build config structure.
        /// </summary>
        public void Write()
        {
            var (fileIndexes, directoryFileBytes) = this.BuildDirectoryFile();
            // Append directory file to file list.
            var directoryFileIndex = RomUtils.AppendFile(directoryFileBytes);
            // Todo: Write fileIndexes to config structure and write to Asm.
            var spiderConfig = new SpiderConfigStruct((uint)directoryFileIndex, fileIndexes);
            this.ConfigStruct = spiderConfig;
        }

        public override IAsmConfigStruct ToStruct(uint version)
        {
            return this.ConfigStruct;
        }
    }
}
