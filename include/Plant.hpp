#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "../include/Global.hpp"

class Plant{
	private:
		int row;
		int column;
		int primary_health;
		int current_health = primary_health;
	protected:
		bool in_drag_mode = false;
	protected:
		Clock clock;
		Texture texture;
    	Sprite sprite;
	public:
		void eat();
		void handleMousePress(Vector2i mouse_pos);
		void handleMouseRelease(/*Vector2i mouse_pos*/);
 
};

#endif