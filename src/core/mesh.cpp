/*!
 * FileName: 	Mesh.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/17 23:00
 * Author: 		miller
 * Desc:		
 */

#include "mesh.h"

__T2D_NS_BEGIN__

Mesh::Mesh(){}

Mesh::Mesh(const char* name){
	this->name_ = name;
}

Mesh::~Mesh(){}

void Mesh::set_name(const char *name){
	this->name_ = name;
}

void Mesh::set_vertices(std::vector<Vector3> &vertices){
	this->vertices_ = vertices;
}

void Mesh::set_uv(std::vector<Vector2> &uv){
	this->uv_ = uv;
}

void Mesh::set_triangles(std::vector<uint32> &triangles){
	this->triangles_ = triangles;
}

void Mesh::set_colors(std::vector<Color> &colors){
	this->colors_ = colors;
}

void Mesh::set_normals(std::vector<Vector3> &normals){
	this->normals_ = normals;
}

void Mesh::set_up_mesh(){

}

__T2D_NS_END__