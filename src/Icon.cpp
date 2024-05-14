#include "Icon.hpp"

Icon :: Icon(int x, int y) {
    row = x;
    column = y;
    money = 50;
    if(!texture.loadFromFile("files/pic/money.png")){
		cerr << "back ground not found!\n";
		exit(-1);
	}
	
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5);


	if(!font.loadFromFile("files/font/HouseofTerrorRegular.otf")) {
        cout << "font can not load";
        exit(0);
    }
	text.setFont(font);
    text.setColor(Color :: Black);
    text.setCharacterSize(50);

	Vector2f pos = {0, 0};
    sprite.setPosition({pos});
    Vector2f text_pos = {sprite.getPosition().x + 90, sprite.getPosition().y};
    text.setPosition(text_pos);
	text.setString(to_string(money));
}

void Icon :: addItem(PlantType plant_type, int cool_down, string path, int price) {
    int number = items.size();
    Item* item = new Item(60 + number * 60, 60 + number * 60 + 60, plant_type, cool_down, path, price);
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
            items[i]->sprite.setColor(sf::Color(255, 255, 255, 255));
            items[i]->setShowBorder(false);
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
    last_changed = INVALID;
    if(mouse_pos.x > 100) return INVALID;
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