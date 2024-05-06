#ifndef WALNUT_INCLUDE
#define WALNUT_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class Walnut : public Plant{
public:
	Walnut(int x, int y);
	~Walnut(){};
    Vector2f get_projectile_pos();
private:
    Clock clock;
	Texture texture;
    Sprite sprite;
    Vector2f pos;
};

#endif