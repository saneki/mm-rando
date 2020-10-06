using System;
using System.Collections.Generic;
using MMR.Common.Extensions;
using MMR.Randomizer.GameObjects;

namespace MMR.Randomizer.Models.Rom
{
    public class MessageEntryBuilder
    {
        private ushort id;
        private byte[] header = null;
        private string message = "";

        public MessageEntryBuilder Id(ushort id)
        {
            this.id = id;
            return this;
        }

        public MessageEntryBuilder Header(Action<HeaderBuilder> configureHeader)
        {
            var headerBuilder = new HeaderBuilder();
            configureHeader(headerBuilder);
            header = headerBuilder.Build();
            return this;
        }

        public MessageEntryBuilder Message(Action<MessageBuilder> configureMessage)
        {
            var messageBuilder = new MessageBuilder();
            configureMessage(messageBuilder);
            message = messageBuilder.Build();
            return this;
        }

        public MessageEntry Build() => new MessageEntry
        {
            Id = id,
            Header = header,
            Message = message
        };

        public class HeaderBuilder
        {
            private byte textBoxType = 0x00;

            private byte y = 0x00;

            private byte icon = 0x00;

            private ushort nextMessage = 0xFFFF;

            private ushort rupeeCost = 0xFFFF;

            #region TextBox

            private enum TextBoxTypes
            {
                Standard = 0x00,
                SignPost = 0x01,
                FaintBlue = 0x02
            }

            public HeaderBuilder Standard() =>
                SetTextBoxType(TextBoxTypes.Standard);

            public HeaderBuilder SignPost() =>
                SetTextBoxType(TextBoxTypes.SignPost);

            public HeaderBuilder FaintBlue() =>
                SetTextBoxType(TextBoxTypes.FaintBlue);

            private HeaderBuilder SetTextBoxType(TextBoxTypes type)
            {
                // TODO (before public api exposure): types are a nibble, so need to & 0x0F, or ensure no enum type is greater than 0x0F
                textBoxType = (byte) type;
                return this;
            }

            #endregion

            #region TextBox Y

            public HeaderBuilder Y(byte y)
            {
                this.y = y;
                return this;
            }

            #endregion

            #region Icon

            public HeaderBuilder Icon(byte icon)
            {
                this.icon = icon;
                return this;
            }

            #endregion

            #region Next Message

            /// <summary>
            /// The message id of the message box that follows this one.
            /// </summary>
            /// <param name="nextMessage">the message id of the next message box to show</param>
            /// <returns></returns>
            public HeaderBuilder NextMessage(ushort nextMessage)
            {
                this.nextMessage = nextMessage;
                return this;
            }

            #endregion

            #region Rupee Cost

            public HeaderBuilder RupeeCost(ushort cost)
            {
                rupeeCost = cost;
                return this;
            }

            #endregion

            public byte[] Build()
            {
                return new byte[]
                {
                    textBoxType,
                    y,
                    icon,
                    nextMessage.LeftByte(),
                    nextMessage.RightByte(),
                    rupeeCost.LeftByte(),
                    rupeeCost.RightByte(),
                    0xFF, 0xFF, 0xFF, 0xFF
                };
            }
        }

        public class MessageBuilder
        {
            private string message = "";
            private Stack<char> colorStack = new Stack<char>();

            /// <summary>
            /// Appends the quick text start control character (0x17) to the message.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder QuickTextStart() =>
                Append(0x17);

            /// <summary>
            /// Appends the quick text stop control character (0x18) to the message.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder QuickTextStop() =>
                Append(0x18);

            /// <summary>
            /// Appends the pause delay control character (0x1F) and the pause time (in frames) to the message.
            /// </summary>
            /// <param name="pauseFrames"></param>
            /// <returns></returns>
            public MessageBuilder PauseText(ushort pauseFrames) =>
                Append(0x1F).Append(pauseFrames);


            /// <summary>
            /// Appends the end text box control character (0x10) to the message.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder EndTextBox() =>
                Append(0x10);

            /// <summary>
            /// Appends the Skulltula count control character (0x0D) to the message.
            /// <para>
            /// The game takes care of handling cardinality, like 1st, 2nd, 3rd, 4th, etc.
            /// It also keeps track of the current Skulltula type (meaning, there are not
            /// two separate control characters for Ocean count and Swamp count).
            /// </para>
            /// <para>
            /// Multiple occurrences will render multiple times.
            /// </para>
            /// </summary>
            /// <returns></returns>
            public MessageBuilder SkulltulaCount() =>
                Append(0x0D);

            /// <summary>
            /// Appends the end final text box control character (0xBF) to the message.
            /// This character signals that the text box can be dismissed.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder EndFinalTextBox() =>
                Append(0xBF);

            /// <summary>
            /// Appends the new line control character (0x11) to the message.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder NewLine() =>
                Append(0x11);

            /// <summary>
            /// Appends the text to the message.
            /// </summary>
            /// <para>
            /// The text color will be the last text color control character appended to the message.
            /// If no text color has been selected, the default is white.
            /// </para>
            /// <param name="text"></param>
            /// <returns></returns>
            public MessageBuilder Text(string text) =>
                Append(text);

            #region Text Colors

            private MessageBuilder PushTextColor(char color)
            {
                colorStack.Push(color);
                return Append(color);
            }

            public MessageBuilder PopTextColor()
            {
                colorStack.Pop();
                if (colorStack.Count > 0)
                {
                    return Append(colorStack.Peek());
                }
                return Append(TextCommands.ColorWhite); // return to default text color.
            }

            /// <summary>
            /// Appends the start white text control character (0x00) to the message.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder StartWhiteText() =>
                PushTextColor(TextCommands.ColorWhite);

            /// <summary>
            /// Appends the start red text control character (0x01) to the message.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder StartRedText() =>
                PushTextColor(TextCommands.ColorRed);

            /// <summary>
            /// Appends the start red text control character (0x02) to the message.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder StartGreenText() =>
                PushTextColor(TextCommands.ColorGreen);

            /// <summary>
            /// Appends the start light blue text control character (0x05) to the message.
            /// </summary>
            /// <para>
            /// Tatl uses this color at the beginning of her messages.
            /// </para>
            /// <returns></returns>
            public MessageBuilder StartLightBlueText() =>
                PushTextColor(TextCommands.ColorLightBlue);

            /// <summary>
            /// Appends the start pink text control character (0x06) to the message.
            /// </summary>
            /// <returns></returns>
            public MessageBuilder StartPinkText() =>
                PushTextColor(TextCommands.ColorPink);

            #endregion

            /// <summary>
            /// Returns the completed message string.
            /// </summary>
            /// <returns></returns>
            public string Build() => message;

            private MessageBuilder Append(string text)
            {
                message += text;
                return this;
            }

            private MessageBuilder Append(byte value) =>
                Append((char) value);

            private MessageBuilder Append(char value)
            {
                message += value;
                return this;
            }

            private MessageBuilder Append(ushort value) =>
                Append(value.LeftByte()).Append(value.RightByte());
        }
    }

    public static class MessageBuilderExtensions
    {
        /// <summary>
        /// Appends the start quick text control character (0x17) to the message, executes the specified action, and
        /// appends the stop quick text control character(0x18) to the end of the message.
        /// </summary>
        /// <param name="this"></param>
        /// <param name="action"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder QuickText(this MessageEntryBuilder.MessageBuilder @this, Action action)
        {
            @this.QuickTextStart();
            action();
            @this.QuickTextStop();
            return @this;
        }

        #region Color Extensions

        /// <summary>
        /// Appends the start white text control character (0x00) to the message, and executes the specified action.
        /// </summary>
        /// <param name="this">this message builder</param>
        /// <param name="action"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder White(this MessageEntryBuilder.MessageBuilder @this, Action action)
        {
            @this.StartWhiteText();
            action();
            @this.PopTextColor();
            return @this;
        }

        /// <summary>
        /// Appends the start white text control character (0x00) to the message, and writes the specified text.
        /// </summary>
        /// <param name="this">this message builder</param>
        /// <param name="text"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder White(this MessageEntryBuilder.MessageBuilder @this, string text) => @this.White(() => @this.Text(text));

        /// <summary>
        /// Appends the start red text control character (0x01) to the message, and executes the specified action.
        /// </summary>
        /// <param name="this"></param>
        /// <param name="action"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder Red(this MessageEntryBuilder.MessageBuilder @this, Action action)
        {
            @this.StartRedText();
            action();
            @this.PopTextColor();
            return @this;
        }

        /// <summary>
        /// Appends the start red text control character (0x01) to the message, and writes the specified text.
        /// </summary>
        /// <param name="this">this message builder</param>
        /// <param name="text"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder Red(this MessageEntryBuilder.MessageBuilder @this, string text) => @this.Red(() => @this.Text(text));

        /// <summary>
        /// Appends the start green text control character (0x02) to the message, and executes the specified action.
        /// </summary>
        /// <param name="this"></param>
        /// <param name="action"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder Green(this MessageEntryBuilder.MessageBuilder @this, Action action)
        {
            @this.StartGreenText();
            action();
            @this.PopTextColor();
            return @this;
        }

        /// <summary>
        /// Appends the start green text control character (0x02) to the message, and writes the specified text.
        /// </summary>
        /// <param name="this">this message builder</param>
        /// <param name="text"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder Green(this MessageEntryBuilder.MessageBuilder @this, string text) => @this.White(() => @this.Green(text));

        /// <summary>
        /// Appends the start light blue text control character (0x05) to the message, and executes the specified action.
        /// </summary>
        /// <param name="this"></param>
        /// <param name="action"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder LightBlue(this MessageEntryBuilder.MessageBuilder @this, Action action)
        {
            @this.StartLightBlueText();
            action();
            @this.PopTextColor();
            return @this;
        }

        /// <summary>
        /// Appends the start light blue text control character (0x05) to the message, and writes the specified text.
        /// </summary>
        /// <param name="this">this message builder</param>
        /// <param name="text"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder LightBlue(this MessageEntryBuilder.MessageBuilder @this, string text) => @this.LightBlue(() => @this.Text(text));

        /// <summary>
        /// Appends the start pink text control character (0x06) to the message, and executes the specified action.
        /// </summary>
        /// <param name="this"></param>
        /// <param name="action"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder Pink(this MessageEntryBuilder.MessageBuilder @this, Action action)
        {
            @this.StartPinkText();
            action();
            @this.PopTextColor();
            return @this;
        }

        /// <summary>
        /// Appends the start pink text control character (0x06) to the message, and writes the specified text.
        /// </summary>
        /// <param name="this">this message builder</param>
        /// <param name="text"></param>
        /// <returns></returns>
        public static MessageEntryBuilder.MessageBuilder Pink(this MessageEntryBuilder.MessageBuilder @this, string text) => @this.Pink(() => @this.Text(text));

        #endregion
    }
}
