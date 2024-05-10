#include "Walnut.hpp"

Walnut::Walnut(int x, int y) : Plant(x, y, "files/pic/normal_walnut.png", 3, 100) {
    plant_type = WALNUT;
    health = 200;
    cooldown = 10;
    hit_rate = 0;
    price = 2;
}