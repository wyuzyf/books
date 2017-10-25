/** @file    SRListener.h
 *  @note    HangZhou Hikvision Software Co., Ltd. All Right Reserved.
 *  @brief   跨平台渲染库监听类定义的头文件
 *
 *  @author  播放应用软件组 -- 王川艳
 *  @date    2013/03/01
 *  @note    V1.0.0
 *
 *  @warning 版权所有
 */
#ifndef __SR_LISTENER_H__
#define __SR_LISTENER_H__

// 监听类的定义，可以任意扩展
class CSRListener
{
public:

	CSRListener()
	{

	};

	~CSRListener()
	{

	};

	virtual int Draw()
	{
		return 1;
	};

};

#endif