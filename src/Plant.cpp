#include "Plant.hpp"

Plant::Plant(int x, int y) {
    row = x;
    column = y;
    for(int i = 0; i < 7; i++) {
        frames_position[i] = i * 50;
    }
}

void Plant::eat(int destroy_value) {
    health -= destroy_value;
}

void Plant::update(Vector2i mouse_pos) {
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 100){
        clock.restart();
        cur_rect = (cur_rect + 1) % 7;
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
}

void Plant::handleMousePress(Vector2i mouse_pos){
    Vector2f sprite_pos = sprite.getPosition();
    Vector2f sprite_size = { sprite.getTextureRect().width, sprite.getTextureRect().height };
    
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