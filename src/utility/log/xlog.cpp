/**************************************************************
*  Filename :    x_debug.cpp
*  Author   :    miller
*  Data     :    2018/5/26
*  Desc     :
**************************************************************/

#include "xlog.h"

#include <stdarg.h>
#include <sys/timeb.h>
#include <time.h>

static FILE *fp_error;
static char error_filename[80];

int open_error_file(const char *filename, FILE *fp_override){
	if (fp_override != nullptr){
		fp_error = fp_override;
	}else{
		if ((fp_error = fopen(filename, "w")) == nullptr) return 0;
	}

	struct _timeb timebuffer;
	char *timeline;
	char timestring[280];

	_ftime(&timebuffer);
	timeline = ctime(&timebuffer.time);

	sprintf(timestring, "%.19s.%hu, %s", timeline, timebuffer.millitm, &timeline[20]);

	log_error("\nOpening Error Output File (%s) on %s\n", filename, timestring);

	// now the file is created, re-open with append mode
	if (!fp_override){
		fclose(fp_error);
		if ((fp_error = fopen(filename, "a+")) == NULL)
			return(0);
	}

	return 1;
}

int close_error_file(void){
	if (fp_error == nullptr) return 0;

	if (fp_error == stdout || fp_error == stderr) return 1;

	int ret = fclose(fp_error);
	fp_error = nullptr;
	return ret;
}

int log_error(const char *format, ...){
	if (fp_error == nullptr || format == nullptr) return 0;

	char buffer[1024];
	va_list pArgs = nullptr;

	va_start(pArgs, format);
	vsprintf(buffer, format, pArgs);
	va_end(pArgs);

	fprintf(fp_error, buffer);

	fflush(fp_error);

	return 1;
}