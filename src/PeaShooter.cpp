#include "PeaShooter.hpp"

PeaShooter::PeaShooter(int x, int y) : Pea(x, y, "files/pic/peashooter.png") {
    readSettingFile(PEASHOOTER_SETTING_KEYWORD);
    plant_type = PEASHOOTER;
    
}

Ball* PeaShooter::addBall(){
    Vector2f pos_base = { getPos().x + PEA_MOUNTH_X  , getPos().y + PEA_MOUNTH_Y };
    resetShootTime();
    BallGreen* new_ball = new BallGreen(pos_base);
    return new_ball;
}