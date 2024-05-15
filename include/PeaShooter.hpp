
#ifndef PEASHOOTER_INCLUDE
#define PEASHOOTER_INCLUDE

#include "Global.hpp"
#include "Pea.hpp"
#include "BallGreen.hpp"
const string PEASHOOTER_PATH = "files/pic/peashooter.png";
const string PEASHOOTER_SETTING_KEYWORD = "PEASHOOTER";
class PeaShooter : public Pea{
public:
	PeaShooter(int x, int y);
	~PeaShooter(){};
	Ball* addBall() override;
private:
};

#endif