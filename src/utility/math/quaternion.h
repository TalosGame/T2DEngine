/*!
 * FileName: 	quaternion.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/08/26 22:27
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_QUATERNION_H__
#define __T2D_ENGINE_QUATERNION_H__

struct Quaternion{
public:
	Quaternion();
	virtual ~Quaternion();


	
	float x;
	float y;
	float z;
	float w;
};

#endif // __T2D_ENGINE_QUATERNION_H__

