/*!
 * FileName: 	Shader.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/19 0:39
 * Author: 		miller
 * Desc:		
 */

#include "shader.h"
#include "utility/log/xlog.h"
#include "utility/io/file_stream.h"
#include "utility/string_ext.h"
#include "platform/platform_def.h"
#include "renderer/shader_program.h"

__T2D_NS_BEGIN__

BetterMap<const char*, Shader*> Shader::programs_;

Shader::Shader(GLuint program_id) : program_id_(program_id){}

Shader::~Shader(){}

void Shader::enable() const{
	glUseProgram(program_id_);
}

void Shader::disable() const{
	glUseProgram(0);
}

Shader* Shader::find(const char* shader_name){
	if (contains(&programs_, shader_name)){
		return programs_[shader_name];
	}

	ShaderSource *source = ShaderProgram::get_source(shader_name);
	TD_ASSERT(source != nullptr, "Get shader resource error!");

	const char* vert_source = source->vertex_shader_;
	const char* frag_source = source->fragment_shader_;

	GLuint vertex_shader = Shader::create_shader(vert_source, eShaderType::kVertexShader);
	if (vertex_shader == 0) return nullptr;

	GLuint frag_shader = Shader::create_shader(frag_source, eShaderType::kFragmentShader);
	if (frag_shader == 0) return nullptr;

	GLuint program = 0;
	if (!Shader::create_program(vertex_shader, frag_shader, &program)){
		return nullptr;
	}

	Shader *shader = new Shader(program);
	programs_[shader_name] = shader;

	glDeleteShader(vertex_shader);
	glDeleteShader(frag_shader);
	return shader;
}

GLuint Shader::create_shader(const char* source, eShaderType type){
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

bool Shader::release_shader(const std::string& shader_name){
	return false;
}

bool Shader::release_shader(const GLuint program){
	return false;
}

void Shader::release_all(){
// 	for (auto iter = programs_.begin(); iter != programs_.end(); ++iter){
// 		GLuint pr = iter->second;
// 		glDeleteProgram(pr);
// 	}
// 
// 	programs_.clear();
}

__T2D_NS_END__