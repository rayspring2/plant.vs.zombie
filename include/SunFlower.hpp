#ifndef SUNFLOWER_INCLUDE
#define SUNFLOWER_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class SunFlower : public Plant{
public:
	SunFlower(int x, int y);
	~SunFlower(){};
    Vector2f get_projectile_pos(){};
private:
    Clock clock;
	Texture texture;
    Sprite sprite;
    Vector2f pos;
};

#endif