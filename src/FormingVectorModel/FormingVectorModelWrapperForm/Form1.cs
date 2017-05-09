using System;
using System.Windows.Forms;

namespace FormingVectorModelWrapperForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            fileNameTextBox.Text = @"D:\diss\FormingVectorModel\data\2.png";
            binarizationComboBox.SelectedIndex = 2;
            skeletizationComboBox.SelectedIndex = 2;
        }

        private void runButton_Click(object sender, EventArgs e)
        {
            this.Enabled = false;
            FormingVectorModelWrapper.FormingVectorModel.LaunchExe(GetQuery());
            this.Enabled = true;
        }

        private void binarizationComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            binarizationParametrTextBox.Enabled = binarizationComboBox.SelectedIndex == 3;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                fileNameTextBox.Text = openFileDialog1.FileName;
            }
        }

        private string GetQuery()
        {
            string query = "";
            query += fileNameTextBox.Text + " ";

            query += writeIntermediateResultsCheckBox.Checked.ToString().ToLower() + " ";

            if (grayscaleCheckBox.Checked)
            {
                query += "grayscalation ";
            }

            if (invertCheckBox.Checked)
            {
                query += "invertation ";
            }

            switch (skeletizationComboBox.SelectedIndex)
            {
                case 1:
                    query += "middleThresholdBinarization ";
                    break;

                case 2:
                    query += "otsuBinarization ";
                    break;

                case 3:
                    query += "paremetrizedBinarization " + binarizationParametrTextBox.Text + " ";
                    break;

                default:
                    break;
            }

            if (singleNoisePointsRemoverCheckBox.Checked)
            {
                query += "noiseRemove ";
            }

            switch (skeletizationComboBox.SelectedIndex)
            {
                case 1:
                    query += "zhangSuenSkeletization ";
                    break;

                case 2:
                    query += "guoHallSkeletization ";
                    break;

                default:
                    break;
            }

            if (vectorizationCheckBox.Checked)
            {
                query += "vectorization";
            }

            return query;
        }
    }
}
