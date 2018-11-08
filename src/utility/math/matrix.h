/*!
 * Filename: 	math_matrix.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 21:06
 * Author 		miller
 * Description: 
 * vector & matrix right by matrix
 */ 

#ifndef __T2D_ENGINE_MATH_MATRIX_H__
#define __T2D_ENGINE_MATH_MATRIX_H__

#include <string.h>
#include "vector.h"

///Matrix3x3 ///////////////////////////////////////////////////////////////////////
struct Matrix3x3
{
	Matrix3x3();
	explicit Matrix3x3(float src[3][3]);
	Matrix3x3(float m00, float m01, float m02, float m10, float m11, float m12, 
			  float m20, float m21, float m22);
	Matrix3x3(const Matrix3x3 &m);
	~Matrix3x3();

	float operator[](int index) const;
	float &operator[](const int index);
	
	float operator()(int r, int c) const;
	float &operator()(int r, int c);

	Vector3 operator*(const Vector3 &vec) const;
	Matrix3x3 operator*(const Matrix3x3 &a) const;
	Matrix3x3 operator*(float a) const;

	Matrix3x3 operator+(const Matrix3x3 &a) const;
	Matrix3x3 operator-(const Matrix3x3 &a) const;

	Matrix3x3 &operator*=(float a);
	Matrix3x3 &operator+=(Matrix3x3 const &a);
	Matrix3x3 &operator-=(Matrix3x3 const &a);

	bool operator==(const Matrix3x3 &a) const;
	bool operator!=(const Matrix3x3 &a) const;

	float determinant();
	void transpose();
	void transpose(Matrix3x3 &matrix) const;
	Matrix3x3 inverse() const;
	void identity();

	void print(const char *name) const;

	union {
		float M[3][3];
	
		struct {
			float m00, m01, m02;
			float m10, m11, m12;
			float m20, m21, m22;
		};
	};

	static const Matrix3x3 IDENTITY;
};

inline float Matrix3x3::operator[](int index) const{
	return (&m00)[index];
}

inline float &Matrix3x3::operator[](const int index){
	return (&m00)[index];
}

inline float Matrix3x3::operator()(int r, int c) const{
	return M[r][c];
}

inline float &Matrix3x3::operator()(int r, int c){
	return M[r][c];
}

inline Vector3 Matrix3x3::operator*(const Vector3 &vec) const{
	return Vector3(M[0][0] * vec.x + M[0][1] * vec.y + M[0][2] * vec.z,
				   M[1][0] * vec.x + M[1][1] * vec.y + M[1][2] * vec.z,
				   M[2][0] * vec.x + M[2][1] * vec.y + M[2][2] * vec.z);
}

inline Matrix3x3 Matrix3x3::operator*(const Matrix3x3 &a) const{
	return Matrix3x3(M[0][0] * a.M[0][0] + M[0][1] * a.M[1][0] + M[0][2] * a.M[2][0],
					 M[0][0] * a.M[0][1] + M[0][1] * a.M[1][1] + M[0][2] * a.M[2][1], 
					 M[0][0] * a.M[0][2] + M[0][1] * a.M[1][2] + M[0][2] * a.M[2][2],

					 M[1][0] * a.M[0][0] + M[1][1] * a.M[1][0] + M[1][2] * a.M[2][0],
					 M[1][0] * a.M[0][1] + M[1][1] * a.M[1][1] + M[1][2] * a.M[2][1],
					 M[1][0] * a.M[0][2] + M[1][1] * a.M[1][2] + M[1][2] * a.M[2][2], 
					 
					 M[2][0] * a.M[0][0] + M[2][1] * a.M[1][0] + M[2][2] * a.M[2][0], 
					 M[2][0] * a.M[0][1] + M[2][1] * a.M[1][1] + M[2][2] * a.M[2][1], 
					 M[2][0] * a.M[0][2] + M[2][1] * a.M[1][2] + M[2][2] * a.M[2][2]);
}

inline Matrix3x3 Matrix3x3::operator*(float a) const{
	return Matrix3x3(M[0][0] * a, M[0][1] * a, M[0][2] * a,
					 M[1][0] * a, M[1][1] * a, M[1][2] * a,
					 M[2][0] * a, M[2][1] * a, M[2][2] * a);
}

inline Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &a) const{
	return Matrix3x3(M[0][0] + a.M[0][0], M[0][1] + a.M[0][1], M[0][2] + a.M[0][2],
					 M[1][0] + a.M[1][0], M[1][1] + a.M[1][1], M[1][2] + a.M[1][2],
					 M[2][0] + a.M[2][0], M[2][1] + a.M[2][1], M[2][2] + a.M[2][2]);
}

inline Matrix3x3 Matrix3x3::operator-(const Matrix3x3 &a) const{
	return Matrix3x3(M[0][0] - a.M[0][0], M[0][1] - a.M[0][1], M[0][2] - a.M[0][2],
					 M[1][0] - a.M[1][0], M[1][1] - a.M[1][1], M[1][2] - a.M[1][2],
					 M[2][0] - a.M[2][0], M[2][1] - a.M[2][1], M[2][2] - a.M[2][2]);
}

inline Vector3 operator*(const Vector3 &vec, const Matrix3x3 &mat) {
	return Vector3(mat.M[0][0] * vec.x + mat.M[0][1] * vec.y + mat.M[0][2] * vec.z,
				   mat.M[1][0] * vec.x + mat.M[1][1] * vec.y + mat.M[1][2] * vec.z,
				   mat.M[2][0] * vec.x + mat.M[2][1] * vec.y + mat.M[2][2] * vec.z);
}

inline Matrix3x3 operator*(float a, const Matrix3x3 &mat){
	return Matrix3x3(mat.M[0][0] * a, mat.M[0][1] * a, mat.M[0][2] * a,
					 mat.M[1][0] * a, mat.M[1][1] * a, mat.M[1][2] * a,
					 mat.M[2][0] * a, mat.M[2][1] * a, mat.M[2][2] * a);
}

inline Matrix3x3 &Matrix3x3::operator*=(float a){
	M[0][0] *= a; M[0][1] *= a; M[0][2] *= a;
	M[1][0] *= a; M[1][1] *= a; M[1][2] *= a;
	M[2][0] *= a; M[2][1] *= a; M[2][2] *= a;
	return *this;
}

inline Matrix3x3 &Matrix3x3::operator+=(Matrix3x3 const &a){
	M[0][0] += a.M[0][0]; M[0][1] += a.M[0][1]; M[0][2] += a.M[0][2];
	M[1][0] += a.M[1][0]; M[1][1] += a.M[1][1]; M[1][2] += a.M[1][2];
	M[2][0] += a.M[2][0]; M[2][1] += a.M[2][1]; M[2][2] += a.M[2][2];
	return *this;
}

inline Matrix3x3 &Matrix3x3::operator-=(Matrix3x3 const &a){
	M[0][0] -= a.M[0][0]; M[0][1] -= a.M[0][1]; M[0][2] -= a.M[0][2];
	M[1][0] -= a.M[1][0]; M[1][1] -= a.M[1][1]; M[1][2] -= a.M[1][2];
	M[2][0] -= a.M[2][0]; M[2][1] -= a.M[2][1]; M[2][2] -= a.M[2][2];
	return *this;
}

inline void Matrix3x3::identity() {
	M[0][0] = 1.f; M[0][1] = 0.f; M[0][2] = 0.f;
	M[1][0] = 0.f; M[1][1] = 1.f; M[1][2] = 0.f;
	M[2][0] = 0.f; M[2][1] = 0.f; M[2][2] = 1.f;
}

inline bool matrix_to_euler(const Matrix3x3 &m, Vector3 &v){
	// YXZ order
	if (m.m12 < 0.999F) // some fudge for imprecision
	{
		if (m.m12 > -0.999F) // some fudge for imprecision
		{
			v.x = asin(-m.m12);
			v.y = atan2(m.m02, m.m22);
			v.z = atan2(m.m10, m.m11);
			return true;
		}
		else
		{
			// WARNING.  Not unique.  YA - ZA = atan2(r01,r00)
			v.x = PI * 0.5F;
			v.y = atan2(m.m01, m.m00);
			v.z = 0.0F;
			return false;
		}
	}
	else
	{
		// WARNING.  Not unique.  YA + ZA = atan2(-r01,r00)
		v.x = -PI * 0.5F;
		v.y = atan2(-m.m01, m.m00);
		v.z = 0.0F;
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////
struct Matrix4x4
{
	Matrix4x4();
	explicit Matrix4x4(float src[4][4]);
	Matrix4x4(float m00, float m01, float m02, float m03,
			  float m10, float m11, float m12, float m13,
			  float m20, float m21, float m22, float m23, 
			  float m30, float m31, float m32, float m33);
	Matrix4x4(const Matrix4x4 &m);
	~Matrix4x4();

	float operator[](int index) const;
	float &operator[](const int index);

	float operator()(int r, int c) const;
	float &operator()(int r, int c);

	Vector3 operator*(const Vector3 &vec) const;
	Matrix4x4 operator*(const Matrix4x4 &a) const;
	Matrix4x4 operator*(float a) const;

	Matrix4x4 operator+(const Matrix4x4 &a) const;
	Matrix4x4 operator-(const Matrix4x4 &a) const;

	Matrix4x4 &operator*=(float a);
	Matrix4x4 &operator+=(Matrix4x4 const &a);
	Matrix4x4 &operator-=(Matrix4x4 const &a);

	bool operator==(const Matrix4x4 &a) const;
	bool operator!=(const Matrix4x4 &a) const;

	float determinant();
	void transpose();
	void transpose(Matrix4x4 &matrix) const;
	Matrix4x4 inverse() const;
	void identity();

	void print(const char *name) const;

	static Matrix4x4 ortho(float left, float right, float bottom, float top, float near, float far);
	static Matrix4x4 translate(const Vector3 &a);
	static Matrix4x4 TRS(const Vector3 &t, const Vector3 &r, const Vector3 &s);

	union {
		float M[4][4];

		struct {
			float m00, m01, m02, m03;
			float m10, m11, m12, m13;
			float m20, m21, m22, m23;
			float m30, m31, m32, m33;
		};
	};

	static const Matrix4x4 IDENTITY;
};

inline float Matrix4x4::operator[](int index) const{
	return (&m00)[index];
}

inline float &Matrix4x4::operator[](const int index){
	return (&m00)[index];
}

inline float Matrix4x4::operator()(int r, int c) const{
	return M[r][c];
}

inline float &Matrix4x4::operator()(int r, int c){
	return M[r][c];
}

inline Vector3 Matrix4x4::operator*(const Vector3 &vec) const{
	return Vector3(M[0][0] * vec.x + M[0][1] * vec.y + M[0][2] * vec.z + M[0][3],
				   M[1][0] * vec.x + M[1][1] * vec.y + M[1][2] * vec.z + M[1][3],
				   M[2][0] * vec.x + M[2][1] * vec.y + M[2][2] * vec.z + M[2][3]);
}

inline Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &a) const{
	return Matrix4x4(M[0][0] * a.M[0][0] + M[0][1] * a.M[1][0] + M[0][2] * a.M[2][0] + M[0][3] * a.M[3][0],
					 M[0][0] * a.M[0][1] + M[0][1] * a.M[1][1] + M[0][2] * a.M[2][1] + M[0][3] * a.M[3][1],
					 M[0][0] * a.M[0][2] + M[0][1] * a.M[1][2] + M[0][2] * a.M[2][2] + M[0][3] * a.M[3][2],
					 M[0][0] * a.M[0][3] + M[0][1] * a.M[1][3] + M[0][2] * a.M[2][3] + M[0][3] * a.M[3][3],

					 M[1][0] * a.M[0][0] + M[1][1] * a.M[1][0] + M[1][2] * a.M[2][0] + M[1][3] * a.M[3][0],
					 M[1][0] * a.M[0][1] + M[1][1] * a.M[1][1] + M[1][2] * a.M[2][1] + M[1][3] * a.M[3][1],
					 M[1][0] * a.M[0][2] + M[1][1] * a.M[1][2] + M[1][2] * a.M[2][2] + M[1][3] * a.M[3][2],
					 M[1][0] * a.M[0][3] + M[1][1] * a.M[1][3] + M[1][2] * a.M[2][3] + M[1][3] * a.M[3][3],

					 M[2][0] * a.M[0][0] + M[2][1] * a.M[1][0] + M[2][2] * a.M[2][0] + M[2][3] * a.M[3][0],
					 M[2][0] * a.M[0][1] + M[2][1] * a.M[1][1] + M[2][2] * a.M[2][1] + M[2][3] * a.M[3][1],
					 M[2][0] * a.M[0][2] + M[2][1] * a.M[1][2] + M[2][2] * a.M[2][2] + M[2][3] * a.M[3][2],
					 M[2][0] * a.M[0][3] + M[2][1] * a.M[1][3] + M[2][2] * a.M[2][3] + M[2][3] * a.M[3][3],

					 M[3][0] * a.M[0][0] + M[3][1] * a.M[1][0] + M[3][2] * a.M[2][0] + M[3][3] * a.M[3][0],
					 M[3][0] * a.M[0][1] + M[3][1] * a.M[1][1] + M[3][2] * a.M[2][1] + M[3][3] * a.M[3][1],
					 M[3][0] * a.M[0][2] + M[3][1] * a.M[1][2] + M[3][2] * a.M[2][2] + M[3][3] * a.M[3][2],
					 M[3][0] * a.M[0][3] + M[3][1] * a.M[1][3] + M[3][2] * a.M[2][3] + M[3][3] * a.M[3][3]);
}

inline Matrix4x4 Matrix4x4::operator*(float a) const{
	return Matrix4x4(M[0][0] * a, M[0][1] * a, M[0][2] * a, M[0][3] * a,
					 M[1][0] * a, M[1][1] * a, M[1][2] * a, M[1][3] * a,
					 M[2][0] * a, M[2][1] * a, M[2][2] * a, M[2][3] * a,
					 M[3][0] * a, M[3][1] * a, M[3][2] * a, M[3][3] * a);
}

inline Vector3 operator*(const Vector3 &vec, const Matrix4x4 &mat) {
	return Vector3(mat.M[0][0] * vec.x + mat.M[0][1] * vec.y + mat.M[0][2] * vec.z + mat.M[0][3],
				   mat.M[1][0] * vec.x + mat.M[1][1] * vec.y + mat.M[1][2] * vec.z + mat.M[1][3],
				   mat.M[2][0] * vec.x + mat.M[2][1] * vec.y + mat.M[2][2] * vec.z + mat.M[2][3]);
}

inline Matrix4x4 operator*(float a, const Matrix4x4 &mat){
	return Matrix4x4(mat.M[0][0] * a, mat.M[0][1] * a, mat.M[0][2] * a, mat.M[0][3] * a,
					 mat.M[1][0] * a, mat.M[1][1] * a, mat.M[1][2] * a, mat.M[1][3] * a,
					 mat.M[2][0] * a, mat.M[2][1] * a, mat.M[2][2] * a, mat.M[2][3] * a, 
					 mat.M[3][0] * a, mat.M[3][1] * a, mat.M[3][2] * a, mat.M[3][3] * a);
}

inline Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &a) const{
	return Matrix4x4(M[0][0] + a.M[0][0], M[0][1] + a.M[0][1], M[0][2] + a.M[0][2], M[0][3] + a.M[0][3],
					 M[1][0] + a.M[1][0], M[1][1] + a.M[1][1], M[1][2] + a.M[1][2], M[1][3] + a.M[1][3],
					 M[2][0] + a.M[2][0], M[2][1] + a.M[2][1], M[2][2] + a.M[2][2], M[2][3] + a.M[2][3], 
					 M[3][0] + a.M[3][0], M[2][1] + a.M[3][1], M[3][2] + a.M[3][2], M[3][3] + a.M[3][3]);
}

inline Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &a) const{
	return Matrix4x4(M[0][0] - a.M[0][0], M[0][1] - a.M[0][1], M[0][2] - a.M[0][2], M[0][3] - a.M[0][3],
					 M[1][0] - a.M[1][0], M[1][1] - a.M[1][1], M[1][2] - a.M[1][2], M[1][3] - a.M[1][3],
					 M[2][0] - a.M[2][0], M[2][1] - a.M[2][1], M[2][2] - a.M[2][2], M[2][3] - a.M[2][3],
					 M[3][0] - a.M[3][0], M[2][1] - a.M[3][1], M[3][2] - a.M[3][2], M[3][3] - a.M[3][3]);
}

inline Matrix4x4 &Matrix4x4::operator*=(float a){
	M[0][0] *= a; M[0][1] *= a; M[0][2] *= a; M[0][3] *= a;
	M[1][0] *= a; M[1][1] *= a; M[1][2] *= a; M[1][3] *= a;
	M[2][0] *= a; M[2][1] *= a; M[2][2] *= a; M[2][3] *= a;
	M[3][0] *= a; M[3][1] *= a; M[3][2] *= a; M[3][3] *= a;
	return *this;
}

inline Matrix4x4 &Matrix4x4::operator+=(Matrix4x4 const &a){
	M[0][0] += a.M[0][0]; M[0][1] += a.M[0][1]; M[0][2] += a.M[0][2]; M[0][3] += a.M[0][3];
	M[1][0] += a.M[1][0]; M[1][1] += a.M[1][1]; M[1][2] += a.M[1][2]; M[1][3] += a.M[1][3];
	M[2][0] += a.M[2][0]; M[2][1] += a.M[2][1]; M[2][2] += a.M[2][2]; M[2][3] += a.M[2][3];
	M[3][0] += a.M[3][0]; M[3][1] += a.M[3][1]; M[3][2] += a.M[3][2]; M[3][3] += a.M[3][3];
	return *this;
}

inline Matrix4x4 &Matrix4x4::operator-=(Matrix4x4 const &a){
	M[0][0] -= a.M[0][0]; M[0][1] -= a.M[0][1]; M[0][2] -= a.M[0][2]; M[0][3] -= a.M[0][3];
	M[1][0] -= a.M[1][0]; M[1][1] -= a.M[1][1]; M[1][2] -= a.M[1][2]; M[1][3] -= a.M[1][3];
	M[2][0] -= a.M[2][0]; M[2][1] -= a.M[2][1]; M[2][2] -= a.M[2][2]; M[2][3] -= a.M[2][3];
	M[3][0] -= a.M[3][0]; M[3][1] -= a.M[3][1]; M[3][2] -= a.M[3][2]; M[3][3] -= a.M[3][3];
	return *this;
}

inline void Matrix4x4::identity(){
	M[0][0] = 1.f; M[0][1] = 0.f; M[0][2] = 0.f; M[0][3] = 0.f;
	M[1][0] = 0.f; M[1][1] = 1.f; M[1][2] = 0.f; M[1][3] = 0.f;
	M[2][0] = 0.f; M[2][1] = 0.f; M[2][2] = 1.f; M[2][3] = 0.f;
	M[2][0] = 0.f; M[2][1] = 0.f; M[2][2] = 0.f; M[2][3] = 1.f;
}

#endif //__T2D_ENGINE_MATH_MATRIX_H__