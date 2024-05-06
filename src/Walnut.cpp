#include "Walnut.hpp"

Walnut::Walnut(int x, int y) : Plant(x, y, "files/pic/Walnut.png") {
    pos = Vector2f(row, column);
    if (!texture.loadFromFile("files/pic/Walnut.png")) {
        cerr << "picture not found!\n";
		exit(-1);
    }
 
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 50;
    rect.height = 50;
    sprite.setTextureRect(rect);
}
