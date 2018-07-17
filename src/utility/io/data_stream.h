/*!
 * Filename: 	FileStream.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/08 0:32
 * Author 		miller
 * Description: 
 */

#ifndef __T2D_ENGINE_FILE_STREAM_H__
#define __T2D_ENGINE_FILE_STREAM_H__

#include <stdio.h>

#include "platform/platform_def.h"

class DataStream{
public:
	DataStream();
	virtual ~DataStream();

	ubool read_from_file(const char *name);

	uint8 *buffer();
	size_t buffer_len();
	size_t readable_bytes();
	void mark_read_index();
	void reset_read_index();

	void seek(size_t len);

	ubool read_byte(uint8 *value, size_t len);
	ubool read_byte(uint8 **value, size_t len = -1);
	ubool read_uint16(uint16 *value, ubool big_endian = FALSE);
 
private:
	char *search_asset_path(const char *name);
	ubool check_data(size_t len);

private:

	uint8 *buffer_;
	size_t buffer_len_;
	size_t offset_;
	size_t mark_index_;
};

#endif //__T2D_ENGINE_FILE_STREAM_H__
