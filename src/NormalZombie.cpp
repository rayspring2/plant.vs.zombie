#include "NormalZombie.hpp"

NormalZombie::NormalZombie(int x, int y) : Zombie(x, y, "files/pic/normal_zombie.png", 6) {
    health = 80;
    hit_rate = 6;
    damage = 20;
    current_speed = 5;
    speed = 5;
}