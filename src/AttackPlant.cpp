#include "AttackPlant.hpp"

AttackPlant::AttackPlant(int x, int y, string file_name, int frames_number) : Plant(x, y, file_name, frames_number) {
};

Time AttackPlant::getShootTimeElapsed(){
    return shooter_clock.getElapsedTime();
}
void AttackPlant::resetShootTime(){
    shooter_clock.restart();
}