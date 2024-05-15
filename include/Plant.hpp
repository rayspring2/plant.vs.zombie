
#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "Global.hpp"
const int PLANT_UPDATE_PERIOD = 50;

const int FRAME_NUMBER = 70;
const int FRAME_HEIGHT = 47;
const int FRAME_WIDTH = 50;

enum MouseStatus {
	NOTDRAG,
	DRAGING,
	DRAGED
};

class Plant{
protected:
	MouseStatus in_drag_mode = NOTDRAG;
	int x,y;
	int frame_width = FRAME_WIDTH , frame_hight = FRAME_HEIGHT;
	int row, health, price, hit_rate, frame_number, cooldown, frames_position[FRAME_NUMBER], cur_rect = 0, animation_speed;
	Clock clock;
	Texture texture;
	Sprite sprite;
	PlantType plant_type;
	IntRect rect;
	int money;
public:
	PlantType getPlantType();
	void setPos(Vector2f new_pos);
	Vector2f getPs(){return sprite.getPosition();}
	Plant(int x, int y, string file_name, int frames_number, int animation_speed);
	virtual ~Plant(){};
	void handleMousePress();
	virtual void update();
	void fixedBasedPosition() {};
	int getCoolDownTime(){ return cooldown; };
	int getWidth() {return sprite.getGlobalBounds().width;}
	int getHeight() {return sprite.getGlobalBounds().height;}
	void render(RenderWindow &window);
	void hit(int destroy_value);
	bool isAlive();
	Vector2f getPos();
	FloatRect getRect();
	int getHealth(){ return health; }
	int getRow();
	bool show = false;

};


#endif