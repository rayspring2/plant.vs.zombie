#include "LawnCleaner.hpp"

LawnCleaner::LawnCleaner(int x, int y) : x(x) , y(y) {
	readSettingFile();
	if (!texture.loadFromFile(LAWNCLEANER_PATH)) {
        cerr << FILE_ERROR;
		exit(-1);
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}
void LawnCleaner::readSettingFile(){
	ifstream setting_file(SETTING_PATH);
    string input;
    while(setting_file >> input){
        if(input == SETTING_DELIMITER){
            setting_file >> input;
            if(input == LAWNCLEANER_SETTING_KEYWORD){
                break;
            }
        }
    }
    int value;
	setting_file >> input >> value;
    if(input == _CLEANER_UPDATE_TIME)
        CLEANER_UPDATE_TIME = value;
    else
        cerr << FILE_ERROR;

    setting_file >> input >> value;
    if(input == DEFAULT_SPEED)
        default_speed = value;
    else
        cerr << FILE_ERROR;

    setting_file.close();
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
