#ifndef ATTACK_PLANT_INCLUDE
#define ATTACK_PLANT_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"
#include "Ball.hpp"

class AttackPlant : public Plant {
protected:
	int bullet_speed, damage, speed;
	Clock shooter_clock;
public:
	AttackPlant(int x, int y, string file_name, int frames_number, int animation_speed);
	~AttackPlant() {};
	void resetShootTime();
	Time getShootTimeElapsed();
	virtual Ball* addBall();
};

#endif