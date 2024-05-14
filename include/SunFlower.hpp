#ifndef SUNFLOWER_INCLUDE
#define SUNFLOWER_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"
#include "Sun.hpp"
const string SUNFLOWER_SETTING_KEYWORD = "SUNFLOWER";
class SunFlower : public Plant{
private:
	Clock sun_clock;
	void readSettingFile();
public:
	SunFlower(int x, int y);
	Sun* makeSun();
	Time getShootTimeElapsed();
	int getCoolDownTime();
};

#endif