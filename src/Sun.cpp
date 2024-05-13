#include "Sun.hpp"

Sun::Sun(int x, int y , int yspeed):x(x) , y(y) , yspeed(yspeed) {
	
    for(int i = 0; i < frame_number; i++) {
        frames_position[i] = i * sun_width;
    }
    if (!texture.loadFromFile(file_name)) {
        cerr << "picture not found!\n";
		exit(-1);
    }
    sprite.setTexture(texture);
    rect.width = sun_width;
    rect.height = sun_height;
    sprite.setTextureRect(rect);
    sprite.setPosition(x, y);
    life_clock.restart();
}	
Sun::~Sun(){
	
}
void Sun::update(){
	Time elapsed = clock.getElapsedTime();
    if(elapsed.asMilliseconds() >= 100) {
        clock.restart();
        y -= yspeed;
        sprite.setPosition(x, y);
        cur_rect = (cur_rect + 1) % frame_number;
        rect.left = frames_position[cur_rect];
        sprite.setTextureRect(rect);
    }
}
void Sun::render(RenderWindow &window){
	window.draw(sprite);
}

bool Sun::isAlive(){
    if(life_clock.getElapsedTime().asMilliseconds() >= lifespan )
        return 0;
    return 1;
}