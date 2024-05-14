#include "Pea.hpp"

Pea::Pea(int x, int y, string file_name) : AttackPlant(x, y, file_name, 60) {
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
    if(input == "health:")
        health = value;
    else
        cerr << "file currupted! health not found\n";

    setting_file >> input >> value;
    if(input == "damage:")
        damage = value;
    else
        cerr << "file currupted! damage not found\n";
    
    setting_file >> input >> value;
    if(input == "cooldown:")
        cooldown = value;
    else
        cerr << "file currupted! cooldown not found\n";
    
    setting_file >> input >> value;
    if(input == "hit_rate:")
        hit_rate = value;
    else
        cerr << "file currupted! hit_rate not found\n";

    setting_file >> input >> value;
    if(input == "speed:")
        speed = value;
    else
        cerr << "file currupted! speed not found\n";
    setting_file.close();
}


// Gn by HyzeR //