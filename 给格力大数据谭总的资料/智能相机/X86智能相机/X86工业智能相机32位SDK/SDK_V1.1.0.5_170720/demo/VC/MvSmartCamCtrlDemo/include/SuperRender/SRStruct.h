/** @file    SRStruct.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   跨平台渲染库结构体相关定义的头文件
 *
 *  @author  播放应用软件组 -- 王川艳
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning 版权所有
 */
#ifndef __SR_STRUCT_H__
#define __SR_STRUCT_H__

// 定义最大的支持的显示端口数量
#define SR_MAX_WND 32
#define SR_DEFAULT_FRAME_SIZE 128

// 显示引擎枚举
typedef enum tagSRRenderEngine
{
	SR_ENGINE_DEFAULT	= 0x0,			// 不指定显示引擎
	SR_ENGINE_D3D		= 0x1,			// D3D显示引擎
	SR_ENGINE_DDRAW		= 0x2,			// DDraw显示引擎
	SR_ENGINE_OPENGL	= 0x4,			// OpenGL显示引擎
	SR_ENGINE_OPENGLES  = 0x8,			// OpenGL ES显示引擎
}SREngine;

// 矩形结构体
typedef struct tagSRRectF
{
	float fTop;		// [0.0 , 1.0]
	float fBottom;	// [0.0 , 1.0]
	float fLeft;	// [0.0 , 1.0]
	float fRight;	// [0.0 , 1.0]
}SRRECTF;


// 点结构体
typedef struct tagSRPointF
{
	float fX;
	float fY;
}SRPOINTF;

// 色彩结构体
typedef struct tagSRColor
{
	float fR;		// [0.0 , 1.0]
	float fG;		// [0.0 , 1.0]
	float fB;		// [0.0 , 1.0]
	float fAlpha;	// [0.0 , 1.0]
}SRCOLOR;

// 颜色结构体
typedef struct SR_COLOR
{
	float   R;		// [0.0 , 255.0]
	float   G;		// [0.0 , 255.0]
	float   B;		// [0.0 , 255.0]
	float   Y;		// [0.0 , 255.0]
	float   U;		// [0.0 , 255.0]
	float   V;		// [0.0 , 255.0]
}SR_COLOR;

#define SR_UPDATE_FLAG 0x1f

#define SR_CAPS_DRIVQUALITY  0x1

#define CFG_DISPLAYSURFACE     0x400
#define CFG_DISPLAYRESET       0x401
#define CFG_DISPLAY_START_LINE 0x410
#define CFG_SHOW_COLOR_RIBBON  0x420      // 显示彩色带标志

// 能力集结构体
typedef struct tagSRCapability
{
	unsigned int nCapType;				// 需要查询的能力集类型（输入）
	unsigned int nEngineCap;			// 返回的能力集（输出），当需要查询当前引擎的像素能力集时，需要指定一种引擎（输入）
	unsigned int nPixelFormatCap;		// 像素格式的能力集 ，需指定引擎

	unsigned int nMaxRenderWidth;		// 最大的显示宽度 ，需指定引擎
	unsigned int nMaxRenderHeight;		// 最大的显示高度 ，需指定引擎
	unsigned int nMaxPort;				// 最大支持的端口数

	unsigned int nDrivQuality;          // 驱动质量

}SRCAPABILITY;


// 绘图回调的类型
#define		SR_CALLBACK_NULL		0   // 初始化值
#define		SR_CALLBACK_DRAWLINE	1   // 绘制直线  对应于函数
#define		SR_CALLBACK_DRAWRECT	2	// 绘制矩形  对应于函数
#define		SR_CALLBACK_DRAWCIRCLE	4	// 绘制圆形  对应于函数
#define		SR_CALLBACK_DRAWPIXELS	8	// 绘制像素  对应于函数
#define		SR_CALLBACK_DRAWTEXT	16	// 绘制文字  对应于函数

// 旋转单元结构体
typedef struct tagSRTransformElement
{
	bool  bAxisX;
	bool  bAxisY;
	bool  bAxisZ;
	float fValue;	// 旋转的角度
	
}SRTRANSFERELEMENT;

// 旋转组合参数
typedef struct tagSRTransformParam
{
	SRTRANSFERELEMENT * pTransformElement;		// 旋转的坐标轴
	unsigned int		nTransformCount;		// 旋转的组合次数
}SRTRANSFERPARAM;

typedef enum tagSRTextureFilterType
{
	SR_TEXF_NONE            = 0,    // filtering disabled (valid for mip filter only)
	SR_TEXF_POINT           = 1,    // nearest
	SR_TEXF_LINEAR          = 2,    // linear interpolation
	SR_TEXF_ANISOTROPIC     = 3,    // anisotropic
	SR_TEXF_PYRAMIDALQUAD   = 6,    // 4-sample tent
	SR_TEXF_GAUSSIANQUAD    = 7,    // 4-sample gaussian

}SRTEXTUREFILTERTYPE;

/**	@fn	     SR_CallBack
 *	@brief	 绘图回调函数
 *	@param c pUser  
 *	@param n 用户数据
 *	@param c nPort  
 *	@param n 对应的端口
 *	@param c nCBType  
 *	@param n 绘图回调类型
 *	@param c hDC  
 *	@param n 表面DC
 *	@param c nWidth  
 *	@param n 绘图表面的宽
 *	@param c nHeight  
 *	@param n 绘图表面的高
 *	@return	
	见返回值类型说明
 */ 
typedef void (__stdcall * SR_CallBack )( void* pUser  , unsigned int  nPort , unsigned int nCBType , void * hDC ,   unsigned int nWidth , unsigned int nHeight); 


/**	@fn	     SR_CallBack
 *	@brief	 绘图回调函数
 *	@param c pUser  
 *	@param n 用户数据
 *	@param c nPort  
 *	@param n 对应的端口
 *	@param c nCBType  
 *	@param n 绘图回调类型
 *	@param c hDC  
 *	@param n 表面DC
 *	@param c nWidth  
 *	@param n 绘图表面的宽
 *	@param c nHeight  
 *	@param n 绘图表面的高
 *	@return	
	见返回值类型说明
 */ 
typedef void (__stdcall * SR_UpdateCallBack )( void* pUser, void * pData); 
// 各Port对应的结构体
typedef struct tagRenderParam
{
	
	SR_CallBack		    cbFunc;						// 对应的绘图回调函数
	
	void *			    pcbUser;					// 回调函数的用户数据
	
	unsigned int	    nCBType;					// 回调函数的类型
	
	SRRECTF *		    pRectSrc;					// 原始图像的显示区域
	
	SRRECTF *		    pRectDst;					// 目标窗口的显示区域
	
	SRDISPLAYEFFECT	    nDisplayEffect;				// 显示效果
	
	void		*	    pShader;					// 显示效果对应的shdaer

	void *			    hWnd;						// 记录上一次渲染的hWnd

	SRTRANSFERPARAM*    pRotation;                  // 旋转组合参数

	SRTEXTUREFILTERTYPE	nTextureFilterType;		    // 纹理拉伸的类型

    float               fOutR1;                     // 圆环显示的外圆环X轴半径

    float               fOutR2;                     // 圆环显示的外圆环Y轴半径

    float               fInR1;                      // 圆环显示的内圆环X轴半径

    float               fInR2;                      // 圆环显示的内圆环Y轴半径

    SRCOLOR             stColor;                    // 圆环显示时圆环外的颜色

    SRPOINTF            stCenter;                   // 圆环显示时圆环的圆心
	
}RENDERPARAM;

#endif
