#nullable enable

using MMR.Randomizer.Attributes;
using MMR.Randomizer.Models.Rom;

namespace MMR.Randomizer.Models.Attributes
{
    public sealed record GetItemInfo
    {
        public GetItemEntry Entry { get; }
        public string? Message { get; }

        public GetItemInfo(GetItemEntry entry, string? message = null)
        {
            Entry = entry;
            Message = message;
        }

        public GetItemInfo(GetItemEntryAttribute attribute)
            : this(attribute.CreateEntry(), attribute.Message)
        {
        }
    }
}
