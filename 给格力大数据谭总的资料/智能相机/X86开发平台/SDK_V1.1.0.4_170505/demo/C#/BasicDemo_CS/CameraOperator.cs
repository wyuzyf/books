using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NsMvCameraSDK;
using System.Runtime.InteropServices;


namespace NsCameraOperator
{
    //using ImageCallBack = CMvSmartSDK.cbOutputdelegate;
    //using ExceptionCallBack = CMvSmartSDK.cbExceptiondelegate;
    class CCameraOperator
    {
        private CMvSmartSDK m_pcMvSmartSDK = new CMvSmartSDK();
        public CCameraOperator()
        {

        }

        ~CCameraOperator()
        {

        }

        /****************************************************************************
         * @fn           EnumDevices
         * @brief        枚举可连接设备
         * @param        nLayerType       IN         传输层协议：1-GigE; 4-USB;可叠加
         * @param        stDeviceList     OUT        设备列表
         * @return       成功：0；错误：错误码
         ****************************************************************************/
        public static int Discovery(ref CMvSmartSDK.MV_SC_DEVICE_INFO_LIST pstDeviceList)
        {
            int nRet = CMvSmartSDK.MV_OK;
            nRet = CMvSmartSDK.MV_SC_Discovery_CSI(ref pstDeviceList);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           Open
         * @brief        连接设备
         * @param        stDeviceInfo       IN       设备信息结构体
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int Open(ref CMvSmartSDK.MV_SC_DEVICE_INFO pstDeviceInfo)
        {
            int nRet = CMvSmartSDK.MV_OK;
            nRet = m_pcMvSmartSDK.MV_SC_CreateHandle_CSI(ref pstDeviceInfo);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            nRet = m_pcMvSmartSDK.MV_SC_Connect_CSI();
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           Close
         * @brief        关闭设备
         * @param        none
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int Close()
        {
            int nRet = CMvSmartSDK.MV_OK;

            nRet = m_pcMvSmartSDK.MV_SC_Disconnect_CSI();
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            nRet = m_pcMvSmartSDK.MV_SC_DestroyHandle_CSI();
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           StartGrabbing
         * @brief        开始采集
         * @param        none
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int StartGrabbing()
        {
            int nRet = CMvSmartSDK.MV_OK;
            //开始采集
            nRet = m_pcMvSmartSDK.MV_SC_StartJob_CSI();
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }

        public int DisplayOneFrame(IntPtr hWnd, IntPtr pData, UInt32 nDataLen
            , UInt32 nWidth, UInt32 nHeight, UInt32 nPixelFormat)
        {
            int nRet = CMvSmartSDK.MV_OK;
            nRet = m_pcMvSmartSDK.MV_SC_DisplayOneFrame_CSI(hWnd, pData, nDataLen, nWidth, nHeight, nPixelFormat);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }



        /****************************************************************************
         * @fn           StopGrabbing
         * @brief        停止采集
         * @param        none
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int StopGrabbing()
        {
            int nRet = CMvSmartSDK.MV_OK;
            nRet = m_pcMvSmartSDK.MV_SC_StopJob_CSI();
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           RegisterImageCallBack
         * @brief        注册取流回调函数
         * @param        CallBackFunc          IN        回调函数
         * @param        pUser                 IN        用户参数
         * @return       成功：0；错误：-1
         ****************************************************************************/
        //public int RegisterImageCallBack(ImageCallBack CallBackFunc, IntPtr pUser)
        //{
        //    int nRet;
        //    nRet = m_pcMvSmartSDK.MV_SC_RegisterImageCallBack_CSI(CallBackFunc, pUser);
        //    if (CMvSmartSDK.MV_OK != nRet)
        //    {
        //        return CO_FAIL;
        //    }
        //    return CO_OK;
        //}


        /****************************************************************************
         * @fn           RegisterExceptionCallBack
         * @brief        注册异常回调函数
         * @param        CallBackFunc          IN        回调函数
         * @param        pUser                 IN        用户参数
         * @return       成功：0；错误：-1
         ****************************************************************************/
        //public int RegisterExceptionCallBack(ExceptionCallBack CallBackFunc, IntPtr pUser)
        //{
        //    int nRet;
        //    nRet = m_pcMvSmartSDK.MV_SC_RegisterExceptionCallBack_CSI(CallBackFunc, pUser);
        //    if (CMvSmartSDK.MV_OK != nRet)
        //    {
        //        return CO_FAIL;
        //    }
        //    return CO_OK;
        //}


        /****************************************************************************
         * @fn           GetOneFrame
         * @brief        获取一帧图像数据
         * @param        pData                 IN-OUT            数据数组指针
         * @param        pnDataLen             IN                数据大小
         * @param        nDataSize             IN                数组缓存大小
         * @param        pFrameInfo            OUT               数据信息
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int GetOneFrame(IntPtr pData, UInt32 nDataSize, IntPtr pstImageOutInfo)
        {
            int nRet = CMvSmartSDK.MV_OK;
            nRet = m_pcMvSmartSDK.MV_SC_GetOneFrame_CSI(pData, nDataSize, pstImageOutInfo);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           GetIntValue
         * @brief        获取Int型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        pnValue               OUT       返回值
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int GetIntValue(string strKey, ref UInt32 pnValue)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_GetIntegerValue_CSI(strKey, ref pnValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           SetIntValue
         * @brief        设置Int型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        nValue                IN        设置参数值，具体取值范围参考HikCameraNode.xls文档
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int SetIntValue(string strKey, UInt32 nValue)
        {

            int nRet = m_pcMvSmartSDK.MV_SC_SetIntegerValue_CSI(strKey, nValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }



        /****************************************************************************
         * @fn           GetFloatValue
         * @brief        获取Float型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        pValue                OUT       返回值
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int GetFloatValue(string strKey, ref float pfValue)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_GetFloatValue_CSI(strKey, ref pfValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           SetFloatValue
         * @brief        设置Float型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        fValue                IN        设置参数值，具体取值范围参考HikCameraNode.xls文档
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int SetFloatValue(string strKey, float fValue)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_SetFloatValue_CSI(strKey, fValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           GetEnumValue
         * @brief        获取Enum型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        pnValue               OUT       返回值
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int GetEnumValue(string strKey, ref UInt32 pnValue)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_GetEnumerationValue_CSI(strKey, ref pnValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }



        /****************************************************************************
         * @fn           SetEnumValue
         * @brief        设置Float型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        nValue                IN        设置参数值，具体取值范围参考HikCameraNode.xls文档
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int SetEnumValue(string strKey, UInt32 nValue)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_SetEnumerationValue_CSI(strKey, nValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }



        /****************************************************************************
         * @fn           GetBoolValue
         * @brief        获取Bool型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        pbValue               OUT       返回值
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int GetBoolValue(string strKey, ref bool pbValue)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_GetBooleanValue_CSI(strKey, ref pbValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           SetBoolValue
         * @brief        设置Bool型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        bValue                IN        设置参数值，具体取值范围参考HikCameraNode.xls文档
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int SetBoolValue(string strKey, bool bValue)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_SetBooleanValue_CSI(strKey, bValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           GetStringValue
         * @brief        获取String型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        strValue              OUT       返回值
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int GetStringValue(string strKey, ref string strValue)
        {
            UInt32 nLength = (UInt32)strValue.Length;
            int nRet = m_pcMvSmartSDK.MV_SC_GetStringValue_CSI(strKey, ref strValue, nLength);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }

            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           SetStringValue
         * @brief        设置String型参数值
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @param        strValue              IN        设置参数值，具体取值范围参考HikCameraNode.xls文档
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int SetStringValue(string strKey, string strValue)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_SetStringValue_CSI(strKey, strValue);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           CommandExecute
         * @brief        Command命令
         * @param        strKey                IN        参数键值，具体键值名称参考HikCameraNode.xls文档
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int CommandExecute(string strKey)
        {
            int nRet = m_pcMvSmartSDK.MV_SC_CommandExecute_CSI(strKey);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }


        /****************************************************************************
         * @fn           SaveImage
         * @brief        保存图片
         * @param        pSaveParam            IN        保存图片配置参数结构体
         * @return       成功：0；错误：-1
         ****************************************************************************/
        public int SaveImage(ref CMvSmartSDK.MVSC_IMG_CONVERT_PARAM pstImageConvertParam)
        {
            int nRet;
            nRet = m_pcMvSmartSDK.MV_SC_SaveJpg_CSI(ref pstImageConvertParam);
            if (CMvSmartSDK.MV_OK != nRet)
            {
                return nRet;
            }
            return CMvSmartSDK.MV_OK;
        }
    }
}
