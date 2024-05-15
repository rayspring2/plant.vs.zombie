#ifndef NORMALZOMBIE_INCLUDE
#define NORMALZOMBIE_INCLUDE
#include "Global.hpp"
#include "Zombie.hpp"
const string NORMALEZOMBIE_SETTING_KEYWORD = "NORMALEZOMBIE";
const string NORMAL_ZOMBIE_TEXTURE_PATH = "files/pic/normal_zombie_walk_eat.png";
const int NORMAL_ZOMBIE_TEXTURE_WIDTH = 100;
const int NORMAL_ZOMBIE_TEXTURE_HEIGHT = 116;
const int NORMAL_ZOMBIE_FRAMES_CNT = 60;
class NormalZombie : public Zombie{
protected:
   
public:
    NormalZombie(int x, int y ,  int row);
};

#endif