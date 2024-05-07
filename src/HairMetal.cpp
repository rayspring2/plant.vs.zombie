#include "HairMetal.hpp"

HairMetal::HairMetal(int x, int y) : Zombie(x, y, "files/pic/HairMetal.png", 53) {
    health = 80;
    hit_rate = 6;
    damage = 20;
    speed = 5;
}