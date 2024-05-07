#include "KernelPult.hpp"

KernelPult::KernelPult(int x, int y) : AttackPlant(x, y, "files/pic/KernelPult.png", 53) {
    health = 20;
    damage = 15;
    cooldown = 10;
    hit_rate = 8;
    speed = 7;
    price = 8;
}
