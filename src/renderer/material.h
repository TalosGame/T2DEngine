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

class Material{
public:
	Material(Shader *shader);
	virtual ~Material();



private:

	Shader *shader_;
};

#endif // __T2D_ENGINE_MATERIAL_H__
