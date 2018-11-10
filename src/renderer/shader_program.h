/*!
 * FileName: 	shader_program.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/26 2:40
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_T2D_SHADER_H__
#define __T2D_ENGINE_T2D_SHADER_H__

#include <GLES3/gl3.h>
#include <unordered_map>
#include "platform/platform_macros.h"
#include "utility/misc/better_map.h"

__T2D_NS_BEGIN__

struct ShaderSource{
public:
	const char* name_;
	const char* vertex_shader_;
	const char* fragment_shader_;
};

class ShaderProgram
{
public: 
	static ShaderSource* load_shader_program(const char* name);
	static ShaderSource* get_source(const char* name);

private:
	ShaderProgram();
	~ShaderProgram();

	static BetterMap<const char*, ShaderSource*> program_sources_;
};

__T2D_NS_END__

#endif // __T2D_ENGINE_T2D_SHADER_H__
