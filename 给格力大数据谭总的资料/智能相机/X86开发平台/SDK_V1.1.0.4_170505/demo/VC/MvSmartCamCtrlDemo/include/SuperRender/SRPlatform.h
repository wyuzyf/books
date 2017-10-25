/** @file    SRPlatform.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   跨平台渲染库平台宏定义的头文件
 *
 *  @author  播放应用软件组 -- 王川艳
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning 版权所有
 */
#ifndef __HK_RENDER_PLATFORM_H__
#define __HK_RENDER_PLATFORM_H__

	#ifdef WIN32
		#ifndef SR_WIN32
		#define SR_WIN32 WIN32
		#endif

		#if defined( SUPERRENDER_EXPORTS)
		#define SR_API  extern "C" __declspec(dllexport) 
		#else 
		#define SR_API  extern "C" __declspec(dllimport) 
		#endif

	#endif

	#ifdef __linux__
		#ifndef SR_LINUX
		#define SR_LINUX __linux__
		#endif

        #ifndef SP_API
            #define SR_API
        #endif
        #ifndef __stdcall
            #define __stdcall
        #endif

	#endif

	#ifdef __APPLE__
		#ifndef SR_APPLE
			#define SR_APPLE __APPLE__
		#endif
		#ifndef SP_API
			#define SR_API
		#endif
		#ifndef __stdcall
			#define __stdcall
        #endif
	#endif


	#ifdef ANDROID
		#ifndef SR_ANDROID
			#define SR_ANDROID
		#endif
		#ifndef SP_API
			#define SR_API
		#endif
		#ifndef __stdcall
			#define __stdcall
        #endif
	#endif
	
#endif