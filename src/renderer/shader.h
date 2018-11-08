/*!
 * FileName: 	Shader.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/19 0:39
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_SHADER_H__
#define __T2D_ENGINE_SHADER_H__

#include <GLES3/gl3.h>
#include <unordered_map>
#include <string>

#include "t2d_macros.h"
#include "shader_program.h"
#include "utility/misc/better_map.h"

__T2D_NS_BEGIN__

enum eShaderType{
	kVertexShader = 0,
	kFragmentShader
};

class Shader{
public:
	GET(GLuint, program_id);

	void enable() const;
	void disable() const;
	
	static Shader* find(const char* shader_name);

	static bool release_shader(const std::string &shader_name);
	static bool release_shader(const GLuint program);
	static void release_all();
	
private:
	Shader(GLuint program_id);
	virtual ~Shader();

	static GLuint create_shader(const char *source, eShaderType type);
	static bool create_program(GLuint vertex_shader, GLuint frag_shader, GLuint *ret);

private:

	static BetterMap<const char*, Shader *> programs_;
};

__T2D_NS_END__

#endif // __T2D_ENGINE_SHADER_H__