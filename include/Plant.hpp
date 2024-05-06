#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "../include/Global.hpp"

class Plant{
	private:
		int row;
		int column;
		int primary_health;
		int current_health = primary_health;
		string base_shape; // is a picture
	public:
		void eat();
};

#endif