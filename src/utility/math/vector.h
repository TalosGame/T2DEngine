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
#include "mathf.h"

struct Vector2
{
public:
	Vector2();
	explicit Vector2(float x, float y);
	Vector2(const Vector2& vec2);
	~Vector2();

	void zero();
	void set(float x, float y);
	void normalize();

	float operator[](const int index) const;
	float &operator[](const int index);

	Vector2& operator=(const Vector2& a);

	Vector2 operator*(float a) const;
	Vector2 operator*(const Vector2& a) const;

	Vector2 operator+(const Vector2& a) const;
	Vector2 operator-(const Vector2& a) const;

	Vector2& operator+=(const Vector2& a);
	Vector2& operator-=(const Vector2& a);

	bool operator==(const Vector2& a) const;
	bool operator!=(const Vector2& a) const;

	// Returns the length of this vector
	float lenght() const;
	// Returns the squared length of this vector
	float sqr_lenght() const;

	float distance(const Vector2& a) const;
	float sqr_distance(const Vector2& a) const;

	float dot(const Vector2& a) const;

	float x;
	float y;

	static const Vector2 kZero;
	static const Vector2 kUp;
	static const Vector2 kDown;
	static const Vector2 kRight;
	static const Vector2 kLeft;
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

inline Vector2& Vector2::operator=(const Vector2& a){
	this->x = a.x;
	this->y = a.y;
	return *this;
}

inline Vector2 Vector2::operator*(float a) const {
	return Vector2(this->x * a, this->y * a);
}

inline Vector2 Vector2::operator*(const Vector2& a) const{
	return Vector2(this->x * a.x, this->y * a.y);
}

inline Vector2 Vector2::operator+(const Vector2& a) const{
	return Vector2(this->x + a.x, this->y + a.y);
}

inline Vector2 Vector2::operator-(const Vector2& a) const{
	return Vector2(this->x - a.x, this->y - a.y);
}

inline Vector2& Vector2::operator+=(const Vector2& a){
	this->x += a.x;
	this->y += a.y;
	return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& a){
	this->x -= a.x;
	this->y -= a.y;
	return *this;
}

inline bool Vector2::operator==(const Vector2& a) const{
	if (fast_fabs(this->x - a.x) > EPSILON_E3 
		|| fast_fabs(this->y - a.y) > EPSILON_E3){
		return false;
	}

	return true;
}

inline bool Vector2::operator!=(const Vector2& a) const{
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

inline float Vector2::distance(const Vector2& a) const{
	Vector2 ret = *this - a;
	float sqrLen = ret.x * ret.x + ret.y * ret.y;

	return SQRTFAST(sqrLen);
}

inline float Vector2::sqr_distance(const Vector2& a) const{
	Vector2 ret = *this - a;
	return ret.x * ret.x + ret.y * ret.y;
}

inline float Vector2::dot(const Vector2& a) const{
	return (this->x * a.x + this->y * a.y);
}

/// vector3 define////////////////////////////////////////////////////////
struct Vector3
{
public:
	Vector3();
	explicit Vector3(float x, float y, float z);
	Vector3(const Vector3& vec3);
	Vector3(const Vector2& vec2);
	~Vector3();

	void zero();
	void set(float x, float y, float z);
	void normalize();

	float operator[](const int index) const;
	float &operator[](const int index);

	Vector3& operator=(const Vector3& a);
	Vector3 operator-() const;

	Vector3 operator*(float a) const;
	Vector3 operator*(const Vector3& a) const;

	Vector3 operator+(const Vector3& a) const;
	Vector3 operator-(const Vector3& a) const;

	Vector3& operator+=(const Vector3& a);
	Vector3& operator-=(const Vector3& a);

	bool operator==(const Vector3& a) const;
	bool operator!=(const Vector3& a) const;

	// Returns the length of this vector
	float lenght() const;
	// Returns the squared length of this vector
	float sqr_lenght() const;

	float distance(const Vector3& a) const;
	float sqr_distance(const Vector3& a) const;

	float dot(const Vector3& a) const;
	Vector3 cross(const Vector3& a) const;

	float x;
	float y;
	float z;

	static const Vector3 kZero;
	static const Vector3 kUp;
	static const Vector3 kDown;
	static const Vector3 kRight;
	static const Vector3 kLeft;
	static const Vector3 kForward;
	static const Vector3 kBack;
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

inline float& Vector3::operator[](const int index){
	return (&x)[index];
}

inline Vector3& Vector3::operator=(const Vector3& a){
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
	return *this;
}

inline Vector3 Vector3::operator-() const{
	return Vector3(-this->x, -this->y, -this->z);
}

inline Vector3 Vector3::operator*(float a) const{
	return Vector3(this->x * a, this->y * a, this->z * a);
}

inline Vector3 Vector3::operator*(const Vector3& a) const{
	return Vector3(this->x * a.x, this->y * a.y, this->z * a.z);
}

inline Vector3 Vector3::operator+(const Vector3& a) const{
	return Vector3(this->x + a.x, this->y + a.y, this->z + a.z);
}

inline Vector3 Vector3::operator-(const Vector3& a) const{
	return Vector3(this->x - a.x, this->y - a.y, this->z - a.z);
}

inline Vector3& Vector3::operator+=(const Vector3& a){
	this->x += a.x;
	this->y += a.y;
	this->z += a.z;
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& a){
	this->x -= a.x;
	this->y -= a.y;
	this->z -= a.z;
	return *this;
}

inline bool Vector3::operator==(const Vector3& a) const{
	if (fast_fabs(this->x - a.x) > EPSILON_E3
		|| fast_fabs(this->y - a.y) > EPSILON_E3
		|| fast_fabs(this->z - a.z) > EPSILON_E3){
		return false;
	}

	return true;
}

inline bool Vector3::operator!=(const Vector3& a) const{
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

inline float Vector3::distance(const Vector3& a) const{
	Vector3 ret = *this - a;
	float sqrLen = ret.x * ret.x + ret.y * ret.y + ret.z * ret.z;

	return SQRTFAST(sqrLen);
}

inline float Vector3::sqr_distance(const Vector3& a) const{
	Vector3 ret = *this - a;
	return ret.x * ret.x + ret.y * ret.y + ret.z * ret.z;
}

inline float Vector3::dot(const Vector3& a) const{
	return (this->x * a.x + this->y * a.y + this->z * a.z);
}

inline Vector3 Vector3::cross(const  Vector3 &a) const{
	Vector3 ret;
	ret.x = this->y * a.z - this->z * a.y;
	ret.y = this->z * a.x - this->x * a.z;
	ret.z = this->x * a.y - this->y * a.x;

	return ret;
}

struct Vector4
{
	Vector4();
	explicit Vector4(float x, float y, float z, float w);
	Vector4(const Vector3 &vec3);
	Vector4(const Vector2& vec2);
	~Vector4();

	void zero();
	void set(float x, float y, float z);
	void normalize();

	float operator[](const int index) const;
	float& operator[](const int index);

	Vector4& operator=(const Vector4& a);
	Vector4 operator-() const;

	Vector4 operator*(float a) const;
	Vector4 operator*(const Vector4& a) const;
	Vector4 operator*(const Vector3& a) const;

	Vector4 operator+(const Vector4& a) const;
	Vector4 operator+(const Vector3& a) const;

	Vector4 operator-(const Vector4& a) const;
	Vector4 operator-(const Vector3& a) const;

	Vector4 &operator+=(const Vector4& a);
	Vector4& operator+=(const Vector3& a);

	Vector4 &operator-=(const Vector4& a);
	Vector4 &operator-=(const Vector3& a);

	bool operator==(const Vector3& a) const;
	bool operator!=(const Vector3& a) const;

	// Returns the length of this vector
	float lenght() const;
	// Returns the squared length of this vector
	float sqr_lenght() const;

	float distance(const Vector4& a) const;
	float sqr_distance(const Vector4& a) const;

	float dot(const Vector4& a) const;
	Vector4 cross(const Vector4& a) const;

	float x;
	float y;
	float z;
	float w;
};

inline void Vector4::zero(){
	this->x = this->y = this->z = 0;
	this->z = 1.0f;
}

inline void Vector4::set(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = 1.0f;
}

inline float Vector4::operator[](const int index) const{
	return (&x)[index];
}

inline float& Vector4::operator[](const int index){
	return (&x)[index];
}

inline Vector4& Vector4::operator=(const Vector4& a){
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
	this->w = 1;
	return *this;
}

inline Vector4 Vector4::operator-() const{
	return Vector4(-this->x, -this->y, -this->z, 1.0f);
}

inline Vector4 Vector4::operator*(float a) const{
	return Vector4(this->x * a, this->y * a, this->z * a, 1.0f);
}

inline Vector4 Vector4::operator*(const Vector4& a) const{
	return Vector4(this->x * a.x, this->y * a.y, this->z * a.z, 1.0f);
}

inline Vector4 Vector4::operator*(const Vector3& a) const{
	return Vector4(this->x * a.x, this->y * a.y, this->z * a.z, 1.0f);
}

inline Vector4 Vector4::operator+(const Vector4& a) const{
	return Vector4(this->x + a.x, this->y + a.y, this->z + a.z, 1.0f);
}

inline Vector4 Vector4::operator+(const Vector3& a) const{
	return Vector4(this->x + a.x, this->y + a.y, this->z + a.z, 1.0f);
}

inline Vector4 Vector4::operator-(const Vector4& a) const{
	return Vector4(this->x - a.x, this->y - a.y, this->z - a.z, 1.0f);
}

inline Vector4 Vector4::operator-(const Vector3& a) const{
	return Vector4(this->x - a.x, this->y - a.y, this->z - a.z, 1.0f);
}

inline Vector4& Vector4::operator+=(const Vector4& a){
	this->x += a.x;
	this->y += a.y;
	this->z += a.z;
	return *this;
}

inline Vector4& Vector4::operator+=(const Vector3& a){
	this->x += a.x;
	this->y += a.y;
	this->z += a.z;
	return *this;
}

inline Vector4& Vector4::operator-=(const Vector4& a){
	this->x -= a.x;
	this->y -= a.y;
	this->z -= a.z;
	return *this;
}

inline Vector4& Vector4::operator-=(const Vector3& a){
	this->x -= a.x;
	this->y -= a.y;
	this->z -= a.z;
	return *this;
}

inline bool Vector4::operator==(const Vector3& a) const{
	if (fast_fabs(this->x - a.x) > EPSILON_E3
		|| fast_fabs(this->y - a.y) > EPSILON_E3
		|| fast_fabs(this->z - a.z) > EPSILON_E3){
		return false;
	}

	return true;
}

inline bool Vector4::operator!=(const Vector3& a) const{
	if (fast_fabs(this->x - a.x) > EPSILON_E3
		|| fast_fabs(this->y - a.y) > EPSILON_E3
		|| fast_fabs(this->z - a.z) > EPSILON_E3){
		return true;
	}

	return false;
}

inline float Vector4::lenght() const{
	return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

inline float Vector4::sqr_lenght() const{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

inline float Vector4::distance(const Vector4& a) const{
	Vector4 ret = *this - a;
	float sqrLen = ret.x * ret.x + ret.y * ret.y + ret.z * ret.z;

	return SQRTFAST(sqrLen);
}

inline float Vector4::sqr_distance(const Vector4& a) const{
	Vector4 ret = *this - a;
	return ret.x * ret.x + ret.y * ret.y + ret.z * ret.z;
}

inline float Vector4::dot(const Vector4& a) const{
	return (this->x * a.x + this->y * a.y + this->z * a.z);
}

inline Vector4 Vector4::cross(const Vector4& a) const{
	Vector4 ret;
	ret.x = this->y * a.z - this->z * a.y;
	ret.y = this->z * a.x - this->x * a.z;
	ret.z = this->x * a.y - this->y * a.x;
	ret.w = 1.0f;

	return ret;
}

#endif // __XENGINE_MATH_VECTOR_H__