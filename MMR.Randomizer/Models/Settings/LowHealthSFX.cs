using MMR.Randomizer.Models.SoundEffects;

namespace MMR.Randomizer.Models.Settings
{
    public enum LowHealthSFX
    {
        Default = -3, // vanilla behavior
        Disabled = -2, // no sound at all
        Random = -1,

        // specific sfx
        CuccoChicks = SoundEffect.LittleChickChirp,
        CuccoClucking = SoundEffect.CuccoClucking,
        LinkPanting = SoundEffect.ChildLinkPantLowHealth,
        DogBark = SoundEffect.DogBark,
        SilverRupee = SoundEffect.SilverRupeeGet,
        TatlDash = SoundEffect.TatlDashNormal,
        TatlMessage = SoundEffect.TatlMessage,
        MikauBaby = SoundEffect.MikauBaybee,
        CowMooing = SoundEffect.CowMoo,
        LadderWarp = SoundEffect.SecretLadderAppears,
        AmusedFather = SoundEffect.SwampTouristProprietorHehHeh,
        TingleChuckle = SoundEffect.TingleChuckle,
    }
}
