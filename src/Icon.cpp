#include "Icon.hpp"

Icon :: Icon(int x, int y) {
    row = x;
    column = y;
    money = PRIMARY_MONEY;
    if(!texture.loadFromFile(MONEY_PATH)){
		cerr << PIC_NOT_FOUND;
		exit(0);
	}
	sprite.setTexture(texture);
	sprite.setScale(SPRITE_SCALE, SPRITE_SCALE);


	if(!font.loadFromFile(FONT_PATH)) {
        cout << FONT_NOT_FOUND;
        exit(0);
    }
	text.setFont(font);
    text.setColor(Color :: Black);
    text.setCharacterSize(MONEY_FONT_SIZE);

	Vector2f pos = LEFT_UP_POS;
    sprite.setPosition(pos);
    Vector2f text_pos = {sprite.getPosition().x + MONEY_POS_X, sprite.getPosition().y};
    text.setPosition(text_pos);
	text.setString(to_string(money));
}

int getUpNumber(int number) {
    return (number + UP_NUM) * WIDTH_OF_ITEMS;
}

int getDownNumber(int number) {
    return (number + DOWN_NUM) * WIDTH_OF_ITEMS;
}

void Icon :: addItem(PlantType plant_type, int cool_down, string path, int price) {
    int number = items.size();
    Item* item = new Item(getUpNumber(number), getDownNumber(number), plant_type, cool_down, path, price);
    items.push_back(item);
}

void Icon :: isValidRequset() {
    for(int i = 0; i < items.size(); i++) {
        if(items[i]->getPlantType() == last_changed and items[i]->getStatus() == AVAILABLE) {
            items[i]->setStatus(LOADING);
            items[i]->clock.restart();
            last_changed = INVALID;
            money -= items[i]->getPrice();
        }
    }
}

void Icon :: turnOffBorder() {
    for(int i = 0; i < items.size(); i++) {
        if(items[i]->getPlantType() == last_changed and items[i]->getStatus() == AVAILABLE) {
            items[i]->border_rec.setOutlineColor(Color::Transparent);
            items[i]->sprite.setColor(TRANSPARENT_MODE);
            items[i]->setShowBorder(false);
        }
    }
}

bool Icon :: checkAvailable(int index) {
    if(items[index]->getStatus() != AVAILABLE) {
        return false;
    }
    return true;
}

PlantType Icon :: checkMouse(RenderWindow &window) {
    Vector2i mouse_pos = Mouse::getPosition(window);
    last_changed = INVALID;
    if(mouse_pos.x > HEIGHT_OF_ITEMS) return INVALID;
    for(int i = 0; i < items.size(); i++) {
        if(mouse_pos.y < items[i]->getDown() and items[i]->getUp() <= mouse_pos.y) {
            last_changed = items[i]->getPlantType();
        }
    }
    if(checkAvailable(last_changed)) {
        items[last_changed]->makeBorder(window);
        return last_changed;
    }
    else {
        return INVALID;
    }
}

void Icon :: render(RenderWindow &window) {
    window.draw(sprite);
    window.draw(text);
    for(int i = 0; i < items.size(); i++) {
        items[i]->render(window);
    }
}

void Icon :: update() {
	text.setString(to_string(money));
    for(int i = 0; i < items.size(); i++) {
        items[i]->update(money);
    }
}