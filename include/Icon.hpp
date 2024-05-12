#ifndef Icon_INCLUDE
#define Icon_INCLUDE
#include "Global.hpp"
#include "Item.hpp"

class Icon{
public:
	Icon(int x, int y);
	~Icon(){};
    int getRow() {return row;}
    int getColumn() {return column;}
    void update();
	void render(RenderWindow &window);
    void handleMousePress(Vector2i mouse_pos);
    void handleMouseRelease();
	void isValidRequset(int is_valid);
    PlantType checkMouse(RenderWindow &window);
    void changeBorder(int number);
    void resetCooldown(PlantType plant_type);
    void backToNormalMode(PlantType plnat_type);
    bool checkAvailable(int index);
    vector<Item*> items;
protected:
    int money = 100;
	Texture texture;
	Sprite sprite;
    PlantType last_changed;
private:
    int row, column;
};

#endif