/*!
 * Filename: 	mathf.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/07 21:02
 * Author 		miller
 * Description: 
 */

#ifndef __T2D_ENGINE_MATHF_H__
#define __T2D_ENGINE_MATHF_H__

#include "math_vector.h"
#include "math_matrix.h"

#include <math.h>

#define PI		 (3.141592654f)
#define PI2		 (6.283185308f)
#define PI_DIV_2 (1.570796327f)
#define PI_DIV_4 (0.785398163f)

// defines for small numbers
#define EPSILON_E3 (float)(1E-3)  // 10^-3  0.0001
#define EPSILON_E4 (float)(1E-4)  // 10^-4  0.00001
#define EPSILON_E5 (float)(1E-5)  // 10^-5  0.000001
#define EPSILON_E6 (float)(1E-6)  // 10^-6  0.0000001

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define DEG_TO_RAD(ang)  ((ang) * PI / 180.0f)
#define RAD_TO_DEG(rads) ((rads) * 180.0f / PI)

#define SWAP(a,b,t) {t=a; a=b; b=t;}

// mathf lib init
void math_init(void);

float fast_sin(float angle);
float fast_cos(float angle);

int fast_distance_2d(int x, int y);
float fast_distance_3d(float x, float y, float z);

// private function define
static void build_sin_cos_tables(void);

#endif //__T2D_ENGINE_MATHF_H__