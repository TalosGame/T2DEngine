#ifndef __XENGINE_TEXTURE2D_H__
#define __XENGINE_TEXTURE2D_H__

#include "resource_def.h"
#include "core/object.h"
#include "platform/platform_def.h"

class Texture2D : Object
{
public:
    Texture2D();
    ~Texture2D();

	bool LoadData(const uint8 *data, uint32 width, uint32 height, GLsizei size);

    uint32 texture_id();

private:
	uint32 texture_id_;
    uint32 width_;
    uint32 height_;
    TextureFormat format_;
};

#endif //__XENGINE_TEXTURE2D_H__
