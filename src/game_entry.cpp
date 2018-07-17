#include "platform/Device.h"

#include "utility/log/xlog.h"
#include "resource/resources.h"

#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT	640
#define GAME_FPS		30

void init(){
	// Set the viewport
	glViewport(0, 0, 800, 640);

	//Resources::Instance()->load<Texture2D>("SemiAlpha.pkm");
	Resources::Instance()->load<Texture2D>("fish_4.pkm");
}

void update(){

}

void draw(float dt){
	//write_error("draw dt: %f\n", dt);

	// Clear the color buffer
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
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