/*!
 * FileName: 	Mesh.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/17 22:53
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_MESH_H__
#define __T2D_ENGINE_MESH_H__

#include <vector>
#include <string>
#include <GLES3/gl3.h>
#include "utility/math/vector.h"
#include "color.h"
#include "platform/platform_def.h"
#include "platform/platform_macros.h"

__T2D_NS_BEGIN__

class Mesh{
public:
	Mesh();
	Mesh(const char* name);
	virtual ~Mesh();

	void set_name(const char *name);
	void set_vertices(std::vector<Vector3> &vertices);
	void set_uv(std::vector<Vector2> &uv);
	void set_triangles(std::vector<uint32> &triangles);
	void set_colors(std::vector<Color> &colors);
	void set_normals(std::vector<Vector3> &normals);

	void set_up_mesh();

private:
	std::string name_;

	std::vector<Vector3> vertices_;
	std::vector<Vector2> uv_;
	std::vector<uint32> triangles_;
	std::vector<Color> colors_;
	std::vector<Vector3> normals_;

	GLuint vao_, vbo_, ebo_;
};

__T2D_NS_END__

#endif // __T2D_ENGINE_MESH_H__
