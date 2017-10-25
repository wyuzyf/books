/***************************************************************************************************
* 
* 版权信息：版权所有 (c) 2016, 杭州海康机器人技术有限公司, 保留所有权利
* 
* 文件名称：SmartCamParams.h
* 摘    要：智能相机参数定义
*
* 当前版本：1.0.0.0
* 日    期：2016-05-02
* 备    注：新建
***************************************************************************************************/
#ifndef _MV_SMTCAM_PARAMS_H_
#define _MV_SMTCAM_PARAMS_H_

#include "PixelType.h"


// 最大支持的设备个数
#define MV_SC_MAX_DEVICE_NUM      16

//  异常消息类型
#define MV_SC_EXCEPTION_DEV_DISCONNECT     0x00008001      // 设备断开连接

//节点String值最大长度
#define MV_SC_MAX_XML_STRVALUE_LEN 256

//设备信息结构体定义
typedef struct _MV_SC_DEVICE_INFO_
{
    unsigned int    nDeviceIp;                      // 设备Ip
    unsigned int    nNetAdapterIp;                  // 设备对应的网卡的IP
    unsigned char   strUserName[16];                // 需要用户填写
    unsigned char   strPassword[32];                // 需要用户填写
    unsigned int    bForceConnect;                  // 需要用户填写

    unsigned short  nMacAddrHigh;                    // 设备Mac地址高2字节
    unsigned int    nMacAddrLow;                     // 设备Mac地址低4字节
    unsigned int    nIpCfgOption;                    // 设备Ip配置选项
    unsigned int    nIpCfgCurrent;                   // 设备Ip配置:bit31-static bit30-dhcp bit29-lla 代表三种Ip配置选项
    unsigned int    nCurrentSubNetMask;              // 设备子网掩码
    unsigned int    nDefultGateWay;                  // 网关
    unsigned char   chManufacturerName[32];          // 制造商名称
    unsigned char   chModelName[32];                 // 型号
    unsigned char   chDeviceVersion[32];             // 设备版本
    unsigned char   chManufacturerSpecificInfo[48];  // 制造商详细信息
    unsigned char   chSerialNumber[16];              // 序列号
    unsigned char   chUserDefinedName[16];           // 用户自定义名称

    unsigned int    nReserved[16];
}MV_SC_DEVICE_INFO;

enum SC_PROGRAM_STATE
{
	SC_PROGRAM_UNKNOWN,
	SC_PROGRAM_RUNNING,
	SC_PROGRAM_STOP
};

typedef struct _MV_SC_UPGRADE_INFO_
{
	unsigned long		deviceIndex;
	unsigned long		hostIp;
	unsigned short		progress;
	SC_PROGRAM_STATE 	programState;
	unsigned char		deviceHostName[32];
	unsigned char		cameraName[32];
	unsigned char		cameraVersion[32];
	MV_SC_DEVICE_INFO 	oriCameraInfo;
}MV_SC_UPGRADE_INFO;

typedef struct _MV_SC_UPGRADE_INFO_LIST_
{
	unsigned int           nDeviceNum;                             // 在线设备数量
	MV_SC_UPGRADE_INFO     astUpgradeDeviceInfo[MV_SC_MAX_DEVICE_NUM];     // 支持最多16个设备
}MV_SC_UPGRADE_INFO_LIST;

// 设备信息列表
typedef struct _MV_SC_DEVICE_INFO_LIST_
{
    unsigned int            nDeviceNum;                             // 在线设备数量
    MV_SC_DEVICE_INFO      astDeviceInfo[MV_SC_MAX_DEVICE_NUM];     // 支持最多16个设备
}MV_SC_DEVICE_INFO_LIST;


// 网络传输的相关信息
typedef struct _MV_NETTRANS_INFO_
{
    int64_t         nReviceDataSize;    // 已接收数据大小  [统计StartGrabbing和StopGrabbing之间的数据量]
    int             nThrowFrameCount;   // 丢帧数量
    unsigned int    nReserved[5];       // 保留

}MV_NETTRANS_INFO;

// 全匹配的一种信息结构体
typedef struct _MV_ALL_MATCH_INFO_
{
    unsigned int    nType;          // 需要输出的信息类型，e.g. MV_MATCH_TYPE_NET_DETECT
    void*           pInfo;          // 输出的信息缓存，由调用者分配
    unsigned int    nInfoSize;      // 信息缓存的大小

}MV_ALL_MATCH_INFO;

//像素类型
enum MvScPixelType
{
    // Undefined pixel type
    PixelType_Sc_Undefined              = 0,    
    PixelType_Sc_Bmp                    = 1,
    PixelType_Sc_Jpg                    = 2,
    PixelType_Sc_Mono8                  = 3,
};

//输出信息类型
enum MvScResultType
{
    ScResType_NULL                      = 0,    // 没有结果输出
    ScResType_BCR                       = 1,    // 输出信息为BCR  (对应结构体 MV_SC_RESULT_BCR)
};


#define MV_SC_MAX_BCR_CODE_LEN 256

//条码信息结构体定义
typedef struct _MV_SC_BCR_INFO_
{
    unsigned int    nID;                                // 条码ID
    char            chCode[MV_SC_MAX_BCR_CODE_LEN];     // 字符
    unsigned int    nLen;                               // 字符长度
    unsigned int    nBarType;                           // 条码类型

    // 条码位置
    struct SC_POINT
    {
        int x;                                          // x坐标
        int y;                                          // y坐标
    } pt[4];

    int             nAngle;                             // 条码角度（0~1800）
    unsigned int    nMainPackageId;                     // 主包ID
    unsigned int    nSubPackageId;                      // 次包ID
    unsigned int    nReserved[2];                       // 保留
} MV_SC_BCR_INFO;

// 一次最多输出的条码个数
#define MAX_SC_BCR_COUNT    200

// ScResType_BCR 对应的结构体
typedef struct _MV_SC_RESULT_BCR_
{
    unsigned int    nCodeNum;                           // 条码数量
    MV_SC_BCR_INFO  stBcrInfo[MAX_SC_BCR_COUNT];        // 条码信息结构体
    unsigned int    nReserved[4];                       // 保留
}MV_SC_RESULT_BCR;

// 结果数据缓存的上限
#define MV_SC_MAX_RESULT_SIZE       (1024*64)

// 输出帧信息结构体定义
typedef struct _MV_SC_IMAGE_OUT_INFO_
{
    unsigned short      nWidth;             // 图像宽
    unsigned short      nHeight;            // 图像高
    MvScPixelType       enPixelType;        // 像素或图片格式

    unsigned int        nTriggerIndex;      // 触发序号（仅在电平触发时有效）
    unsigned int        nFrameNum;          // 帧号
    unsigned int        nFrameLen;          // 当前帧数据大小
    unsigned int        nTimeStampHigh;     // 时间戳高32位
    unsigned int        nTimeStampLow;      // 时间戳低32位

    unsigned int        nResultType;        // 输出的消息类型

    unsigned char       chResult[MV_SC_MAX_RESULT_SIZE];    // 根据消息类型对应不同的结构体

    unsigned int        nFrameLenForCutout; // 抠面单后的图片数据大小

    unsigned int        bFlaseTrigger;       // 是否误触发
    unsigned int        nFocusScore;       //  聚焦得分

    unsigned int        nReserved[5];       // 保留
}MV_SC_IMAGE_OUT_INFO;

//触发模式打开状态
typedef enum _MV_SC_TRIGGER_MODE_
{
    SC_TRIGGER_MODE_OFF         = 0,        // 关闭
    SC_TRIGGER_MODE_ON          = 1,        // 打开
}MV_SC_TRIGGER_MODE;

//触发源
typedef enum _MV_SC_TRIGGER_SOURCE_
{
    SC_TRIGGER_SOURCE_LINE0             = 0,        // Line0 触发
    SC_TRIGGER_SOURCE_LINE1             = 2,        // Line1 触发
    SC_TRIGGER_SOURCE_LINE2             = 3,        // Line2 触发
    SC_TRIGGER_SOURCE_COUNTER0          = 5,        // Counter0 触发
    SC_TRIGGER_SOURCE_SOFTWARE          = 1,        // 软触发
}MV_SC_TRIGGER_SOURCE;

// 自动曝光模式
typedef enum _MV_SC_EXPOSURE_AUTO_MODE_
{
    SC_EXPOSURE_AUTO_MODE_OFF        = 0,            // 关闭
    SC_EXPOSURE_AUTO_MODE_ONCE       = 1,            // 一次
    SC_EXPOSURE_AUTO_MODE_CONTINUOUS = 2,            // 连续

}MV_SC_EXPOSURE_AUTO_MODE;

//自动增益
typedef enum _MV_SC_GAIN_AUTO_MODE_
{
    SC_GAIN_AUTO_MODE_OFF        = 0,            // 关闭
    SC_GAIN_AUTO_MODE_ONCE       = 1,            // 一次
    SC_GAIN_AUTO_MODE_CONTINUOUS = 2,            // 连续
};


//明场/暗场矫正 模式  
typedef enum _MV_SC_FIELD_CORRECT_MODE_
{
    SC_DARK_FILED_CORRECT        = 0,            // 暗场校验
    SC_BRIGHT_FILED_CORRECT       = 1,            // 明场校验
    SC_INVAILED_FILED_CORRECT     = 2,            // 无效校验

}MV_SC_FIELD_CORRECT_MODE;




// GigEVision IP Configuration
#define MV_IP_CFG_STATIC        0x05000000
#define MV_IP_CFG_DHCP          0x06000000
#define MV_IP_CFG_LLA           0x04000000

// GigEVision Net Transfer Mode
#define MV_NET_TRANS_DRIVER     0x00000001
#define MV_NET_TRANS_SOCKET     0x00000002

// 信息类型
#define MV_MATCH_TYPE_NET_DETECT             0x00000001      // 网络流量和丢包信息

//  网络流量和丢包信息反馈结构体，对应类型为 MV_MATCH_TYPE_NET_DETECT
typedef struct _MV_MATCH_INFO_NET_DETECT_
{
    int64_t         nReviceDataSize;    // 已接收数据大小  [统计StartGrabbing和StopGrabbing之间的数据量]
    int64_t         nLostPacketCount;   // 丢失的包数量
    unsigned int    nLostFrameCount;    // 丢帧数量
    unsigned int    nReserved[5];          // 保留
}MV_MATCH_INFO_NET_DETECT;

#define MV_MAX_XML_SYMBOLIC_NUM      64

//图像基本信息结构体定义
typedef struct _MV_IMAGE_BASIC_INFO_
{
    // width
    unsigned short      nWidthValue;        // 图像宽度
    unsigned short      nWidthMin;          // 图像宽度最小值
    unsigned int        nWidthMax;          // 图像宽度最大值
    unsigned int        nWidthInc;          // 图像宽度步进值

    // height
    unsigned int        nHeightValue;       // 图像高度
    unsigned int        nHeightMin;         // 图像高度最小值
    unsigned int        nHeightMax;         // 图像高度最大值
    unsigned int        nHeightInc;         // 图像高度步进值

    // framerate
    float               fFrameRateValue;    // 帧率值
    float               fFrameRateMin;      // 帧率最小值
    float               fFrameRateMax;      // 帧率最大值

    // 像素格式
    unsigned int        enPixelType;                // 当前的像素格式
    unsigned int        nSupportedPixelFmtNum;      // 支持的像素格式种类
    unsigned int        enPixelList[MV_MAX_XML_SYMBOLIC_NUM];
    unsigned int        nReserved[8];                           // 保留

}MV_IMAGE_BASIC_INFO;

typedef struct _MVSC_CMDVALUE_T
{
    bool            bIsDone;
    unsigned int    nReserved[4];
}MVSC_CMDVALUE;

//BOOL型值结构体定义
typedef struct _MVSC_BOOLVALUE_T
{
    bool            bCurValue;      // 当前值
    unsigned int    nReserved[4];
}MVSC_BOOLVALUE;

//整型值结构体定义
typedef struct _MVSC_INTVALUE_T
{
    unsigned int    nCurValue;      // 当前值
    unsigned int    nMax;           // 最大值
    unsigned int    nMin;           // 最小值
    unsigned int    nInc;           // 步进值

    unsigned int    nReserved[4];   // 保留
}MVSC_INTVALUE;

//浮点型值结构体定义
typedef struct _MVSC_FLOATVALUE_T
{
    float           fCurValue;      // 当前值
    float           fMax;           // 最大值
    float           fMin;           // 最小值

    unsigned int    nReserved[4];   // 保留
}MVSC_FLOATVALUE;

//String型值结构体定义
typedef struct _MVSC_STRINGVALUE_T
{
    char   chCurValue[MV_SC_MAX_XML_STRVALUE_LEN];      // 当前值

    unsigned int    nReserved[4];                       // 保留
}MVSC_STRINGVALUE;

//枚举型值结构体定义
typedef struct _MVSC_ENUMVALUE_T
{
    unsigned int    nCurValue;      // 当前值
    unsigned int    nSupportedNum;  // 数据的有效数据个数
    unsigned int    nSupportValue[MV_MAX_XML_SYMBOLIC_NUM];     // 当前支持的枚举值

    unsigned int    nReserved[4];   // 保留
}MVSC_ENUMVALUE;




// 网络传输的相关信息
typedef struct _MVSC_NETTRANS_INFO_
{
    int64_t         nGvspReceiveDataSize;           // GVSP通道接收的数据大小
    int             nGvspThrowFrameCount;           // GVSP通道抛出的帧数
    int64_t         nGvmpReceiveDataSize;           // GVMP通道接收的数据大小
    int             nGvmpThrowFrameCount;           // GVMP通道抛出的帧数
    unsigned int    nReserved[24];                  // 保留

}MVSC_NETTRANS_INFO;

// 输出协议
#define CommuPtlSmartSDK 1
#define CommuPtlTcpIP    2
#define CommuPtlSerial   3



// 图片格式转换参数
typedef struct _MVSC_IMG_CONVERT_PARAM_
{
    unsigned char*      pData;              // [IN]     输入数据缓存
    unsigned int        nDataLen;           // [IN]     输入数据大小
    unsigned short      nWidth;             // [IN]     图像宽
    unsigned short      nHeight;            // [IN]     图像高

    char                strFilePath[256];   // [IN]     输出图片路径
    unsigned int        nJpgQuality;        // [IN]     编码质量, (0-100]
    unsigned int        nReserved[4];

}MVSC_IMG_CONVERT_PARAM;


#endif /* _MV_SMTCAM_PARAMS_H_ */
