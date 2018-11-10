/**************************************************************
*  Filename :    math_vector.cpp
*  Author   :    miller
*  Data     :    2018/5/24
*  Desc     :
**************************************************************/

#include "vector.h"
#include <math.h>
#include "mathf.h"
#include "utility/log/xlog.h"

Vector2::Vector2() {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(const Vector2& vec2) : x(vec2.x), y(vec2.y) {}

Vector2::~Vector2() {}

void Vector2::normalize(){
	float lenght = sqrtf(this->x * this->x + this->y * this->y);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	this->x = this->x * lenght_inv;
	this->y = this->y * lenght_inv;
}

///Vector3 ////////////////////////////////////////////////////////////////////////

Vector3::Vector3() {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3 &vec3) : x(vec3.x), y(vec3.y), z(vec3.z) {}

Vector3::Vector3(const Vector2& vec2) : x(vec2.x), y(vec2.y), z(0.0f) {}

Vector3::~Vector3() {}

void Vector3::normalize(){
	float lenght = sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	this->x = this->x * lenght_inv;
	this->y = this->y * lenght_inv;
	this->z = this->z * lenght_inv;
}

///Vector4 ////////////////////////////////////////////////////////////////////////
Vector4::Vector4() {}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector3 &vec3) : x(vec3.x), y(vec3.y), z(vec3.z), w(1) {}

Vector4::Vector4(const Vector2& vec2) : x(vec2.x), y(vec2.y), z(0.0f), w(1) {}

Vector4::~Vector4() {}

void Vector4::normalize(){
	float lenght = sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	this->x = this->x * lenght_inv;
	this->y = this->y * lenght_inv;
	this->z = this->z * lenght_inv;
	this->w = 1;
}

///const struct variable define/////////////////////////////////////////////////////////////
const Vector2 Vector2::kZero = Vector2(0.0f, 0.0f);
const Vector2 Vector2::kUp = Vector2(0.0f, 1.0f);
const Vector2 Vector2::kDown = Vector2(0.0f, -1.0f);
const Vector2 Vector2::kRight = Vector2(1.0f, 0.0f);
const Vector2 Vector2::kLeft = Vector2(-1.0f, 0.0f);

const Vector3 Vector3::kZero = Vector3(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::kUp = Vector3(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::kDown = Vector3(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::kRight = Vector3(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::kLeft = Vector3(-1.0f, 0.0f, 0.0f);
const Vector3 Vector3::kForward = Vector3(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::kBack = Vector3(0.0f, 0.0f, -1.0f);
