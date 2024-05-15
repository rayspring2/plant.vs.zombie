#pragma once
#ifndef ITEM_INCLUDE
#define ITEM_INCLUDE
#include "Global.hpp"

const int AVAILABLE_TOP = 0;
const int UNAVAILABLE_TOP = 60;
const int WIDTH_OF_ITEM = 100;
const sf::Color CLICK_MODE_COLOR = sf::Color(255, 255, 255, 128);
const int HEIGHT_OF_ITEM = 60;
const int FONT_SIZE = 24;
const int TEXT_POS_X = 40;
const int TEXT_POS_Y = 20;
const int PRICE_TEXT_X = 65;
const int PRICE_TEXT_Y = 35;

class Item {
public:
	Item(int x, int y, PlantType plant_type, int cooldown, string path, int price);
	~Item(){};
    ItemState getStatus();
    void setStatus(ItemState new_item_state) {item_state = new_item_state;}
    int getPrice() {return price;}
    void update(int money);
    void render(RenderWindow &window);
    PlantType getPlantType() {return plant_type;}
    void makeBorder(RenderWindow& window);
    void fixTexture(string path);
    //
    Clock clock;
    Texture texture;
    Sprite sprite;
    void setShowBorder(bool show_value) {show_border = show_value;}
    bool getShowBorder() {return show_border;}

    RectangleShape border_rec;
    //
protected:

private:

    bool show_border;
    int price;
    int cooldown;
    float current_time;
    ItemState item_state;
    IntRect rect;
    Font font;
    Text text;
    Text price_text;
    PlantType plant_type;
};


#endif