#include "Plant.hpp"

Plant::Plant(int x, int y, string file_name, int frame_number, int animation_speed) : animation_speed(animation_speed), frame_number(frame_number) {
    row = x;
    column = y;
    sprite.setPosition(x,y);
    for(int i = 0; i < frame_number; i++) {
        frames_position[i] = i * 50;
    }
    if (!texture.loadFromFile(file_name)) {
        cerr << "picture not found!\n";
		exit(-1);
    }
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 50;
    rect.height = 50;
    sprite.setTextureRect(rect);
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
    if(elapsed.asMilliseconds() >= animation_speed){
        clock.restart();
        cur_rect = (cur_rect + 1) % frame_number;
        IntRect rect;
        rect.width = 50;
        rect.height = 50;
        rect.left = frames_position[cur_rect];
        sprite.setTextureRect(rect);
    }

    if(in_drag_mode == DRAGING){
        Vector2f target(static_cast<float>(mouse_pos.x) - sprite.getTextureRect().width/2, static_cast<float>(mouse_pos.y) - sprite.getTextureRect().height/2);
        sprite.setPosition(target);
        show = true;
        in_drag_mode = DRAGED;
    }
	sprite.setScale(1.5, 1.5);
}

void Plant::handleMousePress(){
    if (in_drag_mode == NOTDRAG) in_drag_mode = DRAGING;
}

void Plant::render(RenderWindow &window) {
    window.draw(sprite);
}

PlantType Plant::getPlantType(){
    return plant_type;
}

Vector2f Plant::getPos(){
	return sprite.getPosition();
}

void Plant::setPos(Vector2f position){
	return sprite.setPosition(position);
}