#ifndef Icon_INCLUDE
#define Icon_INCLUDE
#include "Global.hpp"
#include "Item.hpp"

const int PRIMARY_MONEY = 50;
const string MONEY_PATH = "files/pic/money.png";
const float SPRITE_SCALE = 0.45;
const int MONEY_FONT_SIZE = 50;
const int MONEY_POS_X = 90;
const Vector2f LEFT_UP_POS = {0, 0};
const int UP_NUM = 1;
const int DOWN_NUM = 2;
const int WIDTH_OF_ITEMS = 60;
const int HEIGHT_OF_ITEMS = 60;
const sf::Color TRANSPARENT_MODE = sf::Color(255, 255, 255, 255);

class Icon{
public:
	Icon(int x, int y);
	~Icon(){};
    int getRow() {return row;}
    int getColumn() {return column;}
    void update();
	void render(RenderWindow &window);
	void isValidRequset();
    PlantType checkMouse(RenderWindow &window);
    bool checkAvailable(int index);
	void turnOffBorder();
    void addItem(PlantType plant_type, int cool_down, string path, int price);

    void increase_money(int money_collected){money += money_collected;}
protected:
	Texture texture;
    Font font;
    Text text;
	Sprite sprite;
    PlantType last_changed;
private:

    vector<Item*> items;
    int money;
    int row, column;
};

#endif