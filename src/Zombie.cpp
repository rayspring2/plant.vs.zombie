#include "Zombie.hpp"
#include "Plant.hpp"

Zombie::Zombie(int x, int y, string file_name, int frame_number, int zombie_width,  int zombie_height) :
zombie_width(zombie_width), zombie_height(zombie_height), frame_number(frame_number) {
    row = x;
    column = y;
    gameover = false;
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
    if(health < 0) health = 0;
}

void Zombie::eat(Plant* eating_plant) {
    eating_plant -> hit(damage);
}

bool Zombie::isAlive() {
    if(!health) return false;
    return true;
}

bool Zombie::getGameOverStatus() {
    return gameover;
}

void Zombie::update() {
    Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 50 and row > 220) {
        row -= 2;
        sprite.setPosition(row, column);
    }
    if(row <= 220) {
        gameover = true;
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