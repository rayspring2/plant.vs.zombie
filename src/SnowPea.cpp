#include "SnowPea.hpp"

SnowPea::SnowPea(int x, int y) : Pea(x, y, "files/pic/snowpea.png") {
    readSettingFile(SNOWPEA_SETTING_KEYWORD);
    plant_type = SNOWPEA;
}

Ball* SnowPea::addBall(){
    BallIcy* new_ball = new BallIcy({ getPos().x + PEA_MOUNTH_X, getPos().y + PEA_MOUNTH_Y }); 
    resetShootTime();
    return new_ball;
}