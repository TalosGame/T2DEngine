/*!
 * Filename: 	platform_def.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/08 0:20
 * Author 		miller
 * Description: 
 */

#ifndef __T2D_ENGINE_PLATFORM_DEF_H__
#define __T2D_ENGINE_PLATFORM_DEF_H__

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;

// esCreateWindow flag - RGB color buffer
#define ES_WINDOW_RGB           0
// esCreateWindow flag - ALPHA color buffer
#define ES_WINDOW_ALPHA         1
// esCreateWindow flag - depth buffer
#define ES_WINDOW_DEPTH         2
// esCreateWindow flag - stencil buffer
#define ES_WINDOW_STENCIL       4
// esCreateWindow flat - multi-sample buffer
#define ES_WINDOW_MULTISAMPLE   8

#define SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#define SAFE_FREE(p)             do { if(p) { free(p); (p) = nullptr; } } while(0)

#define GL_CHECK(x)                                                                          \
x;                                                                                           \
{                                                                                            \
	GLenum glError = glGetError();                                                           \
	if(glError != GL_NO_ERROR) {                                                             \
		log_error("glGetError() = %i (0x%.8x) at %s:%i\n", glError, glError, __FILE__, __LINE__); \
	}                                                                                \
}

// res path define
namespace respath {
	static const char *RES_ROOT_PATH = "res/";
}

///
//  Global extern.  The application must declare this function
//  that runs the application.
//
extern int game_entry(void *device);

#endif //__T2D_ENGINE_PLATFORM_DEF_H__
