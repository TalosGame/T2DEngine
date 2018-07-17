/**************************************************************
*  Filename :    XDebug.h
*  Author   :    miller
*  Data     :    2018/5/26
*  Desc     :
**************************************************************/

#ifndef __XENGINE_XLOG_H__
#define __XENGINE_XLOG_H__

#include <stdio.h>

// debug info in files /////////////////////////////////
int open_error_file(const char *filename, FILE *fp_override = nullptr);
int close_error_file(void);
int log_error(const char *format, ...);






#endif // __XENGINE_XLOG_H__
