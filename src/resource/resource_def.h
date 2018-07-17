#ifndef __XENGINE_RESOURCE_DEF_H__
#define __XENGINE_RESOURCE_DEF_H__

#include "platform/platform_def.h"
#include <GLES3/gl3.h>

/// texture define //////////////////////
typedef enum _TextureFormat{
	/// ETC1 ETC2 /////////////////
	ETC1_RGB8 = 0x8D64,
	ETC1_ALPHA8 = ETC1_RGB8,
	//
	ETC2_R11 = 0x9270,
	ETC2_SIGNED_R11 = 0x9271,
	ETC2_RG11 = 0x9272,
	ETC2_SIGNED_RG11 = 0x9273,
	ETC2_RGB8 = 0x9274,
	ETC2_SRGB8 = 0x9275,
	ETC2_RGB8A1 = 0x9276,
	ETC2_SRGB8_PUNCHTHROUGH_ALPHA1 = 0x9277,
	ETC2_RGBA8 = 0x9278
	///////////////////////////////

}TextureFormat;

typedef struct _ETC2Header{
	uint8 identifier[6];
	uint16 format;
	uint16 encoded_width;
	uint16 encoded_height;
	uint16 width;
	uint16 height;

	GLsizei get_size(GLenum internalFormat){
		if (internalFormat != GL_COMPRESSED_RG11_EAC       && internalFormat != GL_COMPRESSED_SIGNED_RG11_EAC &&
			internalFormat != GL_COMPRESSED_RGBA8_ETC2_EAC && internalFormat != GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC){
			return (encoded_width * encoded_height) >> 1;
		}
		
		return encoded_width * encoded_height;		
	}

}ETC2Header, *ETC2HeaderPtr;

namespace etc2_pkm{
	#define ETC2_RGB_NO_MIPMAPS           1
	#define ETC2_RGBA_NO_MIPMAPS          3

	static const uint32 ETC2_PKM_FORMAT_OFFSET = 6;
	static const uint32 ETC2_PKM_ENCODED_WIDTH_OFFSET = 8;
	static const uint32 ETC2_PKM_ENCODED_HEIGHT_OFFSET = 10;
	static const uint32 ETC2_PKM_WIDTH_OFFSET = 12;
	static const uint32 ETC2_PKM_HEIGHT_OFFSET = 14;

	static const int ETC2_PKM_HEADER_SIZE = 16;
	static const char ETC2_PKM_MAGIC[] = { 'P', 'K', 'M', ' ', '2', '0' };
}

/////////////////////////////////////////////

#endif // __XENGINE_RESOURCE_DEF_H__
