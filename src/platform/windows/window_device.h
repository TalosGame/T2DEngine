 /*!
 * Filename: 	WindowDevice.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 19:52
 * Author 		miller
 * Description: 
 */
 
#ifndef __T2D_ENGINE_WINDOW_DEVICE_H__
#define __T2D_ENGINE_WINDOW_DEVICE_H__

#include "platform/platform_def.h"
#include "platform/Device.h"

class WindowDevice : public Device{
public:
	WindowDevice();
	virtual ~WindowDevice();

	virtual void game_loop();

protected:
	virtual ubool init_window();
};

// private function define ///////////////////////////////////////////////
static ubool WinCreate(Device *device, const char *title);
static LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static void center_window(EGLNativeWindowType hwnd, RECT *client_rect, int width, int height);

//////////////////////////////////////////////////////////////////////////

//static void framebuffer_resize_callback(GLFWwindow* window, int width, int height);

#endif //__T2D_ENGINE_WINDOW_DEVICE_H__
