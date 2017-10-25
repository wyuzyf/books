// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// ("Fluent UI")，该示例仅作为参考资料提供， 
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有 (C) Microsoft Corporation
// 保留所有权利。

// MvSmartCamCtrlDemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include "MvSmartCamCtrl.h"


// CMvSmartCamCtrlDemoDlg 对话框
class CMvSmartCamCtrlDemoDlg : public CDialog
{
// 构造
public:
	CMvSmartCamCtrlDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MVSMARTCAMCTRLDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    void DisplayOneFrame();
public:
    MV_SC_DEVICE_INFO_LIST m_stDeviceInfoList;
    MV_SC_DEVICE_INFO m_stDeviceInfo;
    void* m_handle;
    bool m_bConnect;
    bool m_bStartJob;
    unsigned char * m_pData;
    unsigned int m_nDataSize;
    MV_SC_IMAGE_OUT_INFO m_stImageOutInfo;
    CComboBox m_ctrlComboDeviceList;
    unsigned int m_nComboDeviceList;
    afx_msg void OnBnClickedButtonEnumDevice();
    afx_msg void OnCbnSelchangeComboDeviceList();
    afx_msg void OnBnClickedButtonOpenDevice();
    afx_msg void OnBnClickedButtonCloseDevice();
    afx_msg void OnBnClickedButtonStartGrabbing();
    afx_msg void OnBnClickedButtonStopGrabbing();
    CEdit m_ctrlEditExposureTime;
    CEdit m_ctrlEditGain;
    CEdit m_ctrlEditFrameRate;
    afx_msg void OnBnClickedButtonParamGet();
    afx_msg void OnBnClickedButtonParamSet();
	BOOL PreTranslateMessage(MSG* pMsg);
 
    afx_msg void OnBnClickedRadioTriggerOff();
    afx_msg void OnBnClickedRadioTriggerOn();
    afx_msg void OnBnClickedCheckSoftware();
    CButton m_ctrlCheckSoftware;
    afx_msg void OnBnClickedButtonSoftwareOnce();
	afx_msg void OnBnClickedButtonSaveBmp();
    afx_msg void OnClose();
};
