using MMR.Randomizer.Utils.Mzxrules;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;

namespace MMR.Randomizer.Utils
{
    public static class ImageUtils
    {
        public static Bitmap CopyDataToBitmap(byte[] data, int width, int height, PixelFormat pixelFormat)
        {
            Bitmap bmp = new Bitmap(width, height, pixelFormat);

            BitmapData bmpData = bmp.LockBits(
                                 new Rectangle(0, 0, bmp.Width, bmp.Height),
                                 ImageLockMode.WriteOnly, bmp.PixelFormat);

            System.Runtime.InteropServices.Marshal.Copy(data, 0, bmpData.Scan0, data.Length);

            bmp.UnlockBits(bmpData);

            return bmp;
        }

        /// <summary>
        /// Converts a raw RGBA image into a ARGB image. Also reverses byte order.
        /// </summary>
        /// <param name="data"></param>
        /// <returns></returns>
        public static byte[] RgbaToArgb(byte[] data)
        {
            var copy = new byte[data.Length];
            for (var i = 0; i < data.Length; i += 4)
            {
                copy[i] = data[i + 2];
                copy[i + 1] = data[i + 1];
                copy[i + 2] = data[i];
                copy[i + 3] = data[i + 3];
            }
            return copy;
        }

        public static List<int> GetIconIndices(byte[] hash)
        {
            var numberOfIcons = 5;
            var value = Endian.ConvertInt32(BitConverter.ToInt32(hash, 0));
            var indices = new List<int>();
            for (var i = 0; i < numberOfIcons; i++)
            {
                indices.Add((value >> 26) & 0x3F);
                value <<= 6;
            }
            return indices;
        }
    }
}
