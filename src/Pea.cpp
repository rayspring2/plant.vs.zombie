#include "Pea.hpp"

Pea::Pea(int x, int y, string file_name) : AttackPlant(x, y, file_name) {
    pos = Vector2f(row, column);
    for(int i = 0; i < 7; i++) {
        frames_position[i] = i * 50;
    }
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 50;
    rect.height = 50;
    sprite.setTextureRect(rect);
}
