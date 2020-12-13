using System;
using MMR.Randomizer.Attributes;

namespace MMR.Randomizer.Models.Settings
{
    [Flags]
    public enum ShortenCutsceneBossIntro
    {
        None = 0,

        [HackContent(nameof(Resources.mods.shorten_cutscene_odolwa_intro))]
        Odolwa = 1,

        [HackContent(nameof(Resources.mods.shorten_cutscene_goht_intro))]
        Goht = 2,

        [HackContent(nameof(Resources.mods.shorten_cutscene_gyorg_intro))]
        Gyorg = 4,

        [HackContent(nameof(Resources.mods.shorten_cutscene_twinmold_intro))]
        Twinmold = 8,

        [HackContent(nameof(Resources.mods.shorten_cutscene_majora_intro))]
        Majora = 16,

        [HackContent(nameof(Resources.mods.shorten_cutscene_wart_intro))]
        Wart = 32,

        [HackContent(nameof(Resources.mods.shorten_cutscene_igos_intro))]
        Igos = 64,
    }
}
