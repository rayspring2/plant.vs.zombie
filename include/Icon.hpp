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
	void isValidRequset();
    PlantType checkMouse(RenderWindow &window);
    void changeBorder(int number);
    void resetCooldown(PlantType plant_type);
    void backToNormalMode(PlantType plnat_type);
    bool checkAvailable(int index);
	void turnOffBorder();
    void addItem(PlantType plant_type, int cool_down, string path, int price);

    vector<Item*> items;
    void increase_money(int money_collected){money += money_collected;}
protected:
	Texture texture;
    Font font;
    Text text;
	Sprite sprite;
    PlantType last_changed;
private:
    int money;
    int row, column;
};

#endif