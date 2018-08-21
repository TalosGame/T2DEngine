#include <vector>
#include "platform/Device.h"
#include "platform/platform_macros.h"
#include "utility/log/xlog.h"
#include "resource/resources.h"
#include "core/color.h"
#include "core/mesh.h"
#include "renderer/shader.h"
#include "utility/math/math_matrix.h"
#include "utility/misc/geometry.h"
#include "utility/math/math_vector.h"
#include "utility/math/mathf.h"
#include "renderer/shader_program.h"
#include "core/camera.h"
#include "core/game_object.h"

#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	640
#define GAME_FPS		30

//static const Color WHITE = Color( 1, 1, 1, 1 );

Texture2D *texture = nullptr;
GLuint VBO, VAO, EBO;
GLuint program_id;

void init(){
// 	GameObject *go = new GameObject("ss");
// 	go->add_component<Camera>();
// 	go->add_component<Texture2D>();
// 
// 	Camera *camera = dynamic_cast<Camera *>(go->get_component<Camera>());
// 	Transform *transform = dynamic_cast<Transform *>(go->get_component<Transform>());
// 	
// 	//T2D::Rect a(0, 0, 1, 1);
// 
// 	t2d::Vector2 vec2(1, 2);
// 	vec2[0] = 10;
// 
// 	float x = vec2[0];
// 	float y = vec2[1];
// 
// 	delete go;
// 	go = nullptr;

	t2d::Vector2 vec1(1, 1);
	t2d::Vector2 vec2(2, 2);
	//float dis = vec1.distance(vec2);
	//float dis1 = sqrt(4);
	//float val = t2d::fast_fabs(-1.0f);

	float m3[3][3] = {
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};

	t2d::Matrix3x3 m(m3);

	t2d::Matrix3x3 m1(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	);

	float v = m1[0];

	m1[0] = 0;
	m1(0, 0) = 2;

	//m1 *= 2;

	// Set the viewport
	glViewport(0, 0, 800, 640);

	program_id = Shader::load_shader("T2D/BlendVertexColor", eShaderProgram::kBlendVertexColorProgram);

	float vertices[] = {
		// positions        // colors         // texture coords
		0.08f, 0.079f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top right
		0.08f, -0.079f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // bottom right
		-0.08f, -0.079f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // bottom left
		-0.08f, 0.079f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f  // top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	
	texture = (Texture2D *)Resources::Instance()->load<Texture2D>("fish_4.pkm");
}

void update(){
}

void draw(float dt){
	//write_error("draw dt: %f\n", dt);

	// Clear the color buffer
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// bind Texture
	glBindTexture(GL_TEXTURE_2D, texture->texture_id());

	glUseProgram(program_id);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void exit(){

}

int game_entry(void *device){
	Device *devicePtr = static_cast<Device*>(device);
	if (!devicePtr->set_up_device(SCREEN_WIDTH, SCREEN_HEIGHT, ES_WINDOW_RGB)){
		return -1;
	}

	init();

	devicePtr->set_game_fps(GAME_FPS);
	devicePtr->register_handle_func(update, draw, exit);
	return 0;
}


