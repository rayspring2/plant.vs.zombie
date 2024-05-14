#include "BallIcy.hpp"

BallIcy::BallIcy(Vector2f shooter_pos)  : Ball( shooter_pos, "files/pic/ball_blue.png" ){
    readSettingFile(BALLICY_SETTING_KEYWORD);
}