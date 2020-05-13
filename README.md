Majora's Mask Randomizer is a Windows application that randomizes item locations, music, and more for Majora's Mask, presenting millions of way to replay the game.


A video tutorial of setting up MMR is found here: https://www.youtube.com/watch?v=D0n829cYzl4

Currently the UI is only available on windows, it is broken in wine. The CLI version works if you install dotnet and run the CLI as "dotnet MMR.CLI.dll -input <MM.z64> [-seed *seed*]" but modifying the settings means modifying the settings.json by hand. A replacement webui is in development which will supply a UI on all platforms.

Additional information on every feature of MMR is available by reading the tooltip shown by hovering the mouse over the option, or reading the detailed manual by pressing F1, or visiting the help menu.

MMR has no unique emulator requirements, you can play a randomized rom with any method that allows you to play a MM rom. MMR roms work on N64 emulators, they can be played on N64 hardware with everdrive and similar flashcard technology, and they can be played on Wii Virtual Console, MMR will even convert the randomized rom to a wad for you.

## WARNINGS

In vanilla MM, you use [Garo's Mask] to convince the ghost to summon a tree and grant you ikana valley access, but in vanilla MM, he will also accept you wearing a [Gibdo Mask] and grant you ikana access. Most people don't know this because you get the Gibdo mask after getting access to the soaring owl and you never need to travel east up that cliff again if you don't want to, but MMR accepts both masks as giving you access.

MMR has a feature that allows you to use Fierce Diety mask anywhere, which is fun to play, but is slightly dangerous. His body is too big and can get stuck in tunnels and doors, play with him at your own risk. The same is true for playing as adult link.

MMR can randomize enemies on the overworld and in dungeons, which is fun to play, but is slightly dangerous. Enemizer currently ignores logic, which can lead to seeds being (rarely) unbeatable (bombs all being locked behind a beamos, enemies you can't kill or move being in your way, ect). Play with enemizer at your own risk.

Do not mask the A button during cutscenes that have fish, you can softlock (this is a vanilla MM bug)

There is a list of other known issues in the #known-issues channel of our discord, linked at the bottom of this page.

## FAQS 

Q: My ROM doesn't seem to work what's wrong?
A: The ROM should be a .z64 file (big endian). If it is not .z64 it will not work. Make sure you are not trying to use a ROM with a .n64 or .v64 extension. You will have to use Tool64 here to byteswap your ROM to "Big Endian": https://www.zophar.net/utilities/n64aud/tool-n64.html Also do NOT re-randomize a already randomized rom.

Q: I renamed my ROM to .z64 but it's not working?
A: DO NOT RENAME YOUR ROM! It has to be BYTESWAPED using Tool64 for it to work properly!

Q: It says I need the expansion pack when I try to boot! How do I fix this?
A: You need to be sure you are running the game with 8MB of ram (memory) not 4MB.
In P64 this can be found in Options > Settings > settings: MAJORAS MASK > Set memory to 8MB

Q: I checked "Wii Virtual Console Channel" but I cannot find my .wad file. Why?
A: Check in your %appdata% folder and the default wad folder with the randomizer.

Q: I'm getting an error about the randomizer not being able to find a path!
A: Extract everything from the zip file to an empty folder. The randomizer needs to have access to all files it comes with, the EXE alone is not enough.

Q: I'm starting with items I shouldn't/Why don't I have Ocarina?
A: You have to make a new save file in the randomizer, you cannot start with an old save made in another seed.

Q: I'm having some weird graphical errors! How can I fix this?
A: This is not a fault of the randomizer or your rom. This is a problem with whatever you are using to play the rom. Either Look up better graphical settings or look into a new method to play. If you have trouble come visit our discord #emulator-support channel we might be able to help.

Q: My emulator has a black screen/won't load/is not working.
A: Either try another emulator, try a different graphics plugin or download the P64 prebuilt created for playing MM in our discord #resources channel.

### Come visit our discord
Additional help and resources can be found at our discord: https://discord.gg/7jBRhhJ
