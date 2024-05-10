#include "Menu.hpp"

Menu :: Menu(int x, int y) {
    row = x;
    column = y;
}

PlantType Menu :: checkMouse(RenderWindow &window) {
    Vector2i mouse_pos = Mouse::getPosition(window);
    if(mouse_pos.x > 100) return INVALID;
    if(mouse_pos.y < 60) {
        return PEASHOOTER;
    }
    else if(mouse_pos.y < 120) {
        return SNOWPEA;
    }
    else if(mouse_pos.y < 180) {
        return SUNFLOWER;
    }
    else {
        return WALNUT;
    }
}

void Menu :: render(RenderWindow &window) {
    for(int i = 0; i < items.size(); i++) {
        items[i]->render(window);
    }
}

void Menu :: addItem(PlantType plant_type) {
    if(plant_type == PEASHOOTER) {
        items.push_back(new Item(0, 0, PEASHOOTER, 10, "files/pic/Peashootermenu.png"));
    }
    else if(plant_type == SNOWPEA) {
        items.push_back(new Item(0, 60, SNOWPEA, 10, "files/pic/Snowpeamenu.png"));
    }
    else if(plant_type == SUNFLOWER) {
        items.push_back(new Item(0, 120, SUNFLOWER, 10, "files/pic/Sunflowermenu.png"));
    }
    else if(plant_type == WALNUT) {
        items.push_back(new Item(0, 180, WALNUT, 10, "files/pic/Walnutmenu.png"));
    }
}

void Menu :: update() {
    for(int i = 0; i < items.size(); i++) {
        items[i]->update(money);
    }
}