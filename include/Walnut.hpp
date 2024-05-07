#ifndef WALNUT_INCLUDE
#define WALNUT_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class Walnut : public Plant{
public:
	Walnut(int x, int y);
protected:
    int status = 0;
};

#endif