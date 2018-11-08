/*!
 * FileName: 	shader_program.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/26 2:41
 * Author: 		miller
 * Desc:		
 */

#include "shader_program.h"
#include "utility/io/file_stream.h"
#include "utility/string_ext.h"

__T2D_NS_BEGIN__

BetterMap<const char*, ShaderSource*> ShaderProgram::program_sources_;

ShaderProgram::ShaderProgram(){}

ShaderProgram::~ShaderProgram(){}

ShaderSource* ShaderProgram::get_source(const char* name){
	if (contains(&program_sources_, name)){
		return program_sources_[name];
	}

	return nullptr;
}

ShaderSource* ShaderProgram::load_shader_program(const char *name){
	char shader_path[100];
	ShaderSource *source = new ShaderSource();
	sprintf_s(shader_path, "src\\shaders\\%s.vert", name);

	FileStream *fs = new FileStream();
	fs->open(shader_path, "rb");
	const char* buffer = fs->read_buffer();

	int index = index_of(buffer, '"');
	int nextIdx = index_of(buffer, index + 1, '"');
	source->name_ = substring(buffer, index + 1, nextIdx - index - 1);

	int sIdx = index_of(buffer, '#');
	int lastSIdx = last_index_of(buffer, '}');
	source->vertex_shader_ = substring(buffer, sIdx, lastSIdx - sIdx - 1);

	fs->close();

	memset(shader_path, 0, 100);
	sprintf_s(shader_path, "src\\shaders\\%s.frag", name);
	fs->open(shader_path, "rb");
	buffer = fs->read_buffer();

	sIdx = index_of(buffer, '#');
	lastSIdx = last_index_of(buffer, '}');
	source->fragment_shader_ = substring(buffer, sIdx, lastSIdx - sIdx - 1);

	delete fs;
	fs = nullptr;

	program_sources_[source->name_] = source;
	return source;
}

__T2D_NS_END__