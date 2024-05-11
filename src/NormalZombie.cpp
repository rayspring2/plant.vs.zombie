#include "NormalZombie.hpp"

NormalZombie::NormalZombie(int x, int y) : Zombie(x, y, "files/pic/normal_zombie.png", 6, 100, 116) {
    health = 80;
    hit_rate = 6;
    damage = 20;
    speed = 0.1;
}