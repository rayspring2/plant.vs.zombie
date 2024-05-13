#pragma once
#ifndef ITEM_INCLUDE
#define ITEM_INCLUDE
#include "Global.hpp"



class Item {
public:
	Item(int x, int y, PlantType plant_type, int cooldown, string path);
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
    void increase_current_time();
    void setShowBorder(bool show_value) {show_border = show_value;}
    bool getShowBorder() {return show_border;}

    RectangleShape border_rec;
    //
protected:

private:
    bool show_border;
    int price = 10;
    int cooldown;
    float current_time;
    ItemState item_state;
    IntRect rect;
    Font font;
    Text text;
    PlantType plant_type;
};


#endif