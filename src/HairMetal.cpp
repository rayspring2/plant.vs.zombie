
#include "HairMetal.hpp"

HairMetal::HairMetal(int x, int y) : Zombie(x, y, "files/pic/up.png", 46, 100, 100) {
    health = 80;
    hit_rate = 6;
    damage = 20;
    speed = 0.1;
    sprite.setScale(1.7,1.7);
}