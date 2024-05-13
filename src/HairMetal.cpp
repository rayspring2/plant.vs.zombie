
#include "HairMetal.hpp"

HairMetal::HairMetal(int x, int y) : Zombie(x, y, "files/pic/hairmetal.png", 38, 140, 116) {
    health = 80;
    hit_rate = 6;
    damage = 20;
    speed = 5;

}