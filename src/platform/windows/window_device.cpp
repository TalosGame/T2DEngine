/*!
 * Filename: 	WindowDevice.cpp
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 19:55
 * Author 		miller
 * Description: 
 */
 
#include "window_device.h"

#include "common/xlog.h"

#ifdef _WIN64
#define GWL_USERDATA GWLP_USERDATA
#endif
 
WindowDevice::WindowDevice(){

}

WindowDevice::~WindowDevice(){

}

ubool WindowDevice::init_window() {
	return WinCreate(this, "");
}

void WindowDevice::game_loop(){
	int skip_ticks = 1000 / this->game_fps_;
	int max_frameskip = 5;
	this->game_running_ = TRUE;

	DWORD previous = GetTickCount();
	DWORD lag = 0;
	int loops;
	MSG msg = { 0 };

	while (this->game_running_)
	{
		int gotMsg = (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0);
		if (gotMsg)
		{
			if (msg.message == WM_QUIT)
			{
				this->game_running_ = FALSE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}

		loops = 0;
		DWORD current = GetTickCount();
		DWORD elapsed = current - previous;
		previous = current;
		lag += elapsed;

		while (lag >= skip_ticks && loops < max_frameskip) {
			if (this->update != nullptr){
				this->update();
			}

			lag -= skip_ticks;
			loops++;
		}

		if (this->draw != nullptr){
			this->draw((float)lag / skip_ticks);
			eglSwapBuffers(eglDisplay_, eglSurface_);
			ValidateRect(this->eglNativeWindow_, NULL);
		}
	}
}

ubool WinCreate(Device *device, const char *title){
	WNDCLASS wndclass = { 0 };
	DWORD    wStyle = 0;
	HINSTANCE hInstance = GetModuleHandle(NULL);

	WNDCLASSEX winClass;
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc = window_proc;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 2 * sizeof(size_t);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winClass.hInstance = hInstance;
	winClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	winClass.lpszMenuName = NULL;
	winClass.lpszClassName = "T2DEngine";
	winClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&winClass)) {
		log_error("Register window class error!");
		return FALSE;
	}

	int sw = device->screen_width();
	int sh = device->screen_height();

	// set the size, but not the position
	RECT wr = { 0, 0, sw, sh };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	EGLNativeWindowType window = nullptr;
	if(!(window = CreateWindowEx(NULL,
								"T2DEngine",
								"T2DEngine",
								WS_OVERLAPPEDWINDOW | WS_VISIBLE,
								0,
								0,
								wr.right - wr.left, wr.bottom - wr.top,
								NULL,
								NULL,
								hInstance,
								device))){

		log_error("Create window error!");
		return FALSE;
	}

	center_window(window, &wr, sw, sh);

	device->set_eglNativeWindow(window);

	// Set the ESContext* to the GWL_USERDATA so that it is available to the
	// ESWindowProc
#ifdef _WIN64
	//In LLP64 LONG is stll 32bit.
	SetWindowLongPtr(device->eglNativeWindow(), GWL_USERDATA, (LONGLONG)(LONG_PTR)device);
#else
	SetWindowLongPtr(device->eglNativeWindow(), GWL_USERDATA, (LONG)(LONG_PTR)device);
#endif

	return TRUE;
}

void center_window(EGLNativeWindowType hwnd, RECT *client_rect, int width, int height) {
	RECT rect;
	int w = client_rect->right - client_rect->left;
	int h = client_rect->bottom - client_rect->top;

	GetClientRect(GetDesktopWindow(), &rect);

	MoveWindow(hwnd,
			   (rect.right - rect.left - w) / 2,
			   (rect.bottom - rect.top - h) / 2,
			   w,
			   h,
			   TRUE);
}

static LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	LRESULT  lRet = 1;

	WindowDevice* device = NULL;
	if (msg == WM_NCCREATE) {
		CREATESTRUCT *pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
		device = reinterpret_cast<WindowDevice*>(pCreate->lpCreateParams);
		SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)device);
	}
	else {
		LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
		device = reinterpret_cast<WindowDevice*>(ptr);
	}

	switch (msg)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CHAR:{
// 		POINT      point;
// 		ESContext *esContext = (ESContext *)(LONG_PTR)GetWindowLongPtr(hWnd, GWL_USERDATA);
// 
// 		GetCursorPos(&point);
// 
// 		if (esContext && esContext->keyFunc)
// 			esContext->keyFunc(esContext, (unsigned char)wParam,
// 			(int)point.x, (int)point.y);
	}
	break;

	default:
		lRet = DefWindowProc(hwnd, msg, wParam, lParam);
		break;
	}

	return lRet;
}

///
//  Global extern.  The application must declare this function
//  that runs the application.
//
extern int game_entry(void *device);

// Windows entrypoint for application
int main(int argc, char *argv[])
{
	Device *device = new WindowDevice();
	if (game_entry(device) == -1){
		return -1;
	}

	device->game_loop();

	if (device->exit != nullptr){
		device->exit();
	}

	return 0;
}
