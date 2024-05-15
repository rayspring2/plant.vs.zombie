
#include "HairMetal.hpp"

HairMetal::HairMetal(int x, int y) : Zombie(x, y, "files/pic/hairmetal_walking_eating.png", 46, 100, 116) {
    health = 80;
    hit_rate = 6;
    damage = 20;
    speed = 2;
    sprite.setScale(1.7,1.7);
}