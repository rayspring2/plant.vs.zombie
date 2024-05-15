#ifndef HAIRMETAL_INCLUDE
#define HAIRMETAL_INCLUDE
#include "Global.hpp"
#include "Zombie.hpp"

const string HAIRMETAL_SETTING_KEYWORD = "HAIRMETAL";
const string HAIRMETAL_ZOMBIE_TEXTURE_PATH = "files/pic/hairmetal_walking_eating.png";
const int HAIRMETAL_ZOMBIE_TEXTURE_WIDTH = 124;
const int HAIRMETAL_ZOMBIE_TEXTURE_HEIGHT = 101;
const int HAIRMETAL_ZOMBIE_FRAMES_CNT = 46;
const float HAIRMETAL_ZOMBIE_SCALE = 1.7;
class HairMetal: public Zombie{
public:
	HairMetal(int x, int y , int row);
};

#endif