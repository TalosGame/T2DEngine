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

size_t strcat_ext(char **dst_out, int num, ...){
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
