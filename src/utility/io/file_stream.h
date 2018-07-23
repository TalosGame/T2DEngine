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
	FileStream(const char *name, const char *model);
	virtual ~FileStream();

	const char *read_buffer();
	//const char *read_line();

private:
	FILE *fp_;

	char *buffer_;
	size_t buffer_len_;
};

#endif // __T2D_ENGINE_FILE_STREAM_H__
