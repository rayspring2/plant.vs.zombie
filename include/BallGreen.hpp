#ifndef BALLGREEN_INCLUDE
#define BALLGREEN_INCLUDE

#include "Global.hpp"
#include "Ball.hpp"
const string BALLGREEN_SETTING_KEYWORD = "BALLGREEN";
const string BALL_GREEN_PATH = "files/pic/ball_green.png";
class BallGreen : public Ball{
public:
	BallGreen(Vector2f shooter_pos);
};

#endif