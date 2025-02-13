#include <Ball.hpp>

Ball::Ball(Vector2f shooter_pos , string pic_path ) {
	row = ((int)shooter_pos.y - GROUND_UP_OFFSET) / CELLHIGHT + 1 ;
	pos = shooter_pos;
	if(!texture.loadFromFile(pic_path)){
		cerr << _BALL_DID_NOT_LOAD;
	}
	sprite.setTexture(texture);
}
void Ball::readSettingFile(string type){
	ifstream setting_file(SETTING_PATH);
    string input;
    while(setting_file >> input){
        if(input == SETTING_DELIMITER){
            setting_file >> input;
            if(input == type){
                break;
            }
        }
    }
    int value;
    setting_file >> input >> value;
    if(input == _DAMAGE_VALUE)
        damage_value = value;
    else
        cerr << _BALL_SETTING_DAMAGE;

	setting_file >> input >> value;
    if(input == _SPEED_VALUE)
        speed = value;
    else
        cerr << _BALL_SETTING_SPEED;

    setting_file.close();
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