#pragma once
#ifndef ITEM_INCLUDE
#define ITEM_INCLUDE
#include "Global.hpp"

enum ItemState {
    LOADING ,
	AVAILABLE ,
	UNAVAILABLE
};

class Item {
public:
	Item(int x, int y, PlantType plant_type, int cooldown, string path);
	~Item(){};
    ItemState getStatus();
    int getPrice() {return price;}
    void update(int money);
    void render(RenderWindow &window);
protected:

private:
    int price = 10, cooldown;
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
