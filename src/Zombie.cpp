#include "Zombie.hpp"
#include "Plant.hpp"

Zombie::Zombie(int x, int y, int row, string file_name, int frame_number, int zombie_width,  int zombie_height) :
x(x), y(y), row(row), zombie_width(zombie_width), 
zombie_height(zombie_height), frame_number(frame_number) {
    readSettingFile();
    current_speed = speed;
    for(int i = 0; i < frame_number; i++) {
        frames_position[i] = i * zombie_width;
    }
    if (!texture.loadFromFile(file_name)) {
        cerr << PIC_NOT_FOUND;
		exit(-1);
    }
    reduced_speed_clock.restart();
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = zombie_width;
    rect.height = zombie_height;
    sprite.setTextureRect(rect);
    sprite.setPosition(x, y);
}

void Zombie::readSettingFile(){
    ifstream setting_file(SETTING_PATH);
    string input;
    while(setting_file >> input){
        if(input == SETTING_DELIMITER){
            setting_file >> input;
            if(input == ZOMBIE_SETTING_KEYWORD){
                break;
            }
        }
    }
    int value;
    setting_file >> input >> value;
    if(input == _ZOMBIE_UPDATE_TIME)
        ZOMBIE_UPDATE_TIME = value;
    else
        cerr << PIC_NOT_FOUND;
    setting_file.close();
}
void Zombie::readSettingFile( string type){
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
    if(input == ZOMBIE_HEALTH)
        health = value;
    else
        cerr << PIC_NOT_FOUND;

    setting_file >> input >> value;
    if(input == ZOMBIE_HIT_RATE)
        hit_rate = value;
    else
        cerr << PIC_NOT_FOUND;
    
    setting_file >> input >> value;
    if(input == ZOMBIE_DAMAGE)
        damage = value;
    else
        cerr << PIC_NOT_FOUND;
    
    setting_file >> input >> value;
    if(input == ZOMBIE_SPEED)
        speed = value;
    else
        cerr << PIC_NOT_FOUND;

    setting_file.close();
}

void Zombie::hit(int destroy_value) {
    health -= destroy_value;
}

bool Zombie::isAlive() {
    if(health <= 0) return false;
    return true;
}

void Zombie::update() {
    Time elapsed = clock.getElapsedTime();

    if(elapsed.asMilliseconds() >= ZOMBIE_UPDATE_TIME * speed_scale){
        if( x > GROUND_LEFT_OFFSET && mode == WALKING){
            x -= speed;
            sprite.setPosition(x, y);
        }
        if(x <= GROUND_LEFT_OFFSET) {
            gameover = true;
        }
        clock.restart();
        cur_rect = (cur_rect + 1) % frame_number;
        IntRect rect;
        rect.width = zombie_width;
        rect.height = zombie_height;
        rect.left = frames_position[cur_rect];
        rect.top = 0;
        if(mode == EATING)
            rect.top = zombie_height;
        sprite.setTextureRect(rect);
    }
    if(reduced_speed_clock.getElapsedTime().asMilliseconds() >= ZOMBIE_REDUCED && speed_scale == TWO){
        speed_scale = ONE;
        sprite.setColor(Color::White);
    }
    
    
}


void Zombie::render(RenderWindow &window) {
    window.draw(sprite);
}

FloatRect Zombie::getRect(){
    return sprite.getGlobalBounds();
}


int Zombie::getDamageValue(){
    return damage;
}
bool Zombie::isReadytoHit(){
    Time elapse = eating_clock.getElapsedTime();
    if( elapse.asSeconds() >= hit_rate * speed_scale ){
        eating_clock.restart();
        return 1;
    }
    return 0;
}

void Zombie::reduceSpeed(){
    speed_scale = TWO;
    reduced_speed_clock.restart();
    sprite.setColor(ZOMBIE_COLOR);
}
void Zombie::die(){
    health = 0;
}