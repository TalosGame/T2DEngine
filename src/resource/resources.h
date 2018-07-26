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
#include "utility/io/data_stream.h"
#include "core/object.h"
#include "texture2d.h"

class Resources
{
public:
	static Resources *Instance();

	void Destorty();

	template <typename T>
	Object *load(const char *name){
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

	Object *load_texture(const char *name);
	bool is_etc2_format(DataStream *ds);
	bool read_etc2_head(DataStream *ds, ETC2HeaderPtr header_ptr);

	bool contains(const char *name);

private:
	static Resources *instance_;

	std::unordered_map <std::string, Object *> assets_;	
};

#endif // __T2D_ENGINE_RESOURCES_H__
