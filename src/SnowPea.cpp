#include "SnowPea.hpp"

SnowPea::SnowPea(int x, int y) : Pea(x, y, "files/pic/snowpea.png") {
    plant_type = SNOWPEA;
    health = 30;
    damage = 8;
    cooldown = 9;
    hit_rate = 5;
    speed = 5;
    price = 6;
}

Ball* SnowPea::addBall(){
    BallIcy* new_ball = new BallIcy({ getPos().x + PEA_MOUNTH_X, getPos().y + PEA_MOUNTH_Y }); 
    resetShootTime();
    return new_ball;
}