#include "SunFlower.hpp"

SunFlower::SunFlower(int x, int y) : Plant(x, y, "files/pic/sunflower2.png", 25) {
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
    if(input == "health:")
        health = value;
    else
        cerr << "file currupted! health not found\n";

    setting_file >> input >> value;
    if(input == "cooldown:")
        cooldown = value;
    else
        cerr << "file currupted! cooldown not found\n";
    setting_file.close();
}

Sun* SunFlower::makeSun() {
    sun_clock.restart();
    return new Sun(x, y , 0);
}

Time SunFlower::getShootTimeElapsed(){
    return sun_clock.getElapsedTime();
}
int SunFlower::getCoolDownTime(){
    return cooldown;
}

