#ifndef ZOMBIE_INCLUDE
#define ZOMBIE_INCLUDE
#include "Global.hpp"

const string ZOMBIE_SETTING_KEYWORD = "ZOMBIE";
const int FRAME_POSITION = 70;
const string _ZOMBIE_UPDATE_TIME = "ZOMBIE_UPDATE_TIME:";
const string ZOMBIE_HIT_RATE = "hit_rate:";
const string ZOMBIE_HEALTH = "health:";
const string ZOMBIE_DAMAGE = "damage:";
const string ZOMBIE_SPEED = "speed:";
const int ZOMBIE_REDUCED = 3000;
const sf::Color ZOMBIE_COLOR = sf::Color({100 , 100 , 200});

enum ZombieState{
	WALKING, EATING
};

class Zombie{
private:
	int ZOMBIE_UPDATE_TIME;
	void readSettingFile();
protected:
	bool gameover = false;
	int speed_scale = 1;
	int x, y, row, health, damage, hit_rate, frame_number;
	int frames_position[FRAME_POSITION], cur_rect = ZERO, zombie_width, zombie_height;
	float current_speed, speed;
	Clock clock;
	Clock eating_clock;
	Clock reduced_speed_clock;
	Texture texture;
	Sprite sprite;
	void readSettingFile( string type);
public:
	bool getGameover() {return gameover;}
	ZombieState mode = WALKING;
	Zombie(int x, int y, int row, string file_name, int frame_number, int zombie_width, int zombie_height);
	~Zombie(){};
	void update();
	void render(RenderWindow &window);
	void hit(int destroy_value);
	bool isAlive();
	int getX() {return x;}
	int getY() {return y;}
	int getRow() { return row; }
	int getHealth() {return health;}
	int getDamageValue();
	FloatRect getRect();
	bool isReadytoHit();
	void reduceSpeed();
	void die();
};

#endif