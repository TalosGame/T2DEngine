 /*!
 * Filename: 	Device.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 19:38
 * Author 		miller
 * Description: 
 */
 
#ifndef __T2D_ENGINE_DEVICE_H__
#define __T2D_ENGINE_DEVICE_H__

#ifdef __APPLE__
#include <OpenGLES/ES3/gl.h>
#else
#include <GLES3/gl3.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#endif

#include "platform_def.h"

class Device{
public:
	Device();
	virtual ~Device();

	bool set_up_device(uint32 width, uint32 height, uint32 flags);

	void set_game_fps(int fps);
	int game_fps();
	void register_handle_func(void(*update)(), void(*draw)(float dt), void(*exit)());

	int screen_width();
	int screen_height();

	void set_eglNativeWindow(EGLNativeWindowType window);
	EGLNativeWindowType eglNativeWindow();
	EGLDisplay eglDisplay();
	EGLSurface eglSurface();

	void(*update)();
	void(*draw)(float dt);
	void(*exit)();

	virtual void game_loop() = 0;

protected:
	virtual bool init_window() = 0;

private:
	EGLint GetContextRenderableType(EGLDisplay eglDisplay);

protected:
	uint32 screen_width_;
	uint32 screen_height_;
	int game_fps_;

	bool game_running_;

#ifndef __APPLE__
	/// Display handle
	EGLNativeDisplayType eglNativeDisplay_;

	/// Window handle
	EGLNativeWindowType  eglNativeWindow_;

	/// EGL display
	EGLDisplay  eglDisplay_;

	/// EGL context
	EGLContext  eglContext_;

	/// EGL surface
	EGLSurface  eglSurface_;
#endif
};

#endif //__T2D_ENGINE_DEVICE_H__
