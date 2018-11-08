Shader "T2D/BlendVertexColor" {
	#version 300 es
	precision mediump float;
	in vec3 v_ourColor;
	in vec2 v_texCoord;
	layout(location = 0) out vec4 outColor;

	// texture sampler
	uniform sampler2D s_texture;

	void main()
	{
		outColor = texture(s_texture, v_texCoord);
	}
}