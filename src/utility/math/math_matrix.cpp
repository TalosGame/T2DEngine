/*!
 * Filename: 	math_matrix.cpp
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 21:20
 * Author 		miller
 * Description: 
 */

#include "math_matrix.h"
#include <math.h>
#include "utility/log/xlog.h"
#include "mathf.h"

__T2D_NAMESPACE_BEGIN__

Matrix3x3::Matrix3x3(){}

Matrix3x3::Matrix3x3(float src[3][3]){
	memcpy(M, src, sizeof(Matrix3x3));
}

Matrix3x3::Matrix3x3(float m00, float m01, float m02, float m10, float m11, float m12,
					 float m20, float m21, float m22){

	this->m00 = m00; this->m01 = m01; this->m02 = m02;
	this->m10 = m10; this->m11 = m11; this->m12 = m12;
	this->m20 = m20; this->m21 = m21; this->m22 = m22;
}

Matrix3x3::Matrix3x3(const Matrix3x3 &m) : m00(m.m00), m01(m.m01), m02(m.m02),
										   m10(m.m10), m11(m.m11), m12(m.m12),
										   m20(m.m20), m21(m.m21), m22(m.m22) {
}

Matrix3x3::~Matrix3x3(){

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

///const matrix variable define/////////////////////////////////////////////////////////////
const Matrix3x3 Matrix3x3::IDENTITY = Matrix3x3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

__T2D_NAMESPACE_END__
