#include "Walnut.hpp"

Walnut::Walnut(int x, int y) : Plant(x, y, "files/pic/walnut_all.png", 3, 100) {
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
void Walnut::update(){
    rect.top = 0 ;
    if(default_health / 3 <= health && health <= default_health * 2 / 3){
        rect.top = frame_hight;
    }
    if(default_health / 3 > health){
        rect.top = 2 * frame_hight;
    }
    Plant::update();
}