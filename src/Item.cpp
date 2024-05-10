#include "Item.hpp"

Item :: Item(int x, int y, PlantType plant_type, int cooldown, string path) : cooldown(cooldown), plant_type(plant_type) {
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
        int elapsed = clock.getElapsedTime().asSeconds();
        if(elapsed >= cooldown) {
            clock.restart();
            item_state = UNAVAILABLE;
        }
        else {
            text.setString(to_string(cooldown - elapsed));
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