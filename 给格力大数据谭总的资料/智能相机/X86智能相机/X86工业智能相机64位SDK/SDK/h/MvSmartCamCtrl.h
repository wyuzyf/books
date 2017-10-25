/***************************************************************************************************
* 
* 版权信息：版权所有 (c) 2016, 杭州海康机器人技术有限公司, 保留所有权利
* 
* 文件名称：MvSmartCamCtrl.h
* 摘    要：智能相机SDK的C接口类
*
* 当前版本：1.0.0.0
* 日    期：2016-05-02
* 备    注：新建
***************************************************************************************************/
#ifndef _MV_SMART_CAM_CTRL_H_
#define _MV_SMART_CAM_CTRL_H_

#include "MvErrorDefine.h"
#include "MvSmartCamParams.h"


/**
*  @brief  动态库导入导出定义
*/
#ifndef MVSMARTCAMCTRL_API

    #ifdef WIN32
        #if defined(MVSMARTCAMCTRL_EXPORTS)
            #define MVSMARTCAMCTRL_API __declspec(dllexport)
        #else
            #define MVSMARTCAMCTRL_API __declspec(dllimport)
        #endif
    #else
        #ifndef __stdcall
            #define __stdcall
        #endif

        #ifndef MVSMARTCAMCTRL_API
            #define  MVSMARTCAMCTRL_API
        #endif
    #endif

#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif


#ifdef __cplusplus
extern "C" {
#endif 

/*@fn       MV_SC_GetSDKVersion
**@brief    获取当前的SDK版本
**@param    无
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API unsigned int __stdcall MV_SC_GetSDKVersion();

/*@fn       MV_SC_Discovery
**@brief    枚举设备
**@param    pstDevList      设备信息列表结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_Discovery(IN OUT MV_SC_DEVICE_INFO_LIST * pstDevList);

/*@fn       MV_SC_DiscoveryEx
**@brief    枚举设备，扩展接口，可以指定枚举端口号
**@param    pstDevList      设备信息列表结构体指针
**@param    nDevPort        指定设备端口号
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_DiscoveryEx(IN OUT MV_SC_DEVICE_INFO_LIST * pstDevList, IN const unsigned short nDevPort);

/*@fn       MV_SC_GetDeviceInfo
**@brief    获取设备信息
**@param    nDeviceIp       设备IP地址
**@param    pstDeviceInfo   设备信息结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetDeviceInfo(IN unsigned int nDeviceIp, OUT MV_SC_DEVICE_INFO * pstDeviceInfo);

/*@fn       MV_SC_GetDeviceInfoEx
**@brief    获取设备信息，扩展接口，可指定端口号
**@param    nDeviceIp       设备IP地址
**@param    pstDeviceInfo   设备信息结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetDeviceInfoEx(IN unsigned int nDeviceIp, IN const unsigned short nDevPort, OUT MV_SC_DEVICE_INFO * pstDeviceInfo);

/*@fn       MV_SC_CreateHandle
**@brief    创建设备句柄
**@param    handle          设备句柄
**@param    pstDevInfo      设备信息结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_CreateHandle(  OUT void ** handle
                                                    , IN  MV_SC_DEVICE_INFO* pstDevInfo);

/*@fn       MV_SC_CreateHandleEx
**@brief    创建设备句柄，扩展接口，可以指定创建设备句柄的端口号
**@param    handle          设备句柄
**@param    pstDevInfo      设备信息结构体指针
**@param    nDevPort        指定设备端口号
**@param    bLogEnable      是否创建Log文件
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_CreateHandleEx(  OUT void ** handle
                                                      , IN  MV_SC_DEVICE_INFO* pstDevInfo
                                                      , IN  const unsigned short nDevPort
                                                      , IN  const bool bLogEnable);

/*@fn       MV_SC_DestroyHandle
**@brief    销毁设备句柄
**@param    handle          要销毁的设备句柄
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_DestroyHandle(IN void * handle);

/*@fn       MV_SC_ForceIp
**@brief    
**@param    handle          设备句柄
**@param    nNewIp          
**@param    nNewSubNet      
**@param    nNewGateWay     
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ForceIp(IN void * handle, IN unsigned int nNewIp);

/*@fn       MV_SC_GetTlProxy
**@brief    获取传输层代理类
**@param    handle          设备句柄
**@param    ppcTlProxy      返回的传输层代理类指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetTlProxy(IN void * handle, OUT void ** ppcTlProxy);

/* 3种状态：Offline、Online、NotConnected
   异常：CvsInSightLockedException、CvsSensorAlreadyConnectedException、
         CvsInvalidLogonException、CvsNetworkException
*/

/*@fn       MV_SC_Connect
**@brief    连接设备
**@param    handle          设备句柄
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_Connect(IN void * handle);

/*@fn       MV_SC_Disconnect
**@brief    断开连接
**@param    handle          设备句柄
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_Disconnect(IN void * handle);

/*@fn       MV_SC_SaveJob
**@brief    保存当前工作流程到第n组（n取值范围1-3）
**@param    handle          设备句柄
**@param    nIndex          
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SaveJob(IN void * handle, IN int nIndex);

/*@fn       MV_SC_ImportJob
**@brief    导入工作流程到第n组（n取值范围1-3）
**@param    handle          设备句柄
**@param    pJobBuf         工作流程缓存指针
**@param    nBufLen         工作流程缓存大小
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ImportJob(IN void * handle, IN unsigned char* pJobBuf, IN unsigned int nBufLen);

/*@fn       MV_SC_ExportJob
**@brief    导出第n组（n取值范围1-3）工作流程
**@param    handle          设备句柄
**@param    pJobBuf         工作流程缓存指针
**@param    nBufSize        工作流程缓存大小
**@param    pnBufLen        返回的缓存大小指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ExportJob(IN void * handle, IN OUT unsigned char* pJobBuf, IN unsigned int nBufSize, IN OUT unsigned int* pnBufLen);

/*@fn       MV_SC_ExportLog
**@brief    
**@param    handle          设备句柄
**@param    pJobBuf         工作流程缓存指针
**@param    nBufSize        工作流程缓存大小
**@param    pnBufLen        返回的缓存大小指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ExportLog(IN void * handle, IN OUT unsigned char* pJobBuf, IN unsigned int nBufSize, IN OUT unsigned int* pnBufLen);

/*@fn       MV_SC_ImportFilterRules
**@brief    导入扩展过滤规则
**@param    handle          设备句柄
**@param    pJobBuf         工作流程缓存指针
**@param    nBufSize        工作流程缓存大小
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_ImportFilterRules(IN void * handle, IN unsigned char* pJobBuf, IN unsigned int nBufLen);

/*@fn       MV_SC_OutportFilterRules
**@brief    导出扩展过滤规则
**@param    handle          设备句柄
**@param    pJobBuf         工作流程缓存指针
**@param    nBufSize        工作流程缓存大小
**@param    pnBufLen        返回的缓存大小指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_OutportFilterRules(IN void * handle, IN OUT unsigned char* pJobBuf, IN unsigned int nBufSize, IN OUT unsigned int* pnBufLen);

/*@fn       MV_SC_SetFilterRulesEnable
**@brief    设置扩展过滤规则使能
**@param    handle          设备句柄
**@param    bCutout         
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetFilterRulesEnable(IN void* handle, IN bool bCutout);


/*@fn       MV_SC_GetFilterRulesEnableStatus
**@brief    获取相机扩展过滤规则使能的状态
**@param    handle          设备句柄
**@param    bCutout         
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetFilterRulesEnableStatus(IN void* handle, IN bool *pbEnbale);


/*@fn       MV_SC_BeCameraExistExFilterRules
**@brief    获取相机是否存在扩展过滤规则
**@param    handle          设备句柄
**@param    pbExist         
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_BeCameraExistExFilterRules(IN void* handle, IN bool *pbExist);

/*@fn       MV_SC_StartJob
**@brief    开始工作流程
**@param    handle          设备句柄
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_StartJob(IN void * handle);

/*@fn       MV_SC_StopJob
**@brief    停止工作流程
**@param    handle          设备句柄
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_StopJob(IN void * handle);

/*@fn       MV_SC_GetJobState
**@brief    获取相机当前的工作状态，pbWorking返回值为1，表示处于工作状态，为0表示非工作状态
**@param    handle          设备句柄
**@param    pbWorking       工作状态指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetJobState(IN void * handle, IN OUT int* pbWorking);

/*@fn       MV_SC_SetCutoutEnable
**@brief    设置是否抠图
**@param    handle          设备句柄
**@param    bCutout         是否抠图标志
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetCutoutEnable(IN void* handle, IN bool bCutout);

/*@fn       MV_SC_GetOneFrame
**@brief    获取一帧图像数据
**@param    handle          设备句柄
**@param    pData           获取的图像数据指针
**@param    pData           图像数据缓存区大小
**@param    pstImageInfo    图像帧信息结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetOneFrame(IN void * handle, 
                                                  IN OUT unsigned char * pData , 
                                                  IN unsigned int nDataSize, 
                                                  IN OUT MV_SC_IMAGE_OUT_INFO * pstImageInfo);

/*@fn       MV_SC_DisplayOneFrame
**@brief    显示一帧图像
**@param    hWnd            显示窗口句柄
**@param    pData           要显示的图像数据指针
**@param    pData           图像数据大小
**@param    nWidth          图像宽度
**@param    nHeight         图像高度
**@param    nPixelFormat    图像格式
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_DisplayOneFrame(IN void * hWnd, IN unsigned char * pData , 
                                                   unsigned int nDataLen, IN unsigned int nWidth, IN unsigned int nHeight, IN unsigned int nPixelFormat);

/*@fn       MV_SC_Display
**@brief    显示一帧图像，新增，去除了MV_SC_DisplayOneFrame函数中渲染库的重复初始化和销毁，将这两个动作移到了整个程序的初始化和销毁中去。
**@param    handle          设备句柄
**@param    hWnd            显示窗口句柄
**@param    pData           要显示的图像数据指针
**@param    pData           图像数据大小
**@param    nWidth          图像宽度
**@param    nHeight         图像高度
**@param    nPixelFormat    图像格式
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_Display(  IN void * handle
                                               , IN void * hWnd
                                               , IN unsigned char * pData
                                               , IN unsigned int nDataLen
                                               , IN unsigned int nWidth
                                               , IN unsigned int nHeight
                                               , IN MvScPixelType nPixelFormat);

/*@fn       MV_SC_RegisterOutputCallBack
**@brief    注册图像数据回调函数
**@param    handle          设备句柄
**@param    cbOutput        回调函数指针
**@param    pUser           类指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_RegisterOutputCallBack(IN void * handle, 
                                                             IN void(__stdcall * cbOutput)(unsigned char * pData, MV_SC_IMAGE_OUT_INFO* pstImageInfo, void* pUser),
                                                             IN void * pUser);

/*@fn       MV_SC_RegisterExceptionCallBack
**@brief    注册异常回调函数
**@param    handle          设备句柄
**@param    cbOutput        回调函数指针
**@param    pUser           类指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_RegisterExceptionCallBack(IN void * handle, 
                                                                 void(__stdcall * cbException)(unsigned int nMsgType, void * pUser), 
                                                                 void * pUser);


// 参数设置和获取(高级参数)
/*@fn       MV_SC_GetGenICamXML
**@brief    获取XML数据
**@param    handle          设备句柄
**@param    pData           用来保存获取的XML数据的数据缓存指针
**@param    nDataSize       缓存大小
**@param    pnDataLen       返回的XML数据长度指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetGenICamXML(IN void * handle, IN OUT unsigned char * pData, IN unsigned int nDataSize, IN OUT unsigned int * pnDataLen);

/*@fn       MV_SC_CommandExecute
**@brief    执行命令
**@param    handle          设备句柄
**@param    strName         命令对应的XML节点名称
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_CommandExecute(IN void * handle, IN const char * strName);

/*@fn       MV_SC_GetBooleanValue
**@brief    获取Boolean型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    pbValue         返回的参数值指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetBooleanValue(IN void * handle, IN const char * strName, IN OUT bool * pbValue);

/*@fn       MV_SC_SetBooleanValue
**@brief    设置Boolean型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    bValue          要设置的参数值
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetBooleanValue(IN void * handle, IN const char * strName, IN bool bValue);

/*@fn       MV_SC_GetIntegerValue
**@brief    获取Integer型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    pnValue         返回的参数值指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetIntegerValue(IN void * handle, IN const char * strName, IN OUT unsigned int * pnValue);

/*@fn       MV_SC_SetIntegerValue
**@brief    设置Integer型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    nValue          要设置的参数值
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetIntegerValue(IN void * handle, IN const char * strName, IN unsigned int nValue);

/*@fn       MV_SC_GetFloatValue
**@brief    获取Float型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    pfValue         返回的参数值指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetFloatValue(IN void * handle, IN const char * strName, IN OUT float * pfValue);

/*@fn       MV_SC_SetFloatValue
**@brief    设置Float型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    fValue          要设置的参数值
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetFloatValue(IN void * handle, IN const char * strName, IN float fValue);

/*@fn       MV_SC_GetStringValue
**@brief    获取String型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    strValue        返回的参数值指针
**@param    nSize           参数值指针指向的缓存区长度
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetStringValue(IN void * handle, IN const char * strName, IN OUT char * strValue, IN unsigned int nSize);

/*@fn       MV_SC_SetStringValue
**@brief    设置String型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    strValue        要设置的参数值
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetStringValue(IN void * handle, IN const char * strName, IN const char * strValue);

/*@fn       MV_SC_GetEnumerationValue
**@brief    获取Enumeration型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    pnValue         返回的参数值指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetEnumerationValue(IN void * handle, IN const char * strName, IN OUT unsigned int * pnValue);

/*@fn       MV_SC_SetEnumerationValue
**@brief    设置Enumeration型参数值
**@param    handle          设备句柄
**@param    strName         参数对应的XML节点名称
**@param    nValue          要设置的参数值
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SetEnumerationValue(IN void * handle, IN const char * strName, IN unsigned int nValue);

/*@fn       MV_SC_GetNetTransInfo
**@brief    获取网络传输信息
**@param    handle          设备句柄
**@param    pstNetTransInfo 网络传输信息结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetNetTransInfo(IN void * handle, OUT MVSC_NETTRANS_INFO * pstNetTransInfo);

/*@fn       MV_SC_GetOptimalPacketSize
**@brief    获取最优的数据包大小
**@param    handle          设备句柄
**@param    pstNetTransInfo 网络传输信息结构体指针
**@return   返回值小于0，表示错误码；大于0，表示推荐使用的packetsize
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetOptimalPacketSize(IN void * handle);


// 以下接口为定制接口，请谨慎使用

/*@fn       MV_SC_SaveJpg
**@brief    保存JPG格式图像
**@param    pstParam        图像转换参数结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_SaveJpg(MVSC_IMG_CONVERT_PARAM* pstParam);


/************************************************************************/
/* 功能扩展型接口                                                       */
/************************************************************************/

/*@fn       MV_SC_GetIntegerValueEx
**@brief    获得整型参数值相关的全部值，如参数值、最大值、最小值、步进长度等
**@param    handle          设备句柄
**@param    strName         整型参数值对应的XML节点名
**@param    pstValue        整型结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetIntegerValueEx(IN void * handle, IN const char * strName, IN OUT MVSC_INTVALUE * pstValue);

/*@fn       MV_SC_GetIntegerValueEx
**@brief    获得浮点型参数值相关的全部值，如参数值、最大值、最小值等
**@param    handle          设备句柄
**@param    strName         浮点型参数值对应的XML节点名
**@param    pstValue        浮点型结构体指针
**@return   成功：返回MV_OK;失败：返回错误码
*/
MVSMARTCAMCTRL_API int __stdcall MV_SC_GetFloatValueEx(IN void * handle, IN const char * strName, IN OUT MVSC_FLOATVALUE * pstValue);

#ifdef __cplusplus
}
#endif 

#endif //_MV_SMART_CAM_CTRL_H_
