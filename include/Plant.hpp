#ifndef PLANT_INCLUDE
#define PLANT_INCLUDE
#include "Global.hpp"
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
	int row, column, health, price, hit_rate, frames_number, cooldown, frames_position[70], cur_rect = 0;
	Clock clock;
	Texture texture;
	Sprite sprite;
	PlantType plant_type;
	int money;
public:
	PlantType getPlantType();
	Plant(int x, int y, string file_name, int frames_number);
	~Plant(){};
	void handleMousePress(Vector2i mouse_pos);
	void handleMouseRelease();
	void update(Vector2i mouse_pos= {0 , 0});
	void fixedBasedPosition() {};
	void render(RenderWindow &window);
	void hit(int destroy_value);
	bool isAlive();
	Vector2f getPos();
	void virtual myvirtualfunc(){};
};

#endif