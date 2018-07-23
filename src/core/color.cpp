/*!
 * FileName: 	Color.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/19 23:52
 * Author: 		miller
 * Desc:		
 */

#include "color.h"
#include "utility/log/xlog.h"
#include "utility/math/mathf.h"

///color struct ///////////////////////////////////////////////////////////////////////
Color::Color() : r_(0), g_(0), b_(0), a_(1.0f){}

Color::Color(float r, float g, float b, float a) : r_(r), g_(g), b_(b), a_(a) {}

Color::Color(const Color &color) : r_(color.r_), g_(color.g_), b_(color.b_), a_(color.a_){}

bool Color::operator==(const Color& right) const{
	return (this->r_ == right.r_ && this->g_ == right.g_ && this->b_ == right.b_ && this->a_ == right.a_);
}

bool Color::operator!=(const Color& right) const{
	return !(*this == right);
}

Color operator-(const Color &c1, const Color &c2){
	return Color(c1.r_ - c2.r_, c1.g_ - c2.g_, c1.b_ - c2.b_, c1.a_ - c2.a_);
}

Color operator+(const Color &c1, const Color &c2){
	return Color(c1.r_ + c2.r_, c1.g_ + c2.g_, c1.b_ + c2.b_, c1.a_ + c2.a_);
}

Color operator*(const Color &c1, const Color &c2){
	return Color(c1.r_ * c2.r_, c1.g_ * c2.g_, c1.b_ * c2.b_, c1.a_ * c2.a_);
}

Color operator/(const Color &c1, const Color &c2){
	return Color(c1.r_ / c2.r_, c1.g_ / c2.g_, c1.b_ / c2.b_, c1.a_ / c2.a_);
}

///color32 struct ///////////////////////////////////////////////////////////////////////
Color32::Color32() : r_(0), g_(0), b_(0), a_(255) {}

Color32::Color32(uint8 r, uint8 g, uint8 b, uint8 a) : r_(r), g_(g), b_(b), a_(a) {}

Color32::Color32(const Color32 &color) : r_(color.r_), g_(color.g_), b_(color.b_), a_(color.a_){}

bool Color32::operator==(const Color32& right) const{
	return (this->r_ == right.r_ && this->g_ == right.g_ && this->b_ == right.b_ && this->a_ == right.a_);
}

bool Color32::operator!=(const Color32& right) const{
	return !(*this == right);
}

Color32 operator-(const Color32 &c1, const Color32 &c2){
	return Color32(c1.r_ - c2.r_, c1.g_ - c2.g_, c1.b_ - c2.b_, c1.a_ - c2.a_);
}

Color32 operator+(const Color32 &c1, const Color32 &c2){
	return Color32(c1.r_ + c2.r_, c1.g_ + c2.g_, c1.b_ + c2.b_, c1.a_ + c2.a_);
}

Color32 operator*(const Color32 &c1, const Color32 &c2){
	return Color32(c1.r_ * c2.r_, c1.g_ * c2.g_, c1.b_ * c2.b_, c1.a_ * c2.a_);
}

Color32 operator/(const Color32 &c1, const Color32 &c2){
	return Color32(c1.r_ / c2.r_, c1.g_ / c2.g_, c1.b_ / c2.b_, c1.a_ / c2.a_);
}

///const struct variable define //////////////////////////////////////////
const Color Color::WHITE(1.0f, 1.0f, 1.0f, 1.0f);
const Color Color::YELLOW(1.0f, 0.92f, 0.016f, 1.0f);
const Color Color::BLUE(0.0f, 0.0f, 1.0f, 1.0f);
const Color Color::GREEN(0.0f, 1.0f, 0.0f, 1.0f);
const Color Color::RED(1.0f, 0.0f, 0.0f, 1.0f);
const Color Color::MAGENTA(1.0f, 0.0f, 1.0f, 1.0f);
const Color Color::BLACK(0.0f, 0.0f, 0.0f, 1.0f);
const Color Color::GRAY(0.5f, 0.5f, 0.5f, 1.0f);

const Color32 Color32::WHITE(255, 255, 255, 255);
const Color32 Color32::YELLOW(255, 235, 4, 255);
const Color32 Color32::BLUE(0, 0, 255, 255);
const Color32 Color32::GREEN(0, 255, 0, 255);
const Color32 Color32::RED(255, 0, 0, 255);
const Color32 Color32::MAGENTA(255, 0, 255, 255);
const Color32 Color32::BLACK(0, 0, 0, 255);
const Color32 Color32::GRAY(128, 128, 128, 255);

//////////////////////////////////////////////////////////////////////////