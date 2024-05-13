#include "SunFlower.hpp"

SunFlower::SunFlower(int x, int y) : Plant(x, y, "files/pic/sunflower2.png", 25) {
    plant_type = SUNFLOWER;
    health = 30;
    cooldown = 40;
    hit_rate = 12;
    price = 2;
}

// void SunFlower::update(Vector2i mouse_pos) {
//     // MAKE SUN FLOWER
//     // Plant :: update(mouse_pos);
// }

Sun* SunFlower::makeSun() {
    sun_clock.restart();
    return new Sun(x, y , 0);
}

Time SunFlower::getShootTimeElapsed(){
    return sun_clock.getElapsedTime();
}
int SunFlower::getCoolDownTime(){
    return cooldown;
}