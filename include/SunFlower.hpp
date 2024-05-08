#ifndef SUNFLOWER_INCLUDE
#define SUNFLOWER_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class SunFlower : public Plant{
public:
	SunFlower(int x, int y);
	void update(Vector2i mouse_pos);
	void makeSun();
private:
};

#endif