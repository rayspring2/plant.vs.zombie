#include "LawnCleaner.hpp"

LawnCleaner::LawnCleaner(int x, int y) : x(x) , y(y) {
	if (!texture.loadFromFile("files/pic/LawnCleaner.png")) {
        cerr << "picture not found!\n";
		exit(-1);
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}
void LawnCleaner::update(){
	Time elapsed = clock.getElapsedTime();

    if(elapsed.asMilliseconds() >= CLEANER_UPDATE_TIME){
		x += speed;
        sprite.setPosition(x, y);
		clock.restart();
	}
}
void LawnCleaner::render(RenderWindow &window){
	window.draw( sprite );
}
void LawnCleaner::move(){
	speed = default_speed;
}
bool LawnCleaner::isOut(){
	if( x >= WIDTH)
		return 1;
	return 0;
}

FloatRect LawnCleaner::getRect(){
    return sprite.getGlobalBounds();
}
