#include "application.h"
#include "string_ext.h"
#include "log/xlog.h"

static const char *RES_ROOT_PATH = "res/";

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