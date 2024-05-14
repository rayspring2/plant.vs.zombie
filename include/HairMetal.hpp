#ifndef HAIRMETAL_INCLUDE
#define HAIRMETAL_INCLUDE
#include "Global.hpp"
#include "Zombie.hpp"
const string HAIRMETAL_SETTING_KEYWORD = "HAIRMETAL";
class HairMetal: public Zombie{
public:
	HairMetal(int x, int y , int row);
};

#endif