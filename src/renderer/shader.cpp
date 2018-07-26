/*!
 * FileName: 	Shader.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/19 0:39
 * Author: 		miller
 * Desc:		
 */

#include "shader.h"
#include <string>
#include "utility/log/xlog.h"
#include "utility/io/file_stream.h"
#include "utility/string_ext.h"
#include "platform/platform_def.h"
#include "t2d_shader.h"

std::unordered_map<std::string, GLuint> Shader::programs_;

Shader::Shader(){}

Shader::~Shader(){}

GLuint Shader::load_shader(const std::string &shader_name, eShaderProgram shader_program){
	if (contains(shader_name)){
		return programs_[shader_name];
	}

	const char *vert_source = nullptr;
	const char *frag_source = nullptr;
	switch (shader_program)
	{
	case kBlendVertexColorProgram:
		vert_source = t2dBlendVertexColor_vert;
		frag_source = t2dBlendVertexColor_frag;
		break;
	default:
		break;
	}

// 	std::string shader_path("src/shaders/");
// 	shader_path.append(file_name).append(".vert");

	GLuint vertex_shader = Shader::create_shader(vert_source, eShaderType::kVertexShader);
	if (vertex_shader == 0) return 0;

	//shader_path = replace(shader_path, ".vert", ".frag");
	GLuint frag_shader = Shader::create_shader(frag_source, eShaderType::kFragmentShader);
	if (frag_shader == 0) return 0;

	Shader *shader = new Shader();
	GLuint program = 0;
	if (shader->create_program(vertex_shader, frag_shader, &program)){
		programs_[shader_name] = program;
	}

	glDeleteShader(vertex_shader);
	glDeleteShader(frag_shader);
	return program;
}

GLuint Shader::load_shader(const std::string &shader_name, const std::string &program_name){
	if (contains(shader_name)){
		return programs_[shader_name];
	}

	//std::string shader_path("shaders\\");
	//shader_path.append(program_name).append("_v.shader");


}

GLuint Shader::create_shader(const char *source, eShaderType type){
	if (source == nullptr){
		log_error("Invalid shader source!");
		return 0;
	}

	GLuint shader_type = (type == eShaderType::kVertexShader ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
	GLuint shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint success;
	char infoLog[1024];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success){
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		log_error("SHADER_COMPILATION_ERROR of type : %d\nlog:%s", type, infoLog);
		return 0;
	}

	return shader;
}

bool Shader::create_program(GLuint vertex_shader, GLuint frag_shader, GLuint *ret){
	GLuint program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader);
	glAttachShader(program_id, frag_shader);
	glLinkProgram(program_id);

	GLint success;
	char infoLog[1024];
	glGetProgramiv(program_id, GL_LINK_STATUS, &success);
	if (!success){
		glGetProgramInfoLog(program_id, 1024, NULL, infoLog);
		log_error("PROGRAM_LINKING_ERROR\nlog:%s", infoLog);
		return false;
	}

	*ret = program_id;
	return true;
}

bool Shader::release_shader(const std::string &shader_name){
	return false;
}

bool Shader::release_shader(const GLuint program){
	return false;
}

void Shader::release_all(){
	for (auto iter = programs_.begin(); iter != programs_.end(); ++iter){
		GLuint pr = iter->second;
		glDeleteProgram(pr);
	}

	programs_.clear();
}

bool Shader::contains(const std::string &name){
	if (programs_.find(name) != programs_.end()){
		return true;
	}

	return false;
}


