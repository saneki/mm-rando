using MMR.Randomizer.Models.SoundEffects;

namespace MMR.Randomizer.Models.Settings
{
    public enum LowHealthSFX
    {
        Default = -3,
        Disabled = -2,
        Random = -1,

        Chicks = SoundEffect.LittleChickChirp,
        Panting = SoundEffect.ChildLinkPantLowHealth,
        SilverRupee = SoundEffect.SilverRupeeGet,
        TatlDash = SoundEffect.TatlDashNormal,
        Baybee = SoundEffect.MikauBaybee,
        DogBark = SoundEffect.DogBark,
        Cow = SoundEffect.CowMoo,
        SecretLadder = SoundEffect.SecretLadderAppears,
        AmusedFather = SoundEffect.SwampTouristProprietorHehHeh,
    }
}
