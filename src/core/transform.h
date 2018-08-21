/*!
 * FileName: 	Transform.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/28 10:34
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_TRANSFORM_H__
#define __T2D_ENGINE_TRANSFORM_H__

#include <vector>
#include "component.h"
#include "utility/math/math_vector.h"
#include "utility/math/math_matrix.h"
#include "utility/misc/geometry.h"
#include "platform/platform_macros.h"

__T2D_NAMESPACE_BEGIN__

class Transform : public Component{
public:
	Transform();
	virtual ~Transform();

	// position of the transform in world space
	Vector3 get_postion();
	// postion of the transform relative of parent transform
	Vector3 local_postion();

	//T2D::Rect rect;

	GET_SET(Transform *, parent);
private:
	Vector3 postion_;
	Vector3 scale_;

	//Matrix3x3 
};

__T2D_NAMESPACE_END__

#endif // __T2D_ENGINE_TRANSFORM_H__
