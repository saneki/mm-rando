#nullable enable

using MMR.Randomizer.Models.Rom;
using System;

namespace MMR.Randomizer.Attributes
{
    public class GetItemEntryAttribute : Attribute
    {
        public byte Item { get; }
        public byte Flags { get; }
        public byte Graphic { get; }
        public byte Type { get; }
        public ushort MessageId { get; }
        public ushort ObjectId { get; }
        public string? Message { get; }

        public GetItemEntryAttribute(byte item, byte flags, byte graphic, byte type, ushort messageId, ushort objectId, string? message = null)
        {
            Item = item;
            Flags = flags;
            Graphic = graphic;
            Type = type;
            MessageId = messageId;
            ObjectId = objectId;
            Message = message;
        }

        public GetItemEntry CreateEntry()
        {
            return new GetItemEntry
            {
                ItemGained = Item,
                Flag = Flags,
                Index = Graphic,
                Type = Type,
                Message = (short)MessageId,
                Object = (short)ObjectId,
            };
        }
    }
}
