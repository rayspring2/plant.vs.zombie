#ifndef LAWNCLEANER_INCLUDE
#define LAWNCLEANER_INCLUDE

#include "Global.hpp"
const string LAWNCLEANER_SETTING_KEYWORD = "LAWNCLEANER";
class LawnCleaner{
private:
	int CLEANER_UPDATE_TIME;
	Clock clock;
	int speed = 0;
	int x , y;
	int default_speed;
	Texture texture;
	Sprite sprite;
	void readSettingFile();
	
public:
	LawnCleaner(int x = 0, int y = 0);
	void update();
	void render(RenderWindow &window);
	void move();
	bool isOut();
	FloatRect getRect();
};

#endif