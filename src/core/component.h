/*!
 * FileName: 	Component.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/29 18:39
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_COMPONENT_H__
#define __T2D_ENGINE_COMPONENT_H__

#include <string>
#include <vector>
#include "object.h"
#include "platform/platform_def.h"
#include "platform/platform_macros.h"
#include "t2d_macros.h"

__T2D_NS_BEGIN__

class GameObject;

class Component : Object{
public:
	Component();
	virtual ~Component();

	//virtual void Update() = 0;

	GET_SET(GameObject*, game_object);

private:
};

__T2D_NS_END__

#endif // __T2D_ENGINE_COMPONENT_H__
