using MMR.Randomizer.Models.Rom;
using NUnit.Framework;
using System.Linq;

namespace MMR.Yaz.Tests
{
    public class RomEncodeTests
    {
        const string RomFilename = "Rom.z64";

        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void TestEncoding()
        {
            var rom = RomFile.From(RomFilename);
            var compressedFiles = rom.Files.Where(x => x.IsCompressed).ToArray();
            foreach (var entry in compressedFiles)
            {
                PerformCompression(rom, entry);
            }
        }

        static void PerformCompression(RomFile rom, VirtualFile entry)
        {
            var length = entry.PhysicalEnd - entry.PhysicalStart;
            var slice = rom.Buffer.Span.Slice((int)entry.PhysicalStart, (int)length);
            var decoded = Yaz.Decode(slice);
            var encodedLength = Yaz.Encode(decoded, out var encoded);
            var aligned = (encodedLength + 0xF) & -0x10;
            // Currently only compares compressed lengths, as compressed output is likely slightly different due to optimization.
            Assert.AreEqual(slice.Length, aligned);
        }
    }
}
