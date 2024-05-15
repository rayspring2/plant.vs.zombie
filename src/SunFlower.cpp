#include "SunFlower.hpp"

SunFlower::SunFlower(int x, int y) : Plant(x, y, SUNFLOWER_PATH, 25, 60) {
    readSettingFile();
    plant_type = SUNFLOWER;
}
void SunFlower::readSettingFile(){
    ifstream setting_file(SETTING_PATH);
    string input;
    while(setting_file >> input){
        if(input == SETTING_DELIMITER){
            setting_file >> input;
            if(input == SUNFLOWER_SETTING_KEYWORD){
                break;
            }
        }
    }
    int value;
    setting_file >> input >> value;
    if(input == HEALTH)
        health = value;
    else
        cerr << FILE_ERROR;

    setting_file >> input >> value;
    if(input == COOLDOWN)
        cooldown = value;
    else
        cerr << FILE_ERROR;
    setting_file.close();
}

Sun* SunFlower::makeSun(Vector2f plant_position) {
    sun_clock.restart();
    return new Sun(plant_position.x, plant_position.y , 0);
}

Time SunFlower::getShootTimeElapsed(){
    return sun_clock.getElapsedTime();
}
int SunFlower::getCoolDownTime(){
    return cooldown;
}

