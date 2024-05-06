#include "SunFlower.hpp"

SunFlower::SunFlower(int x, int y) : Plant(x, y, "files/pic/sunflower.png") {
    pos = Vector2f(row, column);
    if (!texture.loadFromFile("files/pic/sunflower.png")) {
        cerr << "picture not found!\n";
		exit(-1);
    }

    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 50;
    rect.height = 50;
    sprite.setTextureRect(rect);
}
