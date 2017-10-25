/** @file    SuperRenderDefine.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   跨平台渲染库数据定义的头文件
 *
 *  @author  播放应用软件组 -- 王川艳
 *  @date    2011/11/22
 *  @note    V1.0.0
 *
 *  @warning 版权所有
 */
#ifndef __SUPER_RENDER_DEFINE_H__
#define __SUPER_RENDER_DEFINE_H__
#include "SRPlatform.h"
#include "SRListener.h"
#include "SRFormat.h"
#include "SRStruct.h"
#include "windows.h"


/*
#ifndef SUPPORT_OPENGL
#define SUPPORT_OPENGL
#endif*/

#ifndef SUPPORT_D3D
#define SUPPORT_D3D
#endif


#ifndef SUPPORT_DDRAW
#define SUPPORT_DDRAW
#endif


#ifndef SUPPORT_DEBUG
//#define SUPPORT_DEBUG
#endif

#ifdef SUPPORT_DEBUG
	#define SR_DEBUG printf
#else
	#define SR_DEBUG 
#endif

#endif


