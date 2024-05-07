#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "Global.hpp"

class Plant{
protected:
	bool in_drag_mode = false;
	int row, column, health, price, hit_rate, frames_number, cooldown, frames_position[70], cur_rect = 0;
	Clock clock;
	Texture texture;
	Sprite sprite;
	int money;
public:
	Plant(int x, int y, string file_name, int frames_number);
	~Plant(){};
	void handleMousePress(Vector2i mouse_pos);
	void handleMouseRelease();
	void update(Vector2i mouse_pos);
	void fixedBasedPosition() {};
	void render(RenderWindow &window);
	void hit(int destroy_value);
	bool isAlive();
};

#endif