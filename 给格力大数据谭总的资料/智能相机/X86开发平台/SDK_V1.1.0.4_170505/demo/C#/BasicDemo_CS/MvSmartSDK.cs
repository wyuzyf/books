using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;

namespace NsMvCameraSDK
{
    public class CMvSmartSDK
    {
        // 回调函数声明
        //public delegate void cbOutputdelegate(IntPtr pData, ref MV_FRAME_OUT_INFO pFrameInfo, IntPtr pUser);
        //public delegate void cbXmlUpdatedelegate(MV_XML_InterfaceType enType, IntPtr pstFeature, ref MV_XML_NODES_LIST pstNodesList, IntPtr pUser);
        //public delegate void cbExceptiondelegate(UInt32 nMsgType, IntPtr pUser);

        // 向外提供的C#接口
        public static UInt32 MV_SC_GetSDKVersion_CSI()
        {
            return MV_SC_GetSDKVersion();
        }

        public static Int32 MV_SC_Discovery_CSI(ref MV_SC_DEVICE_INFO_LIST pstDevList)
        {
            return MV_SC_Discovery(ref pstDevList);
        }

        public CMvSmartSDK()
        {
            handle = IntPtr.Zero;
        }

        ~CMvSmartSDK()
        {
            // MV_SC_DestroyDevice_CSI();
        }

        public Int32 MV_SC_CreateHandle_CSI(ref MV_SC_DEVICE_INFO pstDevInfo)
        {
            return MV_SC_CreateHandle(ref handle, ref pstDevInfo);
        }

        public Int32 MV_SC_DestroyHandle_CSI()
        {
            return MV_SC_DestroyHandle(handle);
        }

        public Int32 MV_SC_DestroyHandle_CSI(UInt32 nNewIp)
        {
            return MV_SC_ForceIp(handle, nNewIp);
        }

        public Int32 MV_SC_GetTlProxy_CSI(ref IntPtr ppcTlProxy)
        {
            return MV_SC_GetTlProxy(handle, ref ppcTlProxy);
        }

        public Int32 MV_SC_Connect_CSI()
        {
            return MV_SC_Connect(handle);
        }

        public Int32 MV_SC_Disconnect_CSI()
        {
            return MV_SC_Disconnect(handle);
        }

        public Int32 MV_SC_SaveJob_CSI(Int32 nIndex)
        {
            return MV_SC_SaveJob(handle, nIndex);
        }

        public Int32 MV_SC_ImportJob_CSI(IntPtr pJobBuf, UInt32 nBufLen)
        {
            return MV_SC_ImportJob(handle, pJobBuf, nBufLen);
        }

        public Int32 MV_SC_ExportJob_CSI(ref IntPtr pJobBuf, UInt32 nBufSize, ref UInt32 pnBufLen)
        {
            return MV_SC_ExportJob(handle, ref pJobBuf, nBufSize, ref pnBufLen);
        }

        public Int32 MV_SC_StartJob_CSI()
        {
            return MV_SC_StartJob(handle);
        }

        public Int32 MV_SC_StopJob_CSI()
        {
            return MV_SC_StopJob(handle);
        }

        public Int32 MV_SC_GetJobState_CSI(ref IntPtr pbWorking)
        {
            return MV_SC_GetJobState(handle, ref pbWorking);
        }

        public Int32 MV_SC_GetOneFrame_CSI(IntPtr pData, UInt32 nDataSize, IntPtr pstImageInfo)
        {
            return MV_SC_GetOneFrame(handle, pData, nDataSize, pstImageInfo);
        }

        public Int32 MV_SC_DisplayOneFrame_CSI(IntPtr hWnd, IntPtr pData, UInt32 nDataLen
            , UInt32 nWidth, UInt32 nHeight, UInt32 nPixelFormat)
        {
            return MV_SC_Display(handle, hWnd, pData, nDataLen, nWidth, nHeight, nPixelFormat);

        //    return MV_SC_DisplayOneFrame(handle, hWnd, pData, nDataLen, nWidth, nHeight, nPixelFormat);
        }

        public Int32 MV_SC_GetGenICamXML_CSI(ref IntPtr pData, UInt32 nDataSize, ref UInt32 pnDataLen)
        {
            return MV_SC_GetGenICamXML(handle, ref pData, nDataSize, ref pnDataLen);
        }

        public Int32 MV_SC_CommandExecute_CSI(String strName)
        {
            return MV_SC_CommandExecute(handle, strName);
        }

        public Int32 MV_SC_GetBooleanValue_CSI(String strName, ref Boolean pbValue)
        {
            return MV_SC_GetBooleanValue(handle, strName, ref pbValue);
        }

        public Int32 MV_SC_SetBooleanValue_CSI(String strName, Boolean bValue)
        {
            return MV_SC_SetBooleanValue(handle, strName, bValue);
        }

        public Int32 MV_SC_GetIntegerValue_CSI(String strName, ref UInt32 pnValue)
        {
            return MV_SC_GetIntegerValue(handle, strName, ref pnValue);
        }

        public Int32 MV_SC_SetIntegerValue_CSI(String strName, UInt32 nValue)
        {
            return MV_SC_SetIntegerValue(handle, strName, nValue);
        }

        public Int32 MV_SC_GetFloatValue_CSI(String strName, ref float pfValue)
        {
            return MV_SC_GetFloatValue(handle, strName, ref pfValue);
        }

        public Int32 MV_SC_SetFloatValue_CSI(String strName, float fValue)
        {
            return MV_SC_SetFloatValue(handle, strName, fValue);
        }

        public Int32 MV_SC_GetStringValue_CSI(String strName, ref String strValue, UInt32 nSize)
        {
            return MV_SC_GetStringValue(handle, strName, ref strValue, nSize);
        }

        public Int32 MV_SC_SetStringValue_CSI(String strName, String strValue)
        {
            return MV_SC_SetStringValue(handle, strName, strValue);
        }

        public Int32 MV_SC_GetEnumerationValue_CSI(String strName, ref UInt32 pnValue)
        {
            return MV_SC_GetEnumerationValue(handle, strName, ref pnValue);
        }

        public Int32 MV_SC_SetEnumerationValue_CSI(String strName, UInt32 nValue)
        {
            return MV_SC_SetEnumerationValue(handle, strName, nValue);
        }

        public Int32 MV_SC_GetNetTransInfo_CSI(ref MVSC_NETTRANS_INFO pstNetTransInfo)
        {
            return MV_SC_GetNetTransInfo(handle, ref pstNetTransInfo);
        }

        public Int32 MV_SC_GetOptimalPacketSize_CSI()
        {
            return MV_SC_GetOptimalPacketSize(handle);
        }

        public Int32 MV_SC_SaveJpg_CSI(ref MVSC_IMG_CONVERT_PARAM pstParam)
        {
            return MV_SC_SaveJpg(ref pstParam);
        }

        public Int32 MV_SC_LocalUpgrade_CSI(String pFilePathName)
        {
            return MV_SC_LocalUpgrade(handle, pFilePathName);
        }

        public Int32 MV_SC_GetUpgradeProcess_CSI(ref UInt32 pnProcess)
        {
            return MV_SC_GetUpgradeProcess(handle, ref pnProcess);
        }


        // 转换函数
        public static object ByteToStruct(Byte[] bytes, Type type)
        {
            int size = Marshal.SizeOf(type);
            if (size > bytes.Length)
            {
                return null;
            }

            // 分配结构体内存空间
            IntPtr structPtr = Marshal.AllocHGlobal(size);

            // 将byte数组拷贝到分配好的内存空间
            Marshal.Copy(bytes, 0, structPtr, size);

            // 将内存空间转换为目标结构体
            object obj = Marshal.PtrToStructure(structPtr, type);

            // 释放内存空间
            Marshal.FreeHGlobal(structPtr);

            return obj;
        }

        //[StructLayout(LayoutKind.Sequential)]

        // 私有成员变量
        IntPtr handle;                                                          // 设备句柄

        // 从C/C++接口库导出的函数
        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetSDKVersion")]
        private static extern UInt32 MV_SC_GetSDKVersion();

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_Discovery")]
        private static extern Int32 MV_SC_Discovery(ref MV_SC_DEVICE_INFO_LIST pstDevList);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_CreateHandle")]
        private static extern Int32 MV_SC_CreateHandle(ref IntPtr handle, ref MV_SC_DEVICE_INFO pstDevInfo);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_DestroyHandle")]
        private static extern Int32 MV_SC_DestroyHandle(IntPtr handle);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_ForceIp")]
        private static extern Int32 MV_SC_ForceIp(IntPtr handle, UInt32 nNewIp);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetTlProxy")]
        private static extern Int32 MV_SC_GetTlProxy(IntPtr handle, ref IntPtr ppcTlProxy);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_Connect")]
        private static extern Int32 MV_SC_Connect(IntPtr handle);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_Disconnect")]
        private static extern Int32 MV_SC_Disconnect(IntPtr handle);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_SaveJob")]
        private static extern Int32 MV_SC_SaveJob(IntPtr handle, Int32 nIndex);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_ImportJob")]
        private static extern Int32 MV_SC_ImportJob(IntPtr handle, IntPtr pJobBuf, UInt32 nBufLen);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_ExportJob")]
        private static extern Int32 MV_SC_ExportJob(IntPtr handle, ref IntPtr pJobBuf, UInt32 nBufSize, ref UInt32 pnBufLen);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_StartJob")]
        private static extern Int32 MV_SC_StartJob(IntPtr handle);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_StopJob")]
        private static extern Int32 MV_SC_StopJob(IntPtr handle);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetJobState")]
        private static extern Int32 MV_SC_GetJobState(IntPtr handle, ref IntPtr pbWorking);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetOneFrame")]
        private static extern Int32 MV_SC_GetOneFrame(IntPtr handle, IntPtr pData, UInt32 nDataSize, IntPtr pstImageInfo);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_DisplayOneFrame")]
        private static extern Int32 MV_SC_DisplayOneFrame(IntPtr handle, IntPtr hWnd, IntPtr pData, UInt32 nDataLen
            , UInt32 nWidth, UInt32 nHeight, UInt32 nPixelFormat);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_Display")]
        private static extern Int32 MV_SC_Display(IntPtr handle, IntPtr hWnd, IntPtr pData, UInt32 nDataLen
            , UInt32 nWidth, UInt32 nHeight, UInt32 nPixelFormat);


        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetGenICamXML")]
        private static extern Int32 MV_SC_GetGenICamXML(IntPtr handle, ref IntPtr pData, UInt32 nDataSize, ref UInt32 pnDataLen);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_CommandExecute")]
        private static extern Int32 MV_SC_CommandExecute(IntPtr handle, String strName);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetBooleanValue")]
        private static extern Int32 MV_SC_GetBooleanValue(IntPtr handle, String strName, ref Boolean pbValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_SetBooleanValue")]
        private static extern Int32 MV_SC_SetBooleanValue(IntPtr handle, String strName, Boolean bValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetIntegerValue")]
        private static extern Int32 MV_SC_GetIntegerValue(IntPtr handle, String strName, ref UInt32 pnValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_SetIntegerValue")]
        private static extern Int32 MV_SC_SetIntegerValue(IntPtr handle, String strName, UInt32 nValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetFloatValue")]
        private static extern Int32 MV_SC_GetFloatValue(IntPtr handle, String strName, ref float pfValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_SetFloatValue")]
        private static extern Int32 MV_SC_SetFloatValue(IntPtr handle, String strName, float fValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetStringValue")]
        private static extern Int32 MV_SC_GetStringValue(IntPtr handle, String strName, ref String strValue, UInt32 nSize);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_SetStringValue")]
        private static extern Int32 MV_SC_SetStringValue(IntPtr handle, String strName, String strValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetEnumerationValue")]
        private static extern Int32 MV_SC_GetEnumerationValue(IntPtr handle, String strName, ref UInt32 pnValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_SetEnumerationValue")]
        private static extern Int32 MV_SC_SetEnumerationValue(IntPtr handle, String strName, UInt32 nValue);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetNetTransInfo")]
        private static extern Int32 MV_SC_GetNetTransInfo(IntPtr handle, ref MVSC_NETTRANS_INFO pstNetTransInfo);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetOptimalPacketSize")]
        private static extern Int32 MV_SC_GetOptimalPacketSize(IntPtr handle);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_SaveJpg")]
        private static extern Int32 MV_SC_SaveJpg(ref MVSC_IMG_CONVERT_PARAM pstParam);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_LocalUpgrade")]
        private static extern Int32 MV_SC_LocalUpgrade(IntPtr handle, String pFilePathName);

        [DllImport("MvSmartCamCtrl.dll", EntryPoint = "MV_SC_GetUpgradeProcess")]
        private static extern Int32 MV_SC_GetUpgradeProcess(IntPtr handle, ref UInt32 pnProcess);

        ////////////////////////////////////常量定义///////////////////////////
        // 错误码定义
        // 正确码定义
        public const Int32 MV_OK = unchecked((Int32)0x00000000);     ///< 成功，无错误

        // 通用错误码定义:范围0x80000000-0x800000FF
        public const Int32 MV_E_HANDLE = unchecked((Int32)0x80000000);     ///< 错误或无效的句柄
        public const Int32 MV_E_SUPPORT = unchecked((Int32)0x80000001);     ///< 不支持的功能
        public const Int32 MV_E_BUFOVER = unchecked((Int32)0x80000002);     ///< 缓存已满
        public const Int32 MV_E_CALLORDER = unchecked((Int32)0x80000003);     ///< 函数调用顺序错误
        public const Int32 MV_E_PARAMETER = unchecked((Int32)0x80000004);     ///< 错误的参数
        public const Int32 MV_E_RESOURCE = unchecked((Int32)0x80000006);     ///< 资源申请失败
        public const Int32 MV_E_NODATA = unchecked((Int32)0x80000007);     ///< 无数据
        public const Int32 MV_E_PRECONDITION = unchecked((Int32)0x80000008);     ///< 前置条件有误，或运行环境已发生变化
        public const Int32 MV_E_VERSION = unchecked((Int32)0x80000009);     ///< 版本不匹配
        public const Int32 MV_E_NOENOUGH_BUF = unchecked((Int32)0x8000000A);     ///< 传入的内存空间不足
        public const Int32 MV_E_UNKNOW = unchecked((Int32)0x800000FF);     ///< 未知的错误

        // GenICam系列错误:范围0x80000100-0x800001FF
        public const Int32 MV_E_GC_GENERIC = unchecked((Int32)0x80000100);     ///< 通用错误
        public const Int32 MV_E_GC_ARGUMENT = unchecked((Int32)0x80000101);     ///< 参数非法
        public const Int32 MV_E_GC_RANGE = unchecked((Int32)0x80000102);     ///< 值超出范围
        public const Int32 MV_E_GC_PROPERTY = unchecked((Int32)0x80000103);     ///< 属性
        public const Int32 MV_E_GC_RUNTIME = unchecked((Int32)0x80000104);     ///< 运行环境有问题
        public const Int32 MV_E_GC_LOGICAL = unchecked((Int32)0x80000105);     ///< 逻辑错误
        public const Int32 MV_E_GC_ACCESS = unchecked((Int32)0x80000106);     ///< 访问权限有误
        public const Int32 MV_E_GC_TIMEOUT = unchecked((Int32)0x80000107);     ///< 超时
        public const Int32 MV_E_GC_DYNAMICCAST = unchecked((Int32)0x80000108);     ///< 转换异常
        public const Int32 MV_E_GC_UNKNOW = unchecked((Int32)0x800001FF);     ///< GenICam未知错误

        // GigE_STATUS对应的错误码:范围0x80000200-0x800002FF
        public const Int32 MV_E_NOT_IMPLEMENTED = unchecked((Int32)0x80000200);     ///< 命令不被设备支持
        public const Int32 MV_E_INVALID_ADDRESS = unchecked((Int32)0x80000201);     ///< 访问的目标地址不存在
        public const Int32 MV_E_WRITE_PROTECT = unchecked((Int32)0x80000202);     ///< 目标地址不可写
        public const Int32 MV_E_ACCESS_DENIED = unchecked((Int32)0x80000203);     ///< 访问无权限
        public const Int32 MV_E_BUSY = unchecked((Int32)0x80000204);     ///< 设备忙，或网络断开
        public const Int32 MV_E_PACKET = unchecked((Int32)0x80000205);     ///< 网络包数据错误
        public const Int32 MV_E_NETER = unchecked((Int32)0x80000206);     ///< 网络相关错误

        // USB_STATUS对应的错误码:范围0x80000300-0x800003FF
        public const Int32 MV_E_USB_READ = unchecked((Int32)0x80000300);     ///< 读usb出错
        public const Int32 MV_E_USB_WRITE = unchecked((Int32)0x80000301);     ///< 写usb出错
        public const Int32 MV_E_USB_DEVICE = unchecked((Int32)0x80000302);     ///< 设备异常
        public const Int32 MV_E_USB_GENICAM = unchecked((Int32)0x80000303);     ///< GenICam相关错误
        public const Int32 MV_E_USB_BANDWIDTH = unchecked((Int32)0x80000304);     ///< 带宽不足  该错误码新增
        public const Int32 MV_E_USB_UNKNOW = unchecked((Int32)0x800003FF);     ///< USB未知的错误

        // 升级时对应的错误码:范围0x80000400-0x800004FF
        public const Int32 MV_E_UPG_FILE_MISMATCH = unchecked((Int32)0x80000400);     ///< 升级固件不匹配
        public const Int32 MV_E_UPG_LANGUSGE_MISMATCH = unchecked((Int32)0x80000401);     ///< 升级固件语言不匹配
        public const Int32 MV_E_UPG_CONFLICT = unchecked((Int32)0x80000402);     ///< 升级冲突（设备已经在升级了再次请求升级即返回此错误）
        public const Int32 MV_E_UPG_INNER_ERR = unchecked((Int32)0x80000403);     ///< 升级时相机内部出现错误
        public const Int32 MV_E_UPG_UNKNOW = unchecked((Int32)0x800004FF);     ///< 升级时未知错误

        public const Int32 MV_SC_MAX_DEVICE_NUM = 64;
        public const Int32 MV_SC_EXCEPTION_DEV_DISCONNECT = 0x8001;
        public const Int32 MV_SC_MAX_XML_STRVALUE_LEN = 64;
        public const Int32 MV_SC_MAX_BCR_CODE_LEN = 256;
        public const Int32 MAX_SC_BCR_COUNT = 200;
        public const Int32 MV_SC_MAX_RESULT_SIZE = (1024 * 64);
        public const Int32 MV_IP_CFG_STATIC = 0x5000000;
        public const Int32 MV_IP_CFG_DHCP = 0x6000000;
        public const Int32 MV_IP_CFG_LLA = 0x4000000;
        public const Int32 MV_NET_TRANS_DRIVER = 0x1;
        public const Int32 MV_NET_TRANS_SOCKET = 0x2;
        public const Int32 MV_MATCH_TYPE_NET_DETECT = 0x1;
        public const Int32 MV_MAX_XML_SYMBOLIC_NUM = 64;
        public const Int32 CommuPtlSmartSDK = 1;
        public const Int32 CommuPtlTcpIP = 2;
        public const Int32 CommuPtlSerial = 3;


        public enum MvGvspPixelType
        {
            // Undefined pixel type
            PixelType_Gvsp_Undefined = -1,

            // Mono buffer format defines
            PixelType_Gvsp_Mono1p = 0x01010037,
            PixelType_Gvsp_Mono2p = 0x01020038,
            PixelType_Gvsp_Mono4p = 0x01040039,
            PixelType_Gvsp_Mono8 = 0x01080001,
            PixelType_Gvsp_Mono8_Signed = 0x01080002,
            PixelType_Gvsp_Mono10 = 0x01100003,
            PixelType_Gvsp_Mono10_Packed = 0x010c0004,
            PixelType_Gvsp_Mono12 = 0x01100005,
            PixelType_Gvsp_Mono12_Packed = 0x010c0006,
            PixelType_Gvsp_Mono14 = 0x01100025,
            PixelType_Gvsp_Mono16 = 0x01100007,

            // Bayer buffer format defines 
            PixelType_Gvsp_BayerGR8 = 0x01080008,
            PixelType_Gvsp_BayerRG8 = 0x01080009,
            PixelType_Gvsp_BayerGB8 = 0x0108000a,
            PixelType_Gvsp_BayerBG8 = 0x0108000b,
            PixelType_Gvsp_BayerGR10 = 0x0110000c,
            PixelType_Gvsp_BayerRG10 = 0x0110000d,
            PixelType_Gvsp_BayerGB10 = 0x0110000e,
            PixelType_Gvsp_BayerBG10 = 0x0110000f,
            PixelType_Gvsp_BayerGR12 = 0x01100010,
            PixelType_Gvsp_BayerRG12 = 0x01100011,
            PixelType_Gvsp_BayerGB12 = 0x01100012,
            PixelType_Gvsp_BayerBG12 = 0x01100013,
            PixelType_Gvsp_BayerGR10_Packed = 0x010c0026,
            PixelType_Gvsp_BayerRG10_Packed = 0x010c0027,
            PixelType_Gvsp_BayerGB10_Packed = 0x010c0028,
            PixelType_Gvsp_BayerBG10_Packed = 0x010c0029,
            PixelType_Gvsp_BayerGR12_Packed = 0x010c002a,
            PixelType_Gvsp_BayerRG12_Packed = 0x010c002b,
            PixelType_Gvsp_BayerGB12_Packed = 0x010c002c,
            PixelType_Gvsp_BayerBG12_Packed = 0x010c002d,
            PixelType_Gvsp_BayerGR16 = 0x0110002e,
            PixelType_Gvsp_BayerRG16 = 0x0110002f,
            PixelType_Gvsp_BayerGB16 = 0x01100030,
            PixelType_Gvsp_BayerBG16 = 0x01100031,

            // RGB Packed buffer format defines 
            PixelType_Gvsp_RGB8_Packed = 0x02180014,
            PixelType_Gvsp_BGR8_Packed = 0x02180015,
            PixelType_Gvsp_RGBA8_Packed = 0x02200016,
            PixelType_Gvsp_BGRA8_Packed = 0x02200017,
            PixelType_Gvsp_RGB10_Packed = 0x02300018,
            PixelType_Gvsp_BGR10_Packed = 0x02300019,
            PixelType_Gvsp_RGB12_Packed = 0x0230001a,
            PixelType_Gvsp_BGR12_Packed = 0x0230001b,
            PixelType_Gvsp_RGB16_Packed = 0x02300033,
            PixelType_Gvsp_RGB10V1_Packed = 0x0220001c,
            PixelType_Gvsp_RGB10V2_Packed = 0x0220001d,
            PixelType_Gvsp_RGB12V1_Packed = 0x02240034,
            PixelType_Gvsp_RGB565_Packed = 0x02100035,
            PixelType_Gvsp_BGR565_Packed = 0x02100036,

            // YUV Packed buffer format defines 
            PixelType_Gvsp_YUV411_Packed = 0x020c001e,
            PixelType_Gvsp_YUV422_Packed = 0x0210001f,
            PixelType_Gvsp_YUV422_YUYV_Packed = 0x02100032,
            PixelType_Gvsp_YUV444_Packed = 0x02180020,
            PixelType_Gvsp_YCBCR8_CBYCR = 0x0218003a,
            PixelType_Gvsp_YCBCR422_8 = 0x0210003b,
            PixelType_Gvsp_YCBCR422_8_CBYCRY = 0x02100043,
            PixelType_Gvsp_YCBCR411_8_CBYYCRYY = 0x020c003c,
            PixelType_Gvsp_YCBCR601_8_CBYCR = 0x0218003d,
            PixelType_Gvsp_YCBCR601_422_8 = 0x0210003e,
            PixelType_Gvsp_YCBCR601_422_8_CBYCRY = 0x02100044,
            PixelType_Gvsp_YCBCR601_411_8_CBYYCRYY = 0x020c003f,
            PixelType_Gvsp_YCBCR709_8_CBYCR = 0x02180040,
            PixelType_Gvsp_YCBCR709_422_8 = 0x02100041,
            PixelType_Gvsp_YCBCR709_422_8_CBYCRY = 0x02100045,
            PixelType_Gvsp_YCBCR709_411_8_CBYYCRYY = 0x020c0042,

            // RGB Planar buffer format defines 
            PixelType_Gvsp_RGB8_Planar = 0x02180021,
            PixelType_Gvsp_RGB10_Planar = 0x02300022,
            PixelType_Gvsp_RGB12_Planar = 0x02300023,
            PixelType_Gvsp_RGB16_Planar = 0x02300024,
        };

        public enum MvScPixelType
        {
            // Undefined pixel type
            PixelType_Sc_Undefined = 0,
            PixelType_Sc_Bmp = 1,
            PixelType_Sc_Jpg = 2,
            PixelType_Sc_Mono8 = 3,
        };

        public enum MvScResultType
        {
            ScResType_NULL = 0,    // 没有结果输出
            ScResType_BCR = 1,   // 输出信息为BCR  (对应结构体 MV_SC_RESULT_BCR)
        };

        public enum MV_SC_TRIGGER_MODE
        {
            SC_TRIGGER_MODE_OFF = 0,            // 关闭
            SC_TRIGGER_MODE_ON = 1,            // 打开
        };
        public enum MV_SC_TRIGGER_SOURCE
        {
            SC_TRIGGER_SOURCE_LINE0 = 0,
            SC_TRIGGER_SOURCE_LINE1 = 2,
            SC_TRIGGER_SOURCE_LINE2 = 3,
            SC_TRIGGER_SOURCE_COUNTER0 = 5,
            SC_TRIGGER_SOURCE_SOFTWARE = 1,
        };

        // 自动曝光模式
        public enum MV_SC_EXPOSURE_AUTO_MODE
        {
            SC_EXPOSURE_AUTO_MODE_OFF = 0,            // 关闭
            SC_EXPOSURE_AUTO_MODE_ONCE = 1,            // 一次
            SC_EXPOSURE_AUTO_MODE_CONTINUOUS = 2,            // 连续
        };

        // 自动增益模式
        public enum MV_SC_GAIN_AUTO_MODE
        {
            SC_GAIN_AUTO_MODE_OFF = 0,            // 关闭
            SC_GAIN_AUTO_MODE_ONCE = 1,            // 一次
            SC_GAIN_AUTO_MODE_CONTINUOUS = 2,            // 连续
        };

        public struct MV_SC_DEVICE_INFO
        {
            public UInt32 nDeviceIp;
            public UInt32 nNetAdapterIp;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public String strUserName;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String strPassword;
            public UInt32 bForceConnect;
            public UInt16 nMacAddrHigh;
            public UInt32 nMacAddrLow;
            public UInt32 nIpCfgOption;
            public UInt32 nIpCfgCurrent;
            public UInt32 nCurrentSubNetMask;
            public UInt32 nDefultGateWay;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String chManufacturerName;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String chModelName;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
            public String chDeviceVersion;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 48)]
            public String chManufacturerSpecificInfo;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public String chSerialNumber;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public String chUserDefinedName;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
            public UInt32[] nReserved;
        };

        public struct MV_SC_DEVICE_INFO_LIST
        {
            public UInt32 nDeviceNum;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = MV_SC_MAX_DEVICE_NUM)]
            public MV_SC_DEVICE_INFO[] astDeviceInfo;
        };

        public struct MV_NETTRANS_INFO
        {
            public Int64 nReviceDataSize;
            public Int32 nThrowFrameCount;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 5)]
            public UInt32[] nReserved;
        }

        public struct MV_ALL_MATCH_INFO
        {
            public Int32 nType;
            public IntPtr pInfo;
            public UInt32 nInfoSize;
        }

        public struct MV_SC_BCR_INFO
        {
            public UInt32    nID;         // 条码ID
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = MV_SC_MAX_BCR_CODE_LEN)]
            public String chCode;
            public UInt32   nLen;        // 字符长度
            public UInt32    nBarType;   // 条码类型

            // 条码位置
            public struct SC_POINT
            {
                public Int32 x;
                public Int32 y;
            };

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public SC_POINT[] pt;

            public Int32             nAngle;      // 条码角度（0~1800）
            public UInt32    nMainPackageId;
            public UInt32    nSubPackageId;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
            public UInt32[] nReserved;
        };

        // ScResType_BCR 对应的结构体
        public struct MV_SC_RESULT_BCR
        {
            public UInt32    nCodeNum;       // 条码数量
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = MAX_SC_BCR_COUNT)]
            public MV_SC_BCR_INFO[] stBcrInfo;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public UInt32[] nReserved;
        };

        // 输出帧的信息
        public struct MV_SC_IMAGE_OUT_INFO
        {
            public UInt16      nWidth;             // 图像宽
            public UInt16      nHeight;            // 图像高
            public MvScPixelType enPixelType;        // 像素或图片格式

            UInt32        nTriggerIndex;      // 触发序号（仅在电平触发时有效）
            UInt32        nFrameNum;          // 帧号
            UInt32        nFrameLen;          // 当前帧数据大小
            UInt32        nTimeStampHigh;     // 时间戳高32位
            UInt32        nTimeStampLow;      // 时间戳低32位

            UInt32        nResultType;        // 输出的消息类型

            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = MV_SC_MAX_RESULT_SIZE)]
            public String chResult;


            UInt32        nFrameLenForCutout;     // 抠面单后的图片数据大小32位
            UInt32        bFlaseTrigger;     // 是否误触发32位
            UInt32        nFocusScore;     // 聚焦得分


            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 5)]
            public UInt32[] nReserved;
        };

        //  网络流量和丢包信息反馈结构体，对应类型为 MV_MATCH_TYPE_NET_DETECT
        public struct MV_MATCH_INFO_NET_DETECT
        {
            public Int64         nReviceDataSize;    // 已接收数据大小  [统计StartGrabbing和StopGrabbing之间的数据量]
            public Int64         nLostPacketCount;   // 丢失的包数量
            public UInt32    nLostFrameCount;    // 丢帧数量
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 6)]
            public UInt32[] nReserved;
        };
        public struct MV_IMAGE_BASIC_INFO
        {
            // width
            public UInt16      nWidthValue;
            public UInt16      nWidthMin;
            public UInt32        nWidthMax;
            public UInt32        nWidthInc;

            // height
            public UInt32        nHeightValue;
            public UInt32        nHeightMin;
            public UInt32        nHeightMax;
            public UInt32        nHeightInc;

            // framerate
            public float               fFrameRateValue;
            public float               fFrameRateMin;
            public float               fFrameRateMax;

            // 像素格式
            public UInt32        enPixelType;                // 当前的像素格式
            public UInt32        nSupportedPixelFmtNum;      // 支持的像素格式种类
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = MV_MAX_XML_SYMBOLIC_NUM)]
            public UInt32[] enPixelList;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
            public UInt32[] nReserved;
        };

        public struct MVSC_CMDVALUE
        {
                public bool            bIsDone;
                [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
                public UInt32[] nReserved;
        };

        public struct MVSC_INTVALUE
        {
            public UInt32    nCurValue;      // 当前值
            public UInt32    nMax;
            public UInt32    nMin;
            public UInt32    nInc;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public UInt32[] nReserved;
        };

        public struct MVSC_FLOATVALUE
        {
            public float           fCurValue;      // 当前值
            public float           fMax;
            public float           fMin;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public UInt32[] nReserved;
        };

        public struct MVSC_STRINGVALUE
        {
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = MV_SC_MAX_XML_STRVALUE_LEN)]
            public String chCurValue;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public UInt32[] nReserved;
        };

        public struct MVSC_ENUMVALUE
        {
            public UInt32    nCurValue;      // 当前值
            public UInt32    nSupportedNum;  // 数据的有效数据个数
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = MV_MAX_XML_SYMBOLIC_NUM)]
            public UInt32[] nSupportValue;

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public UInt32[] nReserved;
        };

        // 网络传输的相关信息
        public struct MVSC_NETTRANS_INFO
        {
            public Int64         nGvspReceiveDataSize;
            public Int32             nGvspThrowFrameCount;
            public Int64         nGvmpReceiveDataSize;
            public Int32             nGvmpThrowFrameCount;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 24)]
            public UInt32[] nReserved;
        };

        // 图片格式转换参数
        public struct MVSC_IMG_CONVERT_PARAM
        {
                    public IntPtr pData;
            public UInt32        nDataLen;           // [IN]     输入数据大小
            public UInt16      nWidth;             // [IN]     图像宽
            public UInt16      nHeight;            // [IN]     图像高

            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
            public String strFilePath;
            public UInt32        nJpgQuality;        // [IN]     编码质量, (0-100]
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
            public UInt32[] nReserved;

        };
    }
}
