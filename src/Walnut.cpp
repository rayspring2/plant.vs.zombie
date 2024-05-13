#include "Walnut.hpp"

Walnut::Walnut(int x, int y) : Plant(x, y, "files/pic/normal_walnut.png", 3, 100) {
    plant_type = WALNUT;
    health = 200;
    default_health = health;
    cooldown = 10;
    hit_rate = 0;
    price = 2;
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