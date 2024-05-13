#ifndef SUNFLOWER_INCLUDE
#define SUNFLOWER_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"
#include "Sun.hpp"

class SunFlower : public Plant{
private:
	Clock sun_clock;
public:
	SunFlower(int x, int y);
	Sun* makeSun();
	Time getShootTimeElapsed();
	int getCoolDownTime();
};

#endif