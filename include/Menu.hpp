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
    void addItem(PlantType plant_type);
    void handleMousePress(Vector2i mouse_pos);
    void handleMouseRelease();
    PlantType checkMouse(RenderWindow &window);
    vector<Item*> items;
protected:
    Clock clock;
    int money = 100;
	Texture texture;
	Sprite sprite;
private:
    int row, column;
};

#endif