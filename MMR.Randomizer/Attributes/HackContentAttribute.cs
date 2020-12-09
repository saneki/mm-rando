using System;
using System.Reflection;

namespace MMR.Randomizer.Attributes
{
    public class HackContentAttribute : Attribute
    {
        public byte[] HackContent { get; }

        public HackContentAttribute(string modResourcePropertyName)
        {
            if (modResourcePropertyName != null)
            {
                HackContent = (byte[])typeof(Resources.mods).GetProperty(modResourcePropertyName, BindingFlags.Static).GetValue(null);
            }
        }
    }
}
