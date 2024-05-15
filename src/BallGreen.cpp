#include "BallGreen.hpp"

BallGreen::BallGreen(Vector2f shooter_pos) : Ball( shooter_pos,BALL_GREEN_PATH){
    readSettingFile(BALLGREEN_SETTING_KEYWORD);
}