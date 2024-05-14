#include "Item.hpp"

void Item :: fixTexture(string path) {
    if (!texture.loadFromFile(path)) {
        cerr << "picture not found!\n";
        exit(0);
    }
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 100;
    rect.height = 60;
    sprite.setTextureRect(rect);
}

void Item :: makeBorder(RenderWindow &window) {
    show_border = true;
    sprite.setColor(sf::Color(255, 255, 255, 128));
}

Item :: Item(int up, int down, PlantType plant_type, int cool_down, string path, int price) : up(up), down(down), cooldown(cool_down), plant_type(plant_type), price(price) {
    sprite.setPosition(0, up);

    cout << plant_type << " " << up << " " << down << endl;
    item_state = UNAVAILABLE;
    if(!font.loadFromFile("files/font/HouseofTerrorRegular.otf")) {
        cout << "font can not load";
        exit(0);
    }
    fixTexture(path);
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
        if(elapsed>= cooldown) {
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
        rect.top = 0;
        rect.width = 100;
        rect.height = 60;
        sprite.setTextureRect(rect);
    }
    if (price > money && item_state == AVAILABLE) {
        item_state = UNAVAILABLE;
    }
}

void Item :: render(RenderWindow &window) {
    window.draw(sprite);
    if(item_state == LOADING) {
        window.draw(text);
    }
    if(show_border) window.draw(border_rec);
}

ItemState Item :: getStatus() {
    return item_state;
}

//
void Item::increase_current_time() {
    current_time += 100;
}
//