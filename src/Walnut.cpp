#include "Walnut.hpp"

Walnut::Walnut(int x, int y) : Plant(x, y, "files/pic/walnut_almodes.png", 3) {
    plant_type = WALNUT;
    health = 200;
    delfault_health = health;
    cooldown = 10;
    hit_rate = 0;
    price = 2;
}
/* 
void Walnut::update(Vector2i mouse_pos){
    cerr <<"has entered\n";
    rect.top = 0;
    if( delfault_health / 3 <= health && health <= 2 * delfault_health / 3 ){
        rect.top = frame_hight;
    }
    if( health <= delfault_health / 3){
        rect.top = 2 * frame_hight;
    }
    Plant::update();
} */