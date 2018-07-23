/*!
 * Filename: 	string_ext.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/08 0:30
 * Author 		miller
 * Description: 
 */

#ifndef __T2D_ENGINE_STRING_EXT_H__
#define __T2D_ENGINE_STRING_EXT_H__

#include "platform/platform_def.h"
#include <string>

// 字符串拼接多个字符串
size_t strcat_ext(char **dst_out, int num, ...);

std::string &replace(std::string &str, const std::string &old_value, const std::string &new_value);


#endif //__T2D_ENGINE_STRING_EXT_H__