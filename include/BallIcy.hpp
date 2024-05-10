#ifndef BALLICY_INCLUDE
#define BALLICY_INCLUDE
#include "Global.hpp"
#include "Ball.hpp"
class BallIcy : public Ball{
public:
	BallIcy(Vector2f shooter_pos);
	~BallIcy() {};
};

#endif