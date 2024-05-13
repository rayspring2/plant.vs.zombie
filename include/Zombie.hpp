#ifndef ZOMBIE_INCLUDE
#define ZOMBIE_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"
enum ZombieState{
	WALKING, EATING	
};

class Zombie{
protected:
	int speed_scale = 1;
	int x, y, row, health, damage, hit_rate, frame_number;
	int frames_position[70], cur_rect = 0, zombie_width, zombie_height;
	float current_speed, speed;
	Clock clock;
	Clock eating_clock;
	Clock reduced_speed_clock;
	Texture texture;
	Sprite sprite;
	bool gameover = false;
public:
	ZombieState mode = WALKING;
	Zombie(int x, int y, string file_name, int frame_number, int zombie_width, int zombie_height);
	~Zombie(){};
	void update();
	void render(RenderWindow &window);
	void hit(int destroy_value);
    void eat(Plant* eating_plant);
	bool getGameOverStatus();
	bool isAlive();
	int getX() {return x;}
	int getY() {return y;}
	int getRow() { return row; }
	int getHealth() {return health;}
	int getDamageValue();
	FloatRect getRect();
	bool isReadytoHit();
	void reduceSpeed();
};

#endif