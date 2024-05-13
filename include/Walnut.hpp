#ifndef WALNUT_INCLUDE
#define WALNUT_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class Walnut : public Plant{
public:
	Walnut(int x, int y);
	/* void update(Vector2i mouse_pos = {0 , 0}) override; */
private:
	int delfault_health;
protected:
    //int status = 0;
};

#endif