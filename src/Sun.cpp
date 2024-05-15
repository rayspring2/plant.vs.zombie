#include "Sun.hpp"

Sun::Sun(int x, int y , int yspeed):x(x) , y(y) , yspeed(yspeed) {
	readSettingFile();
    for(int i = 0; i < SUN_FRAME_NUMBER; i++) {
        frames_position[i] = i * SUN_FRANE_WIDTH;
    }
    if (!texture.loadFromFile(file_name)) {
        cerr << FILE_ERROR;
		exit(-1);
    }
    sprite.setTexture(texture);
    rect.width = SUN_FRANE_WIDTH;
    rect.height = SUN_FRANE_HEIGHT;
    sprite.setTextureRect(rect);
    sprite.setPosition(x, y);
    life_clock.restart();
}	
void Sun::readSettingFile(){
    ifstream setting_file(SETTING_PATH);
    string input;
    while(setting_file >> input){
        if(input == SETTING_DELIMITER){
            setting_file >> input;
            if(input == SUN_SETTING_KEYWORD){
                break;
            }
        }
    }
    int value;
    setting_file >> input >> value;
    if(input == _SUN_UPDATE_PERIOD)
        SUN_UPDATE_PERIOD = value;
    else
        cerr << FILE_ERROR;

    setting_file >> input >> value;
    if(input == LIFESPAN)
        lifespan = value;
    else
        cerr << FILE_ERROR;
    setting_file.close();
}

Sun::~Sun(){
	
}
void Sun::update(){
	Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= SUN_UPDATE_PERIOD) {
        clock.restart();
        y += yspeed;
        sprite.setPosition(x, y);
        cur_rect = (cur_rect + 1) % SUN_FRAME_NUMBER;
        rect.left = frames_position[cur_rect];
        sprite.setTextureRect(rect);
    }
}
void Sun::render(RenderWindow &window){
	window.draw(sprite);
}

bool Sun::isAlive(){
    if(life_clock.getElapsedTime().asMilliseconds() >= lifespan )
        return 0;
    return 1;
}