/*!
 * FileName: 	shader_program.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/26 2:41
 * Author: 		miller
 * Desc:		
 */

#include "shader_program.h"

#define GLSL(version, shader)  "#version " #version "\n" #shader

#include "shaders/BlendVertexColor.frag"
#include "shaders/BlendVertexColor.vert"