#include "SunFlower.hpp"

SunFlower::SunFlower(int x, int y) : Plant(x, y, "files/pic/sunflower2.png", 25, 60) {
    plant_type = SUNFLOWER;
    health = 30;
    cooldown = 40;
    hit_rate = 12;
}

Sun* SunFlower::makeSun(Vector2f plant_position) {
    sun_clock.restart();
    return new Sun(plant_position.x, plant_position.y , 0);
}

Time SunFlower::getShootTimeElapsed(){
    return sun_clock.getElapsedTime();
}
int SunFlower::getCoolDownTime(){
    return cooldown;
}