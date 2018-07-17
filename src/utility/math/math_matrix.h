/*!
 * Filename: 	math_matrix.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 21:06
 * Author 		miller
 * Description: 
 */

#ifndef __T2D_ENGINE_MATH_MATRIX_H__
#define __T2D_ENGINE_MATH_MATRIX_H__

#include <string.h>
#include "mathf.h"

typedef struct _Matrix4x4 {
	union {
		float M[4][4];

		struct {
			float m00, m01, m02, m03;
			float m10, m11, m12, m13;
			float m20, m21, m22, m23;
			float m30, m31, m32, m33;
		};
	};
}Matrix4x4, *Matrix4x4Ptr;

typedef struct _Matrix4x3 {
	union {
		float M[4][3];

		struct {
			float m00, m01, m02;
			float m10, m11, m12;
			float m20, m21, m22;
			float m30, m31, m32;
		};
	};
}Matrix4x3, *Matrix4x3Ptr;

typedef struct _Matrix1x4 {
	union {
		float M[4];

		struct {
			float m00, m01, m02, m03;
		};
	};
}Matrix1x4, *Matrix1x4Ptr;

typedef struct _Matrix3x3 {
	union {
		float M[3][3];

		struct {
			float m00, m01, m02;
			float m10, m11, m12;
			float m20, m21, m22;
		};
	};
}Matrix3x3, *Matrix3x3Ptr;

typedef struct _Matrix3x2 {
	union {
		float M[3][2];

		struct {
			float m00, m01;
			float m10, m11;
			float m20, m21;
		};
	};
}Matrix3x2, *Matrix3x2Ptr;

typedef struct _Matrix1x3 {
	union {
		float M[3];

		struct {
			float m00, m01, m02;
		};
	};
}Matrix1x3, *Matrix1x3Ptr;

typedef struct _Matrix2x2 {
	union {
		float M[2][2];

		struct {
			float m00, m01;
			float m10, m11;
		};
	};
}Matrix2x2, *Matrix2x2Ptr;

typedef struct _Matrix1x2 {
	union {
		float M[2];

		struct {
			float m00, m01;
		};
	};
}Matrix1x2, *Matrix1x2Ptr;

// identity matrices /////////////////////////////////

// 4x4 identity matrix
const Matrix4x4 IMAT_4X4 = { 1, 0, 0, 0,
0, 1, 0, 0,
0, 0, 1, 0,
0, 0, 0, 1 };

// 4x3 identity matrix
const Matrix4x3 IMAT_4X3 = { 1, 0, 0,
0, 1, 0,
0, 0, 1,
0, 0, 0 };

// 3x3 identity matrix
const Matrix3x3 IMAT_3X3 = { 1, 0, 0,
0, 1, 0,
0, 0, 1 };


// 2x2 identity matrix
const Matrix2x2 IMAT_2X2 = { 1, 0,
0, 1 };

// MACROS, SMALL INLINE FUNCS /////////////////////////////////

#define MAT_2X2_ZERO(m) (memset((void*)m, 0, sizeof(Matrix2x2)))
#define MAT_3X3_ZERO(m) (memset((void*)m, 0, sizeof(Matrix3x3)))
#define MAT_4X4_ZERO(m) (memset((void*)m, 0, sizeof(Matrix4x4)))
#define MAT_4X3_ZERO(m) (memset((void*)m, 0, sizeof(Matrix4x3)))

#define MAT_4X4_IDENTITY(m) (memcpy((void*)m, &IMAT_4X4, sizeof(Matrix4x4)))
#define MAT_4X3_IDENTITY(m) (memcpy((void*)m, &IMAT_4X3, sizeof(Matrix4x3)))
#define MAT_3X3_IDENTITY(m) (memcpy((void*)m, &IMAT_3X3, sizeof(Matrix3x3)))
#define MAT_2X2_IDENTITY(m) (memcpy((void*)m, &IMAT_2X2, sizeof(Matrix2x2)))

#define MAT_4X4_COPY(dst_mat, src_mat) (memcpy((void*)dst_mat, (void*)src_mat, sizeof(Matrix4x4)))
#define MAT_4X3_COPY(dst_mat, src_mat) (memcpy((void*)dst_mat, (void*)src_mat, sizeof(Matrix4x3)))
#define MAT_3X3_COPY(dst_mat, src_mat) (memcpy((void*)dst_mat, (void*)src_mat, sizeof(Matrix3x3)))
#define MAT_2X2_COPY(dst_mat, src_mat) (memcpy((void*)dst_mat, (void*)src_mat, sizeof(Matrix2x2)))

// matrix transposing macros
inline void matrix_transpose_3x3(Matrix3x3Ptr m) {
	Matrix3x3 mt;
	mt.m00 = m->m00; mt.m01 = m->m10; mt.m02 = m->m20;
	mt.m10 = m->m01; mt.m11 = m->m11; mt.m12 = m->m21;
	mt.m20 = m->m02; mt.m21 = m->m12; mt.m22 = m->m22;
	memcpy((void*)m, (void*)&mt, sizeof(Matrix3x3));
}

inline void matrix_transpose_3x3(Matrix3x3Ptr m, Matrix3x3Ptr ret) {
	ret->m00 = m->m00; ret->m01 = m->m10; ret->m02 = m->m20;
	ret->m10 = m->m01; ret->m11 = m->m11; ret->m12 = m->m21;
	ret->m20 = m->m02; ret->m21 = m->m12; ret->m22 = m->m22;
}

inline void matrix_4x4_transpose(Matrix4x4Ptr m) {
	Matrix4x4 mt;
	mt.m00 = m->m00; mt.m01 = m->m10; mt.m02 = m->m20; mt.m03 = m->m30;
	mt.m10 = m->m01; mt.m11 = m->m11; mt.m12 = m->m21; mt.m13 = m->m31;
	mt.m20 = m->m02; mt.m21 = m->m12; mt.m22 = m->m22; mt.m23 = m->m32;
	mt.m30 = m->m03; mt.m31 = m->m13; mt.m32 = m->m23; mt.m33 = m->m33;
	memcpy((void*)m, (void*)&mt, sizeof(Matrix4x4));
}

inline void matrix_4x4_transpose(Matrix4x4Ptr m, Matrix4x4Ptr ret) {
	ret->m00 = m->m00; ret->m01 = m->m10; ret->m02 = m->m20; ret->m03 = m->m30;
	ret->m10 = m->m01; ret->m11 = m->m11; ret->m12 = m->m21; ret->m13 = m->m31;
	ret->m20 = m->m02; ret->m21 = m->m12; ret->m22 = m->m22; ret->m23 = m->m32;
	ret->m30 = m->m03; ret->m31 = m->m13; ret->m32 = m->m23; ret->m33 = m->m33;
}

// matrix and vector column swaping macros
inline void matrix_2x2_col_swap(Matrix2x2Ptr m, int c, Matrix1x2Ptr v) {
	m->M[0][c] = v->M[0];
	m->M[1][c] = v->M[1];
}

inline void matrix_3x3_col_swap(Matrix3x3Ptr m, int c, Matrix1x3Ptr v) {
	m->M[0][c] = v->M[0];
	m->M[1][c] = v->M[1];
	m->M[2][c] = v->M[2];
}

inline void matrix_4x4_col_swap(Matrix4x4Ptr m, int c, Matrix1x3Ptr v) {
	m->M[0][c] = v->M[0];
	m->M[1][c] = v->M[1];
	m->M[2][c] = v->M[2];
	m->M[3][c] = v->M[3];
}

inline void matrix_4x3_col_swap(Matrix4x4Ptr m, int c, Matrix1x3Ptr v) {
	m->M[0][c] = v->M[0];
	m->M[1][c] = v->M[1];
	m->M[2][c] = v->M[2];
	m->M[3][c] = v->M[3];
}

// 2*2 matrix ///////////////////////////////////
void matrix_init_m2x2(Matrix2x2Ptr m, float m00, float m01, float m10, float m11);
float matrix_det_m2x2(Matrix2x2Ptr m);
void matrix_add_m2x2(Matrix2x2Ptr m1, Matrix2x2Ptr m2, Matrix2x2Ptr ret);
void matrix_mul_m2x2(Matrix2x2Ptr m1, Matrix2x2Ptr m2, Matrix2x2Ptr ret);
void matrix_mul_m1x2_m2x2(Matrix1x2Ptr m1, Matrix2x2Ptr m2, Matrix1x2Ptr ret);
int matrix_inverse_m2x2(Matrix2x2Ptr m, Matrix2x2Ptr ret);
int solve_2x2_system(Matrix2x2Ptr a, Matrix1x2Ptr x, Matrix1x2Ptr b);
void matrix_2x2_print(Matrix2x2Ptr m, const char *name);

// 3*3 matrix ///////////////////////////////////
void matrix_3x3_init(Matrix3x3Ptr m, float m00, float m01, float m02, float m10, float m11,
					 float m12, float m20, float m21, float m22);
float matrix_3x3_det(Matrix3x3Ptr m);
void matrix_3x3_add(Matrix3x3Ptr m1, Matrix3x3Ptr m2, Matrix3x3Ptr ret);
void matrix_3x3_mul(Matrix3x3Ptr m1, Matrix3x3Ptr m2, Matrix3x3Ptr ret);
void matrix_1x3_3x3_mul(Matrix1x3Ptr m1, Matrix3x3Ptr m2, Matrix1x3Ptr ret);
int matrix_3x3_inverse(Matrix3x3Ptr m, Matrix3x3Ptr ret);
int solve_3x3_system(Matrix3x3Ptr a, Matrix1x3Ptr x, Matrix1x3Ptr b);
void matrix_3x3_print(Matrix3x3Ptr m, const char *name);

// 4*4 matrix ///////////////////////////////////
void matrix_4x4_init(Matrix4x4Ptr m, float m00, float m01, float m02, float m03,
					 float m10, float m11, float m12, float m13,
					 float m20, float m21, float m22, float m23,
					 float m30, float m31, float m32, float m33);
void matrix_4x4_add(Matrix4x4Ptr m1, Matrix4x4Ptr m2, Matrix4x4Ptr ret);
void matrix_4x4_mul(Matrix4x4Ptr m1, Matrix4x4Ptr m2, Matrix4x4Ptr ret);
void matrix_1x4_4x4_mul(Matrix1x4Ptr m1, Matrix4x4Ptr m2, Matrix1x4Ptr ret);
void matrix_vector3_4x4_mul(Vector3Ptr v, Matrix4x4Ptr m, Vector3Ptr ret);
void matrix_vector3_4x3_mul(Vector3Ptr v, Matrix4x3Ptr m, Vector3Ptr ret);
void matrix_vector4_4x4_mul(Vector4Ptr v, Matrix4x4Ptr m, Vector4Ptr ret, bool div_w = false);
void matrix_vector4_4x3_mul(Vector4Ptr v, Matrix4x4Ptr m, Vector4Ptr ret);
int matrix_4x4_inverse(Matrix4x4Ptr m, Matrix4x4Ptr ret);
void matrix_4x4_print(Matrix4x4Ptr m, const char *name);

void matrix_4x4_rotation(float theta_x, float theta_y, float theta_z, Matrix4x4Ptr ret);

// private function define

#endif //__T2D_ENGINE_MATH_MATRIX_H__