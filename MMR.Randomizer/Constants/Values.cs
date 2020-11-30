﻿using System;
using System.Collections.ObjectModel;
using System.IO;

namespace MMR.Randomizer.Constants
{
    public static class Values
    {

        public static string MainDirectory = AppDomain.CurrentDomain.BaseDirectory;
        public static string MusicDirectory = Path.Combine(MainDirectory, "music");
        public static string VCDirectory = Path.Combine(MainDirectory, "vc");

        public const byte VanillaClockSpeed = 3;

        public static readonly uint[,] TatlColours = new uint[,] { // normal, npc, check, enemy, boss
            { 0xffffe6ff, 0xdca05000, 0x9696ffff, 0x9696ff00, 0x00ff00ff, 0x00ff0000, 0xffff00ff, 0xc89b0000, 0xffff00ff, 0xc89b0000 },
            { 0x200020ff, 0x80000000, 0x001080ff, 0x0080ff00, 0x104000ff, 0x80ff0000, 0x800000ff, 0x20002000, 0x800000ff, 0xff800000 },
            { 0xffc0e0ff, 0xff00ff00, 0xe040ffff, 0xff000000, 0xff80ffff, 0xff00ff00, 0xffe000ff, 0xff000000, 0xff0000ff, 0xff000000 },
            { 0xc0ffffff, 0x0000ff00, 0xffffffff, 0x00ffff00, 0x00ffffff, 0x00ffff00, 0xc080ffff, 0x0000ff00, 0x8080ffff, 0x0000ff00 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
        };

        public static readonly ReadOnlyCollection<int> DCFlags
            = new ReadOnlyCollection<int>(new int[] {
                0x57C, 0x589, 0x59C, 0x59F
        });

        public static readonly ReadOnlyCollection<int> DCFlagMasks
            = new ReadOnlyCollection<int>(new int[] {
                0x02, 0x80, 0x20, 0x80
        });

        public static readonly ReadOnlyCollection<byte> DCSceneIds
            = new ReadOnlyCollection<byte>(new byte[] {
                0x1F, 0x44, 0x36, 0x5F
        });

    }
}
