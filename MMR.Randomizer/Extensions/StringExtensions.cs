using MMR.Randomizer.GameObjects;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;

namespace MMR.Randomizer.Extensions
{
    public static class StringExtensions
    {
        public static string WrapLine(this string str, int width, string newline)
        {
            var words = str.Split(' ');
            var lines = new List<string>();
            var currentLine = new List<string>();
            var currentLength = 0;
            foreach (var word in words)
            {
                var length = word.Count(c => HasWidth(c));
                if (currentLength + length > width)
                {
                    lines.Add(string.Join(" ", currentLine));
                    currentLength = 0;
                    currentLine.Clear();
                }
                currentLine.Add(word);
                currentLength += length + 1;
            }
            lines.Add(string.Join(" ", currentLine));
            return string.Join(newline, lines);
        }
        
        public static string Wrap(this string str, int width, string newline)
        {
            var newLines = new List<string>();
            var lines = str.Split(new string[] { newline }, StringSplitOptions.RemoveEmptyEntries);
            foreach (var line in lines)
            {
                newLines.Add(line.WrapLine(width, newline));
            }
            return string.Join(newline, newLines);
        }

        public static string EndTextbox(this string str)
        {
            var countLines = str.Count(c => c == '\u0011') + 1;
            var minLines = 4;
            var newline = "\u0011";
            for (var i = countLines; i < minLines; i++)
            {
                str += newline;
                newline = "\u0013";
            }
            str += "\u0012";
            return str;
        }

        public static string SurroundWithCommandCheckGetItemAndSkip(this string str, Item location)
        {
            var getItemIndex = location.GetItemIndex().Value;
            var upper = (char)(getItemIndex >> 8);
            var lower = (char)(getItemIndex & 0xFF);
            return $"\u0009\u0001{upper}{lower}{str}\u0009\u0002";
        }

        public static string SurroundWithCommandCheckGetItemReplaceItemName(this string str, Item location)
        {
            var getItemIndex = location.GetItemIndex().Value;
            var upper = (char)(getItemIndex >> 8);
            var lower = (char)(getItemIndex & 0xFF);
            return $"\u0009\u0003{upper}{lower}{str}\u0009\u0002";
        }

        public static string SurroundWithCommandCheckGetItemReplaceItemDescription(this string str, Item location)
        {
            var getItemIndex = location.GetItemIndex().Value;
            var upper = (char)(getItemIndex >> 8);
            var lower = (char)(getItemIndex & 0xFF);
            return $"\u0009\u0004{upper}{lower}{str}\u0009\u0002";
        }

        public static string SurroundWithCommandCheckGetItemReplaceArticle(this string str, Item location)
        {
            var getItemIndex = location.GetItemIndex().Value;
            var upper = (char)(getItemIndex >> 8);
            var lower = (char)(getItemIndex & 0xFF);
            return $"\u0009\u0005{upper}{lower}{str}\u0009\u0002";
        }

        public static string SurroundWithCommandCheckGetItemReplacePronoun(this string str, Item location)
        {
            var getItemIndex = location.GetItemIndex().Value;
            var upper = (char)(getItemIndex >> 8);
            var lower = (char)(getItemIndex & 0xFF);
            return $"\u0009\u0006{upper}{lower}{str}\u0009\u0002";
        }

        public static string SurroundWithCommandCheckGetItemReplaceAmount(this string str, Item location)
        {
            var getItemIndex = location.GetItemIndex().Value;
            var upper = (char)(getItemIndex >> 8);
            var lower = (char)(getItemIndex & 0xFF);
            return $"\u0009\u0007{upper}{lower}{str}\u0009\u0002";
        }

        public static string SurroundWithCommandCheckGetItemReplaceVerb(this string str, Item location)
        {
            var getItemIndex = location.GetItemIndex().Value;
            var upper = (char)(getItemIndex >> 8);
            var lower = (char)(getItemIndex & 0xFF);
            return $"\u0009\u0008{upper}{lower}{str}\u0009\u0002";
        }

        public static string SurroundWithCommandAutoWrap(this string str)
        {
            return $"\u0009\u0011{str}\u0009\u0012";
        }

        private static readonly ReadOnlyCollection<int> specialCharacters = new ReadOnlyCollection<int>(new int[]
        {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x09, 0x11, 0x12, 0x13, 0x19, 0x1E, 0xBF, 0xC2, 0xC3, 0xE0,
        });

        private static bool HasWidth(char c)
        {
            return !char.IsWhiteSpace(c) && !specialCharacters.Contains(c);
        }
    }
}
