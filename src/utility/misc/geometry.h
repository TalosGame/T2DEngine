/*!
 * FileName: 	Geometry.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/08/07 23:29
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_GEOMETRY_H__
#define __T2D_ENGINE_GEOMETRY_H__

#include "utility/math/math_vector.h"
#include "platform/platform_macros.h"

__T2D_NAMESPACE_BEGIN__

struct Rect
{
public:
	Rect();
	Rect(float x, float y, float w, float h);
	Rect(const Rect &rect);

	void set(float x, float y, float w, float h);

	//Vector2 size() const;
	//Vector2 center() const;

	bool intersects_rect(const Rect& rect) const;

	Rect& operator=(const Rect& rhs);

	float x;
	float y;
	float width;
	float height;
};

bool operator==(Rect lhs, Rect rhs);

__T2D_NAMESPACE_END__

#endif // __T2D_ENGINE_GEOMETRY_H__