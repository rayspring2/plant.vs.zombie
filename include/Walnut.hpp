#ifndef WALNUT_INCLUDE
#define WALNUT_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class Walnut : public Plant{
public:
	Walnut(int x, int y);
	void update() override;
protected:
    int default_health;
};

#endif