Shader "T2D/BlendVertexColor" {
	#version 300 es
	layout(location = 0) in vec3 a_postion;
	layout(location = 1) in vec3 a_color;
	layout(location = 2) in vec2 a_texCoord;
	out vec3 v_ourColor;
	out vec2 v_texCoord;

	void main()
	{
		gl_Position = vec4(a_postion, 1.0);
		v_ourColor = a_color;
		v_texCoord = vec2(a_texCoord.x, a_texCoord.y);
	}
}