#ifndef SUNFLOWER_INCLUDE
#define SUNFLOWER_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"
#include "Sun.hpp"

const string COOLDOWN = "cooldown:";
const string HEALTH = "health:";
const string SUNFLOWER_PATH = "files/pic/sunflower2.png";
const string SUNFLOWER_SETTING_KEYWORD = "SUNFLOWER";
class SunFlower : public Plant{
private:
	Clock sun_clock;
	void readSettingFile();
public:
	SunFlower(int x, int y);
	Sun* makeSun(Vector2f plant_position);
	Time getShootTimeElapsed();
	int getCoolDownTime();
};

#endif