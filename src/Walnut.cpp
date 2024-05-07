#include "Walnut.hpp"

Walnut::Walnut(int x, int y) : Plant(x, y, "files/pic/walnut/very_cracked_walnut.png", 3) {
    health = 200;
    cooldown = 10;
    hit_rate = 0;
    price = 2;
}