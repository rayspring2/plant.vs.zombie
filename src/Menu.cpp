#include "Menu.hpp"

Menu :: Menu(int x, int y) {
    row = x;
    column = y;
    items.push_back(new Item(0, 0, PEASHOOTER, 10, "files/pic/Peashootermenu.png"));
    items.push_back(new Item(0, 60, SNOWPEA, 10, "files/pic/Snowpeamenu.png"));
    items.push_back(new Item(0, 120, SUNFLOWER, 10, "files/pic/Sunflowermenu.png"));
    items.push_back(new Item(0, 180, WALNUT, 10, "files/pic/Walnutmenu.png"));
}

void Menu :: resetCooldown(PlantType plant_type) {
    for(int i = 0; i < items.size(); i++) {
        if(items[i]->getPlantType() == plant_type) {
            items[i]->setStatus(LOADING);
        }
    }
}

void Menu :: isValidRequset(int is_valid) {
    if(is_valid) {
        for(int i = 0; i < items.size(); i++) {
            if(items[i]->getPlantType() == last_changed) {
                items[i]->setStatus(LOADING);
                cout << items[i]->getPlantType() << " " << items[i]->clock.getElapsedTime().asSeconds() << endl;
                last_changed = INVALID;
            }
        }
    }
}

PlantType Menu :: checkMouse(RenderWindow &window) {
    Vector2i mouse_pos = Mouse::getPosition(window);
    if(mouse_pos.x > 100) return INVALID;
    if(mouse_pos.y < 60) {
        last_changed = PEASHOOTER;
    }
    else if(mouse_pos.y < 120) {
        last_changed = SNOWPEA;
    }
    else if(mouse_pos.y < 180) {
        last_changed = SUNFLOWER;
    }
    else if(mouse_pos.y < 240){
        last_changed = WALNUT;
    }
    else last_changed = INVALID;

    for(int i = 0; i < items.size(); i++) {
        if(items[i]->getPlantType() == last_changed) {
            if(items[i]->getStatus() != AVAILABLE) last_changed = INVALID;
        }
    }

    // if(last_changed != INVALID) {
    //     for(int i = 0; i < items.size(); i++) {
    //         if(items[i]->getPlantType() == last_changed and items[i]->getStatus() == LOADING) {
    //             return INVALID;
    //         }
    //     }
    // }
    return last_changed;
}

void Menu :: render(RenderWindow &window) {
    for(int i = 0; i < items.size(); i++) {
        items[i]->render(window);
    }
}

void Menu :: update() {
    for(int i = 0; i < items.size(); i++) {
        items[i]->update(money);
    }

    //
    Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() >= 100) {
            clock.restart();
            for(int i = 0; i < items.size(); i++) {
            items[i]->increase_current_time();
        }
    }
    //
}