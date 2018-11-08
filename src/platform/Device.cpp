/*!
 * Filename: 	Device.cpp
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 19:46
 * Author 		miller
 * Description: 
 */

#include "Device.h"

#include "utility/log/xlog.h"
#include "utility/math/mathf.h"
#include "resource/resources.h"
 
Device::Device(){
	this->update = nullptr;
	this->draw = nullptr;
	this->exit = nullptr;
	this->game_running_ = false;
}

Device::~Device(){

}

bool Device::set_up_device(uint32 width, uint32 height, uint32 flags) {
	// init math lib
	math_init();
	// init default shaders
	t2d::Resources::Instance()->initialize_extra_resources();

	// init log
	open_error_file("", stdout);

	this->screen_width_ = width;
	this->screen_height_ = height;

#ifndef __APPLE__
	EGLConfig config;
	EGLint majorVersion;
	EGLint minorVersion;
	EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE };

	if (!this->init_window()){
		return false;
	}

	this->eglDisplay_ = eglGetDisplay(this->eglNativeDisplay_);
	if (this->eglDisplay_ == EGL_NO_DISPLAY){
		return false;
	}

	// Initialize EGL
	if (!eglInitialize(this->eglDisplay_, &majorVersion, &minorVersion)){
		return false;
	}

	EGLint numConfigs = 0;
	EGLint attribList[] =
	{
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
		EGL_ALPHA_SIZE, (flags & ES_WINDOW_ALPHA) ? 8 : EGL_DONT_CARE,
		EGL_DEPTH_SIZE, (flags & ES_WINDOW_DEPTH) ? 8 : EGL_DONT_CARE,
		EGL_STENCIL_SIZE, (flags & ES_WINDOW_STENCIL) ? 8 : EGL_DONT_CARE,
		EGL_SAMPLE_BUFFERS, (flags & ES_WINDOW_MULTISAMPLE) ? 1 : 0,
		// if EGL_KHR_create_context extension is supported, then we will use
		// EGL_OPENGL_ES3_BIT_KHR instead of EGL_OPENGL_ES2_BIT in the attribute list
		EGL_RENDERABLE_TYPE, GetContextRenderableType(this->eglDisplay_),
		EGL_NONE
	};

	// Choose config
	if (!eglChooseConfig(this->eglDisplay_, attribList, &config, 1, &numConfigs))
	{
		return false;
	}

	if (numConfigs < 1)
	{
		return false;
	}

#ifdef ANDROID
	// For Android, need to get the EGL_NATIVE_VISUAL_ID and set it using ANativeWindow_setBuffersGeometry
	EGLint format = 0;
	eglGetConfigAttrib(this->eglDisplay_, config, EGL_NATIVE_VISUAL_ID, &format);
	ANativeWindow_setBuffersGeometry(this->eglNativeWindow_, 0, 0, format);   
#endif // ANDROID

   // Create a surface
   this->eglSurface_ = eglCreateWindowSurface(this->eglDisplay_, config, this->eglNativeWindow_, NULL);

   if (this->eglSurface_ == EGL_NO_SURFACE){
	   return GL_FALSE;
   } 

   // Create a GL context
   this->eglContext_ = eglCreateContext(this->eglDisplay_, config, EGL_NO_CONTEXT, contextAttribs);

   if (this->eglContext_ == EGL_NO_CONTEXT){
	   return GL_FALSE;
   }

   // Make the context current
   if (!eglMakeCurrent(this->eglDisplay_, this->eglSurface_, this->eglSurface_, this->eglContext_)){
	   return GL_FALSE;
   }
#endif // __APPLE__

   return true;
}

//	Check whether EGL_KHR_create_context extension is supported.  
//  If so, return EGL_OPENGL_ES3_BIT_KHR instead of EGL_OPENGL_ES2_BIT
EGLint Device::GetContextRenderableType(EGLDisplay eglDisplay)
{
#ifdef EGL_KHR_create_context
	const char *extensions = eglQueryString(eglDisplay, EGL_EXTENSIONS);

	// check whether EGL_KHR_create_context is in the extension string
	if (extensions != NULL && strstr(extensions, "EGL_KHR_create_context"))
	{
		// extension is supported
		return EGL_OPENGL_ES3_BIT_KHR;
	}
#endif
	// extension is not supported
	return EGL_OPENGL_ES2_BIT;
}

void Device::set_game_fps(int fps){
	this->game_fps_ = fps;
}

int Device::game_fps(){
	return this->game_fps_;
}

void Device::register_handle_func(void(*update)(), void(*draw)(float dt), void(*exit)()){
	this->update = update;
	this->draw = draw;
	this->exit = exit;
}

int Device::screen_width() {
	return this->screen_width_;
}

int Device::screen_height() {
	return screen_height_;
}

void Device::set_eglNativeWindow(EGLNativeWindowType window){
	this->eglNativeWindow_ = window;
}

EGLNativeWindowType Device::eglNativeWindow(){
	return this->eglNativeWindow_;
}

EGLDisplay Device::eglDisplay(){
	return this->eglDisplay_;
}

EGLSurface Device::eglSurface(){
	return this->eglSurface_;
}
