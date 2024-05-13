#include "PeaShooter.hpp"

PeaShooter::PeaShooter(int x, int y) : Pea(x, y, "files/pic/peashooter.png") {
    plant_type = PEASHOOTER;
    health = 40;
    damage = 5;
    cooldown = 5;
    hit_rate = 5;
    speed = 7;
    price = 4;
}

Ball* PeaShooter::addBall(){
    Vector2f pos_base = { getPos().x + PEA_MOUNTH_X  , getPos().y + PEA_MOUNTH_Y };
    resetShootTime();
    BallGreen* new_ball = new BallGreen(pos_base);
    return new_ball;
}
