#ifndef SYSTEM_INCLUDE
#define SYSTEM_INCLUDE
#include "../include/Global.hpp"

class System{
private:
	Texture bg_texture;
	Sprite bg_sprite;
	void update();
	void render();
	void handleEvent();
public:
	RenderWindow window;
	void run();	
	System();
};

#endif