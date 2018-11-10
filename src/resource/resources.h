/*!
 * FileName: 	Resources.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/17 22:33
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_RESOURCES_H__
#define __T2D_ENGINE_RESOURCES_H__

#include <unordered_map>
#include <string>
#include "core/object.h"
#include "texture2d.h"
#include "platform/platform_macros.h"
#include "utility/io/data_stream.h"
#include "utility/misc/better_map.h"

__T2D_NS_BEGIN__

class Resources
{
public:
	static Resources* Instance();

	void initialize_extra_resources();
	void destorty();

	template <typename T>
	Object *load(const char* name){
		if (typeid(T) == typeid(Texture2D)){
			return load_texture(name);
		}

		if (typeid(T) == typeid(int)){
			log_error("int");
			return nullptr;
		}

		return nullptr;
	}

private:
	Resources();
	~Resources();

	Object *load_texture(const char* name);
	bool is_etc2_format(DataStream* ds);
	bool read_etc2_head(DataStream* ds, ETC2HeaderPtr header_ptr);

	bool contains(const char* name);

private:
	static Resources* instance_;

	BetterMap<const char*, Object*> assets_;
};

__T2D_NS_END__

#endif // __T2D_ENGINE_RESOURCES_H__
