#ifndef ZOMBIE_INCLUDE
#define ZOMBIE_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"

class Zombie{
protected:
	int row, column, health, damage, hit_rate, frame_number;
	int current_speed, speed, frames_position[70], cur_rect = 0, zombie_width, zombie_height;
	Clock clock;
	Texture texture;
	Sprite sprite;
	bool gameover = false;
public:
	Zombie(int x, int y, string file_name, int frames_number, int zombie_width, int zombie_height);
	~Zombie(){};
	void update();
	void render(RenderWindow &window);
	void hit(int destroy_value);
    void eat(Plant* eating_plant);
	bool getGameOverStatus();
	bool isAlive();
	int get_row() {return row;}
	int get_column() {return column;}
};

#endif