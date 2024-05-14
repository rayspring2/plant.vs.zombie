
#include "HairMetal.hpp"

HairMetal::HairMetal(int x, int y , int row) : Zombie(x, y, row, "files/pic/hairmetal_walking_eating.png", 46 , 124, 101) {
    readSettingFile(HAIRMETAL_SETTING_KEYWORD);
    sprite.setScale(1.7,1.7);
}