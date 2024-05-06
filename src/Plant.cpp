#include "../include/Plant.hpp"

void Plant::eat(){

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