namespace FormingVectorModelWrapperForm
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.runButton = new System.Windows.Forms.Button();
            this.vectorizationCheckBox = new System.Windows.Forms.CheckBox();
            this.skeletizationComboBox = new System.Windows.Forms.ComboBox();
            this.singleNoisePointsRemoverCheckBox = new System.Windows.Forms.CheckBox();
            this.binarizationParametrTextBox = new System.Windows.Forms.TextBox();
            this.binarizationComboBox = new System.Windows.Forms.ComboBox();
            this.invertCheckBox = new System.Windows.Forms.CheckBox();
            this.grayscaleCheckBox = new System.Windows.Forms.CheckBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.button2 = new System.Windows.Forms.Button();
            this.fileNameTextBox = new System.Windows.Forms.TextBox();
            this.writeIntermediateResultsCheckBox = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pictureBox1.BackColor = System.Drawing.Color.White;
            this.pictureBox1.Location = new System.Drawing.Point(279, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(524, 287);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox1.Controls.Add(this.vectorizationCheckBox);
            this.groupBox1.Controls.Add(this.skeletizationComboBox);
            this.groupBox1.Controls.Add(this.singleNoisePointsRemoverCheckBox);
            this.groupBox1.Controls.Add(this.binarizationParametrTextBox);
            this.groupBox1.Controls.Add(this.binarizationComboBox);
            this.groupBox1.Controls.Add(this.invertCheckBox);
            this.groupBox1.Controls.Add(this.grayscaleCheckBox);
            this.groupBox1.Location = new System.Drawing.Point(12, 41);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(261, 169);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Actions";
            // 
            // runButton
            // 
            this.runButton.Location = new System.Drawing.Point(12, 260);
            this.runButton.Name = "runButton";
            this.runButton.Size = new System.Drawing.Size(155, 23);
            this.runButton.TabIndex = 8;
            this.runButton.Text = "Run";
            this.runButton.UseVisualStyleBackColor = true;
            this.runButton.Click += new System.EventHandler(this.runButton_Click);
            // 
            // vectorizationCheckBox
            // 
            this.vectorizationCheckBox.AutoSize = true;
            this.vectorizationCheckBox.Checked = true;
            this.vectorizationCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.vectorizationCheckBox.Location = new System.Drawing.Point(6, 142);
            this.vectorizationCheckBox.Name = "vectorizationCheckBox";
            this.vectorizationCheckBox.Size = new System.Drawing.Size(79, 17);
            this.vectorizationCheckBox.TabIndex = 7;
            this.vectorizationCheckBox.Text = "Vectorizate";
            this.vectorizationCheckBox.UseVisualStyleBackColor = true;
            // 
            // skeletizationComboBox
            // 
            this.skeletizationComboBox.FormattingEnabled = true;
            this.skeletizationComboBox.Items.AddRange(new object[] {
            "Without skeletization",
            "Zhang Suen skeletization",
            "Guo Hall skeletization"});
            this.skeletizationComboBox.Location = new System.Drawing.Point(6, 115);
            this.skeletizationComboBox.Name = "skeletizationComboBox";
            this.skeletizationComboBox.Size = new System.Drawing.Size(155, 21);
            this.skeletizationComboBox.TabIndex = 6;
            // 
            // singleNoisePointsRemoverCheckBox
            // 
            this.singleNoisePointsRemoverCheckBox.AutoSize = true;
            this.singleNoisePointsRemoverCheckBox.Checked = true;
            this.singleNoisePointsRemoverCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.singleNoisePointsRemoverCheckBox.Location = new System.Drawing.Point(6, 92);
            this.singleNoisePointsRemoverCheckBox.Name = "singleNoisePointsRemoverCheckBox";
            this.singleNoisePointsRemoverCheckBox.Size = new System.Drawing.Size(94, 17);
            this.singleNoisePointsRemoverCheckBox.TabIndex = 5;
            this.singleNoisePointsRemoverCheckBox.Text = "Remove noise";
            this.singleNoisePointsRemoverCheckBox.UseVisualStyleBackColor = true;
            // 
            // binarizationParametrTextBox
            // 
            this.binarizationParametrTextBox.Enabled = false;
            this.binarizationParametrTextBox.Location = new System.Drawing.Point(167, 65);
            this.binarizationParametrTextBox.Name = "binarizationParametrTextBox";
            this.binarizationParametrTextBox.Size = new System.Drawing.Size(77, 20);
            this.binarizationParametrTextBox.TabIndex = 4;
            // 
            // binarizationComboBox
            // 
            this.binarizationComboBox.FormattingEnabled = true;
            this.binarizationComboBox.Items.AddRange(new object[] {
            "Without binarization",
            "Middle Threshold binarization",
            "Otsu binarization",
            "Paremetrized binarization"});
            this.binarizationComboBox.Location = new System.Drawing.Point(6, 65);
            this.binarizationComboBox.Name = "binarizationComboBox";
            this.binarizationComboBox.Size = new System.Drawing.Size(155, 21);
            this.binarizationComboBox.TabIndex = 3;
            this.binarizationComboBox.SelectedIndexChanged += new System.EventHandler(this.binarizationComboBox_SelectedIndexChanged);
            // 
            // invertCheckBox
            // 
            this.invertCheckBox.AutoSize = true;
            this.invertCheckBox.Checked = true;
            this.invertCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.invertCheckBox.Location = new System.Drawing.Point(6, 42);
            this.invertCheckBox.Name = "invertCheckBox";
            this.invertCheckBox.Size = new System.Drawing.Size(53, 17);
            this.invertCheckBox.TabIndex = 1;
            this.invertCheckBox.Text = "Invert";
            this.invertCheckBox.UseVisualStyleBackColor = true;
            // 
            // grayscaleCheckBox
            // 
            this.grayscaleCheckBox.AutoSize = true;
            this.grayscaleCheckBox.Checked = true;
            this.grayscaleCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.grayscaleCheckBox.Location = new System.Drawing.Point(6, 19);
            this.grayscaleCheckBox.Name = "grayscaleCheckBox";
            this.grayscaleCheckBox.Size = new System.Drawing.Size(73, 17);
            this.grayscaleCheckBox.TabIndex = 0;
            this.grayscaleCheckBox.Text = "Grayscale";
            this.grayscaleCheckBox.UseVisualStyleBackColor = true;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(12, 12);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 2;
            this.button2.Text = "Open";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // fileNameTextBox
            // 
            this.fileNameTextBox.Location = new System.Drawing.Point(93, 14);
            this.fileNameTextBox.Name = "fileNameTextBox";
            this.fileNameTextBox.Size = new System.Drawing.Size(180, 20);
            this.fileNameTextBox.TabIndex = 3;
            // 
            // writeIntermediateResultsCheckBox
            // 
            this.writeIntermediateResultsCheckBox.AutoSize = true;
            this.writeIntermediateResultsCheckBox.Checked = true;
            this.writeIntermediateResultsCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.writeIntermediateResultsCheckBox.Location = new System.Drawing.Point(12, 216);
            this.writeIntermediateResultsCheckBox.Name = "writeIntermediateResultsCheckBox";
            this.writeIntermediateResultsCheckBox.Size = new System.Drawing.Size(144, 17);
            this.writeIntermediateResultsCheckBox.TabIndex = 9;
            this.writeIntermediateResultsCheckBox.Text = "Write intermediate results";
            this.writeIntermediateResultsCheckBox.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(815, 310);
            this.Controls.Add(this.writeIntermediateResultsCheckBox);
            this.Controls.Add(this.runButton);
            this.Controls.Add(this.fileNameTextBox);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "FormingVectorModel";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox invertCheckBox;
        private System.Windows.Forms.CheckBox grayscaleCheckBox;
        private System.Windows.Forms.ComboBox binarizationComboBox;
        private System.Windows.Forms.TextBox binarizationParametrTextBox;
        private System.Windows.Forms.CheckBox singleNoisePointsRemoverCheckBox;
        private System.Windows.Forms.ComboBox skeletizationComboBox;
        private System.Windows.Forms.CheckBox vectorizationCheckBox;
        private System.Windows.Forms.Button runButton;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox fileNameTextBox;
        private System.Windows.Forms.CheckBox writeIntermediateResultsCheckBox;
    }
}

