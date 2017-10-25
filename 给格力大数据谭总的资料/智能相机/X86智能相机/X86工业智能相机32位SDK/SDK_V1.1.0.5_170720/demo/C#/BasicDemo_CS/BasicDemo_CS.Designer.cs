namespace NsBasicDemo_CS
{
    partial class CBasicDemo_CS
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
            this.ComboBoxDeviceList = new System.Windows.Forms.ComboBox();
            this.pictureBoxDisplay = new System.Windows.Forms.PictureBox();
            this.GroupBoxInit = new System.Windows.Forms.GroupBox();
            this.ButtonEnumDevice = new System.Windows.Forms.Button();
            this.ButtonCloseDevice = new System.Windows.Forms.Button();
            this.ButtonOpenDevice = new System.Windows.Forms.Button();
            this.GroupBoxGrabImage = new System.Windows.Forms.GroupBox();
            this.ButtonSoftwareOnce = new System.Windows.Forms.Button();
            this.CheckBoxSoftware = new System.Windows.Forms.CheckBox();
            this.ButtonStopGrabbing = new System.Windows.Forms.Button();
            this.ButtonStartGrabbing = new System.Windows.Forms.Button();
            this.RadioButtonTriggerOn = new System.Windows.Forms.RadioButton();
            this.RadioButtonTriggerOff = new System.Windows.Forms.RadioButton();
            this.GroupBoxImageSave = new System.Windows.Forms.GroupBox();
            this.ButtonSaveBmp = new System.Windows.Forms.Button();
            this.GroupBoxParam = new System.Windows.Forms.GroupBox();
            this.ButtonParamSet = new System.Windows.Forms.Button();
            this.ButtonParamGet = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.TextBoxFrameRate = new System.Windows.Forms.TextBox();
            this.TextBoxGain = new System.Windows.Forms.TextBox();
            this.TextBoxExposureTime = new System.Windows.Forms.TextBox();
            this.GroupBoxDeviceControl = new System.Windows.Forms.GroupBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxDisplay)).BeginInit();
            this.GroupBoxInit.SuspendLayout();
            this.GroupBoxGrabImage.SuspendLayout();
            this.GroupBoxImageSave.SuspendLayout();
            this.GroupBoxParam.SuspendLayout();
            this.GroupBoxDeviceControl.SuspendLayout();
            this.SuspendLayout();
            // 
            // ComboBoxDeviceList
            // 
            this.ComboBoxDeviceList.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.ComboBoxDeviceList.FormattingEnabled = true;
            this.ComboBoxDeviceList.Location = new System.Drawing.Point(12, 13);
            this.ComboBoxDeviceList.Name = "ComboBoxDeviceList";
            this.ComboBoxDeviceList.Size = new System.Drawing.Size(668, 21);
            this.ComboBoxDeviceList.TabIndex = 0;
            this.ComboBoxDeviceList.SelectedIndexChanged += new System.EventHandler(this.cbDeviceList_SelectedIndexChanged);
            // 
            // pictureBoxDisplay
            // 
            this.pictureBoxDisplay.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.pictureBoxDisplay.Location = new System.Drawing.Point(12, 53);
            this.pictureBoxDisplay.Name = "pictureBoxDisplay";
            this.pictureBoxDisplay.Size = new System.Drawing.Size(668, 612);
            this.pictureBoxDisplay.TabIndex = 1;
            this.pictureBoxDisplay.TabStop = false;
            // 
            // GroupBoxInit
            // 
            this.GroupBoxInit.Controls.Add(this.ButtonEnumDevice);
            this.GroupBoxInit.Location = new System.Drawing.Point(729, 53);
            this.GroupBoxInit.Name = "GroupBoxInit";
            this.GroupBoxInit.Size = new System.Drawing.Size(311, 65);
            this.GroupBoxInit.TabIndex = 2;
            this.GroupBoxInit.TabStop = false;
            this.GroupBoxInit.Text = "初始化";
            // 
            // ButtonEnumDevice
            // 
            this.ButtonEnumDevice.Location = new System.Drawing.Point(25, 22);
            this.ButtonEnumDevice.Name = "ButtonEnumDevice";
            this.ButtonEnumDevice.Size = new System.Drawing.Size(263, 25);
            this.ButtonEnumDevice.TabIndex = 0;
            this.ButtonEnumDevice.Text = "查找设备";
            this.ButtonEnumDevice.UseVisualStyleBackColor = true;
            this.ButtonEnumDevice.Click += new System.EventHandler(this.bnEnum_Click);
            // 
            // ButtonCloseDevice
            // 
            this.ButtonCloseDevice.Location = new System.Drawing.Point(158, 36);
            this.ButtonCloseDevice.Name = "ButtonCloseDevice";
            this.ButtonCloseDevice.Size = new System.Drawing.Size(130, 25);
            this.ButtonCloseDevice.TabIndex = 2;
            this.ButtonCloseDevice.Text = "关闭设备";
            this.ButtonCloseDevice.UseVisualStyleBackColor = true;
            this.ButtonCloseDevice.Click += new System.EventHandler(this.bnClose_Click);
            // 
            // ButtonOpenDevice
            // 
            this.ButtonOpenDevice.Location = new System.Drawing.Point(25, 36);
            this.ButtonOpenDevice.Name = "ButtonOpenDevice";
            this.ButtonOpenDevice.Size = new System.Drawing.Size(130, 25);
            this.ButtonOpenDevice.TabIndex = 1;
            this.ButtonOpenDevice.Text = "打开设备";
            this.ButtonOpenDevice.UseVisualStyleBackColor = true;
            this.ButtonOpenDevice.Click += new System.EventHandler(this.bnOpen_Click);
            // 
            // GroupBoxGrabImage
            // 
            this.GroupBoxGrabImage.Controls.Add(this.ButtonSoftwareOnce);
            this.GroupBoxGrabImage.Controls.Add(this.CheckBoxSoftware);
            this.GroupBoxGrabImage.Controls.Add(this.ButtonStopGrabbing);
            this.GroupBoxGrabImage.Controls.Add(this.ButtonStartGrabbing);
            this.GroupBoxGrabImage.Controls.Add(this.RadioButtonTriggerOn);
            this.GroupBoxGrabImage.Controls.Add(this.RadioButtonTriggerOff);
            this.GroupBoxGrabImage.Location = new System.Drawing.Point(729, 238);
            this.GroupBoxGrabImage.Name = "GroupBoxGrabImage";
            this.GroupBoxGrabImage.Size = new System.Drawing.Size(311, 145);
            this.GroupBoxGrabImage.TabIndex = 3;
            this.GroupBoxGrabImage.TabStop = false;
            this.GroupBoxGrabImage.Text = "采集图像";
            // 
            // ButtonSoftwareOnce
            // 
            this.ButtonSoftwareOnce.Location = new System.Drawing.Point(158, 114);
            this.ButtonSoftwareOnce.Name = "ButtonSoftwareOnce";
            this.ButtonSoftwareOnce.Size = new System.Drawing.Size(130, 25);
            this.ButtonSoftwareOnce.TabIndex = 5;
            this.ButtonSoftwareOnce.Text = "软触发一次";
            this.ButtonSoftwareOnce.UseVisualStyleBackColor = true;
            this.ButtonSoftwareOnce.Click += new System.EventHandler(this.bnTriggerExec_Click);
            // 
            // CheckBoxSoftware
            // 
            this.CheckBoxSoftware.AutoSize = true;
            this.CheckBoxSoftware.Location = new System.Drawing.Point(25, 121);
            this.CheckBoxSoftware.Name = "CheckBoxSoftware";
            this.CheckBoxSoftware.Size = new System.Drawing.Size(62, 17);
            this.CheckBoxSoftware.TabIndex = 4;
            this.CheckBoxSoftware.Text = "软触发";
            this.CheckBoxSoftware.UseVisualStyleBackColor = true;
            this.CheckBoxSoftware.CheckedChanged += new System.EventHandler(this.cbSoftTrigger_CheckedChanged);
            // 
            // ButtonStopGrabbing
            // 
            this.ButtonStopGrabbing.Location = new System.Drawing.Point(158, 67);
            this.ButtonStopGrabbing.Name = "ButtonStopGrabbing";
            this.ButtonStopGrabbing.Size = new System.Drawing.Size(130, 25);
            this.ButtonStopGrabbing.TabIndex = 3;
            this.ButtonStopGrabbing.Text = "停止采集";
            this.ButtonStopGrabbing.UseVisualStyleBackColor = true;
            this.ButtonStopGrabbing.Click += new System.EventHandler(this.bnStopGrab_Click);
            // 
            // ButtonStartGrabbing
            // 
            this.ButtonStartGrabbing.Location = new System.Drawing.Point(25, 67);
            this.ButtonStartGrabbing.Name = "ButtonStartGrabbing";
            this.ButtonStartGrabbing.Size = new System.Drawing.Size(127, 25);
            this.ButtonStartGrabbing.TabIndex = 2;
            this.ButtonStartGrabbing.Text = "开始采集";
            this.ButtonStartGrabbing.UseVisualStyleBackColor = true;
            this.ButtonStartGrabbing.Click += new System.EventHandler(this.bnStartGrab_Click);
            // 
            // RadioButtonTriggerOn
            // 
            this.RadioButtonTriggerOn.AutoSize = true;
            this.RadioButtonTriggerOn.Location = new System.Drawing.Point(158, 28);
            this.RadioButtonTriggerOn.Name = "RadioButtonTriggerOn";
            this.RadioButtonTriggerOn.Size = new System.Drawing.Size(73, 17);
            this.RadioButtonTriggerOn.TabIndex = 1;
            this.RadioButtonTriggerOn.TabStop = true;
            this.RadioButtonTriggerOn.Text = "触发模式";
            this.RadioButtonTriggerOn.UseVisualStyleBackColor = true;
            this.RadioButtonTriggerOn.CheckedChanged += new System.EventHandler(this.bnTriggerMode_CheckedChanged);
            // 
            // RadioButtonTriggerOff
            // 
            this.RadioButtonTriggerOff.AutoSize = true;
            this.RadioButtonTriggerOff.Location = new System.Drawing.Point(25, 28);
            this.RadioButtonTriggerOff.Name = "RadioButtonTriggerOff";
            this.RadioButtonTriggerOff.Size = new System.Drawing.Size(73, 17);
            this.RadioButtonTriggerOff.TabIndex = 0;
            this.RadioButtonTriggerOff.TabStop = true;
            this.RadioButtonTriggerOff.Text = "连续模式";
            this.RadioButtonTriggerOff.UseVisualStyleBackColor = true;
            this.RadioButtonTriggerOff.CheckedChanged += new System.EventHandler(this.bnContinuesMode_CheckedChanged);
            // 
            // GroupBoxImageSave
            // 
            this.GroupBoxImageSave.Controls.Add(this.ButtonSaveBmp);
            this.GroupBoxImageSave.Location = new System.Drawing.Point(729, 406);
            this.GroupBoxImageSave.Name = "GroupBoxImageSave";
            this.GroupBoxImageSave.Size = new System.Drawing.Size(311, 54);
            this.GroupBoxImageSave.TabIndex = 4;
            this.GroupBoxImageSave.TabStop = false;
            this.GroupBoxImageSave.Text = "保存图片";
            // 
            // ButtonSaveBmp
            // 
            this.ButtonSaveBmp.Location = new System.Drawing.Point(25, 22);
            this.ButtonSaveBmp.Name = "ButtonSaveBmp";
            this.ButtonSaveBmp.Size = new System.Drawing.Size(263, 25);
            this.ButtonSaveBmp.TabIndex = 0;
            this.ButtonSaveBmp.Text = "保存裸数据";
            this.ButtonSaveBmp.UseVisualStyleBackColor = true;
            this.ButtonSaveBmp.Click += new System.EventHandler(this.bnSaveBmp_Click);
            // 
            // GroupBoxParam
            // 
            this.GroupBoxParam.Controls.Add(this.ButtonParamSet);
            this.GroupBoxParam.Controls.Add(this.ButtonParamGet);
            this.GroupBoxParam.Controls.Add(this.label3);
            this.GroupBoxParam.Controls.Add(this.label2);
            this.GroupBoxParam.Controls.Add(this.label1);
            this.GroupBoxParam.Controls.Add(this.TextBoxFrameRate);
            this.GroupBoxParam.Controls.Add(this.TextBoxGain);
            this.GroupBoxParam.Controls.Add(this.TextBoxExposureTime);
            this.GroupBoxParam.Location = new System.Drawing.Point(729, 471);
            this.GroupBoxParam.Name = "GroupBoxParam";
            this.GroupBoxParam.Size = new System.Drawing.Size(311, 194);
            this.GroupBoxParam.TabIndex = 5;
            this.GroupBoxParam.TabStop = false;
            this.GroupBoxParam.Text = "参数";
            // 
            // ButtonParamSet
            // 
            this.ButtonParamSet.Location = new System.Drawing.Point(158, 148);
            this.ButtonParamSet.Name = "ButtonParamSet";
            this.ButtonParamSet.Size = new System.Drawing.Size(130, 25);
            this.ButtonParamSet.TabIndex = 7;
            this.ButtonParamSet.Text = "设置参数";
            this.ButtonParamSet.UseVisualStyleBackColor = true;
            this.ButtonParamSet.Click += new System.EventHandler(this.bnSetParam_Click);
            // 
            // ButtonParamGet
            // 
            this.ButtonParamGet.Location = new System.Drawing.Point(25, 148);
            this.ButtonParamGet.Name = "ButtonParamGet";
            this.ButtonParamGet.Size = new System.Drawing.Size(127, 25);
            this.ButtonParamGet.TabIndex = 6;
            this.ButtonParamGet.Text = "获取参数";
            this.ButtonParamGet.UseVisualStyleBackColor = true;
            this.ButtonParamGet.Click += new System.EventHandler(this.bnGetParam_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 104);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(31, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "帧率";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 65);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(31, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "增益";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(31, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "曝光";
            // 
            // TextBoxFrameRate
            // 
            this.TextBoxFrameRate.Location = new System.Drawing.Point(158, 101);
            this.TextBoxFrameRate.Name = "TextBoxFrameRate";
            this.TextBoxFrameRate.Size = new System.Drawing.Size(130, 20);
            this.TextBoxFrameRate.TabIndex = 2;
            // 
            // TextBoxGain
            // 
            this.TextBoxGain.Location = new System.Drawing.Point(158, 62);
            this.TextBoxGain.Name = "TextBoxGain";
            this.TextBoxGain.Size = new System.Drawing.Size(130, 20);
            this.TextBoxGain.TabIndex = 1;
            // 
            // TextBoxExposureTime
            // 
            this.TextBoxExposureTime.Location = new System.Drawing.Point(158, 25);
            this.TextBoxExposureTime.Name = "TextBoxExposureTime";
            this.TextBoxExposureTime.Size = new System.Drawing.Size(130, 20);
            this.TextBoxExposureTime.TabIndex = 0;
            // 
            // GroupBoxDeviceControl
            // 
            this.GroupBoxDeviceControl.Controls.Add(this.ButtonCloseDevice);
            this.GroupBoxDeviceControl.Controls.Add(this.ButtonOpenDevice);
            this.GroupBoxDeviceControl.Location = new System.Drawing.Point(729, 135);
            this.GroupBoxDeviceControl.Name = "GroupBoxDeviceControl";
            this.GroupBoxDeviceControl.Size = new System.Drawing.Size(311, 77);
            this.GroupBoxDeviceControl.TabIndex = 6;
            this.GroupBoxDeviceControl.TabStop = false;
            this.GroupBoxDeviceControl.Text = "设备控制";
            // 
            // CBasicDemo_CS
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1077, 699);
            this.Controls.Add(this.GroupBoxDeviceControl);
            this.Controls.Add(this.GroupBoxParam);
            this.Controls.Add(this.GroupBoxImageSave);
            this.Controls.Add(this.GroupBoxGrabImage);
            this.Controls.Add(this.GroupBoxInit);
            this.Controls.Add(this.pictureBoxDisplay);
            this.Controls.Add(this.ComboBoxDeviceList);
            this.Name = "CBasicDemo_CS";
            this.Text = "MvSmartCamCtrl SDK CS演示程序";
            this.Load += new System.EventHandler(this.CBasicDemo_CS_Load);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.CBasicDemo_CS_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxDisplay)).EndInit();
            this.GroupBoxInit.ResumeLayout(false);
            this.GroupBoxGrabImage.ResumeLayout(false);
            this.GroupBoxGrabImage.PerformLayout();
            this.GroupBoxImageSave.ResumeLayout(false);
            this.GroupBoxParam.ResumeLayout(false);
            this.GroupBoxParam.PerformLayout();
            this.GroupBoxDeviceControl.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ComboBox ComboBoxDeviceList;
        private System.Windows.Forms.PictureBox pictureBoxDisplay;
        private System.Windows.Forms.GroupBox GroupBoxInit;
        private System.Windows.Forms.Button ButtonCloseDevice;
        private System.Windows.Forms.Button ButtonOpenDevice;
        private System.Windows.Forms.Button ButtonEnumDevice;
        private System.Windows.Forms.GroupBox GroupBoxGrabImage;
        private System.Windows.Forms.RadioButton RadioButtonTriggerOn;
        private System.Windows.Forms.RadioButton RadioButtonTriggerOff;
        private System.Windows.Forms.CheckBox CheckBoxSoftware;
        private System.Windows.Forms.Button ButtonStopGrabbing;
        private System.Windows.Forms.Button ButtonStartGrabbing;
        private System.Windows.Forms.Button ButtonSoftwareOnce;
        private System.Windows.Forms.GroupBox GroupBoxImageSave;
        private System.Windows.Forms.Button ButtonSaveBmp;
        private System.Windows.Forms.GroupBox GroupBoxParam;
        private System.Windows.Forms.TextBox TextBoxFrameRate;
        private System.Windows.Forms.TextBox TextBoxGain;
        private System.Windows.Forms.TextBox TextBoxExposureTime;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button ButtonParamSet;
        private System.Windows.Forms.Button ButtonParamGet;
        private System.Windows.Forms.GroupBox GroupBoxDeviceControl;
    }
}

