/*!
 * FileName: 	quaternion.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/08/26 22:27
 * Author: 		miller
 * Desc:		
 */

#include "quaternion.h"

__T2D_NS_MATH_BEGIN__

Quaternion::Quaternion(){}

Quaternion::Quaternion(const Quaternion &q) : w(q.w), x(q.x), y(q.y), z(q.z){}

Quaternion::Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

Quaternion::~Quaternion(){

}

float AngularDistance(const Quaternion& lhs, const Quaternion& rhs){
	float dot = Dot(lhs, rhs);
	if (dot < 0.0f)
		dot = -dot;
	return RAD_TO_DEG(acos(MIN(1.0F, dot)) * 2.0F);
}

const Quaternion Quaternion::identity = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);



__T2D_NS_MATH_END__
