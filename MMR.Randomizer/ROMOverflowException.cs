using System;
using System.Collections.Generic;
using System.Text;

namespace MMR.Randomizer
{
    public class ROMOverflowException : Exception
    {
        public ROMOverflowException(string message) : base(message)
        {
        }
    }

}
