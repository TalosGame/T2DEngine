/*!
 * Filename: 	math_matrix.cpp
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 21:20
 * Author 		miller
 * Description: 
 */

#include "matrix.h"
#include <math.h>
#include "utility/log/xlog.h"
#include "mathf.h"

__T2D_NS_MATH_BEGIN__

Matrix3x3::Matrix3x3(){}

Matrix3x3::Matrix3x3(float src[3][3]){
	memcpy(M, src, sizeof(Matrix3x3));
}

Matrix3x3::Matrix3x3(float m00, float m01, float m02, 
					 float m10, float m11, float m12, 
					 float m20, float m21, float m22) : m00(m00), m01(m01), m02(m02), 
														m10(m10), m11(m11), m12(m12), 
														m20(m20), m21(m21), m22(m22) {
}

Matrix3x3::Matrix3x3(const Matrix3x3 &m) : m00(m.m00), m01(m.m01), m02(m.m02),
										   m10(m.m10), m11(m.m11), m12(m.m12),
										   m20(m.m20), m21(m.m21), m22(m.m22) {
}

Matrix3x3::~Matrix3x3(){

}

bool Matrix3x3::operator==(const Matrix3x3 &a) const{
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (!approximately(M[r][c], a.M[r][c])){
				return false;
			}
		}
	}

	return true;
}

bool Matrix3x3::operator!=(const Matrix3x3 &a) const{
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (!approximately(M[r][c], a.M[r][c])){
				return true;
			}
		}
	}

	return false;
}

float Matrix3x3::determinant(){
	return (m00 * (m11 * m22 - m21 * m12) -
			m01 * (m10 * m22 - m20 * m12) +
			m02 * (m10 * m21 - m20 * m11));
}

void Matrix3x3::transpose(){
	float	temp;
	int		i;
	int		j;

	for (i = 0; i < 3; i++) {
		for (j = i + 1; j < 3; j++) {
			temp = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = temp;
		}
	}
}

void Matrix3x3::transpose(Matrix3x3 &matrix) const{
	int	i;
	int	j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			matrix.M[i][j] = M[j][i];
		}
	}
}

Matrix3x3 Matrix3x3::inverse() const{
	float det = (m00 * (m11 * m22 - m21 * m12) -
				 m01 * (m10 * m22 - m20 * m12) +
			     m02 * (m10 * m21 - m20 * m11));

	//  if determinate is 0 then inverse doesn't exist
	if (fabs(det) < EPSILON_E5){
		return IDENTITY;
	}

	float det_inv = 1.0f / det;

	return Matrix3x3((m11 * m22 - m21 * m12) * det_inv,
					-(m22 * m01 - m21 * m02) * det_inv,
					 (m01 * m12 - m11 * m02) * det_inv,

					-(m10 * m22 - m20 * m12) * det_inv,
					 (m00 * m22 - m20 * m02) * det_inv,
					-(m00 * m12 - m10 * m02) * det_inv,

					 (m10 * m21 - m20 * m11) * det_inv,
					-(m00 * m21 - m20 * m01) * det_inv,
					 (m00 * m11 - m10 * m01) * det_inv);
}

void Matrix3x3::print(const char *name) const{
	// prints out a 3x3 matrix
	log_error("\n%s=\n", name);

	for (int r = 0; r < 3; r++, log_error("\n")){
		for (int c = 0; c < 3; c++){
			log_error("%f ", M[r][c]);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
Matrix4x4::Matrix4x4() : m00(1.0f), m01(0.0f), m02(0.0f), m03(0.0f),
						 m10(0.0f), m11(1.0f), m12(0.0f), m13(0.0f),
						 m20(0.0f), m21(0.0f), m22(1.0f), m23(0.0f),
						 m30(0.0f), m31(0.0f), m32(0.0f), m33(1.0f){
}

Matrix4x4::Matrix4x4(float src[4][4]){
	memcpy(M, src, sizeof(Matrix4x4));
}

Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03,
					 float m10, float m11, float m12, float m13,
					 float m20, float m21, float m22, float m23,
					 float m30, float m31, float m32, float m33) : m00(m00), m01(m01), m02(m02), m03(m03), 
																   m10(m10), m11(m11), m12(m12), m13(m13),
																   m20(m20), m21(m21), m22(m22), m23(m23), 
																   m30(m30), m31(m31), m32(m32), m33(m33) {
}

Matrix4x4::Matrix4x4(const Matrix4x4 &m) : m00(m.m00), m01(m.m01), m02(m.m02), m03(m.m03),
										   m10(m.m10), m11(m.m11), m12(m.m12), m13(m.m13),
										   m20(m.m20), m21(m.m21), m22(m.m22), m23(m.m23),
										   m30(m.m30), m31(m.m31), m32(m.m32), m33(m.m33) {
}

Matrix4x4::~Matrix4x4() { }

bool Matrix4x4::operator==(const Matrix4x4 &a) const{
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (!approximately(M[r][c], a.M[r][c])){
				return false;
			}
		}
	}

	return true;
}

bool Matrix4x4::operator!=(const Matrix4x4 &a) const{
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (!approximately(M[r][c], a.M[r][c])){
				return true;
			}
		}
	}

	return false;
}

float Matrix4x4::determinant(){
	// TODO
	return 0.0f;
}

void Matrix4x4::transpose(){
	float	temp;
	int		i;
	int		j;

	for (i = 0; i < 4; i++) {
		for (j = i + 1; j < 4; j++) {
			temp = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = temp;
		}
	}
}

void Matrix4x4::transpose(Matrix4x4 &matrix) const{
	int	i;
	int	j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			matrix.M[i][j] = M[j][i];
		}
	}
}

Matrix4x4 Matrix4x4::inverse() const{
	// computes the inverse of a 4x4, assumes that the last
	// row is [0 0 0 1]t
	float det = (m00 * (m11 * m22 - m21 * m12) -
				 m01 * (m10 * m22 - m20 * m12) +
			     m02 * (m10 * m21 - m20 * m11));

	// test determinate to see if it's 0
	if (fabs(det) < EPSILON_E5)
		return IDENTITY;

	float det_inv = 1.0f / det;

	float i00 = (m11 * m22 - m21 * m12) * det_inv;
	float i01 = -(m22 * m01 - m21 * m02) * det_inv;
	float i02 = (m01 * m12 - m11 * m02) * det_inv;

	float i10 = -(m10 * m22 - m20 * m12) * det_inv;
	float i11 = (m00 * m22 - m20 * m02) * det_inv;
	float i12 = -(m00 * m12 - m10 * m02) * det_inv;

	float i20 = (m10 * m21 - m20 * m11) * det_inv;
	float i21 = -(m00 * m21 - m20 * m01) * det_inv;
	float i22 = (m00 * m11 - m10 * m01) * det_inv;

	// m^-1 * m = E = 1
	float i03 = -(m03 * i00 + m13 * i01 + m23 * i02);
	float i13 = -(m03 * i10 + m13 * i11 + m23 * i12);
	float i23 = -(m03 * i20 + m13 * i21 + m23 * i22);

	return Matrix4x4(i00, i01, i02, i03,
					 i10, i11, i12, i13,
					 i20, i21, i22, i23,
					 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::ortho(float left, float right, float bottom, float top){
	return Matrix4x4(2.0f / (right - left), 0.0f, 0.0f, -(right + left) / (right - left),
					 0, 2.0f / (top - bottom), 0.0f, -(top + bottom) / (top - bottom),
					 0.0f, 0.0f, 1.0f, 0.0f,
					 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::translate(const Vector3 &a){
	return Matrix4x4(1.0f, 0.0f, 0.0f, a.x,
					 0.0f, 1.0f, 0.0f, a.y,
					 0.0f, 0.0f, 1.0f, a.z,
					 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Matrix4x4::TRS(const Vector3 &t, const Vector3 &r, const Vector3 &s){
	return IDENTITY;
}

///const matrix variable define/////////////////////////////////////////////////////////////
const Matrix3x3 Matrix3x3::IDENTITY = Matrix3x3(1.0f, 0.0f, 0.0f, 
												0.0f, 1.0f, 0.0f, 
												0.0f, 0.0f, 1.0f);

const Matrix4x4 Matrix4x4::IDENTITY = Matrix4x4(1.0f, 0.0f, 0.0f, 0.0f, 
												0.0f, 1.0f, 0.0f, 0.0f, 
												0.0f, 0.0f, 1.0f, 0.0f,
												0.0f, 0.0f, 0.0f, 1.0f);
__T2D_NS_MATH_END__
