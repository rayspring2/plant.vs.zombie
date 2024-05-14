#include "BallGreen.hpp"

BallGreen::BallGreen(Vector2f shooter_pos) : Ball( shooter_pos, "files/pic/ball_green.png" ){
    readSettingFile(BALLGREEN_SETTING_KEYWORD);
}