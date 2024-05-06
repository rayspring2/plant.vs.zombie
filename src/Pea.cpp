#include "Pea.hpp"

Pea::Pea(int x, int y) : AttackPlant(x, y) {
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

void Pea::render(RenderWindow &window){
    window.draw(sprite);
}

void Pea::update(){
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
}