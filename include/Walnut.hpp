#ifndef WALNUT_INCLUDE
#define WALNUT_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class Walnut : public Plant{
public:
	Walnut(int x, int y);
	~Walnut(){};
    void changeStatus();
private:
    string path[3] = {"files/pic/normal_walnut.png", "", ""};
    int status = 0;
};

#endif