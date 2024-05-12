#include "Zombie.hpp"
#include "Plant.hpp"

Zombie::Zombie(int x, int y, string file_name, int frame_number, int zombie_width,  int zombie_height) :
x(x), y(y), zombie_width(zombie_width), 
zombie_height(zombie_height), frame_number(frame_number) {
    row = (y - 53) / 94 + 1 ;
    current_speed = speed;
    for(int i = 0; i < frame_number; i++) {
        frames_position[i] = i * zombie_width;
    }
    if (!texture.loadFromFile(file_name)) {
        cerr << "picture not found!\n";
		exit(-1);
    }
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = zombie_width;
    rect.height = zombie_height;
    sprite.setTextureRect(rect);
    sprite.setPosition(x, y);
}

void Zombie::hit(int destroy_value) {
    health -= destroy_value;
}

void Zombie::eat(Plant* eating_plant) {
    
}

bool Zombie::isAlive() {
    if(health <= 0) return false;
    return true;
}

void Zombie::update() {
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 50 and x > 220 && mode == WALKING) {
        x -= speed;
        sprite.setPosition(x, y);
    }

    if(elapsed.asMilliseconds() >= 100){
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
    if( elapse.asSeconds() >= hit_rate ){
        eating_clock.restart();
        return 1;
    }
    return 0;
}