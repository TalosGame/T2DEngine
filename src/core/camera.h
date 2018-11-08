/*!
 * FileName: 	Camera.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/28 11:26
 * Author: 		miller
 * Desc:		
 */

#ifndef __T2D_ENGINE_CAMERA_H__
#define __T2D_ENGINE_CAMERA_H__

#include "component.h"
#include "platform/platform_macros.h"
#include "t2d_macros.h"
#include "utility/math/matrix.h"
#include "utility/misc/geometry.h"

__T2D_NS_BEGIN__

class Camera : public Component{
public:
	Camera();
	Camera(float pixel_width, float pixel_height);
	virtual ~Camera();

	float pixel_width();
	float pixel_height();

	GET_SET(Rect, pixel_rect);

private:
	Matrix4x4 cameraMatrix_;
	Matrix4x4 orthoMatrix_;
};

__T2D_NS_END__

#endif // __T2D_ENGINE_CAMERA_H__
