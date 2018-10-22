/*!
 * FileName: 	Color.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/19 23:10
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_COLOR_H__
#define __T2D_ENGINE_COLOR_H__

#include "platform/platform_def.h"

struct Color{
	Color();
	Color(float r, float g, float b, float a);
	Color(const Color &color);

	float r_;
	float g_;
	float b_;
	float a_;

	static const Color kWhite;
	static const Color kYellow;
	static const Color kBlue;
	static const Color kGreen;
	static const Color RED;
	static const Color kMagenta;
	static const Color kBlack;
	static const Color kGray;

	bool operator==(const Color& right) const;
	bool operator!=(const Color& right) const;
};

struct  Color32
{
	Color32();
	Color32(uint8 r, uint8 g, uint8 b, uint8 a);
	Color32(const Color32 &color);

	uint8 r_;
	uint8 g_;
	uint8 b_;
	uint8 a_;

	static const Color32 kWhite;
	static const Color32 kYellow;
	static const Color32 kBlue;
	static const Color32 kGreen;
	static const Color32 kRed;
	static const Color32 kMagenta;
	static const Color32 kBlack;
	static const Color32 kGray;

	bool operator==(const Color32& right) const;
	bool operator!=(const Color32& right) const;
};

Color operator-(const Color &c1, const Color &c2);
Color operator+(const Color &c1, const Color &c2);
Color operator*(const Color &c1, const Color &c2);
Color operator/(const Color &c1, const Color &c2);

Color32 operator-(const Color32 &c1, const Color32 &c2);
Color32 operator+(const Color32 &c1, const Color32 &c2);
Color32 operator*(const Color32 &c1, const Color32 &c2);
Color32 operator/(const Color32 &c1, const Color32 &c2);


#endif // __T2D_ENGINE_COLOR_H__
