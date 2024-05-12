#include "Icon.hpp"

Icon :: Icon(int x, int y) {
    row = x;
    column = y;
    items.push_back(new Item(0, 0, PEASHOOTER, 10, "files/pic/PeashooterMenu.png"));
    items.push_back(new Item(0, 60, SNOWPEA, 10, "files/pic/SnowpeaMenu.png"));
    items.push_back(new Item(0, 120, SUNFLOWER, 10, "files/pic/SunflowerMenu.png"));
    items.push_back(new Item(0, 180, WALNUT, 10, "files/pic/WalnutMenu.png"));
}

void Icon :: resetCooldown(PlantType plant_type) {

}

void Icon :: isValidRequset(int is_valid) {
    for(int i = 0; i < items.size(); i++) {
        if(items[i]->getPlantType() == last_changed and items[i]->getStatus() == AVAILABLE) {
            items[i]->setStatus(LOADING);
            cout << "hello" << endl;
            items[i]->clock.restart();
            last_changed = INVALID;
        }
    }
}

void Icon :: changeBorder(int number) {
    if (!items[number]->texture.loadFromFile("files/pic/WalnutMenu.png")) {
        cerr << "picture not found!\n";
        exit(0);
    }
    items[0]->sprite.setTexture(texture);
}

bool Icon :: checkAvailable(int index) {
    if(items[index]->getStatus() != AVAILABLE) {
        return false;
    }
    return true;
}

PlantType Icon :: checkMouse(RenderWindow &window) {
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
    if(checkAvailable(last_changed)) {
        return last_changed;
    }
    else {
        return INVALID;
    }
}

void Icon :: backToNormalMode(PlantType plnat_type) {
    if(plnat_type == PEASHOOTER) {
        items[0]->fixTexture("files/pic/PeashooterMenu.png");
    }
    else if(plnat_type == SNOWPEA) {
cout << 1;
    }
    else if(plnat_type == SUNFLOWER) {
cout << 1;
    }
    else if(plnat_type == WALNUT) {
cout << 1;
    }
    else {
        cout << 1;
    }
}

void Icon :: render(RenderWindow &window) {
    for(int i = 0; i < items.size(); i++) {
        items[i]->render(window);
    }
}

void Icon :: update() {
    for(int i = 0; i < items.size(); i++) {
        items[i]->update(money);
    }
}