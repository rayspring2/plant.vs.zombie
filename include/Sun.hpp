#ifndef SUN_INCLUDE
#define SUN_INCLUDE

#include "Global.hpp"
const int SUN_FRAME_NUMBER = 29;
const int SUN_FRANE_WIDTH = 79;
const int SUN_FRANE_HEIGHT = 79;
const string SUN_SETTING_KEYWORD = "SUN";
class Sun{
private:
	int SUN_UPDATE_PERIOD;
	int yspeed;
	int x , y;
	Texture texture;
	Sprite sprite;
	int cur_rect = 0 , lifespan;
	IntRect rect;
	string file_name = "files/pic/sun.png";
	int frames_position[70];
	Clock clock;
	Clock life_clock;
	void readSettingFile();
public:
	bool can_collect(Vector2f mouse_pos) {return sprite.getGlobalBounds().contains(mouse_pos);}
	Sun(int x = 0 , int y = 0 , int yspeed = 0);
	bool isAlive();
	~Sun();
	void update();
	void render(RenderWindow &window);
};


#endif