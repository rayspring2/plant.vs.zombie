#ifndef ATTACK_PLANT_INCLUDE
#define ATTACK_PLANT_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"

class AttackPlant : public Plant {
protected:
	int bullet_speed, damage, speed;
public:
	AttackPlant(int x, int y, string file_name, int frames_number);
	~AttackPlant() {};
};

#endif