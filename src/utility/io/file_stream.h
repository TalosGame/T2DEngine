/*!
 * FileName: 	FileStream.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/22 16:55
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_FILE_STREAM_H__
#define __T2D_ENGINE_FILE_STREAM_H__
 
#include <stdio.h>

class FileStream{
public:
	FileStream();
	virtual ~FileStream();

	bool open(const char* path, const char* model);
	const char* read_buffer();
	void close();

private:
	FILE *fp_;

	char *buffer_;
	size_t buffer_len_;
};

#endif // __T2D_ENGINE_FILE_STREAM_H__
