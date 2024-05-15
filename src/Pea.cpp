#include "Pea.hpp"

Pea::Pea(int x, int y, string file_name) : AttackPlant(x, y, file_name, 60, 10) {
}
void Pea::readSettingFile( string type){
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
    if(input == PEA_HEALTH)
        health = value;
    else
        cerr << FILE_ERROR;

    setting_file >> input >> value;
    if(input == PEA_DAMAGE)
        damage = value;
    else
        cerr << FILE_ERROR;
    
    setting_file >> input >> value;
    if(input == PEA_COOLDOWN)
        cooldown = value;
    else
        cerr << FILE_ERROR;
    
    setting_file >> input >> value;
    if(input == PEA_HIT_RATE)
        hit_rate = value;
    else
        cerr << FILE_ERROR;

    setting_file >> input >> value;
    if(input == PEA_SPEED)
        speed = value;
    else
        cerr << FILE_ERROR;
    setting_file.close();
}


// Gn by HyzeR //