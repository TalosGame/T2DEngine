/*!
 * FileName: 	Geometry.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/08/08 0:44
 * Author: 		miller
 * Desc:		
 */

#include "geometry.h"

Rect::Rect(){}

Rect::Rect(float x, float y, float w, float h) : x(x), y(y), width(w), height(h){}

Rect::Rect(const Rect &rect) : x(rect.x), y(rect.y), width(rect.width), height(rect.height) {}

void Rect::set(float x, float y, float widht, float height){
	this->x = x;
	this->y = y;
	this->width = widht;
	this->height = height;
}

// Vector2 Rect::size() const{
// 	return Vector2(){ 0.0f, 0.0f };
// }
// 
// Vector2 Rect::center() const{
// 
// }

bool Rect::intersects_rect(const Rect& rect) const{
	if (this->x + this->width < rect.x
		|| this->x > rect.x + rect.width
		|| this->y + this->height < rect.y
		|| this->y > rect.y + rect.height){
		return false;
	}

	return true;
}

Rect& Rect::operator=(const Rect& rhs){
	this->set(rhs.x, rhs.y, rhs.width, rhs.height);
	return *this;
}
