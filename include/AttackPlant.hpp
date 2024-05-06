#ifndef ATTACK_PLANT_INCLUDE
#define ATTACK_PLANT_INCLUDE
#include "../include/Global.hpp"
#include "../include/Plant.hpp"

class AttackPlant : public Plant {
	private:
		int bullet_speed;
	public:
		AttackPlant(int x, int y) : Plant(x, y){};
		void render(RenderWindow &window);
};

#endif