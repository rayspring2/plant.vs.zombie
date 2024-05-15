#ifndef SUN_INCLUDE
#define SUN_INCLUDE

#include "Global.hpp"
const int SUN_UPDATE_PERIOD = 100;
class Sun{
private:
	int yspeed;
	int x , y;
	Texture texture;
	Sprite sprite;
	int cur_rect = 0 , frame_number = 29 , sun_width = 79 , sun_height = 79, lifespan = 3000;
	IntRect rect;
	string file_name = "files/pic/sun.png";
	int frames_position[70];
	Clock clock;
	Clock life_clock;
public:
	bool can_collect(Vector2f mouse_pos) {return sprite.getGlobalBounds().contains(mouse_pos);}
	Sun(int x = 0 , int y = 0 , int yspeed = 0);
	bool isAlive();
	~Sun();
	void update();
	void render(RenderWindow &window);
};


#endif