
#include "NormalZombie.hpp"

NormalZombie::NormalZombie(int x, int y ,  int row) : Zombie(x, y, row, NORMAL_ZOMBIE_TEXTURE_PATH, NORMAL_ZOMBIE_FRAMES_CNT, NORMAL_ZOMBIE_TEXTURE_WIDTH, NORMAL_ZOMBIE_TEXTURE_HEIGHT) {
    readSettingFile(NORMALEZOMBIE_SETTING_KEYWORD);
}