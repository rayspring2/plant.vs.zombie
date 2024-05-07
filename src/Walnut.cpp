#include "Walnut.hpp"

Walnut::Walnut(int x, int y) : Plant(x, y, path[status], 3) {
    health = 200;
    cooldown = 10;
    hit_rate = 0;
    price = 2;
}

void Walnut::changeStatus() {
    if(status == 0) status = 1;
    else if(status == 1) status = 2;
}