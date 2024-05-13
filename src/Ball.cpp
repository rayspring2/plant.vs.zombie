#include <Ball.hpp>

Ball::Ball(Vector2f shooter_pos , string pic_path , int damage_value) : 
	damage_value(damage_value){
	row = ((int)shooter_pos.y - 53) / 94 + 1 ;
	pos = shooter_pos;
	if(!texture.loadFromFile(pic_path)){
		cerr << "faild to load blue ball\n";
	}
	sprite.setTexture(texture);
}

int Ball::getDamageValue(){
	return damage_value;
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

bool Ball::isCollided(){
	return is_collided;
}
void Ball::collide(){
	is_collided = 1;
}

int Ball::getRow(){
	return row;
}