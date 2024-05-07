#include "PeaShooter.hpp"

PeaShooter::PeaShooter(int x, int y) : Pea(x, y, "files/pic/peashooter.png") {
    health = 40;
    damage = 5;
    cooldown = 5;
    hit_rate = 5;
    speed = 7;
    price = 4;
}

