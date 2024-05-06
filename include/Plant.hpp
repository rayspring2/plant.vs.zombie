#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "../include/Global.hpp"

class Plant{
	protected:
		int row, column, health;
	public:
		Plant(int x, int y);
		~Plant(){};
		void update();
		void render(RenderWindow &window);
		void eat(int destroy_value);
};

#endif