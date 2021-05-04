using MMR.Randomizer.LogicMigrator;
using MMR.Randomizer.Properties;
using MMR.Randomizer.GameObjects;
using MMR.UI.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.Json;

namespace MMR.UI.Forms
{
    public partial class LogicEditorForm : Form
    {
        bool updating = false;
        int n;

        private readonly int _defaultItemCount;

        private LogicFile logic;
        private Dictionary<string, JsonFormatLogicItem> itemsById;

        private class LogicFile
        {
            public int Version { get; set; }
            public List<JsonFormatLogicItem> Logic { get; set; }
        }

        private class JsonFormatLogicItem
        {
            public string Id { get; set; }
            public List<string> RequiredItems { get; set; } = new List<string>();
            public List<List<string>> ConditionalItems { get; set; } = new List<List<string>>();
            public TimeOfDay TimeNeeded { get; set; }
            public TimeOfDay TimeAvailable { get; set; }
            public bool IsTrick { get; set; }
            public string TrickTooltip { get; set; } = string.Empty;
        }

        [Flags]
        public enum TimeOfDay
        {
            None,
            Day1   = 1,
            Night1 = 2,
            Day2   = 4,
            Night2 = 8,
            Day3   = 16,
            Night3 = 32,
        }

        private void CheckOnTrue(CheckBox a, int n, int m)
        {
            if (((n >> m) & 1) > 0)
            {
                a.Checked = true;
            }
            else
            {
                a.Checked = false;
            };
        }

        private void FillDependence(int n)
        {
            lRequired.Items.Clear();
            foreach (var item in logic.Logic[n].RequiredItems)
            {
                lRequired.Items.Add(item);
            }
        }

        private void UpdateDependence(int n)
        {
            ItemSelectorForm ItemSelect = new ItemSelectorForm();
            DialogResult R = ItemSelect.ShowDialog();
            if (R == DialogResult.OK)
            {
                List<int> Returned = ItemSelectorForm.ReturnItems;
                if (Returned.Count == 0)
                {
                    return;
                }
                foreach (var returnedItemIndex in Returned)
                {
                    var returnedItemId = logic.Logic[returnedItemIndex].Id;
                    var requiredItems = logic.Logic[n].RequiredItems;
                    if (!requiredItems.Contains(returnedItemId))
                    {
                        requiredItems.Add(returnedItemId);
                    }
                }
                FillDependence(n);
            }
        }

        private void FillConditional(int n)
        {
            lConditional.Items.Clear();
            foreach (var conditional in logic.Logic[n].ConditionalItems)
            {
                var label = string.Join(",", conditional); // TODO .Select updated item name
                lConditional.Items.Add(label);
            }
        }

        private void UpdateConditional(int n, int? conditionalIndex = null)
        {
            List<int> selectedItems = null;
            if (conditionalIndex.HasValue)
            {
                selectedItems = logic.Logic[n].ConditionalItems[conditionalIndex.Value].Select(c => logic.Logic.IndexOf(itemsById[c])).ToList();
            }
            ItemSelectorForm ItemSelect = new ItemSelectorForm(selectedItems);
            DialogResult R = ItemSelect.ShowDialog();
            if (R == DialogResult.OK)
            {
                List<int> Returned = ItemSelectorForm.ReturnItems;
                if (Returned.Count == 0)
                {
                    return;
                }
                if (conditionalIndex.HasValue)
                {
                    logic.Logic[n].ConditionalItems[conditionalIndex.Value] = Returned.Select(index => logic.Logic[index].Id).ToList();
                }
                else
                {
                    logic.Logic[n].ConditionalItems.Add(Returned.Select(index => logic.Logic[index].Id).ToList());
                }
                FillConditional(n);
            }
        }

        private void FillTime(int n)
        {
            var itemLogic = logic.Logic[n];

            cNDay1.Checked = itemLogic.TimeNeeded.HasFlag(TimeOfDay.Day1);
            cNNight1.Checked = itemLogic.TimeNeeded.HasFlag(TimeOfDay.Night1);
            cNDay2.Checked = itemLogic.TimeNeeded.HasFlag(TimeOfDay.Day2);
            cNNight2.Checked = itemLogic.TimeNeeded.HasFlag(TimeOfDay.Night2);
            cNDay3.Checked = itemLogic.TimeNeeded.HasFlag(TimeOfDay.Day3);
            cNNight3.Checked = itemLogic.TimeNeeded.HasFlag(TimeOfDay.Night3);

            cADay1.Checked = itemLogic.TimeAvailable.HasFlag(TimeOfDay.Day1);
            cANight1.Checked = itemLogic.TimeAvailable.HasFlag(TimeOfDay.Night1);
            cADay2.Checked = itemLogic.TimeAvailable.HasFlag(TimeOfDay.Day2);
            cANight2.Checked = itemLogic.TimeAvailable.HasFlag(TimeOfDay.Night2);
            cADay3.Checked = itemLogic.TimeAvailable.HasFlag(TimeOfDay.Day3);
            cANight3.Checked = itemLogic.TimeAvailable.HasFlag(TimeOfDay.Night3);
        }

        private void UpdateTime(int n)
        {
            var Av = TimeOfDay.None;
            if (cADay1.Checked) { Av |= TimeOfDay.Day1; }
            if (cANight1.Checked) { Av |= TimeOfDay.Night1; }
            if (cADay2.Checked) { Av |= TimeOfDay.Day2; }
            if (cANight2.Checked) { Av |= TimeOfDay.Night2; }
            if (cADay3.Checked) { Av |= TimeOfDay.Day3; }
            if (cANight3.Checked) { Av |= TimeOfDay.Night3; }
            logic.Logic[n].TimeAvailable = Av;
            var Ne = TimeOfDay.None;
            if (cNDay1.Checked) { Ne |= TimeOfDay.Day1; }
            if (cNNight1.Checked) { Ne |= TimeOfDay.Night1; }
            if (cNDay2.Checked) { Ne |= TimeOfDay.Day2; }
            if (cNNight2.Checked) { Ne |= TimeOfDay.Night2; }
            if (cNDay3.Checked) { Ne |= TimeOfDay.Day3; }
            if (cNNight3.Checked) { Ne |= TimeOfDay.Night3; }
            logic.Logic[n].TimeNeeded = Ne;
        }

        private void FillTrick(int n)
        {
            cTrick.Checked = logic.Logic[n].IsTrick;
            tTrickDescription.Text = logic.Logic[n].TrickTooltip ?? "(optional tooltip)";
            tTrickDescription.ForeColor = logic.Logic[n].TrickTooltip != null ? SystemColors.WindowText : SystemColors.WindowFrame;
        }

        public LogicEditorForm()
        {
            InitializeComponent();
            Reset();
            _defaultItemCount = logic.Logic.Count;
            nItem.Minimum = 0;
            nItem.Maximum = logic.Logic.Count - 1;
            nItem.Value = 0;
        }

        private void Reset()
        {
            logic = new LogicFile
            {
                Logic = Enum.GetValues<Item>().Where(item => item >= 0).Select(item => new JsonFormatLogicItem
                {
                    Id = item.ToString(),
                    RequiredItems = new List<string>(),
                    ConditionalItems = new List<List<string>>(),
                    TimeAvailable = TimeOfDay.None,
                    TimeNeeded = TimeOfDay.None,
                    IsTrick = false,
                    TrickTooltip = string.Empty,
                }).ToList(),
            };
        }

        private void fLogicEdit_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing)
            {
                e.Cancel = true;
                Hide();
            };
        }

        private void nItem_ValueChanged(object sender, EventArgs e)
        {
            SetIndex((int)nItem.Value);
        }

        private void SetIndex(int index)
        {
            n = index;
            lIName.Text = logic.Logic[n].Id;
            updating = true;
            FillDependence(n);
            FillConditional(n);
            FillTime(n);
            FillTrick(n);
            var isCustomItem = index >= _defaultItemCount;
            bRenameItem.Visible = isCustomItem;
            bDeleteItem.Visible = isCustomItem;
            cTrick.Visible = isCustomItem;
            tTrickDescription.Visible = isCustomItem;
            updating = false;
        }

        private void cNDay1_CheckedChanged(object sender, EventArgs e)
        {
            if (updating)
            {
                return;
            };
            UpdateTime(n);
        }

        private void bReqAdd_Click(object sender, EventArgs e)
        {
            UpdateDependence(n);
        }

        private void bConAdd_Click(object sender, EventArgs e)
        {
            UpdateConditional(n);
        }

        private void bReqClear_Click(object sender, EventArgs e)
        {
            if (lRequired.SelectedIndex != -1)
            {
                logic.Logic[n].RequiredItems.RemoveAt(lRequired.SelectedIndex);
                FillDependence(n);
            };
        }

        private void bConClear_Click(object sender, EventArgs e)
        {
            if (lConditional.SelectedIndex != -1)
            {
                logic.Logic[n].ConditionalItems.RemoveAt(lConditional.SelectedIndex);
                FillConditional(n);
            };
        }

        private void mNew_Click(object sender, EventArgs e)
        {
            ItemSelectorForm.ResetItems();
            Reset();
            nItem.Minimum = 0;
            nItem.Maximum = logic.Logic.Count - 1;
            nItem.Value = 1;
            nItem.Value = 0;
        }

        private void mImport_Click(object sender, EventArgs e)
        {
            if (openLogic.ShowDialog() == DialogResult.OK)
            {
                using (var logicFile = new StreamReader(File.OpenRead(openLogic.FileName)))
                {
                    var logicString = logicFile.ReadToEnd();
                    LoadLogic(logicString);
                }
            }
        }

        private void mSave_Click(object sender, EventArgs e)
        {
            if (saveLogic.ShowDialog() == DialogResult.OK)
            {
                logic.Version = Migrator.CurrentVersion;
                using (var writer = new StreamWriter(File.Open(saveLogic.FileName, FileMode.Create)))
                {
                    writer.Write(JsonSerializer.Serialize(logic));
                }
            }
        }

        private void btn_new_item_Click(object sender, EventArgs e)
        {
            using (var newItemForm = new NewItemForm())
            {
                var result = newItemForm.ShowDialog();
                if (result == DialogResult.OK)
                {
                    var newItem = new JsonFormatLogicItem
                    {
                        Id = newItemForm.ReturnValue,
                    };
                    logic.Logic.Add(newItem);
                    itemsById[newItem.Id] = newItem;
                    nItem.Maximum = logic.Logic.Count - 1;
                    nItem.Value = nItem.Maximum;
                    ItemSelectorForm.AddItem(newItemForm.ReturnValue);
                }
            }
        }

        private void lConditional_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            var index = lConditional.IndexFromPoint(e.Location);
            if (index != ListBox.NoMatches)
            {
                var conditions = logic.Logic[n].ConditionalItems[index];
                var conditionIndices = conditions.Select(c => logic.Logic.IndexOf(itemsById[c])).ToList();
                if (conditionIndices.Count == 1)
                {
                    nItem.Value = conditionIndices[0];
                }
                else
                {
                    var itemSelect = new ItemSelectorForm(checkboxes: false, highlightedItems: conditionIndices);
                    var result = itemSelect.ShowDialog();
                    if (result == DialogResult.OK && ItemSelectorForm.ReturnItems.Any())
                    {
                        var itemIndex = ItemSelectorForm.ReturnItems.First();
                        nItem.Value = itemIndex;
                    }
                }
            }
        }

        private void button_goto_Click(object sender, EventArgs e)
        {
            var itemSelect = new ItemSelectorForm(checkboxes: false);
            var result = itemSelect.ShowDialog();
            if (result == DialogResult.OK && ItemSelectorForm.ReturnItems.Any())
            {
                var itemIndex = ItemSelectorForm.ReturnItems.First();
                nItem.Value = itemIndex;
            }
        }

        private void lRequired_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            var index = lRequired.IndexFromPoint(e.Location);
            if (index != ListBox.NoMatches)
            {
                var gotoItemIndex = logic.Logic[n].RequiredItems[index];
                nItem.Value = logic.Logic.IndexOf(itemsById[gotoItemIndex]);
            }
        }

        private void bConEdit_MouseClick(object sender, MouseEventArgs e)
        {
            var index = lConditional.SelectedIndex;
            if (index != ListBox.NoMatches)
            {
                UpdateConditional(n, index);
            }
        }

        private void bConClone_Click(object sender, EventArgs e)
        {
            var index = lConditional.SelectedIndex;
            if (index != ListBox.NoMatches)
            {
                logic.Logic[n].ConditionalItems.Insert(index + 1, logic.Logic[n].ConditionalItems[index]);
                FillConditional(n);
            }
        }

        private void casualToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            LoadLogic(Resources.REQ_CASUAL);
        }

        private void glitchedToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            LoadLogic(Resources.REQ_GLITCH);
        }

        private void LoadLogic(string logicString)
        {
            logicString = Migrator.ApplyMigrations(logicString);
            logic = JsonSerializer.Deserialize<LogicFile>(logicString);
            itemsById = logic.Logic.ToDictionary(item => item.Id);
            // TODO update ItemSelectorForm
            nItem.Maximum = logic.Logic.Count - 1;
            SetIndex((int)nItem.Value);
        }

        private void bRenameItem_Click(object sender, EventArgs e)
        {
            using (var newItemForm = new NewItemForm())
            {
                var result = newItemForm.ShowDialog();
                if (result == DialogResult.OK)
                {
                    var oldValue = logic.Logic[n].Id;
                    var newValue = newItemForm.ReturnValue;
                    foreach (var item in logic.Logic)
                    {
                        item.RequiredItems = item.RequiredItems.Select(ri => ri == oldValue ? newValue : ri).ToList();
                        item.ConditionalItems = item.ConditionalItems.Select(c => c.Select(ci => ci == oldValue ? newValue : ci).ToList()).ToList();
                    }
                    logic.Logic[n].Id = newValue;
                    ItemSelectorForm.RenameItem(n, newItemForm.ReturnValue);
                    lIName.Text = newItemForm.ReturnValue;
                }
            }
        }

        private void bDeleteItem_Click(object sender, EventArgs e)
        {
            string message;
            string caption;
            MessageBoxButtons buttons;
            var id = logic.Logic[n].Id;
            var usedBy = logic.Logic.Where(il => il.RequiredItems.Contains(id) || il.ConditionalItems.Any(c => c.Contains(id))).ToList();
            if (usedBy.Any())
            {
                // in use
                caption = "Error";
                message = "This item is in use by:\n"+ string.Join("\n", usedBy.Take(5).Select(il => "* " + il.Id));
                if (usedBy.Count > 5)
                {
                    message += $"\nand {usedBy.Count-5} other{(usedBy.Count > 6 ? "s" : "")}.";
                }
                buttons = MessageBoxButtons.OK;
            }
            else
            {
                // not in use
                caption = "Warning";
                message = "Are you sure you want to delete this item?";
                buttons = MessageBoxButtons.YesNo;
            }
            var result = MessageBox.Show(message, caption, buttons);
            if (result == DialogResult.Yes)
            {
                logic.Logic.RemoveAt(n);
                ItemSelectorForm.RemoveItem(n);
                SetIndex(n);
            }
        }

        private const string DEFAULT_TRICK_TOOLTIP = "(optional tooltip)";

        private void tTrickDescription_TextChanged(object sender, EventArgs e)
        {
            logic.Logic[n].TrickTooltip = string.IsNullOrWhiteSpace(tTrickDescription.Text) || tTrickDescription.Text == DEFAULT_TRICK_TOOLTIP
                ? null
                : tTrickDescription.Text;
        }

        private void tTrickDescription_Enter(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(logic.Logic[n].TrickTooltip))
            {
                tTrickDescription.Text = string.Empty;
                tTrickDescription.ForeColor = SystemColors.WindowText;
            }
        }

        private void cTrick_CheckedChanged(object sender, EventArgs e)
        {
            logic.Logic[n].IsTrick = cTrick.Checked;
        }

        private void tTrickDescription_Leave(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(logic.Logic[n].TrickTooltip))
            {
                tTrickDescription.Text = DEFAULT_TRICK_TOOLTIP;
                tTrickDescription.ForeColor = SystemColors.WindowFrame;
            }
        }

        private void bCopy_Click(object sender, EventArgs e)
        {
            var itemSelect = new ItemSelectorForm(checkboxes: false);
            var result = itemSelect.ShowDialog();
            if (result == DialogResult.OK && ItemSelectorForm.ReturnItems.Any())
            {
                var itemIndex = ItemSelectorForm.ReturnItems.First();

                logic.Logic[n].RequiredItems = logic.Logic[itemIndex].RequiredItems.ToList();
                logic.Logic[n].ConditionalItems = logic.Logic[itemIndex].ConditionalItems.Select(c => c.ToList()).ToList();
                logic.Logic[n].IsTrick = logic.Logic[itemIndex].IsTrick;
                logic.Logic[n].TimeAvailable = logic.Logic[itemIndex].TimeAvailable;
                logic.Logic[n].TimeNeeded = logic.Logic[itemIndex].TimeNeeded;
                logic.Logic[n].TrickTooltip = logic.Logic[itemIndex].TrickTooltip;

                SetIndex(n);
                //nItem.Value = itemIndex;
            }
        }
    }
}
