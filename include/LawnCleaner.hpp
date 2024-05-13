#ifndef LAWNCLEANER_INCLUDE
#define LAWNCLEANER_INCLUDE

#include "Global.hpp"
const int CLEANER_UPDATE_TIME = 100;
class LawnCleaner{
private:
	Clock clock;
	int speed = 0;
	int x , y;
	int default_speed = 20;
	Texture texture;
	Sprite sprite;
	
public:
	LawnCleaner(int x = 0, int y = 0);
	void update();
	void render(RenderWindow &window);
	void move();
	bool isOut();
	FloatRect getRect();
};

#endif