/*!
 * FileName: 	Material.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/19 0:50
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_MATERIAL_H__
#define __T2D_ENGINE_MATERIAL_H__
 
#include "shader.h"
#include "platform/platform_macros.h"

__T2D_NS_BEGIN__

class Material{
public:
	Material(Shader *shader);
	virtual ~Material();



private:
	Shader *shader_;
};

__T2D_NS_END__

#endif // __T2D_ENGINE_MATERIAL_H__
