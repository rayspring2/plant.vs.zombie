#include "Zombie.hpp"
#include "Plant.hpp"

Zombie::Zombie(int x, int y, string file_name, int frame_number) {
    row = x;
    column = y;
    frames_number = frame_number;
    for(int i = 0; i < frames_number; i++) {
        frames_position[i] = i * 50;
    }
    if (!texture.loadFromFile(file_name)) {
        cerr << "picture not found!\n";
		exit(-1);
    }
    sprite.setTexture(texture);
    IntRect rect;
    rect.width = 50;
    rect.height = 50;
    sprite.setTextureRect(rect);
}

void Zombie::hit(int destroy_value) {
    health -= destroy_value;
    if(health < 0) health = 0;
}

void Zombie::eat(Plant* eating_plant) {
    eating_plant -> hit(damage);
}

bool Zombie::isAlive() {
    if(!health) return false;
    return true;
}

void Zombie::update() {
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 10){
        clock.restart();
        cur_rect = (cur_rect + 1) % frames_number;
        IntRect rect;
        rect.width = 50;
        rect.height = 50;
        rect.left = frames_position[cur_rect];
        sprite.setTextureRect(rect);
    }
}


void Zombie::render(RenderWindow &window) {
    window.draw(sprite);
}