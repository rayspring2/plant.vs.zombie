#include "SunFlower.hpp"

SunFlower::SunFlower(int x, int y) : Plant(x, y, "files/pic/sunflower.png", 25, 60) {
    plant_type = SUNFLOWER;
    health = 30;
    cooldown = 40;
    hit_rate = 12;
    price = 2;
}

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