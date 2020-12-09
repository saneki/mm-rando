using System;
using System.ComponentModel;
using MMR.Randomizer.Attributes;

namespace MMR.Randomizer.Models.Settings
{
    [Flags]
    public enum ShortenCutscene
    {
        None = 0,

        [Description("Odolwa Intro")]
        [HackContent(nameof(Resources.mods.shorten_cutscene_odolwa_intro))]
        IntroOdolwa = 1,

        [HackContent(nameof(Resources.mods.shorten_cutscene_goht_intro))]
        IntroGoht = 2,

        [HackContent(nameof(Resources.mods.shorten_cutscene_gyorg_intro))]
        IntroGyorg = 4,

        [HackContent(nameof(Resources.mods.shorten_cutscene_twinmold_intro))]
        IntroTwinmold = 8,

        [HackContent(nameof(Resources.mods.shorten_cutscene_majora_intro))]
        IntroMajora = 16,

        [HackContent(nameof(Resources.mods.shorten_cutscene_wart_intro))]
        IntroWart = 32,

        [HackContent(nameof(Resources.mods.shorten_cutscene_igos_intro))]
        IntroIgos = 64,
    }
}
