#include "Plant.hpp"

Plant::Plant(int x, int y, string file_name, int frame_number) :x(x) , y(y) , frame_number(frame_number) {
    row = (y - 53) / 94 + 1 ;
    sprite.setPosition(x,y);
    for(int i = 0; i < frame_number; i++) {
        frames_position[i] = i * frame_width;
    }
    if (!texture.loadFromFile(file_name)) {
        cerr << "picture not found!\n";
		exit(-1);
    }
    sprite.setTexture(texture);
    rect.width = frame_width;
    rect.height = frame_hight;
    sprite.setTextureRect(rect);
    sprite.setScale(1.5, 1.5);
}



void Plant::hit(int destroy_value) {
    health -= destroy_value;
    if(health < 0) health = 0;
}

bool Plant::isAlive() {
    if(!health) return false;
    return true;
}

void Plant::update(Vector2i mouse_pos) {
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 50){
        clock.restart();
        cur_rect = (cur_rect + 1) % frame_number;
        rect.left = frames_position[cur_rect];
        sprite.setTextureRect(rect);
    }

    if(in_drag_mode){
        Vector2f target(static_cast<float>(mouse_pos.x) - sprite.getTextureRect().width/2, static_cast<float>(mouse_pos.y) - sprite.getTextureRect().height/2);
        sprite.setPosition(target);
    }
	//sprite.setScale(1.5, 1.5);
}

void Plant::handleMousePress(Vector2i mouse_pos){
    Vector2f sprite_pos = sprite.getPosition();
    Vector2f sprite_size = { (float)sprite.getTextureRect().width, (float)sprite.getTextureRect().height };

    if (mouse_pos.x >= sprite_pos.x && mouse_pos.x <= sprite_pos.x + sprite_size.x &&
        mouse_pos.y >= sprite_pos.y && mouse_pos.y <= sprite_pos.y + sprite_size.y)
    {
        in_drag_mode = true;
    }

}

void Plant::handleMouseRelease(){
    in_drag_mode = false;
}
void Plant::render(RenderWindow &window) {
    sf::RectangleShape outlineShape(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
    outlineShape.setPosition(sprite.getPosition());
    outlineShape.setOutlineThickness(2); // Set the thickness of the outline
    outlineShape.setOutlineColor(sf::Color::Red); // Set the color of the outline
    outlineShape.setFillColor(sf::Color::Transparent);
    window.draw(sprite);
    window.draw(outlineShape);
}

PlantType Plant::getPlantType(){
    return plant_type;
}

Vector2f Plant::getPos(){
	return sprite.getPosition();
}

FloatRect Plant::getRect(){
    return sprite.getGlobalBounds();
}

int Plant::getRow(){
    return row;
}
