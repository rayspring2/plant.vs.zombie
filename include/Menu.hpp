#ifndef MENU_INCLUDE
#define MENU_INCLUDE
#include "Global.hpp"
#include "Item.hpp"

class Menu{
public:
	Menu(int x, int y);
	~Menu(){};
    int getRow() {return row;}
    int getColumn() {return column;}
    void update();
	void render(RenderWindow &window);
    void handleMousePress(Vector2i mouse_pos);
    void handleMouseRelease();
	void isValidRequset(int is_valid);
    PlantType checkMouse(RenderWindow &window);
    void resetCooldown(PlantType plant_type);
    vector<Item*> items;
protected:
    Clock clock;
    int money = 100;
	Texture texture;
	Sprite sprite;
    PlantType last_changed;
private:
    int row, column;
};

#endif