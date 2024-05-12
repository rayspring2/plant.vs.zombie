#include "AttackPlant.hpp"

AttackPlant::AttackPlant(int x, int y, string file_name, int frames_number, int animation_speed) : Plant(x, y, file_name, frames_number, animation_speed) {
};

Time AttackPlant::getShootTimeElapsed(){
    return shooter_clock.getElapsedTime();
}
void AttackPlant::resetShootTime(){
    shooter_clock.restart();
}

Ball* AttackPlant::addBall() {
		resetShootTime();
		return nullptr;
};