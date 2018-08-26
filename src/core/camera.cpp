/*!
 * FileName: 	Camera.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/28 11:26
 * Author: 		miller
 * Desc:		
 */

#include "camera.h"

__T2D_NS_BEGIN__

Camera::Camera(){

}

Camera::Camera(float pixel_width, float pixel_height) : pixel_rect_(0, 0, pixel_width, pixel_height){
	orthoMatrix_ = Matrix4x4::ortho(0, pixel_width, 0, pixel_height);
}

Camera::~Camera(){

}

float Camera::pixel_width(){
	return pixel_rect_.width;
}

float Camera::pixel_height(){
	return pixel_rect_.height;
}

__T2D_NS_END__