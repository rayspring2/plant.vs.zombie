#ifndef SUNFLOWER_INCLUDE
#define SUNFLOWER_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"
#include "Sun.hpp"

class SunFlower : public Plant{
public:
	Clock sun_clock;
	Time getShootTimeElapsed();
	int getCoolDownTime();

	SunFlower(int x, int y);
	Sun* makeSun();
	~SunFlower() {};
	void update(int money);

};

#endif