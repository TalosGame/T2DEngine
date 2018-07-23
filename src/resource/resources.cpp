/*!
 * FileName: 	Resources.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/17 22:34
 * Author: 		miller
 * Desc:		
 */

#include "resources.h"
#include "resource_def.h"
#include "utility/string_ext.h"
#include "utility/log/xlog.h"

Resources *Resources::instance_ = nullptr;

Resources::Resources(){}

Resources::~Resources(){}

Resources *Resources::Instance(){
	if (instance_ == nullptr){
		instance_ = new Resources();
	}

	return instance_;
}

void Resources::Destorty(){

}

void *Resources::load_texture(const char *name){
	if (contains(name)){
		return assets_[name];
	}

	DataStream ds;
	ds.read_from_file(name);

	// TODO 后续根据数据头判定是什么格式数据
	if (!is_etc2_format(&ds)){
		return nullptr;
	}
	
	ETC2Header header;
	if (!read_etc2_head(&ds, &header)){
		log_error("Read etc2 texture head error!");
		return nullptr;
	}

	uint8 *data = nullptr;
	ds.read_byte(&data);
	if (data == nullptr){
		log_error("Read texture data error!");
		return nullptr;
	}

	Texture2D *tex = new Texture2D();
	if (tex->LoadData(data, header.width, header.height, header.get_size(GL_COMPRESSED_RGBA8_ETC2_EAC))){
		
	}


	return nullptr;
}

bool Resources::is_etc2_format(DataStream *ds){
	if (ds->buffer_len() < etc2_pkm::ETC2_PKM_HEADER_SIZE) {
		return false;
	}

	if (memcmp(ds->buffer(), etc2_pkm::ETC2_PKM_MAGIC, sizeof(etc2_pkm::ETC2_PKM_MAGIC))){
		return false;
	}

	return true;
}

bool Resources::read_etc2_head(DataStream *ds, ETC2HeaderPtr header_ptr){
	ds->seek(etc2_pkm::ETC2_PKM_FORMAT_OFFSET);

	ds->read_uint16(&header_ptr->format, true);
	ds->read_uint16(&header_ptr->encoded_width, true);
	ds->read_uint16(&header_ptr->encoded_height, true);
	ds->read_uint16(&header_ptr->width, true);
	ds->read_uint16(&header_ptr->height, true);

	return (header_ptr->format == ETC2_RGB_NO_MIPMAPS || header_ptr->format == ETC2_RGBA_NO_MIPMAPS) &&
		header_ptr->encoded_width >= header_ptr->width && header_ptr->encoded_width - header_ptr->width < 4 &&
		header_ptr->encoded_height >= header_ptr->height && header_ptr->encoded_height - header_ptr->height < 4;
}

bool Resources::contains(const char *name){
	if (assets_.find(name) != assets_.end()){
		return true;
	}

	return false;
}

/*
Texture2D *Resources::Load(const char *name){
//    Object ret = asset_map_[name];
//    if(ret != nullptr){
//        return ret;
//    }

    char *path = nullptr;
    size_t len = strcat_ext(&path, 3, respath::RES_ROOT_PATH, "textures/", name);
    if(len < 0){
        write_error("[Resources] load resources error! name:%s", name);
        return nullptr;
    }

	FILE *file = nullptr;
    //QFile file(path);
	if ((file = fopen(path, "r")) == nullptr) {
        write_error("[Resources] Couldn't open resource file! path:%s", path);
        return nullptr;
    }

    ETC2Header header;
	size_t ret = fread((char *)&header, sizeof(ETC2Header), 1, file);
    if(ret < 0){
        write_error("[Resources] read etc2 texture header error!");
		fclose(file);
        return nullptr;
    }

    uint32 dataSize = 0;
	fread((char *)&dataSize, sizeof(uint32), 1, file);

    uint8 *data = (uint8 *)malloc(dataSize * sizeof(uint8));
	ret = fread((char *)data, 1, dataSize, file);
    if(ret != dataSize){
        write_error("[Resources] read etc2 texture header error!");
		fclose(file);
        return nullptr;
    }

    //printf("%c", data[dataSize - 1]);
    //qDebug() << data[1];
    //qDebug() << data[dataSize - 1];

    Texture2D *tex = new Texture2D();
    tex->LoadData(data, &header);

	fclose(file);

    return nullptr;
}
*/

//int Resources::ReadTextureHeader(QDataStream *in, ETC2HeaderPtr headPtr){
//    for (uint32 i = 0; i < sizeof(headPtr->m_au8Identifier); i++)
//    {
//        *in >> headPtr->m_au8Identifier[i];

//        if(headPtr->m_au8Identifier[i] != kAu8Itentfier[i]){
//            write_error("[Resources] read etc2 texture header error!");
//            return -1;
//        }
//    }

//    *in >> headPtr->m_u32Endianness;
//    *in >> headPtr->m_u32GlType;
//    *in >> headPtr->m_u32GlTypeSize;
//    *in >> headPtr->m_u32GlFormat;

//    *in >> headPtr->m_u32GlInternalFormat;
//    *in >> headPtr->m_u32GlBaseInternalFormat;

//    *in >> headPtr->m_u32PixelWidth;
//    *in >> headPtr->m_u32PixelHeight;
//    *in >> headPtr->m_u32PixelDepth;
//    *in >> headPtr->m_u32NumberOfArrayElements;
//    *in >> headPtr->m_u32NumberOfFaces;
//    *in >> headPtr->m_u32NumberOfMipmapLevels;
//    *in >> headPtr->m_u32BytesOfKeyValueData;

//    int i = 0;
//    i++;

//    return 0;
//}


