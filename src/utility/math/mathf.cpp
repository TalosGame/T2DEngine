/*!
* FileName: 	mathf.cpp
* Copyright:	TalosGame Studio Co., Ltd
* Data: 		2018/07/24 1:36
* Author: 		miller
* Desc:
*/

#include "mathf.h"
#include <math.h>

// storage for our sin cos tables
// 0-360 degree
float sin_tables[361];
float cos_tables[361];

void math_init() {
	build_sin_cos_tables();
}

void build_sin_cos_tables(){
	for (int i = 0; i <= 360; i++){
		float raduis = DEG_TO_RAD(i);
		sin_tables[i] = sin(raduis);
		cos_tables[i] = cos(raduis);
	}
}

float fast_sin(float angle){
	angle = fmodf(angle, 360.0f);

	if (angle < 0) angle += 360;

	int angle_int = (int)angle;
	float angle_frac = angle - angle_int;

	return sin_tables[angle_int] + angle_frac * (sin_tables[angle_int + 1] - sin_tables[angle_int]);
}

float fast_cos(float angle){
	angle = fmodf(angle, 360.0f);

	if (angle < 0) angle += 360;

	int angle_int = (int)angle;
	float angle_frac = angle - angle_int;

	// 根据小数插值计算1°的正旋值
	// 精度误差 < 0.0001
	return cos_tables[angle_int] + angle_frac * (cos_tables[angle_int + 1] - cos_tables[angle_int]);
}

int fast_distance_2d(int x, int y){
	// this function computes the distance from 0,0 to x,y with 3.5% error

	// first compute the absolute value of x,y
	x = abs(x);
	y = abs(y);

	// compute the minimum of x,y
	int mn = MIN(x, y);

	// return the distance
	return(x + y - (mn >> 1) - (mn >> 2) + (mn >> 4));
}

float fast_distance_3d(float fx, float fy, float fz){
	// this function computes the distance from the origin to x,y,z

	int temp;	 // used for swaping
	int x, y, z; // used for algorithm

	// make sure values are all positive
	x = fabs(fx) * 1024;
	y = fabs(fy) * 1024;
	z = fabs(fz) * 1024;

	// sort values
	if (y < x) SWAP(x, y, temp)

		if (z < y) SWAP(y, z, temp)

			if (y < x) SWAP(x, y, temp)

				int dist = (z + 11 * (y >> 5) + (x >> 2));

	// compute distance with 8% error
	return((float)(dist >> 10));
}

bool approximately(float a, float b, float epsilon){
	return (fabs(a - b) <= epsilon);
}
