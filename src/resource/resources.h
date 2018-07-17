#ifndef __XENGINE_RESOURCE_MANAGER_H__
#define __XENGINE_RESOURCE_MANAGER_H__

#include <unordered_map>
#include <string>

#include "common/object.h"
#include "platform/platform_def.h"
#include "utility/io/data_stream.h"
#include "texture2d.h"

class Resources
{
public:
	static Resources *Instance();

	void Destorty();

	template <typename T>
	void *load(const char *name){
		if (typeid(T) == typeid(Texture2D)){
			load_texture(name);
			return nullptr;
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

	void *load_texture(const char *name);
	ubool is_etc2_format(DataStream *ds);
	ubool read_etc2_head(DataStream *ds, ETC2HeaderPtr header_ptr);

	ubool contains(const char *name);


private:
	static Resources *instance_;

	std::unordered_map <std::string, Object *> assets_;	
};

#endif // __XENGINE_RESOURCE_MANAGER_H__
