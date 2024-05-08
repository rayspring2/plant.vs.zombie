#include <Ball.hpp>

Ball::Ball(Vector2f shooter_pos , string pic_path){
	pos = shooter_pos;
	////
	if(!texture.loadFromFile(pic_path)){
		cerr << "faild to load blue ball\n";
	}
	////
	sprite.setTexture(texture);
}


void Ball::update(){
	pos.x += speed;
	sprite.setPosition(pos);
}

bool Ball::isOut(){
	return sprite.getPosition().x > WIDTH ;
}

FloatRect Ball::getRect(){
	return sprite.getGlobalBounds();
}

void Ball::render(RenderWindow &window){
	window.draw(sprite);
}
Vector2f Ball::getPos(){
	return sprite.getPosition();
}