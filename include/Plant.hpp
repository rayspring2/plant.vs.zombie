
#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "Global.hpp"

enum MouseStatus {
	NOTDRAG,
	DRAGING,
	DRAGED
};

class Plant{
protected:

	MouseStatus in_drag_mode = NOTDRAG;
	int x,y;
	int frame_width = 50 , frame_hight = 47;
	int row, health, price, hit_rate, frame_number, cooldown, frames_position[70], cur_rect = 0, animation_speed;

	Clock clock;
	Texture texture;
	Sprite sprite;
	PlantType plant_type;
	IntRect rect;
	int money;
public:
	PlantType getPlantType();
	Plant(int x, int y, string file_name, int frames_number, int animation_speed);
	virtual ~Plant(){};
	void handleMousePress();
	virtual void update(/* Vector2i mouse_pos= {0 , 0} */);


	void fixedBasedPosition() {};
	int getWidth() {return sprite.getGlobalBounds().width;}
	int getHeight() {return sprite.getGlobalBounds().height;}
	void render(RenderWindow &window);
	void hit(int destroy_value);
	bool isAlive();
	Vector2f getPos();
	void setPos(Vector2f position);
	bool show = false;
	FloatRect getRect();
	int getHealth(){ return health; }
	int getRow();
};


#endif