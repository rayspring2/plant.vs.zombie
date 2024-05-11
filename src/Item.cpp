#include "Item.hpp"

Item :: Item(int x, int y, PlantType plant_type, int cool_down, string path) : cooldown(cool_down), plant_type(plant_type) {
    //
    cooldown = cool_down * 1000;
    current_time = cooldown;
    //
    sprite.setPosition(x, y);
    item_state = UNAVAILABLE;
    if(!font.loadFromFile("files/HouseofTerrorRegular/HouseofTerrorRegular.otf")) {
        cout << "font can not load";
        exit(0);
    }
    if (!texture.loadFromFile(path)) {
        cerr << "picture not found!\n";
		exit(0);
    }
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 100;
    rect.height = 60;
    sprite.setTextureRect(rect);
    text.setFont(font);
    text.setColor(Color :: Red);
    text.setCharacterSize(24);
    Vector2f text_pos = {sprite.getPosition().x + 50, sprite.getPosition().y + 30};
    text.setPosition(text_pos);
}

void Item :: update(int money) {
    if(item_state == LOADING) {
        IntRect rect;
        rect.top = 60;
        rect.width = 100;
        rect.height = 60;
        sprite.setTextureRect(rect);
        //Time elapsed = clock.getElapsedTime();
        if(current_time/*elapsed.asSeconds()*/ >= cooldown) {
            //clock.restart();
            current_time = 0;
            item_state = UNAVAILABLE;
        }
        else {
            text.setString(to_string(((float)(cooldown)-current_time) / 1000))/*cooldown - elapsed.asSeconds())*/;
        }
    }
    if(item_state == UNAVAILABLE) {
        IntRect rect;
        rect.top = 60;
        rect.width = 100;
        rect.height = 60;
        sprite.setTextureRect(rect);
        if(money >= price) {
            item_state = AVAILABLE;
        }
    }
    if(item_state == AVAILABLE) {
        IntRect rect;
        rect.left = 0;
        rect.width = 100;
        rect.height = 60;
        sprite.setTextureRect(rect);
    }
}

void Item :: render(RenderWindow &window) {
    window.draw(sprite);
    if(item_state == LOADING) {
        window.draw(text);
    }
}

ItemState Item :: getStatus() {
    return item_state;
}

//
void Item::increase_current_time() {
    current_time += 100;
}
//