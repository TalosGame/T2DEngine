/*!
 * FileName: 	platform_macros.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/26 23:56
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_PLATFORM_MACROS_H__
#define __T2D_ENGINE_PLATFORM_MACROS_H__

#define __T2D_NAMESPACE_BEGIN__ namespace t2d{
#define __T2D_NAMESPACE_END__	}

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

/// extension set/get macros /////////////////////////////////////////////
#define GET_SET(type, variable) \
protected: type variable##_; \
public: virtual type get_##variable() const { return variable##_; } \
public: virtual	void set_##variable(type variable) { variable##_ = variable; }

#define GET(type, variable) \
protected: type variable##_; \
public: virtual type get_##variable() const { return variable##_; }

#define GET_SET_REF(type, variable) \
protected: type variable##_; \
public: virtual const type &get_##variable() const { return variable##_; } \
public: virtual	void set_##variable(const type &variable) { variable##_ = variable; }

//////////////////////////////////////////////////////////////////////////


#endif // __T2D_ENGINE_PLATFORM_MACROS_H__
