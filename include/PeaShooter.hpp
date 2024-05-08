#ifndef PEASHOOTER_INCLUDE
#define PEASHOOTER_INCLUDE

#include "Global.hpp"
#include "Pea.hpp"
#include "BallGreen.hpp"

class PeaShooter : public Pea{
public:
	PeaShooter(int x, int y);
	~PeaShooter(){};
	Ball* addBall() override;
private:
};

#endif