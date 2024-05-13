
#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "Global.hpp"
const int PLANT_UPDATE_PERIOD = 50;
enum PlantType{
	PEASHOOTER ,
	SNOWPEA ,
	SUNFLOWER ,
	WALNUT ,
	KERNELPULT
};

class Plant{
protected:
	bool in_drag_mode = false;
	int x,y;
	int frame_width = 50 , frame_hight = 47;
	int row, health, price, hit_rate, frame_number, cooldown, frames_position[70], cur_rect = 0;
	Clock clock;
	Texture texture;
	Sprite sprite;
	PlantType plant_type;
	IntRect rect;
	int money;
public:
	PlantType getPlantType();
	Plant(int x, int y, string file_name, int frames_number);
	virtual ~Plant(){};
	void handleMousePress(Vector2i mouse_pos);
	void handleMouseRelease();
	virtual void update(/* Vector2i mouse_pos= {0 , 0} */);
	void fixedBasedPosition() {};
	int getCoolDownTime(){ return cooldown; };
	void render(RenderWindow &window);
	void hit(int destroy_value);
	bool isAlive();
	Vector2f getPos();
	FloatRect getRect();
	int getHealth(){ return health; }
	int getRow();
};


#endif