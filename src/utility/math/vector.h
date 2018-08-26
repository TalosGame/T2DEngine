/*!
 * FileName: 	math_vector.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/08/11 21:47
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __XENGINE_MATH_VECTOR_H__
#define __XENGINE_MATH_VECTOR_H__

#include <math.h>
#include "platform/platform_macros.h"
#include "mathf.h"

__T2D_NS_MATH_BEGIN__

struct Vector2
{
public:
	Vector2();
	explicit Vector2(float x, float y);
	Vector2(const Vector2 &vec2);
	~Vector2();

	void zero();
	void set(float x, float y);
	void normalize();

	float operator[](const int index) const;
	float &operator[](const int index);

	Vector2 &operator=(const Vector2 &a);

	Vector2 operator*(float a) const;
	Vector2 operator*(const Vector2 &a) const;

	Vector2 operator+(const Vector2 &a) const;
	Vector2 operator-(const Vector2 &a) const;

	Vector2 &operator+=(const Vector2 &a);
	Vector2 &operator-=(const Vector2 &a);

	bool operator==(const Vector2 &a) const;
	bool operator!=(const Vector2 &a) const;

	// Returns the length of this vector
	float lenght() const;
	// Returns the squared length of this vector
	float sqr_lenght() const;

	float distance(const Vector2 &a) const;
	float sqr_distance(const Vector2 &a) const;

	float dot(const Vector2 &a) const;

	float x;
	float y;

	static const Vector2 ZERO;
	static const Vector2 UP;
	static const Vector2 DOWN;
	static const Vector2 RIGHT;
	static const Vector2 LEFT;
};

inline void Vector2::zero(){
	this->x = 0.0f;
	this->y = 0.0f;
}

inline void Vector2::set(float x, float y){
	this->x = x;
	this->y = y;
}

inline float Vector2::operator[](const int index) const{
	return (&x)[index];
}

inline float &Vector2::operator[](const int index){
	return (&x)[index];
}

inline Vector2 &Vector2::operator=(const Vector2 &a){
	this->x = a.x;
	this->y = a.y;
	return *this;
}

inline Vector2 Vector2::operator*(float a) const {
	return Vector2(this->x * a, this->y * a);
}

inline Vector2 Vector2::operator*(const Vector2 &a) const{
	return Vector2(this->x * a.x, this->y * a.y);
}

inline Vector2 Vector2::operator+(const Vector2 &a) const{
	return Vector2(this->x + a.x, this->y + a.y);
}

inline Vector2 Vector2::operator-(const Vector2 &a) const{
	return Vector2(this->x - a.x, this->y - a.y);
}

inline Vector2 &Vector2::operator+=(const Vector2 &a){
	this->x += a.x;
	this->y += a.y;
	return *this;
}

inline Vector2 &Vector2::operator-=(const Vector2 &a){
	this->x -= a.x;
	this->y -= a.y;
	return *this;
}

inline bool Vector2::operator==(const Vector2 &a) const{
	if (fast_fabs(this->x - a.x) > EPSILON_E3 
		|| fast_fabs(this->y - a.y) > EPSILON_E3){
		return false;
	}

	return true;
}

inline bool Vector2::operator!=(const Vector2 &a) const{
	if (fast_fabs(this->x - a.x) > EPSILON_E3 
		|| fast_fabs(this->y - a.y) > EPSILON_E3){
		return true;
	}

	return false;
}

inline float Vector2::lenght() const{
	return sqrtf(this->x * this->x + this->y * this->y);
}

inline float Vector2::sqr_lenght() const{
	return this->x * this->x + this->y * this->y;
}

inline float Vector2::distance(const Vector2 &a) const{
	Vector2 ret = *this - a;
	float sqrLen = ret.x * ret.x + ret.y * ret.y;

	return SQRTFAST(sqrLen);
}

inline float Vector2::sqr_distance(const Vector2 &a) const{
	Vector2 ret = *this - a;
	return ret.x * ret.x + ret.y * ret.y;
}

inline float Vector2::dot(const Vector2 &a) const{
	return (this->x * a.x + this->y * a.y);
}

/// vector3 define////////////////////////////////////////////////////////
struct Vector3
{
public:
	Vector3();
	explicit Vector3(float x, float y, float z);
	Vector3(const Vector3 &vec3);
	Vector3(const Vector2 &vec2);
	~Vector3();

	void zero();
	void set(float x, float y, float z);
	void normalize();

	float operator[](const int index) const;
	float &operator[](const int index);

	Vector3 &operator=(const Vector3 &a);

	Vector3 operator*(float a) const;
	Vector3 operator*(const Vector3 &a) const;

	Vector3 operator+(const Vector3 &a) const;
	Vector3 operator-(const Vector3 &a) const;

	Vector3 &operator+=(const Vector3 &a);
	Vector3 &operator-=(const Vector3 &a);

	bool operator==(const Vector3 &a) const;
	bool operator!=(const Vector3 &a) const;

	// Returns the length of this vector
	float lenght() const;
	// Returns the squared length of this vector
	float sqr_lenght() const;

	float distance(const Vector3 &a) const;
	float sqr_distance(const Vector3 &a) const;

	float dot(const Vector3 &a) const;

	float x;
	float y;
	float z;

	static const Vector3 ZERO;
	static const Vector3 UP;
	static const Vector3 DOWN;
	static const Vector3 RIGHT;
	static const Vector3 LEFT;
};

inline void Vector3::zero(){
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

inline void Vector3::set(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

inline float Vector3::operator[](const int index) const{
	return (&x)[index];
}

inline float &Vector3::operator[](const int index){
	return (&x)[index];
}

inline Vector3 &Vector3::operator=(const Vector3 &a){
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
	return *this;
}

inline Vector3 Vector3::operator*(float a) const{
	return Vector3(this->x * a, this->y * a, this->z * a);
}

inline Vector3 Vector3::operator*(const Vector3 &a) const{
	return Vector3(this->x * a.x, this->y * a.y, this->z * a.z);
}

inline Vector3 Vector3::operator+(const Vector3 &a) const{
	return Vector3(this->x + a.x, this->y + a.y, this->z + a.z);
}

inline Vector3 Vector3::operator-(const Vector3 &a) const{
	return Vector3(this->x - a.x, this->y - a.y, this->z - a.z);
}

inline Vector3 &Vector3::operator+=(const Vector3 &a){
	this->x += a.x;
	this->y += a.y;
	this->z += a.z;
	return *this;
}

inline Vector3 &Vector3::operator-=(const Vector3 &a){
	this->x -= a.x;
	this->y -= a.y;
	this->z -= a.z;
	return *this;
}

inline bool Vector3::operator==(const Vector3 &a) const{
	if (fast_fabs(this->x - a.x) > EPSILON_E3
		|| fast_fabs(this->y - a.y) > EPSILON_E3
		|| fast_fabs(this->z - a.z) > EPSILON_E3){
		return false;
	}

	return true;
}

inline bool Vector3::operator!=(const Vector3 &a) const{
	if (fast_fabs(this->x - a.x) > EPSILON_E3
		|| fast_fabs(this->y - a.y) > EPSILON_E3
		|| fast_fabs(this->z - a.z) > EPSILON_E3){
		return true;
	}

	return false;
}

inline float Vector3::lenght() const{
	return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

inline float Vector3::sqr_lenght() const{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

inline float Vector3::distance(const Vector3 &a) const{
	Vector3 ret = *this - a;
	float sqrLen = ret.x * ret.x + ret.y * ret.y + ret.z * ret.z;

	return SQRTFAST(sqrLen);
}

inline float Vector3::sqr_distance(const Vector3 &a) const{
	Vector3 ret = *this - a;
	return ret.x * ret.x + ret.y * ret.y + ret.z * ret.z;
}

inline float Vector3::dot(const Vector3 &a) const{
	return (this->x * a.x + this->y * a.y + this->z * a.z);
}

/*
typedef struct _Vector2
{
	union
	{
		float M[2];

		struct
		{
			float x;
			float y;
		};
	};
}Vector2, Point2, *Vector2Ptr, *Point2Ptr;

typedef struct _Vector3
{
	union
	{
		float M[3];

		struct
		{
			float x;
			float y;
			float z;
		};
	};
}Vector3, Point3, *Vector3Ptr, *Point3Ptr;
*/

typedef struct _Vector4
{
	union
	{
		float M[4];

		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
}Vector4, Point4, *Vector4Ptr, *Point4Ptr;

/*
inline void vector2d_zero(Vector2Ptr v){
	v->x = v->y = 0.0f;
}

inline void vector3d_zero(Vector3Ptr v){
	v->x = v->y = v->z = 0.0f;
}

inline void vector4d_zero(Vector4Ptr v){
	v->x = v->y = v->z = v->w = 0.0f;
}

inline void set_vector2d(Vector2Ptr v, float x, float y){
	v->x = x;
	v->y = y;
}

inline void set_vector2d(Vector2Ptr dst, Vector2Ptr src){
	dst->x = src->x;
	dst->y = src->y;
}

inline void set_point2d(Point2Ptr dst, Point2Ptr src){
	dst->x = src->x;
	dst->y = src->y;
}

inline void set_vector3d(Vector3Ptr v, float x, float y, float z){
	v->x = x;
	v->y = y;
	v->z = z;
}

inline void set_vector3d(Vector3Ptr src, Vector3Ptr dst){
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

inline void set_point3d(Point3Ptr dst, Point3Ptr src){
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

inline void set_vector4d(Vector4Ptr v, float x, float y, float z){
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = 1.0f;
}

inline void set_vector4d(Vector4Ptr src, Vector4Ptr dst){
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	dst->w = src->w;
}

inline void set_point4d(Point4Ptr dst, Point4Ptr src){
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	dst->w = src->w;
}

// 2d vector ///////////////////////////////////
void vector2_add(Vector2Ptr v1, Vector2Ptr v2, Vector2Ptr ret);
Vector2 vector2_add(Vector2Ptr v1, Vector2Ptr v2);
void vector2_sub(Vector2Ptr v1, Vector2Ptr v2, Vector2Ptr ret);
Vector2 vector2_sub(Vector2Ptr v1, Vector2Ptr v2);
void vector2_scale(float k, Vector2Ptr v, Vector2Ptr ret);
void vector2_scale(float k, Vector2Ptr v);
float vector2_dot(Vector2Ptr v1, Vector2Ptr v2);
float vector2_lenght(Vector2Ptr v);
float vector2_lenght_fast(Vector2Ptr v);
void vector2_normalize(Vector2Ptr v);
void vector2_normalize(Vector2Ptr v, Vector2Ptr ret);
void vector2_print(Vector2Ptr v, const char *name);
*/
// 3d vector ///////////////////////////////////
// void vector3_add(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret);
// Vector3 vector3_add(Vector3Ptr v1, Vector3Ptr v2);
// void vector3_sub(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret);
// Vector3 vector3_sub(Vector3Ptr v1, Vector3Ptr v2);
// void vector3_scale(float k, Vector3Ptr v, Vector3Ptr ret);
// Vector3 vector3_scale(float k, Vector3Ptr v);
// float vector3_dot(Vector3Ptr v1, Vector3Ptr v2);
// void vector3_cross(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret);
// Vector3 vector3_cross(Vector3Ptr v1, Vector3Ptr v2);
// float vector3_lenght(Vector3Ptr v);
// float vector3_lenght_fast(Vector3Ptr v);
// void vector3_normalize(Vector3Ptr v);
// void vector3_normalize(Vector3Ptr v, Vector3Ptr ret);
// void vector3_print(Vector3Ptr v, const char *name);

// 4d vector ///////////////////////////////////
void vector4_add(Vector4Ptr v1, Vector4Ptr v2, Vector4Ptr ret);
Vector4 vector4_add(Vector4Ptr v1, Vector4Ptr v2);
void vector4_sub(Vector4Ptr v1, Vector4Ptr v2, Vector4Ptr ret);
Vector4 vector4_sub(Vector4Ptr v1, Vector4Ptr v2);
void vector4_scale(float k, Vector4Ptr v, Vector4Ptr ret);
Vector4 vector4_scale(float k, Vector4Ptr v);
float vector4_dot(Vector4Ptr v1, Vector4Ptr v2);
void vector4_cross(Vector4Ptr v1, Vector4Ptr v2, Vector4Ptr ret);
Vector4 vector4_cross(Vector4Ptr v1, Vector4Ptr v2);
float vector4_lenght(Vector4Ptr v);
float vector4_lenght_fast(Vector4Ptr v);
void vector4_normalize(Vector4Ptr v);
void vector4_normalize(Vector4Ptr v, Vector4Ptr ret);
void vector4_print(Vector4Ptr v, const char *name);

__T2D_NS_MATH_END__

#endif // __XENGINE_MATH_VECTOR_H__