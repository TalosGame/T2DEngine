/**************************************************************
*  Filename :    math_vector.h
*  Author   :    miller
*  Data     :    2018/5/23
*  Desc     : 
**************************************************************/

#ifndef __XENGINE_MATH_VECTOR_H__
#define __XENGINE_MATH_VECTOR_H__

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

// 3d vector ///////////////////////////////////
void vector3_add(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret);
Vector3 vector3_add(Vector3Ptr v1, Vector3Ptr v2);
void vector3_sub(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret);
Vector3 vector3_sub(Vector3Ptr v1, Vector3Ptr v2);
void vector3_scale(float k, Vector3Ptr v, Vector3Ptr ret);
Vector3 vector3_scale(float k, Vector3Ptr v);
float vector3_dot(Vector3Ptr v1, Vector3Ptr v2);
void vector3_cross(Vector3Ptr v1, Vector3Ptr v2, Vector3Ptr ret);
Vector3 vector3_cross(Vector3Ptr v1, Vector3Ptr v2);
float vector3_lenght(Vector3Ptr v);
float vector3_lenght_fast(Vector3Ptr v);
void vector3_normalize(Vector3Ptr v);
void vector3_normalize(Vector3Ptr v, Vector3Ptr ret);
void vector3_print(Vector3Ptr v, const char *name);

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


#endif // __XENGINE_MATH_VECTOR_H__