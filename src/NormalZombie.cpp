
#include "NormalZombie.hpp"

NormalZombie::NormalZombie(int x, int y ,  int row) : Zombie(x, y, row, "files/pic/normal_zombie_walk_eat.png", 60, 100, 116) {
    readSettingFile(NORMALEZOMBIE_SETTING_KEYWORD);
}