#ifndef ZOMBIE_INCLUDE
#define ZOMBIE_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"

class Zombie{
protected:
	int row, column, health, damage, hit_rate, frame_number;
	int frames_position[70], cur_rect = 0, zombie_width, zombie_height;
	float current_speed, speed;
	Clock clock;
	Clock eating_clock;
	Texture texture;
	Sprite sprite;
public:
	string mode = "walking";
	Zombie(int x, int y, string file_name, int frame_number, int zombie_width, int zombie_height);
	~Zombie(){};
	void update();
	static bool compare(Zombie* x, Zombie* y);
	void render(RenderWindow &window);
	void hit(int destroy_value);
    void eat(Plant* eating_plant);
	bool isAlive();
	int get_row() {return row;}
	int get_column() {return column;}
	int getHealth() {return health;}
	int getDamageValue();
	FloatRect getRect();
	bool isReadytoHit();
};

#endif