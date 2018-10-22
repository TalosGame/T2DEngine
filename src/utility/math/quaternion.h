/*!
 * FileName: 	quaternion.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/08/26 22:27
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_QUATERNION_H__
#define __T2D_ENGINE_QUATERNION_H__

#include "platform/platform_macros.h"
#include "vector.h"
#include "matrix.h"
#include "mathf.h"

__T2D_NS_MATH_BEGIN__

struct Quaternion{
public:
	Quaternion();
	Quaternion(const Quaternion &q);
	Quaternion(float w, float x, float y, float z);
	virtual ~Quaternion();

	Quaternion &operator+=(const Quaternion &q);
	Quaternion &operator-=(const Quaternion &q);
	Quaternion &operator*=(const Quaternion &q);
	Quaternion &operator*=(float s);

	Quaternion operator*(const Quaternion &q) const;
	Quaternion operator*(float s) const;

	bool operator==(const Quaternion &a) const;
	bool operator!=(const Quaternion &a) const;

	Quaternion inverse() const;

	float w;
	float x;
	float y;
	float z;

	static const Quaternion identity;
};

inline Quaternion &Quaternion::operator+=(const Quaternion &q){
	this->w += q.w;
	this->x += q.x;
	this->y += q.y;
	this->z += q.z;
	return *this;
}

inline Quaternion &Quaternion::operator-=(const Quaternion &q){
	this->w -= q.w;
	this->x -= q.x;
	this->y -= q.y;
	this->z -= q.z;
	return *this;
}

inline Quaternion &Quaternion::operator*=(const Quaternion &q){
	float w = w * q.w - x * q.x - y * q.y - z * q.z;
	float x = x * q.w + q.x * w + y * q.z - z * q.y;
	float y = y * q.w + q.y * w + z * q.x - x * q.z;
	float z = z * q.w + q.z * w + x * q.y - y * q.x;

	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
	return *this;
}

inline Quaternion &Quaternion::operator*=(float s){
	this->w *= s;
	this->x *= s;
	this->y *= s;
	this->z *= s;
	return *this;
}

inline Quaternion Quaternion::operator*(const Quaternion &q) const{
	return Quaternion(w *q.w - x * q.x - y * q.y - z * q.z,
					  x * q.w + q.x * w + y * q.z - z * q.y,
					  y * q.w + q.y * w + z * q.x - x * q.z,
					  z * q.w + q.z * w + x * q.y - y * q.x);
}

inline Quaternion Quaternion::operator*(float s) const{
	return Quaternion(w*s, x*s, y*s, z*s);
}

inline bool Quaternion::operator==(const Quaternion &q) const{
	return (x == q.x && y == q.y && z == q.z && w == q.w);
}

inline bool Quaternion::operator!=(const Quaternion &q) const{
	return (x != q.x || y != q.y || z != q.z || w != q.w);
}

inline Quaternion Quaternion::inverse() const{
	return Quaternion(this->w, -this->x, -this->y, -this->z);
}

inline Quaternion angle_axis_to_quaternion(const Vector3 &axis, float angle){
	Quaternion q;

	float radius = DEG_TO_RAD(angle * 0.5f);
	float s = sin(radius);
	q.w = cos(radius);
	q.x = axis.x * s;
	q.y = axis.y * s;
	q.z = axis.z * s;

	return q;
}

inline void quaternion_to_matrix(const Quaternion &q, Matrix3x3 &m){
	float x2 = q.x * 2;
	float y2 = q.y * 2;
	float z2 = q.z * 2;
	float xx = q.x * x2;
	float yy = q.y * y2;
	float zz = q.z * z2;
	float xy = q.x * y2;
	float xz = q.x * z2;
	float yz = q.y * z2;
	float wz = q.w * z2;
	float wy = q.w * y2;
	float wx = q.w * x2;

	m.m00 = 1.0f - yy - zz;
	m.m01 = xy - wz;
	m.m02 = xz + wy;

	m.m10 = xy + wz;
	m.m11 = 1.0f - xx - zz;
	m.m12 = yz - wx;
	
	m.m20 = xz - wy;
	m.m21 = yz + wx;
	m.m22 = 1.0f - xx - yy;
}

inline Vector3 quaternion_to_euler(const Quaternion &q){
	Matrix3x3 m;
	Vector3 rot;
	quaternion_to_matrix(q, m);
	matrix_to_euler(m, rot);
	return rot;
}

inline float Dot(const Quaternion& q1, const Quaternion& q2){
	return (q1.x*q2.x + q1.y*q2.y + q1.z*q2.z + q1.w*q2.w);
}

float AngularDistance(const Quaternion& lhs, const Quaternion& rhs);

__T2D_NS_MATH_END__

#endif // __T2D_ENGINE_QUATERNION_H__