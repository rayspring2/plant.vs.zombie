#include "../include/PeaShooter.hpp"

PeaShooter::PeaShooter(int x, int y){
    pos = Vector2f(x, y);
    if (!texture.loadFromFile("files/pic/peashooter.png")) {
        cerr<<"picture not found!\n";
		exit(-1);
    }
    sprite.setTexture(texture);
    sprite.setScale(3, 3);
    IntRect rect;
    rect.width = 30;
    rect.height = 35;
    sprite.setTextureRect(rect);
}

void PeaShooter::render(RenderWindow &window){
    window.draw(sprite);
}

void PeaShooter::update(){
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 300){
        clock.restart();
        cur_rect = (cur_rect + 1) % 7;
        IntRect rect;
        rect.width = 30;
        rect.height = 35;
        rect.left = frames_position[cur_rect];
        sprite.setTextureRect(rect);
    }
}