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

__T2D_NS_MATH_BEGIN__

Vector2::Vector2() {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(const Vector2 &vec2) : x(vec2.x), y(vec2.y) {}

Vector2::~Vector2() {}

void Vector2::normalize(){
	float lenght = sqrtf(this->x * this->x + this->y * this->y);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	this->x = this->x * lenght_inv;
	this->y = this->y * lenght_inv;
}

Vector3::Vector3() {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3 &vec3) : x(vec3.x), y(vec3.y), z(vec3.z) {}

Vector3::Vector3(const Vector2 &vec2) : x(vec2.x), y(vec2.y), z(0.0f) {}

Vector3::~Vector3() {}

void Vector3::normalize(){
	float lenght = sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	this->x = this->x * lenght_inv;
	this->y = this->y * lenght_inv;
	this->z = this->z * lenght_inv;
}

/*
// 2d vector ///////////////////////////////////
void vector2_add(Vector2Ptr v1, Vector2Ptr v2, Vector2Ptr ret){
	ret->x = v1->x + v2->x;
	ret->y = v1->y + v2->y;
}

Vector2 vector2_add(Vector2Ptr v1, Vector2Ptr v2){
	Vector2 ret;
	ret.x = v1->x + v2->x;
	ret.y = v1->y + v2->y;
	return ret;
}

void vector2_sub(Vector2Ptr v1, Vector2Ptr v2, Vector2Ptr ret){
	ret->x = v1->x - v2->x;
	ret->y = v1->y - v2->y;
}

Vector2 vector2_sub(Vector2Ptr v1, Vector2Ptr v2){
	Vector2 ret;
	ret.x = v1->x - v2->x;
	ret.y = v1->y - v2->y;
	return ret;
}

void vector2_scale(float k, Vector2Ptr v, Vector2Ptr ret){
	ret->x = k * v->x;
	ret->y = k * v->y;
}

void vector2_scale(float k, Vector2Ptr v){
	v->x = k * v->x;
	v->y = k * v->y;
}

float vector2_dot(Vector2Ptr v1, Vector2Ptr v2){
	return (v1->x * v2->x + v1->y * v2->y);
}

float vector2_lenght(Vector2Ptr v){
	return sqrtf(v->x * v->x + v->y * v->y);
}

float vector2_lenght_fast(Vector2Ptr v){
	return (float)(fast_distance_2d(v->x, v->y));
}

void vector2_normalize(Vector2Ptr v){
	float lenght = sqrtf(v->x * v->x + v->y * v->y);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;
	
	v->x = v->x * lenght_inv;
	v->y = v->y * lenght_inv;  
}

void vector2_normalize(Vector2Ptr v, Vector2Ptr ret){
	vector2d_zero(ret);

	float lenght = sqrtf(v->x * v->x + v->y * v->y);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	ret->x = v->x * lenght_inv;
	ret->y = v->y * lenght_inv;
}

void vector2_print(Vector2Ptr v, const char *name){
	log_error("\n%s=[", name);
	for (int index = 0; index < 2; index++)
		log_error(" %f", v->M[index]);
	log_error(" ]\n");
}

// 3d vector ///////////////////////////////////
void vector3_add(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret){
	ret->x = v1->x + v2->x;
	ret->y = v1->y + v2->y;
	ret->z = v1->z + v2->z;
}

Vector3 vector3_add(Vector3Ptr v1, Vector3Ptr v2){
	Vector3 ret;

	ret.x = v1->x + v2->x;
	ret.y = v1->y + v2->y;
	ret.z = v1->z + v2->z;
	return ret;
}

void vector3_sub(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret){
	ret->x = v1->x - v2->x;
	ret->y = v1->y - v2->y;
	ret->z = v1->z - v2->z;
}

Vector3 vector3_sub(Vector3Ptr v1, Vector3Ptr v2){
	Vector3 ret;
	ret.x = v1->x - v2->x;
	ret.y = v1->y - v2->y;
	ret.z = v1->z - v2->z;
	return ret;
}

void vector3_scale(float k, Vector3Ptr v, Vector3Ptr ret){
	ret->x = k * v->x;
	ret->y = k * v->y;
	ret->z = k * v->z;
}

Vector3 vector3_scale(float k, Vector3Ptr v){
	Vector3 ret;
	ret.x = k * v->x;
	ret.y = k * v->y;
	ret.z = k * v->z;
	return ret;
}

float vector3_dot(Vector3Ptr v1, Vector3Ptr v2){
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void vector3_cross(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret){
	ret->x = v1->y * v2->z - v1->z * v2->y;
	ret->y = v1->z * v2->x - v1->x * v2->z;
	ret->z = v1->x * v2->y - v1->y * v2->x;
}

Vector3 vector3_cross(Vector3Ptr v1, Vector3Ptr v2){
	Vector3 ret;
	ret.x = v1->y * v2->z - v1->z * v2->y;
	ret.y = v1->z * v2->x - v1->x * v2->z;
	ret.z = v1->x * v2->y - v1->y * v2->x;
	return ret;
}

float vector3_lenght(Vector3Ptr v){
	return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}

float vector3_lenght_fast(Vector3Ptr v){
	return fast_distance_3d(v->x, v->y, v->z);
}

void vector3_normalize(Vector3Ptr v){
	float lenght = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	v->x = v->x * lenght_inv;
	v->y = v->y * lenght_inv;
	v->z = v->z * lenght_inv;
}

void vector3_normalize(Vector3Ptr v, Vector3Ptr ret){
	//vector3d_zero(ret);

	float lenght = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	ret->x = v->x * lenght_inv;
	ret->y = v->y * lenght_inv;
	ret->z = v->z * lenght_inv;
}

void vector3_print(Vector3Ptr v, const char *name){
	log_error("\n%s=[", name);
	for (int index = 0; index < 3; index++)
		log_error(" %f", v->M[index]);
	log_error(" ]\n");
}
*/

// 4d vector ///////////////////////////////////
void vector4_add(Vector4Ptr v1, Vector4Ptr v2, Vector4Ptr ret){
	ret->x = v1->x + v2->x;
	ret->y = v1->y + v2->y;
	ret->z = v1->z + v2->z;
	ret->w = 1;
}

Vector4 vector4_add(Vector4Ptr v1, Vector4Ptr v2){
	Vector4 ret;
	ret.x = v1->x + v2->x;
	ret.y = v1->y + v2->y;
	ret.z = v1->z + v2->z;
	ret.w = 1;
	return ret;
}

void vector4_sub(Vector4Ptr v1, Vector4Ptr v2, Vector4Ptr ret){
	ret->x = v1->x - v2->x;
	ret->y = v1->y - v2->y;
	ret->z = v1->z - v2->z;
	ret->w = 1;
}

Vector4 vector4_sub(Vector4Ptr v1, Vector4Ptr v2){
	Vector4 ret;
	ret.x = v1->x - v2->x;
	ret.y = v1->y - v2->y;
	ret.z = v1->z - v2->z;
	ret.w = 1;
	return ret;
}

void vector4_scale(float k, Vector4Ptr v, Vector4Ptr ret){
	ret->x = k * v->x;
	ret->y = k * v->y;
	ret->z = k * v->z;
	ret->w = 1;
}

Vector4 vector4_scale(float k, Vector4Ptr v){
	Vector4 ret;
	ret.x = k * v->x;
	ret.y = k * v->y;
	ret.z = k * v->z;
	ret.w = 1;
	return ret;
}

float vector4_dot(Vector4Ptr v1, Vector4Ptr v2){
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void vector4_cross(Vector4Ptr v1, Vector4Ptr v2, Vector4Ptr ret){
	ret->x = v1->y * v2->z - v1->z * v2->y;
	ret->y = v1->z * v2->x - v1->x * v2->z;
	ret->z = v1->x * v2->y - v1->y * v2->x;
	ret->w = 1;
}

Vector4 vector4_cross(Vector4Ptr v1, Vector4Ptr v2){
	Vector4 ret;
	ret.x = v1->y * v2->z - v1->z * v2->y;
	ret.y = v1->z * v2->x - v1->x * v2->z;
	ret.z = v1->x * v2->y - v1->y * v2->x;
	ret.w = 1;
	return ret;
}

float vector4_lenght(Vector4Ptr v){
	return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
}

float vector4_lenght_fast(Vector4Ptr v){
	return fast_distance_3d(v->x, v->y, v->z);
}

void vector4_normalize(Vector4Ptr v){
	float lenght = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	v->x = v->x * lenght_inv;
	v->y = v->y * lenght_inv;
	v->z = v->z * lenght_inv;
	v->w = 1;
}

void vector4_normalize(Vector4Ptr v, Vector4Ptr ret){
	//vector4d_zero(ret);

	float lenght = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);

	if (lenght < EPSILON_E5) return;

	float lenght_inv = 1 / lenght;

	ret->x = v->x * lenght_inv;
	ret->y = v->y * lenght_inv;
	ret->z = v->z * lenght_inv;
	ret->w = 1;
}

void vector4_print(Vector4Ptr v, const char *name){
	log_error("\n%s=[", name);
	for (int index = 0; index < 4; index++)
		log_error(" %f", v->M[index]);
	log_error(" ]\n");
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

__T2D_NS_MATH_END__