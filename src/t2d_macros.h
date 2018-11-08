/*!
 * FileName: 	t2d_macros.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/11/05 0:10
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_MACROS_H__
#define __T2D_ENGINE_MACROS_H__

#define GET_ARRAY_LEN(array, len) { len = (sizeof(array) / sizeof(array[0])); }

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


#endif // __T2D_ENGINE_T2D_MACROS_H__

