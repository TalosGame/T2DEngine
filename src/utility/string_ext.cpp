/*!
 * Filename: 	string_ext.cpp
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/08 0:30
 * Author 		miller
 * Description:
 */

#include "string_ext.h"

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

size_t strcat_ext(char** dst_out, int num, ...){
    size_t len = 0, len_tmp = 0;
    char *src = nullptr, *dst = nullptr, *dst_tmp = nullptr;
    va_list pArgs = nullptr;
    *dst_out = nullptr;

    va_start(pArgs, num);
    for(int i = 0; i < num; i++){
        if((src = va_arg(pArgs, char*)) == nullptr) break;

        len += strlen(src);
    }
    va_end(pArgs);

    if(len == 0) return -1;

    dst = (char *)malloc(sizeof(char) * (len + 1));
    if(dst == nullptr) return -1;

    dst_tmp = dst;

    va_start(pArgs, num);
    for(int i = 0; i < num; i++){
        if((src = va_arg(pArgs, char*)) == nullptr) break;

        len_tmp = strlen(src);
        memcpy(dst_tmp, src, len_tmp);
        dst_tmp += len_tmp;
    }
    va_end(pArgs);

    *dst_tmp = '\0';
    *dst_out = dst;
    return len;
}

size_t index_of(const char* str, char search){
	const char* ptr = strchr(str, search);
	if (ptr == nullptr) return -1;

	return ptr - str;
}

size_t index_of(const char* str, int index, char search){
	const char* ptr = strchr(str + index, search);
	if (ptr == nullptr) return -1;

	return ptr - str;
}

size_t last_index_of(const char* str, char search){
	const char* ptr = strrchr(str, search);
	if (ptr == nullptr) return -1;

	return ptr - str;
}

const char* substring(const char* str, int pos, int len){
	char* ret = (char *)malloc(len + 1);
	memset(ret, 0, len + 1);
	memcpy(ret, str + pos, len);
	return ret;
}

std::string& replace(std::string& str, const std::string& old_value, const std::string& new_value){
	std::string::size_type pos = 0;
	if ((pos = str.find(old_value)) != std::string::npos){
		str.replace(pos, old_value.length(), new_value);
	}

	return str;
}
