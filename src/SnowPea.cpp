#include "SnowPea.hpp"

SnowPea::SnowPea(int x, int y) : Pea(x, y, "files/pic/snowpea.png") {
    health = 30;
    damage = 8;
    cooldown = 9;
    hit_rate = 5;
    speed = 5;
    price = 6;
}