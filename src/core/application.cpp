#include "application.h"
#include "utility/string_ext.h"
#include "utility/log/xlog.h"

static const char *RES_ROOT_PATH = "res/";

uint32 Application::screen_width_ = 0;
uint32 Application::screen_height_ = 0;

void Application::Init(uint32 screen_width, uint32 screen_height){
	Application::screen_width_ = screen_width;
	Application::screen_height_ = screen_height;
}

char *Application::search_asset_path(const char *name){
	// TODO 根据平台查询资源路径
	char *path = nullptr;
	size_t len = strcat_ext(&path, 2, RES_ROOT_PATH, name);
	if (len < 0){
		log_error("search asset path error! name:%s\n", name);
		return nullptr;
	}

	return path;
}

uint32 Application::screen_width(){
	return screen_width_;
}

uint32 Application::screen_height(){
	return screen_height_;
}