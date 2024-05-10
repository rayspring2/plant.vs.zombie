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
protected:

private:
    int price = 10, cooldown = 1;
    Clock clock;
    ItemState item_state;
    Texture texture;
    Sprite sprite;
    IntRect rect;
    Font font;
    Text text;
    PlantType plant_type;
};


#endif
