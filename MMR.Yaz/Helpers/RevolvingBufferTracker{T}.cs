using System;
using System.Runtime.CompilerServices;

namespace MMR.Yaz.Helpers
{
    /// <summary>
    /// Contains state used for tracking revolving buffer.
    /// </summary>
    /// <typeparam name="T">Type of element in buffer.</typeparam>
    ref struct RevolvingBufferTracker<T>
    {
        /// <summary>
        /// Amount of items currently being used.
        /// </summary>
        public int Amount { get; private set; }

        /// <summary>
        /// Origin index of buffer.
        /// </summary>
        public int Origin { get; private set; }

        /// <summary>
        /// Get an element at the specified index in a revolving buffer.
        /// </summary>
        /// <param name="self">Revolving buffer tracker.</param>
        /// <param name="index">Index.</param>
        /// <param name="buffer">Underlying buffer.</param>
        /// <returns>Element at specified index.</returns>
        /// <remarks>Does not check if the gotten byte is in bounds.</remarks>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static T Get(ref RevolvingBufferTracker<T> self, int index, Span<T> buffer)
        {
            var position = self.Origin + index;
            if (position < buffer.Length)
            {
                return buffer[position];
            }
            else
            {
                return buffer[position - buffer.Length];
            }
        }

        /// <summary>
        /// Put a given element into a revolving buffer at the specified index.
        /// </summary>
        /// <param name="self">Revolving buffer tracker.</param>
        /// <param name="index">Index.</param>
        /// <param name="item">Item to put.</param>
        /// <param name="buffer">Underlying buffer.</param>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static void Put(ref RevolvingBufferTracker<T> self, int index, T item, Span<T> buffer)
        {
            var position = self.Origin + index;
            if (position < buffer.Length)
            {
                buffer[position] = item;
            }
            else
            {
                buffer[position - buffer.Length] = item;
            }
        }

        /// <summary>
        /// Push an item to the "top" of the revolving buffer.
        /// </summary>
        /// <param name="self">Revolving buffer tracker.</param>
        /// <param name="item">Item to push.</param>
        /// <param name="buffer">Underlying buffer.</param>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static void Push(ref RevolvingBufferTracker<T> self, T item, Span<T> buffer)
        {
            if (self.Amount < buffer.Length)
            {
                // Console.WriteLine("Amount: {0:X4}, Origin: {1:X4}, Length: {2:X4}", self.Amount, self.Origin, buffer.Length);
                // Buffer is not yet full, overwrite unused item.
                /// var position = self.Origin + self.Amount;
                Put(ref self, self.Amount, item, buffer);
                self.Amount++;
            }
            else
            {
                // Buffer is full, advance origin and overwrite last byte.
                Put(ref self, 0, item, buffer);
                self.Origin = (self.Origin + 1) < buffer.Length ? (self.Origin + 1) : 0;
            }
        }

        /// <summary>
        /// Pop an item from the "top" of the revolving buffer.
        /// </summary>
        /// <param name="self">Revolving buffer tracker.</param>
        [MethodImpl(MethodImplOptions.AggressiveInlining)]
        public static void Pop(ref RevolvingBufferTracker<T> self)
        {
            if (self.Amount != 0)
            {
                self.Amount--;
            }
        }
    }
}
