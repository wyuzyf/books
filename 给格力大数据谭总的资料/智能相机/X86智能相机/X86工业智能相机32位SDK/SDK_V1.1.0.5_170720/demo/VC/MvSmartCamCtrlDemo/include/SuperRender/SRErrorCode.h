/** @file    SRFormat.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   跨平台渲染库错误码定义的头文件
 *
 *  @author  播放应用软件组 -- 王川艳
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning 版权所有
 */
#ifndef __SR_RENDER_ERROR_CODE_H__
#define __SR_RENDER_ERROR_CODE_H__


	// 错误码
	#define SR_RETURN_OK				1 // 返回成功
	#define SR_RETURN_FAIL				0 // 返回失败

	#define SR_ERR_ENGINE_NOT_SUPPORT		0x00000001	//	不支持的渲染引擎
	#define SR_ERR_PORT_INVALID				0x00000002	//	非法的端口号
	#define SR_ERR_PORT_USING				0x00000003	//	端口号已经被占用
	#define SR_ERR_PORT_UNKNOW				0x00000004	//	未知错误
	#define SR_ERR_EFFECT_NOT_SUPPORT		0x00000005	//	渲染效果不支持
	#define SR_ERR_HANDLE_NOT_INIT			0x00000006	//	渲染库句柄没有创建
	#define SR_ERR_PF_ENGINE_NOT_INIT		0x00000007	//	像素和渲染引擎还没有指定
	#define SR_ERR_PF_NOTSUPPORT			0x00000008	//	不支持的像素格式
	#define SR_ERR_SRRECT_INVALID			0x00000009	//	非法的矩形结构体

#endif



