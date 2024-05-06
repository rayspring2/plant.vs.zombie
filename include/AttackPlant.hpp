#ifndef ATTACK_PLANT_INCLUDE
#define ATTACK_PLANT_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"

class AttackPlant : public Plant {
	private:
		int bullet_speed;
	public:
		AttackPlant(int x, int y, string file_name, int frames_number) : Plant(x, y, file_name, frames_number){};
};

#endif