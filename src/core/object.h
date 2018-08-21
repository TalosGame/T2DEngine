#ifndef __XENGINE_OBJECT_H__
#define __XENGINE_OBJECT_H__

#include <string>
#include "platform/platform_def.h"
#include "resource/resource_def.h"

class Object
{
public:
    Object(T2dIdentityType id_type);
	Object(T2dIdentityType id_type, const std::string name);
    virtual ~Object();

	uint64 instance_id();

private:
	static uint64 generate_id(T2dIdentityType id_type);

protected:
	std::string name_;

private:
	uint64 instance_id_;
	T2dIdentityType identity_type_;

	static uint64 identity_object_count_;
	static uint64 identity_asset_count_;
};

#endif // __XENGINE_OBJECT_H__
