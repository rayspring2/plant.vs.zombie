#include "Zombie.hpp"
#include "Plant.hpp"

Zombie::Zombie(int x, int y, string file_name, int frame_number, int zombie_width,  int zombie_height) :
zombie_width(zombie_width), zombie_height(zombie_height), frame_number(frame_number) {
    row = x;
    column = y;
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
    sprite.setPosition(row, column);
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
    if(elapsed.asMilliseconds() >= 50 and row > 220 && mode == "walking") {
        row -= speed;
        sprite.setPosition(row, column);
    }

    if(elapsed.asMilliseconds() >= 100){
        clock.restart();
        cur_rect = (cur_rect + 1) % frame_number;
        IntRect rect;
        rect.width = zombie_width;
        rect.height = zombie_height;
        rect.left = frames_position[cur_rect];
        sprite.setTextureRect(rect);

    }
}


void Zombie::render(RenderWindow &window) {
    window.draw(sprite);
}

FloatRect Zombie::getRect(){
    return sprite.getGlobalBounds();
}

bool Zombie::compare(Zombie* x, Zombie* y){
    return x->get_row() < y->get_row();
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