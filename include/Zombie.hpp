#ifndef ZOMBIE_INCLUDE
#define ZOMBIE_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"

class Zombie{
protected:
	int row, column, health, damage, hit_rate, frames_number, current_speed, speed, frames_position[70], cur_rect = 0;
	Clock clock;
	Texture texture;
	Sprite sprite;
public:
	Zombie(int x, int y, string file_name, int frames_number);
	~Zombie(){};
	void update();
	void render(RenderWindow &window);
	void hit(int destroy_value);
    void eat(Plant* eating_plant);
	bool isAlive();
};

#endif