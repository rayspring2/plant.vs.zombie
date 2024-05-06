#include "../include/PeaShooter.hpp"

PeaShooter::PeaShooter(int x, int y) : Pea(x, y) {
    pos = Vector2f(row, column);
    if (!texture.loadFromFile("files/pic/peashooter.png")) {
        cerr << "picture not found!\n";
		exit(-1);
    }
    for(int i = 0; i < 7; i++) {
        frames_position[i] = i * 50;
    }
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 50;
    rect.height = 50;
    sprite.setTextureRect(rect);
}