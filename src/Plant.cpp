#include "Plant.hpp"

Plant::Plant(int x, int y, string file_name) {
    row = x;
    column = y;
    for(int i = 0; i < 60; i++) {
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

void Plant::eat(int destroy_value) {
    health -= destroy_value;
}

void Plant::update(Vector2i mouse_pos) {
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 10){
        clock.restart();
        cur_rect = (cur_rect + 1) % 60;
        IntRect rect;
        rect.width = 50;
        rect.height = 50;
        rect.left = frames_position[cur_rect];
        sprite.setTextureRect(rect);
    }

    if(in_drag_mode){
        Vector2f target(static_cast<float>(mouse_pos.x) - sprite.getTextureRect().width/2, static_cast<float>(mouse_pos.y) - sprite.getTextureRect().height/2);
        sprite.setPosition(target);
    }
    sprite.setScale(1, 1);
    sprite.setPosition(100, 100);
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

void Plant::handleMouseRelease(/*Vector2i mouse_pos*/){
    in_drag_mode = false;
}

void Plant::render(RenderWindow &window) {
    window.draw(sprite);
}