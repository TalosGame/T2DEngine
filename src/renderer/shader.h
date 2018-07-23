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

enum eShaderType{
	kVertexShader = 0,
	kFragmentShader
};
 
class Shader{
public:
	static GLuint load_shader(const std::string &shader_name, const std::string &file_name);
	static bool release_shader(const std::string &shader_name);
	static bool release_shader(const GLuint program);
	static void release_all();

private:
	Shader();
	virtual ~Shader();

	static GLuint create_shader(const std::string &name, eShaderType type);
	static bool create_program(GLuint vertex_shader, GLuint frag_shader, GLuint *ret);

	static bool contains(const std::string &name);

private:
	//GLuint program_id_;
	static std::unordered_map<std::string, GLuint> programs_;
};

#endif // __T2D_ENGINE_SHADER_H__
