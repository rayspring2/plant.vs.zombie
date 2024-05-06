#include "../include/PeaShooter.hpp"

PeaShooter::PeaShooter(int x, int y){
    pos = Vector2f(x, y);
    if (!texture.loadFromFile("files/pic/peashooter.png")) {
        cerr<<"picture not found!\n";
		exit(-1);
    }
    for(int i = 0; i < 7; i++) {
        frames_position[i] = i * 50;
    }
    sprite.setTexture(texture);
    //sprite.setScale(0.5, 0.5);
    IntRect rect;
    rect.width = 50;
    rect.height = 50;
    sprite.setTextureRect(rect);
}

void PeaShooter::render(RenderWindow &window){
    window.draw(sprite);
}

void PeaShooter::update(){
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