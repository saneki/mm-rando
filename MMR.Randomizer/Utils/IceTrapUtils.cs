using MMR.Common.Extensions;
using MMR.Randomizer.Attributes;
using MMR.Randomizer.Extensions;
using MMR.Randomizer.Models;
using MMR.Randomizer.Models.Settings;
using System;
using System.Collections.Generic;

namespace MMR.Randomizer.Utils
{
    public static class IceTrapUtils
    {
        /// <summary>
        /// Get all junk items which are replaceable by ice traps.
        /// </summary>
        /// <param name="itemList">Source items</param>
        /// <param name="onslaught">Whether or not non-randomized junk items should be selected as well</param>
        /// <returns>Replaceable junk items.</returns>
        public static ItemObject[] GetJunkItems(ItemList itemList, bool onslaught = false)
        {
            return itemList.FindAll(x => {
                return (x.IsRandomized || onslaught) && x.NewLocation != null /* && !x.NewLocation.Value.IsShop() */
                && (x.Item.Name().Contains("Rupee") || x.Item.Name().Contains("Arrows") ||
                    x.Item.Name().Contains("Bombs") || x.Item.Name().Contains("Bombchu") ||
                    x.Item.Name().Contains("Deku Nuts"));
            }).ToArray();
        }

        /// <summary>
        /// Select random junk items to replace given <see cref="IceTraps"/> settings.
        /// </summary>
        /// <param name="itemList">Source items</param>
        /// <param name="iceTraps">Settings</param>
        /// <param name="random">Random</param>
        /// <returns>Junk items to replace.</returns>
        public static ItemObject[] SelectJunkItems(ItemList itemList, IceTraps iceTraps, Random random)
        {
            var onslaught = iceTraps == IceTraps.Onslaught;
            var allJunk = GetJunkItems(itemList, onslaught);
            if (iceTraps == IceTraps.None)
            {
                return new ItemObject[0];
            }
            else if (iceTraps == IceTraps.Normal)
            {
                var amount = allJunk.Length / 20;
                return allJunk.Random(amount, random);
            }
            else if (iceTraps == IceTraps.Extra)
            {
                var amount = allJunk.Length / 10;
                return allJunk.Random(amount, random);
            }
            else
            {
                return allJunk;
            }
        }

        /// <summary>
        /// Get chest type override for ice trap based on appearance setting.
        /// </summary>
        /// <param name="appearance">Ice trap appearance setting</param>
        /// <param name="random">Random</param>
        /// <returns>Chest type.</returns>
        public static ChestTypeAttribute.ChestType GetIceTrapChestTypeOverride(IceTrapAppearance appearance, Random random)
        {
            if (appearance == IceTrapAppearance.MajorItems)
            {
                return ChestTypeAttribute.ChestType.LargeGold;
            }
            else if (appearance == IceTrapAppearance.JunkItems)
            {
                return ChestTypeAttribute.ChestType.SmallWooden;
            }
            else
            {
                var choices = new ChestTypeAttribute.ChestType[]
                {
                    ChestTypeAttribute.ChestType.LargeGold,
                    ChestTypeAttribute.ChestType.SmallGold,
                    ChestTypeAttribute.ChestType.SmallWooden,
                };
                return choices[random.Next(choices.Length)];
            }
        }

        /// <summary>
        /// Fix <see cref="MimicItem"/> name for spoiler log.
        /// </summary>
        /// <param name="name">Existing name</param>
        /// <returns>Fixed name.</returns>
        public static string FixItemGraphicName(string name)
        {
            if (name.Contains("Compass")) name = "Compass";
            else if (name.Contains("Map of")) name = "Tingle Map";
            else if (name.Contains("Map")) name = "Dungeon Map";
            else if (name.Contains("Small Key")) name = "Small Key";
            else if (name.Contains("Boss Key")) name = "Boss Key";
            return name;
        }

        /// <summary>
        /// Build set of mimic items from the randomization pool which ice traps may use.
        /// </summary>
        /// <param name="itemList">Randomized items</param>
        /// <param name="appearance">Ice trap appearance setting</param>
        /// <param name="songs">Whether or not song items may be used as mimic</param>
        /// <returns>Mimic item set.</returns>
        public static HashSet<MimicItem> BuildIceTrapMimicSet(ItemList itemList, IceTrapAppearance appearance, bool songs = false)
        {
            var mimics = new HashSet<MimicItem>();
            foreach (var itemObj in itemList)
            {
                var index = itemObj.Item.GetItemIndex();
                var allowSong = songs || !itemObj.Item.IsSong();
                if (index.HasValue && allowSong)
                {
                    var chestType = itemObj.Item.ChestType();
                    if ((appearance == IceTrapAppearance.MajorItems && chestType == ChestTypeAttribute.ChestType.LargeGold) ||
                        (appearance == IceTrapAppearance.MajorItems && chestType == ChestTypeAttribute.ChestType.SmallGold) ||
                        (appearance == IceTrapAppearance.JunkItems && chestType == ChestTypeAttribute.ChestType.SmallWooden) ||
                        (appearance == IceTrapAppearance.Anything))
                    {
                        // Fix item name for spoiler log.
                        // var name = FixItemGraphicName(itemObj.Item.Name());
                        var name = itemObj.Item.Name();

                        // Add mimic item to set.
                        var mimicItem = new MimicItem(itemObj.Item, name);
                        mimics.Add(mimicItem);
                    }
                }
            }
            return mimics;
        }
    }
}
