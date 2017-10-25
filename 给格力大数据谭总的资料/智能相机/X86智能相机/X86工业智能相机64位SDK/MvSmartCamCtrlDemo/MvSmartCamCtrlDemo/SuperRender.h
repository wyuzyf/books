/** @file    SuperRender.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   跨平台渲染库接口的头文件
 *
 *  @author  播放应用软件组 -- 王川艳
 *  @date    2014/05/14
 *  @note    V1.0.1
 *
 *  @warning 版权所有
 */
#ifndef __SUPER_RENDER_H__
#define __SUPER_RENDER_H__

	#include "SuperRenderDefine.h"

	/**	@fn	     SR_CreateHandle
	 *	@brief	 创建显示句柄
	 *	@return	
		见返回值类型说明
	 */ 
	SR_API void  *		 __stdcall	SR_CreateHandle();

	/**	@fn	     SR_Init
	 *	@brief	 初始化
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPixelFormat  
	 *	@param n 像素格式
	 *	@param c nEngineType  
	 *	@param n 显示引擎类型
	 *	@param c bThreadSafe  
	 *	@param n 是否启用线程安全
	 *	@return	
		见返回值类型说明
	 */ 
	SR_API unsigned int __stdcall	SR_Init(	void				* handle ,  
												SRPIXELFORMAT		nPixelFormat , 
												SREngine			nEngineType , 
												unsigned int		bThreadSafe);

	/**	@fn	     SR_UpdateFrameData
	 *	@brief	 上传图像数据
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c pImageData  
	 *	@param n 图像数据内存首地址
	 *	@param c nWidth  
	 *	@param n 图像宽
	 *	@param c nHeight  
	 *	@param n 图像高
	 *	@param c pResverd  
	 *	@param n 保留
	 *	@return	
		见返回值类型说明
	 */ 
	SR_API unsigned int __stdcall	SR_UpdateFrameData(	void			* handle , 
														unsigned char	* pImageData , 
														unsigned int	nWidth , 
														unsigned int	nHeight , 
														void			*pResverd );

	/**	@fn	     SR_AddSubPort
	 *	@brief	 增加一个显示Port号
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 对应的port号
	 *	@param c nDisplayEffect  
	 *	@param n 显示效果
	 *	@return	
		见返回值类型说明
	 */ 
	SR_API unsigned int __stdcall	SR_AddSubPort(	void			* handle , 
													unsigned int	nPort ,  
													SRDISPLAYEFFECT nDisplayEffect);

	/**	@fn	     SR_AddSubPortEx
	 *	@brief	 增加一个显示Port号
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 对应的port号
	 *	@param c nDisplayEffect  
	 *	@param n 显示效果
	 *	@param c nTextureFilterType  
	 *	@param n 纹理拉伸的类型
	 *	@return	
		见返回值类型说明
	 */ 
	SR_API unsigned int __stdcall	SR_AddSubPortEx(void			   * handle , 
													unsigned int	    nPort ,  
													SRDISPLAYEFFECT     nDisplayEffect,
													SRTEXTUREFILTERTYPE nTextureFilterType);

	/**	@fn	     SR_DelSubPort
	 *	@brief	 删除一个显示Port号
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 对应的port号
	 *	@return	
		见返回值类型说明
	 */ 
	SR_API unsigned int __stdcall	SR_DelSubPort(	void * handle , unsigned int nPort);


	 /** @fn	  SR_RegisterDisplayWnd
	  *	 @brief	  注册显示窗口
	  *	 @param c handle  
	  *	 @param n 显示句柄
	  *	 @param c hWnd  
	  *	 @param n 需要注册的窗口句柄
	  *	 @return	
		 见返回值类型说明
	  */ 
	SR_API unsigned int __stdcall  SR_RegisterDisplayWnd(void * handle ,  void * hWnd);

	/**	@fn	     SR_Display
	 *	@brief	 将指定Port号的图像内容显示到指定的窗口上
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 指定的Port号
	 *	@param c hWnd  
	 *	@param n 窗口句柄 
	 *	@return	
		见返回值类型说明
	 */ 
	SR_API unsigned int __stdcall	SR_Display(		void			* handle ,
													unsigned int	nPort, 
													void			* hWnd );

	SR_API unsigned int __stdcall	SR_DisplaySurface(void			* handle,
		                                              unsigned int	nPort, 
		                                              void			* hWnd,
													  void          * pSurface);


	/**	@fn	     SR_SetDisplayRect
	 *	@brief	 将指定Port号的图像内容显示到指定的窗口的指定区域 
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 指定的Port号
	 *	@param c pDisplayRectSrc  
	 *	@param n 原始图像的待显示区域
	 *	@param c pDisplayRectDst  
	 *	@param n 目标窗口的显示区域	 
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall  SR_SetDisplayRect(	void			* handle ,
														unsigned int	nPort , 
														SRRECTF			* pDisplayRectSrc , 
														SRRECTF			* pDisplayRectDst  );


	/**	@fn	     SR_GetCaptureData
	 *	@brief	 从显存抓取图像
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c pData  
	 *	@param n 显存数据的内存地址（IN and OUT）
	 *	@param c pDataSize  
	 *	@param n 获取的数据的大小
	 *	@param c pWidth  
	 *	@param n 获取数据的宽
	 *	@param c pHeight  
	 *	@param n 获取数据的高
	 *	@param c pBitCount  
	 *	@param n 像素的字节数
	 *	@return	
		见返回值类型说明
	 */ 
	SR_API unsigned int __stdcall  SR_GetCaptureData(	void			* handle ,
														unsigned int	nPort,
														unsigned char	* pData , 
														unsigned int	* pDataSize , 
														unsigned int	* pWidth , 
														unsigned int	* pHeight , 
														unsigned int	* pBitCount );

	/**	@fn	     SR_SetTransform
	 *	@brief	 设置图像的旋转和镜像效果，应用于当前显示句柄，作用于所有子端口的图像显示
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nType  
	 *	@param n 显示变换类型
	 *	@return	
		见返回值类型说明;
	 */
	SR_API unsigned int __stdcall  SR_Rotate(	void			* handle , 
												unsigned int	nPort ,
												SRTRANSFERPARAM *pstRotateParam);


	/**	@fn	     SR_SetCallBack
	 *	@brief	 设置指定Port号显示时候的显示回调
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 指定的Port号
	 *	@param c nCBType  
	 *	@param n 显示回调类型
	 *	@param c cbFunc  
	 *	@param n 显示回调函数
	 *	@param c pUser  
	 *	@param n 用户数据
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall  SR_SetCallBack(	void			* handle , 
													unsigned int	nPort, 
													unsigned int	nCBType , 
													SR_CallBack		cbFunc , 
													void			* pUser);


	/**	@fn	     SR_SetUpdateCallBack
	 *	@brief	 设置指定Port号显示时候的显示回调
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c cbFunc  
	 *	@param n 显示回调函数
	 *	@param c pUser  
	 *	@param n 用户数据
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall  SR_SetUpdateCallBack(void			   * handle , 
													     SR_UpdateCallBack	cbFunc , 
													     void			   * pUser);

	/**	@fn	     SR_RegisterListener
	 *	@brief	 注册指定port号的监听类
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 指定的Port号
	 *	@param c nCBType  
	 *	@param n 显示回调类型
	 *	@param c cbFunc  
	 *	@param n 显示回调函数
	 *	@param c pUser  
	 *	@param n 用户数据
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall  SR_RegisterListener(		void			* handle , 
															unsigned int	nPort,  
															CSRListener		* pListener );

	/**	@fn	     SR_DestroyHandle
	 *	@brief	 释放显示句柄
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@return	
		见返回值类型说明
	 */
	 SR_API unsigned int __stdcall	SR_DestroyHandle(	void * handle);


	/**	@fn	     SR_SetVerticalSyncPeriod
	 *	@brief	 是否打开垂直同步功能
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 子端口号
	 *	@param c nPeriod  
	 *	@param n 设置为1打开垂直同步，设置为0关闭垂直同步
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall	SR_SetVerticalSyncPeriod(	void			* handle , 
																unsigned int	nPort , 
																unsigned int	nPeriod);
	
	// 回调绘图函数

	/**	@fn	     SR_DrawLines
	*	@brief	 回调中画线函数
	*	@param c handle  
	*	@param n 显示句柄
	*	@param c pPoints  
	*	@param n 点坐标序列
	*	@param c nPointNum  
	*	@param n 点序列数量
	*	@param c bLoop  
	*	@param n 是否闭合
	*	@param c pColor  
	*	@param n 线条的颜色
	*	@param c nLineWidth  
	*	@param n 线条的宽度
	*	@return	
		见返回值类型说明
	*/
	SR_API unsigned int __stdcall	SR_DrawLines(void * handle , SRPOINTF ** pPoints , unsigned int nPointNum , 
		unsigned int bLoop , SRCOLOR * pColor , unsigned int nLineWidth);

	/**	@fn	     SR_DrawCircle（不填充）
	*	@param c handle  
	*	@param n 显示句柄
	*	@brief	 绘图回调中绘制圆
	*	@param c pCenter   (需归一化)
	*	@param n 圆心坐标
	*	@param c nR1       (需归一化)
	*	@param n X方向半径
	*	@param c nR2       (需归一化)
	*	@param n Y方向半径
	*	@param c pColor    (需归一化)
	*	@param n 线条颜色
	*	@param c nLineWidth  
	*	@param n 线条的宽度
	*	@return	
	见返回值类型说明
	*/ 
	SR_API unsigned int __stdcall	SR_DrawCircle(  void * handle , 
													SRPOINTF * pCenter , 
													float fR1 , 
													float fR2 , 
													SRCOLOR * pColor,
													unsigned int nLineWidth);

    /**	@fn	     SR_DrawCircleEx
	*	@param c handle  
	*	@param n 显示句柄
	*	@brief	 绘图回调中绘制填充圆
	*	@param c pCenter   (需归一化)
	*	@param n 圆心坐标
	*	@param c nR1       (需归一化)
	*	@param n X方向半径
	*	@param c nR2       (需归一化)
	*	@param n Y方向半径
    *	@param c bFill     
    *	@param n 是否填充（0表示不填充，1表示填充）
	*	@param c pColor    (需归一化)
	*	@param n 线条颜色
	*	@param c nLineWidth  
	*	@param n 线条的宽度
	*	@return	
	见返回值类型说明
	*/ 
	SR_API unsigned int __stdcall	SR_DrawCircleEx(void * handle , 
													SRPOINTF * pCenter , 
													float fR1 , 
													float fR2 , 
                                                    unsigned int bFill,
													SRCOLOR * pColor,
													unsigned int nLineWidth);

	/**	@fn	     SR_DrawColorRibbon
	*	@brief	 回调中画彩色带
	*	@param c handle  
	*	@param n 显示句柄
	*	@param c pRect  
	*	@param n 矩形结构体
	*	@return	
	    见返回值类型说明
	*/
	SR_API unsigned int __stdcall	SR_DrawColorRibbon(void * handle,SRRECTF * pRect);
	/**	@fn	     SR_DrawRect
	 *	@brief	 回调中矩形函数
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c pRect  
	 *	@param n 矩形结构体
	 *	@param c pColor  
	 *	@param n 线条的颜色
	 *	@param c nLineWidth  
	 *	@param n 线条的宽度
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall	SR_DrawRect(void * handle,SRRECTF * pRect,
		SRCOLOR * pColor,unsigned int nLineWidth);

	/**	@fn	     DrawPolygon
	 *	@brief	 绘图回调中绘制多边形及区域
	 *	@param c pPoints  
 	 *	@param n 顶点列表
	 *	@param c nPointNum  
	 *	@param n 顶点数量
	 *	@param c bFill  
	 *	@param n 是否填充
	 *	@param c pColor  
	 *	@param n 颜色
	 *	@param c nLineWidth  
	 *	@param n 线条的宽度
	 *	@return	
		见返回值类型说明
	 */ 
    SR_API unsigned int __stdcall SR_DrawPolygon(void * handle,
		SRPOINTF ** pPoints,
		unsigned int nPointNum,
		unsigned int bFill,
		SRCOLOR * pColor,
		unsigned int nLineWidth);
	
	/**	@fn	     SR_DrawFont
	 *	@brief	 绘图回调中写字
	 *	@param c pRect  
	 *	@param n 字在窗口中的位置
	 *	@param c pString  
	 *	@param n 指向字内容的指针
	 *	@param c nWidth  
	 *	@param n 字的宽
	 *	@param c nHeight  
	 *	@param n 字高
	 *	@param c pColor  
	 *	@param n 字颜色
	 *	@param c Format  
	 *	@param n 字在pRect所指矩形中的位置，为0时，在左上角，为1是在右上角
	 *	@return	
	    见返回值类型说明
	 */ 
	SR_API unsigned int __stdcall	SR_DrawFont(void * handle ,
											    SRRECTF * pRect,
											    wchar_t * pString,
											    unsigned int nWidth,
											    unsigned int nHeight, 
											    SRCOLOR * pColor , 
											    unsigned long Format); 
	/**	@fn	     SR_GetCapability
	 *	@brief	 获取显示能力集
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c pCapability  
	 *	@param n 能力集结构体
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall SR_GetCapability(	void * handle ,
													SRCAPABILITY	* pCapability);

	/**	@fn	     SR_SetConfig
	 *	@brief	 设置配置信息
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nCfgType  
	 *	@param n 参数类型
	 *	@param c pValue  
	 *	@param n 参数数据
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall  SR_SetConfig(void * handle, int nCfgType, void *pValue, BOOL bShow = FALSE);

	
	/**	@fn	     SR_GetPonitColor
	 *	@brief	 根据点坐标获取颜色信息
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPointX  
	 *	@param n 点的X轴坐标
	 *	@param c nPointY  
	 *	@param n 点的Y轴坐标
	 *	@param c pPointColor  
	 *	@param n 指向点颜色信息的结构体的指针
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall  SR_GetPonitColor(void * handle, unsigned int nPointX, unsigned int nPointY,SR_COLOR * pPointColor);

	/**	@fn	     SR_GetSDKVersion
	 *	@brief	 获取版本号信息
	 *	@param c pVersionInfo  
	 *	@param n 版本号对应的内存地址
	 *	@return	
		见返回值类型说明
	 */
	SR_API unsigned int __stdcall  SR_GetSDKVersion(	char ** pVersionInfo);

	/**	@fn	     SR_GetLastError
	 *	@brief	 获取最后一次错误
	 *	@param c handle  
	 *	@param n 显示句柄
	 *	@param c nPort  
	 *	@param n 对应的Port号
	 *	@param c nError  
	 *	@param n 错误码
	 *	@return	
		见返回值类型说明
		*/
	SR_API unsigned int __stdcall  SR_GetLastError(	void * handle  , unsigned int nPort , unsigned int * nError);

	/**	@fn	     SR_SetBackgroundColor
	*	@brief	 设置窗口背景颜色
	*	@param c handle  
	*	@param n 显示句柄
	*	@param c hWnd  
	*	@param n 窗口句柄
	*	@param c pColor  (需归一化,取值范围[0.0f,1.0f]，NULL表示黑色)
	*	@param n 指向背景颜色的结构体的指针
	*	@return	
	见返回值类型说明
	*/
	SR_API unsigned int __stdcall  SR_SetBackgroundColor(void * handle,void * hWnd,SRCOLOR* pColor);

    /**	@fn	     SR_SetVerticalFlip
    *	@brief	 设置图像上下翻转
    *	@param c handle  
    *	@param n 显示句柄
    *	@param c bFlag(true为翻转；false为不翻转)
    *	@param n 是否上下翻转
    *	@return	
    见返回值类型说明
    */
    SR_API unsigned int __stdcall  SR_SetVerticalFlip(void * handle,bool bFlag);

    /**	@fn	     SR_SetRingShow
    *	@brief	 设置圆环显示
    *	@param c handle  
    *	@param n 显示句柄
    *	@param c nPort
	*	@param n 对应的port号
    *	@param c pCenter   (需归一化)
    *	@param n 圆心坐标
    *	@param c fOutsideR1 (需归一化,取值范围[0.0f,0.5f])
    *	@param n 外圆环的X轴半径;
    *	@param c fOutsideR2 (需归一化,取值范围[0.0f,0.5f])
    *	@param n 外圆环的Y轴半径;
    *	@param c fInsideR1  (需归一化,取值范围[0.0f,0.5f])
    *	@param n 内圆环的X轴半径;
    *	@param c fInsideR2  (需归一化,取值范围[0.0f,0.5f])
    *	@param n 内圆环的Y轴半径;
    *	@param c pColor     (需归一化)
    *	@param n 线条颜色
    *	@return	
    见返回值类型说明
    */
    SR_API unsigned int __stdcall  SR_SetRingShow(void * handle,
                                                  unsigned int nPort,
                                                  SRPOINTF* pCenter , 
                                                  float fOutsideR1 , 
                                                  float fOutsideR2 , 
                                                  float fInsideR1 , 
                                                  float fInsideR2 ,
                                                  SRCOLOR * pColor);


#endif

	 