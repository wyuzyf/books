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

// MvSmartCamCtrlDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MvSmartCamCtrlDemo.h"
#include "MvSmartCamCtrlDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

unsigned int __stdcall WorkThread(void * pUser)
{
    
    int nRet = MV_OK;
    CString cstrInfo;
    CMvSmartCamCtrlDemoDlg * pcMvSmartCamCtrlDemoDlg = (CMvSmartCamCtrlDemoDlg *)pUser;
    if (pcMvSmartCamCtrlDemoDlg)
    {
        pcMvSmartCamCtrlDemoDlg->DisplayOneFrame();
    }

    return 0;
}


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMvSmartCamCtrlDemoDlg 对话框




CMvSmartCamCtrlDemoDlg::CMvSmartCamCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMvSmartCamCtrlDemoDlg::IDD, pParent)
    , m_handle(0)
    , m_bConnect(0)
    , m_bStartJob(false)
    , m_pData(0)
    , m_nDataSize(0)
    , m_nComboDeviceList(0)
{
    memset(&m_stDeviceInfoList, 0, sizeof(m_stDeviceInfoList));
    memset(&m_stDeviceInfo, 0, sizeof(m_stDeviceInfo));
    memset(&m_stImageOutInfo, 0, sizeof(m_stImageOutInfo));
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMvSmartCamCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_DEVICE_LIST, m_ctrlComboDeviceList);
    DDX_Control(pDX, IDC_EDIT_EXPOSURE_TIME, m_ctrlEditExposureTime);
    DDX_Control(pDX, IDC_EDIT_GAIN, m_ctrlEditGain);
    DDX_Control(pDX, IDC_EDIT_FRAME_RATE, m_ctrlEditFrameRate);
    DDX_Control(pDX, IDC_CHECK_SOFTWARE, m_ctrlCheckSoftware);
}

BEGIN_MESSAGE_MAP(CMvSmartCamCtrlDemoDlg, CDialog)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    //}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BUTTON_ENUM_DEVICE, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonEnumDevice)
    ON_CBN_SELCHANGE(IDC_COMBO_DEVICE_LIST, &CMvSmartCamCtrlDemoDlg::OnCbnSelchangeComboDeviceList)
    ON_BN_CLICKED(IDC_BUTTON_OPEN_DEVICE, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonOpenDevice)
    ON_BN_CLICKED(IDC_BUTTON_CLOSE_DEVICE, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonCloseDevice)
    ON_BN_CLICKED(IDC_BUTTON_START_GRABBING, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonStartGrabbing)
    ON_BN_CLICKED(IDC_BUTTON_STOP_GRABBING, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonStopGrabbing)
    ON_BN_CLICKED(IDC_BUTTON_PARAM_GET, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonParamGet)
    ON_BN_CLICKED(IDC_BUTTON_PARAM_SET, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonParamSet)
    ON_BN_CLICKED(IDC_RADIO_TRIGGER_OFF, &CMvSmartCamCtrlDemoDlg::OnBnClickedRadioTriggerOff)
    ON_BN_CLICKED(IDC_RADIO_TRIGGER_ON, &CMvSmartCamCtrlDemoDlg::OnBnClickedRadioTriggerOn)
    ON_BN_CLICKED(IDC_CHECK_SOFTWARE, &CMvSmartCamCtrlDemoDlg::OnBnClickedCheckSoftware)
    ON_BN_CLICKED(IDC_BUTTON_SOFTWARE_ONCE, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonSoftwareOnce)
    ON_BN_CLICKED(IDC_BUTTON_SAVE_BMP, &CMvSmartCamCtrlDemoDlg::OnBnClickedButtonSaveBmp)
    ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMvSmartCamCtrlDemoDlg 消息处理程序

BOOL CMvSmartCamCtrlDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

    m_pData = (unsigned char *)malloc(1024 * 1024 * 10);
    if (0 == m_pData)
    {
        return TRUE;
    }
    m_nDataSize = 1024 * 1024 * 10;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMvSmartCamCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMvSmartCamCtrlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMvSmartCamCtrlDemoDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CMvSmartCamCtrlDemoDlg::DisplayOneFrame()
{
    int nRet = MV_OK;

    while (m_bStartJob)
    {
        nRet = MV_SC_GetOneFrame(m_handle, m_pData, m_nDataSize, &m_stImageOutInfo);

        if (MV_OK == nRet)
        {
            MV_SC_Display(m_handle, GetDlgItem(IDC_STATIC_DISPLAY)->GetSafeHwnd(), m_pData, m_nDataSize, m_stImageOutInfo.nWidth, m_stImageOutInfo.nHeight, m_stImageOutInfo.enPixelType);
        }
        else
        {
            Sleep(10);
        }
    }
}

BOOL CMvSmartCamCtrlDemoDlg::PreTranslateMessage(MSG* pMsg)
 {
     if(pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_RETURN)    
         return TRUE; 
     if(pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_ESCAPE)    
         return TRUE; 
     return CDialog::PreTranslateMessage(pMsg);
 }

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonEnumDevice()
{
    m_ctrlComboDeviceList.ResetContent();


    // TODO: 在此添加控件通知处理程序代码

    int nRet = MV_OK;
    CString cstrInfo;


    nRet = MV_SC_Discovery(&m_stDeviceInfoList);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("枚举设备失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return;
    }

    for (int i = 0; i < m_stDeviceInfoList.nDeviceNum; i++)
    {
        unsigned char nIp1 = m_stDeviceInfoList.astDeviceInfo[i].nDeviceIp & 0xff;
        unsigned char nIp2 = (m_stDeviceInfoList.astDeviceInfo[i].nDeviceIp & 0xff00) >> 8;
        unsigned char nIp3 = (m_stDeviceInfoList.astDeviceInfo[i].nDeviceIp & 0xff0000) >> 16;
        unsigned char nIp4 = (m_stDeviceInfoList.astDeviceInfo[i].nDeviceIp & 0xff000000) >> 24;


        cstrInfo.Format("Device[%d]Name[%s]Ip[%d.%d.%d.%d]", i, m_stDeviceInfoList.astDeviceInfo[i].chUserDefinedName, nIp4, nIp3, nIp2, nIp1);
        m_ctrlComboDeviceList.AddString(cstrInfo);
    }

    //如果有设备，默认显示第一个设备
    if(0 != m_stDeviceInfoList.nDeviceNum)
    {
        m_ctrlComboDeviceList.SetCurSel(0);
        memcpy_s(&m_stDeviceInfo, sizeof(m_stDeviceInfo), &m_stDeviceInfoList.astDeviceInfo[m_ctrlComboDeviceList.GetCurSel()], sizeof(m_stDeviceInfoList.astDeviceInfo[m_ctrlComboDeviceList.GetCurSel()]));
    }
}

void CMvSmartCamCtrlDemoDlg::OnCbnSelchangeComboDeviceList()
{
    // TODO: 在此添加控件通知处理程序代码
    memcpy_s(&m_stDeviceInfo, sizeof(m_stDeviceInfo), &m_stDeviceInfoList.astDeviceInfo[m_ctrlComboDeviceList.GetCurSel()], sizeof(m_stDeviceInfoList.astDeviceInfo[m_ctrlComboDeviceList.GetCurSel()]));
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonOpenDevice()
{
    // TODO: 在此添加控件通知处理程序代码
    int nRet = MV_OK;
    CString cstrInfo;

    nRet = MV_SC_CreateHandle(&m_handle, &m_stDeviceInfo);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("创建句柄失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    nRet = MV_SC_Connect(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("打开相机失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    m_bConnect = true;

}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonCloseDevice()
{
    // TODO: 在此添加控件通知处理程序代码
    int nRet = MV_OK;
    CString cstrInfo;

    nRet = MV_SC_Disconnect(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("关闭相机失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    nRet = MV_SC_DestroyHandle(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("销毁句柄失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    m_bStartJob = false;
    m_bConnect  = false;
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonStartGrabbing()
{
    // TODO: 在此添加控件通知处理程序代码
    int nRet = MV_OK;
    CString cstrInfo;
    nRet = MV_SC_StartJob(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("开启取流失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    _beginthreadex(0, 0, WorkThread, this, 0, 0);

    m_bStartJob = true;
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonStopGrabbing()
{
    // TODO: 在此添加控件通知处理程序代码
    int nRet = MV_OK;
    CString cstrInfo;
    nRet = MV_SC_StopJob(m_handle);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("停止取流失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    m_bStartJob = false;
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonParamGet()
{
    // TODO: 在此添加控件通知处理程序代码
    
    int nRet = MV_OK;
    CString cstrInfo;

    float fExposureTime = 0.0f;
    nRet = MV_SC_GetFloatValue(m_handle, "ExposureTime", &fExposureTime);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("获取曝光时间失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    float fGain= 0.0f;
    nRet = MV_SC_GetFloatValue(m_handle, "Gain", &fGain);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("获取增益失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    float fFrameRate= 0.0f;
    nRet = MV_SC_GetFloatValue(m_handle, "AcquisitionFrameRate", &fFrameRate);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("获取帧率失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    cstrInfo.Format("%f", fExposureTime);
    m_ctrlEditExposureTime.SetWindowText(cstrInfo);

    cstrInfo.Format("%f", fGain);
    m_ctrlEditGain.SetWindowText(cstrInfo);

    cstrInfo.Format("%f", fFrameRate);
    m_ctrlEditFrameRate.SetWindowText(cstrInfo);
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonParamSet()
{
    // TODO: 在此添加控件通知处理程序代码

    int nRet = MV_OK;
    CString cstrInfo;

    float fExposureTime = 0.0f;
    float fGain= 0.0f;
    float fFrameRate= 0.0f;

    m_ctrlEditExposureTime.GetWindowText(cstrInfo);
    fExposureTime = atof(cstrInfo);

    m_ctrlEditGain.GetWindowText(cstrInfo);
    fGain = atof(cstrInfo);

    m_ctrlEditFrameRate.GetWindowText(cstrInfo);
    fFrameRate = atof(cstrInfo);

    nRet = MV_SC_SetEnumerationValue(m_handle, "ExposureAuto", 0);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("关闭自动曝光失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    nRet = MV_SC_SetFloatValue(m_handle, "ExposureTime", fExposureTime);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("设置曝光时间失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    nRet = MV_SC_SetFloatValue(m_handle, "Gain", fGain);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("设置增益失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }

    nRet = MV_SC_SetEnumerationValue(m_handle, "GainAuto", 0);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("关闭自动增益失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
    nRet = MV_SC_SetFloatValue(m_handle, "AcquisitionFrameRate", fFrameRate);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("设置帧率失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedRadioTriggerOff()
{
    // TODO: 在此添加控件通知处理程序代码
    int nRet = MV_OK;
    CString cstrInfo;
    nRet = MV_SC_SetEnumerationValue(m_handle, "TriggerMode", 0);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("设置连续采集失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedRadioTriggerOn()
{
    // TODO: 在此添加控件通知处理程序代码
    int nRet = MV_OK;
    CString cstrInfo;
    nRet = MV_SC_SetEnumerationValue(m_handle, "TriggerMode", 1);
    if (MV_OK != nRet)
    {
        cstrInfo.Format("设置触发模式失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedCheckSoftware()
{
    // TODO: 在此添加控件通知处理程序代码
    int nRet = MV_OK;
    CString cstrInfo;
    if (m_ctrlCheckSoftware.GetCheck())
    {
        nRet = MV_SC_SetEnumerationValue(m_handle, "TriggerSource", 1);   //选择软触发
        if (MV_OK != nRet)
        {
            cstrInfo.Format("设置软触发失败!nRet = [%#x]", nRet);
            MessageBox(cstrInfo);
            return ;
        }
    }
    else
    {
        nRet = MV_SC_SetEnumerationValue(m_handle, "TriggerSource", 0);
        if (MV_OK != nRet)
        {
            cstrInfo.Format("设置Line0失败!nRet = [%#x]", nRet);
            MessageBox(cstrInfo);
            return ;
        }
    }
}

void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonSoftwareOnce()
{
    // TODO: 在此添加控件通知处理程序代码
    int nRet = MV_OK;
    CString cstrInfo;

    nRet = MV_SC_CommandExecute(m_handle, "TriggerSoftware");
    if (MV_OK != nRet)
    {
        cstrInfo.Format("软触发一次失败!nRet = [%#x]", nRet);
        MessageBox(cstrInfo);
        return ;
    }
}


void CMvSmartCamCtrlDemoDlg::OnBnClickedButtonSaveBmp()
{
    int nRet = MV_OK;
    CString cstrInfo;

    FILE* pFile = NULL;
    pFile = fopen("Image.raw","wb");
    if(NULL == pFile)
    {
        cstrInfo.Format("打开文件失败");
        MessageBox(cstrInfo);
        return ;
    }

    unsigned char* pFrameData = (unsigned char*)malloc(2592*2048);
    MV_SC_IMAGE_OUT_INFO stImageInfo;

    //获取一张图像
//     for (int i = 0; i < 100000; ++i)
//     {
//         memset(&stImageInfo,0,sizeof(MV_SC_IMAGE_OUT_INFO));
//         nRet = MV_SC_GetOneFrame(m_handle, pFrameData,2592*2048, &stImageInfo);
//         if(MV_OK == nRet)
//         {
//             fwrite(pFrameData,1,stImageInfo.nWidth * stImageInfo.nHeight,pFile);
//             cstrInfo.Format("保存成功");
//             MessageBox(cstrInfo);
//             break;
//         }
//     }
    fwrite(m_pData, 1, m_stImageOutInfo.nWidth * m_stImageOutInfo.nHeight, pFile);
    free(pFrameData);
    fclose(pFile);

    // TODO: Add your control notification handler code here
}

void CMvSmartCamCtrlDemoDlg::OnClose()
{
    // TODO: Add your message handler code here and/or call default
    if(m_handle)
    {
        MV_SC_Disconnect(m_handle);
        MV_SC_DestroyHandle(m_handle);
    }
    CDialog::OnClose();
}
