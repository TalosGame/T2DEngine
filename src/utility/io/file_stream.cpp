/*!
 * FileName: 	FileStream.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/22 16:55
 * Author: 		miller
 * Desc:		
 */

#include "file_stream.h"
#include <stdlib.h>
#include "utility/log/xlog.h"
#include "platform/platform_macros.h"

FileStream::FileStream(const char *name, const char *model){
	TD_ASSERT(name != nullptr, "Invalid name");

	fp_ = fopen(name, model);
	if (fp_ == nullptr){
		log_error("Open file error! file name=%s", name);
	}
}

FileStream::~FileStream(){
	if (fp_ == nullptr) return;

	free(this->buffer_);
	this->buffer_ = nullptr;

	fclose(fp_);
	fp_ = nullptr;
}

const char *FileStream::read_buffer(){
	if (fp_ == nullptr) return nullptr;

	fseek(fp_, 0, SEEK_END);
	size_t size = ftell(fp_);
	fseek(fp_, 0, SEEK_SET);

	this->buffer_ = (char *)malloc(size * sizeof(char));
	this->buffer_len_ = fread((char *)buffer_, 1, size, fp_);
	if (this->buffer_len_ != size){
		SAFE_FREE(this->buffer_);
		return nullptr;
	}

	return this->buffer_;
}
