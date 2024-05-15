#ifndef BALLICY_INCLUDE
#define BALLICY_INCLUDE
#include "Global.hpp"
#include "Ball.hpp"
const string BALLICY_SETTING_KEYWORD = "BALLICY";
const string BALL_BLUE_PATH = "files/pic/ball_blue.png";
class BallIcy : public Ball{
private:
public:
	BallIcy(Vector2f shooter_pos);
};

#endif