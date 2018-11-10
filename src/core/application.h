/*!
 * FileName: 	Application.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/26 23:54
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_APPLICATION_H__
#define __T2D_ENGINE_APPLICATION_H__

#include "platform/platform_def.h"

class Application{
public:
	static void Init(uint32 screen_width, uint32 screen_height);

	static char *search_asset_path(const char* name);
	static uint32 screen_width();
	static uint32 screen_height();

private: 
	static uint32 screen_width_;
	static uint32 screen_height_;
};

#endif // __T2D_ENGINE_APPLICATION_H__
