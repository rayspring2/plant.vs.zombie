#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "Global.hpp"

class Plant{
	protected:
		bool in_drag_mode = false;
		int row, column, health;
		int frames_position[70];
    	int cur_rect = 0;
	protected:
		Clock clock;
		Texture texture;
    	Sprite sprite;
	public:
		Plant(int x, int y);
		~Plant(){};
		void handleMousePress(Vector2i mouse_pos);
		void handleMouseRelease();
		void update(Vector2i mouse_pos);
		void render(RenderWindow &window);
		void eat(int destroy_value);
};

#endif