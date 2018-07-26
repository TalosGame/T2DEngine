/*!
 * FileName: 	T2DShader.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/26 2:40
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_T2D_SHADER_H__
#define __T2D_ENGINE_T2D_SHADER_H__

#include <GLES3/gl3.h>

enum eShaderProgram{
	kBlendVertexColorProgram,

	kShaderProgramMAX,
};

extern const GLchar *t2dBlendVertexColor_frag;
extern const GLchar *t2dBlendVertexColor_vert;


#endif // __T2D_ENGINE_T2D_SHADER_H__
