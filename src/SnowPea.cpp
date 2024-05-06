#include "SnowPea.hpp"

SnowPea::SnowPea(int x, int y) : Pea(x, y, "files/pic/snowpea.png") {
    pos = Vector2f(row, column);
    if (!texture.loadFromFile("files/pic/snowpea.png")) {
        cerr << "picture not found!\n";
		exit(-1);
    }
 
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 50;
    rect.height = 50;
    sprite.setTextureRect(rect);
}