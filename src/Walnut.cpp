#include "Walnut.hpp"

Walnut::Walnut(int x, int y) : Plant(x, y, WALNUT_PATH, WALNUT_FRAME, WALNUT_ANIMATION) {
    readSettingFile();
    plant_type = WALNUT;
    default_health = health;
}

void Walnut::readSettingFile(){
    ifstream setting_file(SETTING_PATH);
    string input;
    while(setting_file >> input){
        if(input == SETTING_DELIMITER){
            setting_file >> input;
            if(input == WALNUT_SETTING_KEYWORD){
                break;
            }
        }
    }
    int value;
    setting_file >> input >> value;
    if(input == WALNUT_HEALTH)
        health = value;
    else
        cerr << PIC_NOT_FOUND;

    setting_file >> input >> value;
    if(input == WALNUT_COOLDOWN)
        cooldown = value;
    else
        cerr << PIC_NOT_FOUND;
    setting_file.close();
}
void Walnut::update(){
    rect.top = 0 ;
    if(default_health / THREE <= health && health <= default_health * TWO / THREE){
        rect.top = frame_hight;
    }
    if(default_health / THREE > health){
        rect.top = TWO * frame_hight;
    }
    Plant::update();
}