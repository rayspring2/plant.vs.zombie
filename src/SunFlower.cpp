#include "SunFlower.hpp"

SunFlower::SunFlower(int x, int y) : Plant(x, y, "files/pic/sunflower.png", 25, 60) {
    plant_type = SUNFLOWER;
    health = 30;
    cooldown = 10;
    hit_rate = 12;
    price = 2;
}

void SunFlower::update(Vector2i mouse_pos) {
    // MAKE SUN FLOWER
    Plant :: update(mouse_pos);
}

void SunFlower::makeSun() {
    money += 10;
}