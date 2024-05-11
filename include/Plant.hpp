
#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "Global.hpp"

enum MouseStatus {
	NOTDRAG,
	DARGING,
	DRAGED
};

class Plant{
protected:
	MouseStatus in_drag_mode = NOTDRAG;
	int row, column, health, price, hit_rate, frame_number, cooldown, frames_position[70], cur_rect = 0, animation_speed;
	Clock clock;
	Texture texture;
	Sprite sprite;
	PlantType plant_type;
	int money;
public:
	PlantType getPlantType();
	Plant(int x, int y, string file_name, int frames_number, int animation_speed);
	~Plant(){};
	void handleMousePress();
	void update(Vector2i mouse_pos= {0 , 0});
	void fixedBasedPosition() {};
	int getCoolDownTime(){ return cooldown; };
	void render(RenderWindow &window);
	void hit(int destroy_value);
	bool isAlive();
	bool isDead();
	Vector2f getPos();
	void setPos(Vector2f position);
	void virtual myvirtualfunc(){};
	bool show = false;
	FloatRect getRect();
	int getHealth(){ return health; }
};


#endif