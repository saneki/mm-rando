namespace MMR.Randomizer.Skulltula.Models
{
    /// <summary>
    /// Defines times during which Skullwalltula may spawn and remain spawned.
    /// </summary>
    public enum SpiderTime
    {
        /// <summary>
        /// Skullwalltula may spawn and remain spawned during any time of day.
        /// </summary>
        Any,

        /// <summary>
        /// Skullwalltula should only spawn and remain spawned during night.
        /// </summary>
        Night,
    }
}
