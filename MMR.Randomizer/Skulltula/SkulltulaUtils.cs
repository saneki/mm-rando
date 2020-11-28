using MMR.Randomizer.Models.Rom;

namespace MMR.Randomizer.Skulltula
{
    public static class SkulltulaUtils
    {
        /// <summary>
        /// Update restrictions for specific scenes to allow using sword, hookshot, and bow.
        /// </summary>
        public static void UpdateSceneRestrictions()
        {
            var table = SceneRestrictionsTable.ReadFromROM();
            // Scenes to allow sword, hookshot, etc in.
            var scenes = new byte[] {
                0x61, // Stock Pot Inn
            };
            foreach (var scene in scenes)
            {
                var restrictions = table[scene];
                // Allow sword, B-button usage.
                restrictions.Flags[1] = 0;
                // Allow hookshot, bow, etc.
                restrictions.Flags[11] = 0;
            }
            table.WriteToROM();
        }

        /// <summary>
        /// Perform hacks required for World Skulltula.
        /// </summary>
        public static void PerformHacks()
        {
            UpdateSceneRestrictions();
        }
    }
}
