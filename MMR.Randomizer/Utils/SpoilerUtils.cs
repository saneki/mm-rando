﻿using MMR.Randomizer.Extensions;
using MMR.Randomizer.GameObjects;
using MMR.Randomizer.Models;
using MMR.Randomizer.Models.Settings;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace MMR.Randomizer.Utils
{
    public static class SpoilerUtils
    {
        public static void CreateSpoilerLog(RandomizedResult randomized, GameplaySettings settings, OutputSettings outputSettings)
        {
            var itemList = randomized.ItemList
                .Where(io => !io.Item.IsFake() && io.NewLocation.HasValue)
                .Select(u => new SpoilerItem(u, ItemUtils.IsRequired(u.Item, randomized), ItemUtils.IsImportant(u.Item, randomized), settings.ProgressiveUpgrades));

            Dictionary<Item, Item> dungeonEntrances = new Dictionary<Item, Item>();
            if (settings.RandomizeDungeonEntrances)
            {
                var entrances = new List<Item>
                {
                    Item.AreaWoodFallTempleAccess,
                    Item.AreaSnowheadTempleAccess,
                    Item.AreaGreatBayTempleAccess,
                    Item.AreaInvertedStoneTowerTempleAccess,
                };
                foreach (var entrance in entrances.OrderBy(e => entrances.IndexOf(randomized.ItemList[e].NewLocation.Value)))
                {
                    dungeonEntrances.Add(randomized.ItemList[entrance].NewLocation.Value, entrance);
                }
            }
            var settingsString = settings.ToString();

            var directory = Path.GetDirectoryName(outputSettings.OutputROMFilename);
            var filename = $"{Path.GetFileNameWithoutExtension(outputSettings.OutputROMFilename)}";

            var plainTextRegex = new Regex("[^a-zA-Z0-9' .\\-]+");
            Spoiler spoiler = new Spoiler()
            {
                Version = Randomizer.AssemblyVersion,
                SettingsString = settingsString,
                Seed = randomized.Seed,
                DungeonEntrances = dungeonEntrances,
                ItemList = itemList.ToList(),
                Logic = randomized.Logic,
                GossipHints = randomized.GossipQuotes?.ToDictionary(me => (GossipQuote) me.Id, (me) =>
                {
                    var message = me.Message.Substring(1);
                    var soundEffect = message.Substring(0, 2);
                    message = message.Substring(2);
                    if (soundEffect == "\x69\x0C")
                    {
                        // real
                    }
                    else if (soundEffect == "\x69\x0A")
                    {
                        // fake
                        message = "FAKE - " + message;
                    }
                    else
                    {
                        // junk
                        message = "JUNK - " + message;
                    }
                    return plainTextRegex.Replace(message.Replace("\x11", " "), "");
                }),
            };

            if (outputSettings.GenerateHTMLLog)
            {
                using (StreamWriter newlog = new StreamWriter(Path.Combine(directory, filename + "_Tracker.html")))
                {
                    Templates.HtmlSpoiler htmlspoiler = new Templates.HtmlSpoiler(spoiler);
                    newlog.Write(htmlspoiler.TransformText());
                }
            }
            
            if (outputSettings.GenerateSpoilerLog)
            {
                CreateTextSpoilerLog(spoiler, Path.Combine(directory, filename + "_SpoilerLog.txt"));
            }
        }

        private static void CreateTextSpoilerLog(Spoiler spoiler, string path)
        {
            StringBuilder log = new StringBuilder();
            log.AppendLine($"{"Version:",-17} {spoiler.Version}");
            log.AppendLine($"{"Settings:",-17} {spoiler.SettingsString}");
            log.AppendLine($"{"Seed:",-17} {spoiler.Seed}");
            log.AppendLine();

            if (spoiler.DungeonEntrances.Any())
            {
                log.AppendLine($" {"Entrance",-21}    {"Destination"}");
                log.AppendLine();
                foreach (var kvp in spoiler.DungeonEntrances)
                {
                    log.AppendLine($"{kvp.Key.Entrance(),-21} -> {kvp.Value.Entrance()}");
                }
                log.AppendLine("");
            }

            log.AppendLine($" {"Location",-50}    {"Item"}");
            foreach (var region in spoiler.ItemList.GroupBy(item => item.Region).OrderBy(g => g.Key))
            {
                log.AppendLine();
                log.AppendLine($" {region.Key.Name()}");
                foreach (var item in region.OrderBy(item => item.NewLocationName))
                {
                    log.AppendLine($"{item.NewLocationName,-50} -> {item.Name}" + (item.IsImportant ? "*" : "") + (item.IsRequired ? "*" : ""));
                }
            }


            if (spoiler.GossipHints != null && spoiler.GossipHints.Any())
            {
                log.AppendLine();
                log.AppendLine();

                log.AppendLine($" {"Gossip Stone",-25}    {"Message"}");
                foreach (var hint in spoiler.GossipHints.OrderBy(h => h.Key.ToString()))
                {
                    log.AppendLine($"{hint.Key,-25} -> {hint.Value}");
                }
            }

            using (StreamWriter sw = new StreamWriter(path))
            {
                sw.Write(log.ToString());
            }
        }
    }
}
