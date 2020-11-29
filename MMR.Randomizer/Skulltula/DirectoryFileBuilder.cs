using MMR.Randomizer.Utils.Mzxrules;
using System;
using System.Collections.Generic;
using System.IO;

namespace MMR.Randomizer.Skulltula
{
    /// <summary>
    /// Builds "DirectoryFile" files, performing compression at time of adding file.
    /// </summary>
    public class DirectoryFileBuilder
    {
        private List<byte[]> _innerFiles = new List<byte[]>();

        void CompressAndAddFile(byte[] innerFile)
        {
            // Encode file data as Yaz0.
            var encodedSize = Yaz.Encode(innerFile, innerFile.Length, out byte[] encodedBytes);
            if (encodedSize < 0)
            {
                // Todo: Refine later.
                throw new Exception("Unable to Yaz0-encode file bytes");
            }
            // If returned length does not match buffer size, is not 0x10-byte aligned.
            if (encodedBytes.Length != encodedSize)
            {
                // Copy encoded bytes into buffer with aligned size.
                var temp = new byte[encodedSize];
                Buffer.BlockCopy(encodedBytes, 0, temp, 0, temp.Length);
                encodedBytes = temp;
            }
            _innerFiles.Add(encodedBytes);
        }

        /// <summary>
        /// Compress and add data for file.
        /// </summary>
        /// <param name="innerFile">File data to compress and add</param>
        /// <returns>Index of added file.</returns>
        public int AddInnerFile(byte[] innerFile)
        {
            var index = _innerFiles.Count;
            CompressAndAddFile(innerFile);
            return index;
        }

        /// <summary>
        /// Build to full file bytes.
        /// </summary>
        /// <returns>Bytes.</returns>
        public byte[] Build()
        {
            if (_innerFiles.Count <= 0)
            {
                throw new IndexOutOfRangeException("Cannot build DirectoryFile unless it contains at least 1 child file.");
            }

            var indexSize = (_innerFiles.Count * 4);
            var offsets = new uint[_innerFiles.Count];
            var expectedSize = indexSize;
            offsets[0] = (uint)indexSize;
            // Iterate once over inner files, to build offset table and calculate full size to reserve.
            for (int i = 0; i < _innerFiles.Count; i++)
            {
                var encodedBytes = _innerFiles[i];
                expectedSize += encodedBytes.Length;
                if (i < (offsets.Length - 1))
                {
                    offsets[i + 1] = (offsets[i] + (uint)encodedBytes.Length) - offsets[0];
                }
            }
            using (var memoryStream = new MemoryStream(expectedSize))
            using (var writer = new BinaryWriter(memoryStream))
            {
                // Write offset table.
                for (int i = 0; i < offsets.Length; i++)
                {
                    var offsetBytes = BitConverter.GetBytes(offsets[i]);
                    Array.Reverse(offsetBytes);
                    writer.Write(offsetBytes);
                }
                // Write encoded file data.
                for (int i = 0; i < _innerFiles.Count; i++)
                {
                    writer.Write(_innerFiles[i]);
                }
                return memoryStream.ToArray();
            }
        }
    }
}
