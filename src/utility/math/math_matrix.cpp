/*!
 * Filename: 	math_matrix.cpp
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 21:20
 * Author 		miller
 * Description: 
 */

#include "math_matrix.h"

#include "utility/log/xlog.h"

#define ROTATION_X_AXIS 1
#define ROTATION_Y_AXIS 2
#define ROTATION_Z_AXIS 4

// 2*2 matrix ///////////////////////////////////
void matrix_init_m2x2(Matrix2x2Ptr m, float m00, float m01, float m10, float m11){
	m->m00 = m00; m->m01 = m01;
	m->m10 = m10; m->m11 = m11;
}

float matrix_det_m2x2(Matrix2x2Ptr m){
	return m->m00 * m->m11 - m->m01 * m->m10;
}

void matrix_add_m2x2(Matrix2x2Ptr m1, Matrix2x2Ptr m2, Matrix2x2Ptr ret){
	ret->m00 = m1->m00 + m2->m00; ret->m01 = m1->m01 + m2->m01;
	ret->m10 = m1->m10 + m2->m10; ret->m11 = m1->m11 + m2->m11;
}

void matrix_mul_m2x2(Matrix2x2Ptr m1, Matrix2x2Ptr m2, Matrix2x2Ptr ret){
	ret->m00 = m1->m00 * m2->m00 + m1->m01 * m2->m10;
	ret->m01 = m1->m00 * m2->m01 + m1->m01 * m2->m11;

	ret->m10 = m1->m10 * m2->m00 + m1->m11 * m2->m10;
	ret->m11 = m1->m10 * m2->m01 + m1->m11 * m2->m11;
}

void matrix_mul_m1x2_m2x2(Matrix1x2Ptr m1, Matrix2x2Ptr m2, Matrix1x2Ptr ret){
	for (int c = 0; c < 2; c++){
		float sum = 0.0f;
		for (int r = 0; r < 2; r++){
			sum += (m1->M[r] * m2->M[r][c]);
		}

		ret->M[c] = sum;
	}
}

int matrix_inverse_m2x2(Matrix2x2Ptr m, Matrix2x2Ptr ret){
	float det = m->m00 * m->m11 - m->m01 * m->m10;

	//  if determinate is 0 then inverse doesn't exist
	if (fabs(det) < EPSILON_E5){
		return 0;
	}

	float det_inv = 1.0f / det;

	ret->m00 = m->m11 * det_inv;
	ret->m01 = -m->m01* det_inv;
	ret->m10 = -m->m10 * det_inv;
	ret->m11 = m->m00 * det_inv;
	return 1;
}

int solve_2x2_system(Matrix2x2Ptr a, Matrix1x2Ptr x, Matrix1x2Ptr b){
    float det = matrix_det_m2x2(a);
	if (fabs(det) < EPSILON_E5){
		return 0;
	}

	Matrix2x2 a_inverse;
    matrix_inverse_m2x2(a, &a_inverse);

	matrix_mul_m1x2_m2x2(b, &a_inverse, x);
	return 1;
}

void matrix_2x2_print(Matrix2x2Ptr m, const char *name){
	// prints out a 2x2 matrix
	log_error("\n%s=\n", name);

	for (int r = 0; r < 2; r++, log_error("\n")){
		for (int c = 0; c < 2; c++){
			log_error("%f ", m->M[r][c]);
		}
	}
}

// 3*3 matrix ///////////////////////////////////
void matrix_3x3_init(Matrix3x3Ptr m, float m00, float m01, float m02,
					 float m10, float m11, float m12, 
					 float m20, float m21, float m22){
	m->m00 = m00; m->m01 = m01; m->m02 = m02;
	m->m10 = m10; m->m11 = m11; m->m12 = m12;
	m->m20 = m20; m->m21 = m21; m->m22 = m22;
}

float matrix_3x3_det(Matrix3x3Ptr m){
	return (m->m00 * (m->m11 * m->m22 - m->m21 * m->m12) -
			m->m01 * (m->m10 * m->m22 - m->m20 * m->m12) +
			m->m02 * (m->m10 * m->m21 - m->m20 * m->m11));
}

void matrix_3x3_add(Matrix3x3Ptr m1, Matrix3x3Ptr m2, Matrix3x3Ptr ret){
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			ret->M[r][c] = m1->M[r][c] + m2->M[r][c];
		}
	}
}

void matrix_3x3_mul(Matrix3x3Ptr m1, Matrix3x3Ptr m2, Matrix3x3Ptr ret){
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {

			float sum = 0.0f;
			for (int index = 0; index < 3; index++) {
				sum += (m1->M[r][index] * m2->M[index][c]);
			}

			ret->M[r][c] = sum;
		}
	}
}

void matrix_1x3_3x3_mul(Matrix1x3Ptr m1, Matrix3x3Ptr m2, Matrix1x3Ptr ret){
	for (int c = 0; c < 3; c++){
		float sum = 0.0f;
		for (int r = 0; r < 3; r++){
			sum += (m1->M[r] * m2->M[r][c]);
		}

		ret->M[c] = sum;
	}
}

int matrix_3x3_inverse(Matrix3x3Ptr m, Matrix3x3Ptr ret){
	float det = (m->m00 * (m->m11 * m->m22 - m->m21 * m->m12) -
				 m->m01 * (m->m10 * m->m22 - m->m20 * m->m12) +
				 m->m02 * (m->m10 * m->m21 - m->m20 * m->m11));

	//  if determinate is 0 then inverse doesn't exist
	if (fabs(det) < EPSILON_E5){
		return 0;
	}

	float det_inv = 1.0f / det;

	ret->m00 = (m->m11 * m->m22 - m->m21 * m->m12) * det_inv;
	ret->m01 = -(m->m22 * m->m01 - m->m21 * m->m02) * det_inv;
	ret->m02 = (m->m01 * m->m12 - m->m11 * m->m02) * det_inv;

	ret->m10 = -(m->m10 * m->m22 - m->m20 * m->m12) * det_inv;
	ret->m11 = (m->m00 * m->m22 - m->m20 * m->m02) * det_inv;
	ret->m12 = -(m->m00 * m->m12 - m->m10 * m->m02) * det_inv;

	ret->m20 = (m->m10 * m->m21 - m->m20 * m->m11) * det_inv;
	ret->m21 = -(m->m00 * m->m21 - m->m20 * m->m01) * det_inv;
	ret->m22 = (m->m00 * m->m11 - m->m10 * m->m01) * det_inv;

	return 1;
}

int solve_3x3_system(Matrix3x3Ptr a, Matrix1x3Ptr x, Matrix1x3Ptr b){
	float det = matrix_3x3_det(a);
	if (fabs(det) < EPSILON_E5){
		return 0;
	}

	Matrix3x3 a_inverse;
	matrix_3x3_inverse(a, &a_inverse);

	matrix_1x3_3x3_mul(b, &a_inverse, x);
	return 1;
}

void matrix_3x3_print(Matrix3x3Ptr m, const char *name){
	// prints out a 3x3 matrix
	log_error("\n%s=\n", name);

	for (int r = 0; r < 3; r++, log_error("\n")){
		for (int c = 0; c < 3; c++){
			log_error("%f ", m->M[r][c]);
		}
	}
}

// 4*4 matrix ///////////////////////////////////
void matrix_4x4_init(Matrix4x4Ptr m, float m00, float m01, float m02, float m03,
					 float m10, float m11, float m12, float m13,
					 float m20, float m21, float m22, float m23,
					 float m30, float m31, float m32, float m33){
	m->m00 = m00; m->m01 = m01; m->m02 = m02; m->m03 = m03;
	m->m10 = m10; m->m11 = m11; m->m12 = m12; m->m13 = m13;
	m->m20 = m20; m->m21 = m21; m->m22 = m22; m->m23 = m23;
	m->m30 = m31; m->m31 = m31; m->m32 = m32; m->m33 = m33;
}

void matrix_4x4_add(Matrix4x4Ptr m1, Matrix4x4Ptr m2, Matrix4x4Ptr ret){
	for (int r = 0; r < 4; r++){
		for (int c = 0; c < 4; c++) {
			ret->M[r][c] = m1->M[r][c] + m2->M[r][c];
		}
	}
}

void matrix_4x4_mul(Matrix4x4Ptr m1, Matrix4x4Ptr m2, Matrix4x4Ptr ret){
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {

			float sum = 0.0f;
			for (int index = 0; index < 4; index++) {
				sum += (m1->M[r][index] * m2->M[index][c]);
			}

			ret->M[r][c] = sum;
		}
	}
}

void matrix_1x4_4x4_mul(Matrix1x4Ptr m1, Matrix4x4Ptr m2, Matrix1x4Ptr ret){
	for (int c = 0; c < 4; c++) {
		
		float sum = 0.0f;
		for (int r = 0; r < 4; r++) {
			sum += (m1->M[r] * m2->M[r][c]);
		}

		ret->M[c] = sum;
	}
}

void matrix_vector3_4x4_mul(Vector3Ptr v, Matrix4x4Ptr m, Vector3Ptr ret) {
	for (int c = 0; c < 3; c++) {

		float sum = 0;
		int r = 0;
		for (; r < 3; r++) {
			sum += (v->M[r] * m->M[r][c]);
		}

		// add in last element in column or w*mb[3][col]
		sum += m->M[r][c];

		ret->M[c] = sum;
	}
}

void matrix_vector3_4x3_mul(Vector3Ptr v, Matrix4x3Ptr m, Vector3Ptr ret) {
	for (int c = 0; c < 3; c++) {

		float sum = 0;
		int r = 0;
		for (; r < 3; r++) {
			sum += (v->M[r] * m->M[r][c]);
		}

		// add in last element in column or w*mb[3][col]
		sum += m->M[r][c];

		ret->M[c] = sum;
	}
}

void matrix_vector4_4x4_mul(Vector4Ptr v, Matrix4x4Ptr m, Vector4Ptr ret, bool div_w) {
	for (int c = 0; c < 4; c++) {

		float sum = 0;
		for (int r = 0; r < 4; r++) {
			sum += (v->M[r] * m->M[r][c]);
		}

		ret->M[c] = sum;
	}

	if (!div_w || ret->M[3] == 0) return;

	for (int c = 0; c < 3; c++) {
		ret->M[c] /= ret->M[3];
	}
}

void matrix_vector4_4x3_mul(Vector4Ptr v, Matrix4x4Ptr m, Vector4Ptr ret) {
	for (int c = 0; c < 3; c++) {

		float sum = 0;
		for (int r = 0; r < 4; r++) {
			sum += (v->M[r] * m->M[r][c]);
		}

		ret->M[c] = sum;
	}
}

int matrix_4x4_inverse(Matrix4x4Ptr m, Matrix4x4Ptr ret){
	// computes the inverse of a 4x4, assumes that the last
	// column is [0 0 0 1]t
	float det = (m->m00 * (m->m11 * m->m22 - m->m12 * m->m21) -
				  m->m01 * (m->m10 * m->m22 - m->m12 * m->m20) +
				  m->m02 * (m->m10 * m->m21 - m->m11 * m->m20));

	// test determinate to see if it's 0
	if (fabs( det ) < EPSILON_E5)
		return(0);

	float det_inv = 1.0f / det;

	ret->m00 = det_inv * (m->m11 * m->m22 - m->m12 * m->m21);
	ret->m01 = -det_inv * (m->m01 * m->m22 - m->m02 * m->m21);
	ret->m02 = det_inv * (m->m01 * m->m12 - m->m02 * m->m11);
	ret->m03 = 0.0f; // always 0

	ret->m10 = -det_inv * (m->m10 * m->m22 - m->m12 * m->m20);
	ret->m11 = det_inv * (m->m00 * m->m22 - m->m02 * m->m20);
	ret->m12 = -det_inv * (m->m00 * m->m12 - m->m02 * m->m10);
	ret->m13 = 0.0f; // always 0

	ret->m20 = det_inv * (m->m10 * m->m21 - m->m11 * m->m20);
	ret->m21 = -det_inv * (m->m00 * m->m21 - m->m01 * m->m20);
	ret->m22 = det_inv * (m->m00 * m->m11 - m->m01 * m->m10);
	ret->m23 = 0.0f; // always 0

	ret->m30 = -(m->m30 * ret->m00 + m->m31 * ret->m10 + m->m32 * ret->m20);
	ret->m31 = -(m->m30 * ret->m01 + m->m31 * ret->m11 + m->m32 * ret->m21);
	ret->m32 = -(m->m30 * ret->m02 + m->m31 * ret->m12 + m->m32 * ret->m22);
	ret->m33 = 1.0f; // always 0

	// return success 
	return(1);
}

void matrix_4x4_rotation(float theta_x, float theta_y, float theta_z, Matrix4x4Ptr ret) {
	Matrix4x4 mx, my;
	float sin_theta = 0, cos_theta = 0;
	int rot_seq = 0;

	MAT_4X4_IDENTITY(ret);
	
	if (theta_x > EPSILON_E5) {
		rot_seq |= ROTATION_X_AXIS;
	}

	if (theta_y > EPSILON_E5) {
		rot_seq |= ROTATION_Y_AXIS;
	}

	if (theta_z > EPSILON_E5) {
		rot_seq |= ROTATION_Z_AXIS;
	}

	switch (rot_seq) {
		case ROTATION_X_AXIS:{
			cos_theta = fast_cos(theta_x);
			sin_theta = fast_sin(theta_x);

			// set the matrix up 
			matrix_4x4_init(&mx, 1, 0,		    0,		   0,
								 0, cos_theta,  sin_theta, 0,
								 0, -sin_theta, cos_theta, 0,
								 0, 0,		    0,		   1);

			MAT_4X4_COPY(ret, &mx);
		}break;
		case ROTATION_Y_AXIS:{
			cos_theta = fast_cos(theta_y); 
			sin_theta = fast_sin(theta_y);

			// set the matrix up 
			matrix_4x4_init(&my, cos_theta, 0, -sin_theta, 0,
								 0,			1, 0,		   0,
								 sin_theta, 0, cos_theta,  0,
								 0,			0, 0,		   1);

			MAT_4X4_COPY(ret, &my);
		}break;
		case ROTATION_Z_AXIS:{
		}break;
		case (ROTATION_X_AXIS | ROTATION_Y_AXIS) : {
		}break;
	}
}

void matrix_4x4_print(Matrix4x4Ptr m, const char *name){
	// prints out a 3x3 matrix
	log_error( "\n%s=\n", name );

	for (int r = 0; r < 4; r++, log_error( "\n" )) {
		for (int c = 0; c < 4; c++) {
			log_error( "%f ", m->M[r][c] );
		}
	}
}
