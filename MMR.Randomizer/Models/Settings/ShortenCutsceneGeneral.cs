using System;
using MMR.Randomizer.Attributes;

namespace MMR.Randomizer.Models.Settings
{
    [Flags]
    public enum ShortenCutsceneGeneral
    {
        None = 0,

        [HackContent(nameof(Resources.mods.short_cutscenes))]
        [HackContent(nameof(Resources.mods.shorten_cutscene_don_gero))]
        [HackContent(nameof(Resources.mods.remove_tatl_interrupts))]
        EverythingElse = 1,

        //[HackContent(nameof(Resources.mods.shorten_cutscene_don_gero))]
        //DonGero = 2,
    }
}
