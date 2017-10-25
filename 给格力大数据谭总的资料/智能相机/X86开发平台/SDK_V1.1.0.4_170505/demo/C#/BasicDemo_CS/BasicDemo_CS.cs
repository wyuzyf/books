using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using NsCameraOperator;
using NsMvCameraSDK;
using System.Runtime.InteropServices;
using System.Threading;
using System.IO;

namespace NsBasicDemo_CS
{
    public partial class CBasicDemo_CS : Form
    {
        CMvSmartSDK.MV_SC_DEVICE_INFO_LIST m_pstDeviceInfoList = new CMvSmartSDK.MV_SC_DEVICE_INFO_LIST();
        CCameraOperator m_pcCameraOperator = new CCameraOperator();
        Int32 m_nDeviceIndex = -1;
        bool m_bStartGrabbing = false;
        private const UInt32 MAX_IMAGE_FRAME_SIZE = 2592 * 2048;
        Thread m_Thread;
        IntPtr m_hDisplayWnd;

        public CBasicDemo_CS()
        {
            InitializeComponent();
        }

        private void bnEnum_Click(object sender, EventArgs e)
        {
            Int32 nRet = CMvSmartSDK.MV_OK;
            System.GC.Collect();
            ComboBoxDeviceList.Items.Clear();
            ComboBoxDeviceList.SelectedIndex = -1;
            nRet = CCameraOperator.Discovery(ref m_pstDeviceInfoList);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("枚举设备失败" + nRet.ToString());
                return;
            }
            if (0 == m_pstDeviceInfoList.nDeviceNum)
            {
                MessageBox.Show("没有枚举到相机!");
                return;
            }

            //在窗体列表中显示设备名
            for (int i = 0; i < m_pstDeviceInfoList.nDeviceNum; i++)
            {
                if (m_pstDeviceInfoList.astDeviceInfo[i].chUserDefinedName != "")
                {
                    ComboBoxDeviceList.Items.Add(m_pstDeviceInfoList.astDeviceInfo[i].chUserDefinedName);
                }
                else
                {
                    ComboBoxDeviceList.Items.Add(m_pstDeviceInfoList.astDeviceInfo[i].chModelName + "(" + m_pstDeviceInfoList.astDeviceInfo[i].chSerialNumber + ")");
                }
            }


            GroupBoxInit.Enabled = true;
            GroupBoxDeviceControl.Enabled = false;
            GroupBoxGrabImage.Enabled = false;
            GroupBoxImageSave.Enabled = false;
            GroupBoxParam.Enabled = false;

            ComboBoxDeviceList.Enabled = true;
            ButtonEnumDevice.Enabled = true;
            ButtonOpenDevice.Enabled = false;
            ButtonCloseDevice.Enabled = false;
            RadioButtonTriggerOff.Enabled = false;
            RadioButtonTriggerOn.Enabled = false;
            ButtonStartGrabbing.Enabled = false;
            ButtonStopGrabbing.Enabled = false;
            CheckBoxSoftware.Enabled = false;
            ButtonSoftwareOnce.Enabled = false;
            ButtonSaveBmp.Enabled = false;
            TextBoxExposureTime.Enabled = false;
            TextBoxGain.Enabled = false;
            TextBoxFrameRate.Enabled = false;
            ButtonParamGet.Enabled = false;
            ButtonParamSet.Enabled = false;
        }

        private void bnOpen_Click(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;
            if (m_nDeviceIndex < 0 || m_nDeviceIndex >= m_pstDeviceInfoList.nDeviceNum)
            {
                MessageBox.Show("相机索引错误!");
                return;
            }

            //打开设备
            nRet = m_pcCameraOperator.Open(ref m_pstDeviceInfoList.astDeviceInfo[m_nDeviceIndex]);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("设备打开失败!");
                return;
            }

            nRet = m_pcCameraOperator.SetEnumValue("PixelFormat", (UInt32)CMvSmartSDK.MvGvspPixelType.PixelType_Gvsp_Mono8);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("设置为mono8格式失败");
                return;
            }

            nRet = m_pcCameraOperator.SetEnumValue("TriggerMode", (UInt32)CMvSmartSDK.MV_SC_TRIGGER_MODE.SC_TRIGGER_MODE_OFF);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("设置为连续模式失败");
                return;
            }

            nRet = m_pcCameraOperator.SetEnumValue("TriggerSource", (UInt32)CMvSmartSDK.MV_SC_TRIGGER_SOURCE.SC_TRIGGER_SOURCE_LINE0);
            //if (CMvSmartSDK.MV_OK != nRet)
            //{
            //    MessageBox.Show("设置为Line0模式失败");
            //    return;
            //}



            nRet = m_pcCameraOperator.SetEnumValue("ExposureAuto", (UInt32)CMvSmartSDK.MV_SC_EXPOSURE_AUTO_MODE.SC_EXPOSURE_AUTO_MODE_OFF);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("关闭自动曝光失败");
                return;
            }

            nRet = m_pcCameraOperator.SetEnumValue("GainAuto", (UInt32)CMvSmartSDK.MV_SC_GAIN_AUTO_MODE.SC_GAIN_AUTO_MODE_OFF);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("关闭自动增益失败");
                return;
            }

            float fExposure = 0;
            nRet = m_pcCameraOperator.GetFloatValue("ExposureTime", ref fExposure);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("获取曝光时间失败!");
            }
            TextBoxExposureTime.Text = fExposure.ToString("F1");

            float fGain = 0;
            nRet = m_pcCameraOperator.GetFloatValue("Gain", ref fGain);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("获取增益失败!");
            }
            TextBoxGain.Text = fGain.ToString("F1");

            float fFrameRate = 0;
            nRet = m_pcCameraOperator.GetFloatValue("AcquisitionFrameRate", ref fFrameRate);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("获取帧率失败!");
            }
            TextBoxFrameRate.Text = fFrameRate.ToString("F1");


            RadioButtonTriggerOn.Enabled = false;
            RadioButtonTriggerOff.Enabled = true;
            CheckBoxSoftware.Enabled = false;
            ButtonSoftwareOnce.Enabled = false;

            GroupBoxInit.Enabled = false;
            GroupBoxDeviceControl.Enabled = true;
            GroupBoxGrabImage.Enabled = true;
            GroupBoxImageSave.Enabled = true;
            GroupBoxParam.Enabled = true;

            ComboBoxDeviceList.Enabled = false;
            ButtonEnumDevice.Enabled = false;
            ButtonOpenDevice.Enabled = false;
            ButtonCloseDevice.Enabled = true;
            ButtonStartGrabbing.Enabled = true;
            ButtonStopGrabbing.Enabled = false;
            ButtonSaveBmp.Enabled = false;
            TextBoxExposureTime.Enabled = true;
            TextBoxGain.Enabled = true;
            TextBoxFrameRate.Enabled = true;
            ButtonParamGet.Enabled = true;
            ButtonParamSet.Enabled = true;

        }

        private void bnClose_Click(object sender, EventArgs e)
        {
            int nRet = m_pcCameraOperator.Close();
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("关闭设备失败");
            }

            if (m_bStartGrabbing)
            {
                m_bStartGrabbing = false;
                m_Thread.Abort();
            }

            GroupBoxInit.Enabled = true;
            ButtonEnumDevice.Enabled = true;

            ComboBoxDeviceList.Enabled = true;
            ButtonOpenDevice.Enabled = true;
            ButtonCloseDevice.Enabled = false;

            GroupBoxGrabImage.Enabled = false;
            ButtonStartGrabbing.Enabled = false;
            ButtonStopGrabbing.Enabled = false;
            ButtonSoftwareOnce.Enabled = false;

            GroupBoxImageSave.Enabled = false;
            GroupBoxParam.Enabled = false;

            
        }

        private void bnContinuesMode_CheckedChanged(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;
            if (RadioButtonTriggerOff.Checked)
            {
                nRet = m_pcCameraOperator.SetEnumValue("TriggerMode", (Int32)CMvSmartSDK.MV_SC_TRIGGER_MODE.SC_TRIGGER_MODE_OFF);
                if (CMvSmartSDK.MV_OK != nRet)
                {
                    MessageBox.Show("关闭触发失败!");
                    return;
                }
            }
            else
            {
                m_pcCameraOperator.SetEnumValue("TriggerMode", (Int32)CMvSmartSDK.MV_SC_TRIGGER_MODE.SC_TRIGGER_MODE_ON);
                if (CMvSmartSDK.MV_OK != nRet)
                {
                    MessageBox.Show("开启触发失败!");
                    return;
                }
            }

            RadioButtonTriggerOff.Enabled = false;
            RadioButtonTriggerOn.Enabled = true;
            if (RadioButtonTriggerOn.Checked)
            {
                CheckBoxSoftware.Enabled = true;
            }
            else
            {
                CheckBoxSoftware.Enabled = false;
            }

            if (RadioButtonTriggerOn.Checked && CheckBoxSoftware.Checked)
            {
                ButtonSoftwareOnce.Enabled = true;
            }
            else
            {
                ButtonSoftwareOnce.Enabled = false;
            }
        }

        private void bnTriggerMode_CheckedChanged(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;
            if (RadioButtonTriggerOn.Checked)
            {
                nRet = m_pcCameraOperator.SetEnumValue("TriggerMode", (Int32)CMvSmartSDK.MV_SC_TRIGGER_MODE.SC_TRIGGER_MODE_ON);
                if (CMvSmartSDK.MV_OK != nRet)
                {
                    MessageBox.Show("关闭触发失败!");
                    return;
                }
            }
            else
            {
                m_pcCameraOperator.SetEnumValue("TriggerMode", (Int32)CMvSmartSDK.MV_SC_TRIGGER_MODE.SC_TRIGGER_MODE_OFF);
                if (CMvSmartSDK.MV_OK != nRet)
                {
                    MessageBox.Show("开启触发失败!");
                    return;
                }
            }

            RadioButtonTriggerOff.Enabled = true;
            RadioButtonTriggerOn.Enabled = false;
            if (RadioButtonTriggerOn.Checked)
            {
                CheckBoxSoftware.Enabled = true;
            }
            else
            {
                CheckBoxSoftware.Enabled = false;
            }

            if (RadioButtonTriggerOn.Checked && CheckBoxSoftware.Checked)
            {
                ButtonSoftwareOnce.Enabled = true;
            }
            else
            {
                ButtonSoftwareOnce.Enabled = false;
            }
        }

        private void ThreadFunction()
        {
            while (m_bStartGrabbing)
            {
                Thread.Sleep(30);
                int nRet = CMvSmartSDK.MV_OK;
                byte[] buffer = new byte[MAX_IMAGE_FRAME_SIZE];
                IntPtr pData = Marshal.UnsafeAddrOfPinnedArrayElement(buffer, 0);
                CMvSmartSDK.MV_SC_IMAGE_OUT_INFO stImageOutInfo = new CMvSmartSDK.MV_SC_IMAGE_OUT_INFO();
                IntPtr pImageOutInfo = new IntPtr();
                pImageOutInfo = Marshal.AllocHGlobal(Marshal.SizeOf(stImageOutInfo));

                nRet = m_pcCameraOperator.GetOneFrame(pData, MAX_IMAGE_FRAME_SIZE, pImageOutInfo);
                if (CMvSmartSDK.MV_OK != nRet)
                {
                    continue;
                }

                stImageOutInfo = (CMvSmartSDK.MV_SC_IMAGE_OUT_INFO)Marshal.PtrToStructure(pImageOutInfo, typeof(CMvSmartSDK.MV_SC_IMAGE_OUT_INFO));

                nRet = m_pcCameraOperator.DisplayOneFrame(m_hDisplayWnd, pData,
                    (UInt32)(stImageOutInfo.nWidth * stImageOutInfo.nHeight), stImageOutInfo.nWidth, stImageOutInfo.nHeight, (UInt32)stImageOutInfo.enPixelType);
                if (CMvSmartSDK.MV_OK != nRet)
                {
                    continue;
                }
            }
        }

        private void bnStartGrab_Click(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;

            //开始采集
            nRet = m_pcCameraOperator.StartGrabbing();
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("开始采集失败！");
                return;
            }

            m_hDisplayWnd = pictureBoxDisplay.Handle;

            m_bStartGrabbing = true;
            m_Thread = new Thread(new ThreadStart(ThreadFunction));
            m_Thread.Start();

            ButtonStartGrabbing.Enabled = false;
            ButtonStopGrabbing.Enabled = true;
            ButtonSaveBmp.Enabled = true;
        }

        private void cbSoftTrigger_CheckedChanged(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;
            if (CheckBoxSoftware.Checked)
            {
                nRet = m_pcCameraOperator.SetEnumValue("TriggerSource", (UInt32)CMvSmartSDK.MV_SC_TRIGGER_SOURCE.SC_TRIGGER_SOURCE_SOFTWARE);
                if (CMvSmartSDK.MV_OK != nRet)
                {
                    MessageBox.Show("设置软触发失败！");
                    return;
                }
            }
            else
            {
                nRet = m_pcCameraOperator.SetEnumValue("TriggerSource", (UInt32)CMvSmartSDK.MV_SC_TRIGGER_SOURCE.SC_TRIGGER_SOURCE_LINE0);
                if (CMvSmartSDK.MV_OK != nRet)
                {
                    MessageBox.Show("设置硬软触发失败！");
                    return;
                }
            }

            CheckBoxSoftware.Enabled = true;
            if (RadioButtonTriggerOn.Checked && CheckBoxSoftware.Checked)
            {
                ButtonSoftwareOnce.Enabled = true;
            }
            else
            {
                ButtonSoftwareOnce.Enabled = false;
            }
        
        }

        private void bnTriggerExec_Click(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;

            nRet = m_pcCameraOperator.CommandExecute("TriggerSoftware");
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("软触发一次失败!");
                return;
            }
        }

        private void bnStopGrab_Click(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;
            nRet = m_pcCameraOperator.StopGrabbing();
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("停止取流失败");
                return;
            }

            m_bStartGrabbing = false;
            m_Thread.Abort();

            ButtonStartGrabbing.Enabled = true;
            ButtonStopGrabbing.Enabled = false;
            ButtonSaveBmp.Enabled = false;
        }

        private void bnSaveBmp_Click(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;
            bool bFound = false;
            byte[] buffer = new byte[MAX_IMAGE_FRAME_SIZE];
            IntPtr pData = Marshal.UnsafeAddrOfPinnedArrayElement(buffer, 0);
         //   UInt32 nDataLen = 0;
            CMvSmartSDK.MV_SC_IMAGE_OUT_INFO stImageOutInfo = new CMvSmartSDK.MV_SC_IMAGE_OUT_INFO();
            IntPtr pImageOutInfo = new IntPtr();
            pImageOutInfo = Marshal.AllocHGlobal(Marshal.SizeOf(stImageOutInfo));

            //超时获取一帧，超时时间为1秒
            for (int i = 0; i < 100; i++)
            {
                nRet = m_pcCameraOperator.GetOneFrame(pData, MAX_IMAGE_FRAME_SIZE, pImageOutInfo);
                if (CMvSmartSDK.MV_OK == nRet)
                {
                    bFound = true;
                    break;
                }
                Thread.Sleep(10);
            }
            //超时退出
            if (false == bFound)
            {
                MessageBox.Show("无数据！");
                return;
            }

            stImageOutInfo = (CMvSmartSDK.MV_SC_IMAGE_OUT_INFO)Marshal.PtrToStructure(pImageOutInfo, typeof(CMvSmartSDK.MV_SC_IMAGE_OUT_INFO));

            FileStream file = new FileStream("image.raw", FileMode.Create, FileAccess.Write);//加判断
            file.Write(buffer, 0, (int)(stImageOutInfo.nWidth * stImageOutInfo.nHeight));
            file.Close();

            MessageBox.Show("保存成功!");
        }

        private void bnGetParam_Click(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;
            float fExposure = 0;
            nRet = m_pcCameraOperator.GetFloatValue("ExposureTime", ref fExposure);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("获取曝光时间失败!");
            }
            TextBoxExposureTime.Text = fExposure.ToString("F1");

            float fGain = 0;
            nRet = m_pcCameraOperator.GetFloatValue("Gain", ref fGain);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("获取增益失败!");
            }
            TextBoxGain.Text = fGain.ToString("F1");

            float fFrameRate = 0;
            nRet = m_pcCameraOperator.GetFloatValue("AcquisitionFrameRate", ref fFrameRate);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("获取帧率失败!");
            }
            TextBoxFrameRate.Text = fFrameRate.ToString("F1");
        }

        private void bnSetParam_Click(object sender, EventArgs e)
        {
            int nRet = CMvSmartSDK.MV_OK;

            nRet = m_pcCameraOperator.SetFloatValue("ExposureTime", float.Parse(TextBoxExposureTime.Text));
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("设置曝光时间失败！");
            }

            nRet = m_pcCameraOperator.SetFloatValue("Gain", float.Parse(TextBoxGain.Text));
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("设置增益失败！");
            }

            nRet = m_pcCameraOperator.SetFloatValue("AcquisitionFrameRate", float.Parse(TextBoxFrameRate.Text));
            if (CMvSmartSDK.MV_OK != nRet)
            {
                MessageBox.Show("设置帧率失败！");
            }
        }

        private void cbDeviceList_SelectedIndexChanged(object sender, EventArgs e)
        {
            m_nDeviceIndex = ComboBoxDeviceList.SelectedIndex;

            GroupBoxInit.Enabled = true;
            GroupBoxDeviceControl.Enabled = true;
            GroupBoxGrabImage.Enabled = false;
            GroupBoxImageSave.Enabled = false;
            GroupBoxParam.Enabled = false;

            ComboBoxDeviceList.Enabled = true;
            ButtonEnumDevice.Enabled = true;
            ButtonOpenDevice.Enabled = true;
            ButtonCloseDevice.Enabled = false;
            RadioButtonTriggerOff.Enabled = false;
            RadioButtonTriggerOn.Enabled = false;
            ButtonStartGrabbing.Enabled = false;
            ButtonStopGrabbing.Enabled = false;
            CheckBoxSoftware.Enabled = false;
            ButtonSoftwareOnce.Enabled = false;
            ButtonSaveBmp.Enabled = false;
            TextBoxExposureTime.Enabled = false;
            TextBoxGain.Enabled = false;
            TextBoxFrameRate.Enabled = false;
            ButtonParamGet.Enabled = false;
            ButtonParamSet.Enabled = false;
        }

        private void CBasicDemo_CS_Load(object sender, EventArgs e)
        {
            GroupBoxInit.Enabled = true;
            GroupBoxDeviceControl.Enabled = false;
            GroupBoxGrabImage.Enabled = false;
            GroupBoxImageSave.Enabled = false;
            GroupBoxParam.Enabled = false;

            ComboBoxDeviceList.Enabled = false;
            ButtonEnumDevice.Enabled = true;
            ButtonOpenDevice.Enabled = false;
            ButtonCloseDevice.Enabled = false;
            RadioButtonTriggerOff.Enabled = false;
            RadioButtonTriggerOn.Enabled = false;
            ButtonStartGrabbing.Enabled = false;
            ButtonStopGrabbing.Enabled = false;
            CheckBoxSoftware.Enabled = false;
            ButtonSoftwareOnce.Enabled = false;
            ButtonSaveBmp.Enabled = false;
            TextBoxExposureTime.Enabled = false;
            TextBoxGain.Enabled = false;
            TextBoxFrameRate.Enabled = false;
            ButtonParamGet.Enabled = false;
            ButtonParamSet.Enabled = false;

        }

        private void CBasicDemo_CS_FormClosing(object sender, FormClosingEventArgs e)
        {
            m_pcCameraOperator.Close();
        }

    }
}
