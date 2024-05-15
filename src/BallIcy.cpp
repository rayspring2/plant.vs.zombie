#include "BallIcy.hpp"

BallIcy::BallIcy(Vector2f shooter_pos)  : Ball( shooter_pos, BALL_BLUE_PATH){
    readSettingFile(BALLICY_SETTING_KEYWORD);
}