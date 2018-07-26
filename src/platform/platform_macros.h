/*!
 * FileName: 	platform_macros.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/26 23:56
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_PLATFORM_MACROS_H__
#define __T2D_ENGINE_PLATFORM_MACROS_H__

#define SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#define SAFE_FREE(p)             do { if(p) { free(p); (p) = nullptr; } } while(0)

#if !defined(T2D_DEBUG) || T2D_DEBUG == 0
#define CHECK_GL_ERROR_DEBUG()
#else
#define CHECK_GL_ERROR_DEBUG()		   \
    do {							   \
        GLenum __error = glGetError(); \
        if(__error) {				   \
            cocos2d::log("OpenGL error 0x%04X in %s %s %d\n", __error, __FILE__, __FUNCTION__, __LINE__); \
		}							   \
	} while (false)
#endif

#endif // __T2D_ENGINE_PLATFORM_MACROS_H__
