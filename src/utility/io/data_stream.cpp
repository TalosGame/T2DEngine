/*!
 * Filename: 	DataStream.cpp
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/08 0:36
 * Author 		miller
 * Description: 
 */

#include "data_stream.h"
#include <string.h>
#include "utility/log/xlog.h"
#include "utility/string_ext.h"
#include "utility/application.h"
#include "platform/platform_macros.h"

DataStream::DataStream(){
	this->buffer_ = nullptr;
	this->offset_ = 0;
	this->buffer_len_ = 0;
}

DataStream::~DataStream(){
	free(this->buffer_);
	this->buffer_ = nullptr;
}

bool DataStream::read_from_file(const char *name){
	char *path = Application::search_asset_path(name);
	if (path == nullptr){
		return false;
	}

	FILE *fp = nullptr;
	if ((fp = fopen(path, "rb")) == nullptr) {
		log_error("Couldn't open resource file! path:%s", path);
		return false;
	}

	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	this->buffer_ = (uint8 *)malloc((size)* sizeof(uint8));
	this->buffer_len_ = fread((char *)buffer_, 1, size, fp);
	
	fclose(fp);
	SAFE_FREE(path);

	if (buffer_ == nullptr || buffer_len_ < size){
		log_error("Read data from file name:%s error!\n", name);
		return false;
	}

	return true;
}

uint8 *DataStream::buffer(){
	return this->buffer_;
}

size_t DataStream::buffer_len(){
	return buffer_len_;
}

size_t DataStream::readable_bytes(){
	return buffer_len_ - offset_;
}

void DataStream::mark_read_index(){
	this->mark_index_ = this->offset_;
}

void DataStream::reset_read_index(){
	this->offset_ = this->mark_index_;
}

void DataStream::seek(size_t len){
	this->offset_ += len;
}

bool DataStream::read_byte(uint8 *value, size_t len){
	if (!check_data(len)){
		return false;
	}

	memcpy(value, buffer_ + offset_, len);
	offset_ += len;

	return true;
}

bool DataStream::read_byte(uint8 **value, size_t len){
	size_t read_len = (len == -1 ? buffer_len_ - offset_ : len );
	if (!check_data(read_len)){
		return false;
	}

	uint8 *data = (uint8 *)malloc(sizeof(uint8) * read_len);
	memcpy(data, buffer_ + offset_, read_len);

	*value = data;
	offset_ += read_len;

	return true;
}

bool DataStream::read_uint16(uint16 *value, bool big_endian){
	if (!check_data(2)){
		return false;
	}

	uint16 ret = 0;
	if (big_endian){
		*value = (buffer_[offset_] << 8) | buffer_[offset_ + 1];
		offset_ += 2;
		return true;
	}

	*value = (buffer_[offset_ + 1] << 8) | buffer_[offset_];
	offset_ += 2;

	return true;
}

//private function////////////////////////////////////////////////////////
bool DataStream::check_data(size_t len){
	if (len > buffer_len_ - offset_){
		log_error("Read bytes error! len=%zu", len);
		return false;
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////

