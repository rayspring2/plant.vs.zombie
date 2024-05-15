#include "Item.hpp"

void Item :: fixTexture(string path) {
    if (!texture.loadFromFile(path)) {
        cerr << "picture not found!\n";
        exit(0);
    }
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = WIDTH_OF_ITEM;
    rect.height = HEIGHT_OF_ITEM;
    sprite.setTextureRect(rect);
}

void Item :: makeBorder(RenderWindow &window) {
    show_border = true;
    sprite.setColor(CLICK_MODE_COLOR);
}

Item :: Item(int x, int y, PlantType plant_type, int cool_down, string path, int price) : cooldown(cool_down), plant_type(plant_type), price(price) {
    sprite.setPosition(x, y);
    item_state = UNAVAILABLE;
    if(!font.loadFromFile("files/font/HouseofTerrorRegular.otf")) {
        cout << "font can not load";
        exit(0);
    }
    fixTexture(path);
    text.setFont(font);
    text.setColor(Color :: Red);
    text.setCharacterSize(FONT_SIZE);
    Vector2f text_pos = {sprite.getPosition().x + TEXT_POS_X, sprite.getPosition().y + TEXT_POS_Y};
    text.setPosition(text_pos);

    price_text.setFont(font);
    price_text.setColor(Color :: Black);
    price_text.setCharacterSize(FONT_SIZE);
    Vector2f price_text_pos = {sprite.getPosition().x + PRICE_TEXT_X, sprite.getPosition().y + PRICE_TEXT_Y};
    price_text.setPosition(price_text_pos);
    price_text.setString(to_string(price));
}


void Item :: update(int money) {
    if(item_state == LOADING) {
        IntRect rect;
        rect.top = UNAVAILABLE_TOP;
        rect.width = WIDTH_OF_ITEM;
        rect.height = HEIGHT_OF_ITEM;
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
        rect.top = UNAVAILABLE_TOP;
        rect.width = WIDTH_OF_ITEM;
        rect.height = HEIGHT_OF_ITEM;
        sprite.setTextureRect(rect);
        if(money >= price) {
            item_state = AVAILABLE;
        }
    }
    if(item_state == AVAILABLE) {
        IntRect rect;
        rect.top = AVAILABLE_TOP;
        rect.width = WIDTH_OF_ITEM;
        rect.height = HEIGHT_OF_ITEM;
        sprite.setTextureRect(rect);
    }
    if (price > money && item_state == AVAILABLE) {
        item_state = UNAVAILABLE;
    }
}

void Item :: render(RenderWindow &window) {
    window.draw(sprite);
    window.draw(price_text);
    if(item_state == LOADING) {
        window.draw(text);
    }
    if(show_border) window.draw(border_rec);
}

ItemState Item :: getStatus() {
    return item_state;
}