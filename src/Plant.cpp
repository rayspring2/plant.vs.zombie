#include "../include/Plant.hpp"

Plant::Plant(int x, int y) {
    row = x;
    column = y;
}

void Plant::eat(int destroy_value) {
    health -= destroy_value;
}