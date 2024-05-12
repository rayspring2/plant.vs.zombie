
#include "HairMetal.hpp"

HairMetal::HairMetal(int x, int y) : Zombie(x, y, "files/pic/hairmetal_walking_eating.png", 46, 100, 116) {
    health = 80;
    hit_rate = 6;
    damage = 20;
    speed = 0.0001;
    sprite.setScale(1.5,1.5);
}