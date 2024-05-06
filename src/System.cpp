#include "System.hpp"
#include "Primary.hpp"

System::System(){
	window.create(VideoMode(WIDTH,HEIGHT),"Plants VS Zombies");
	window.setFramerateLimit(FRAME_RATE);
	if(!bg_texture.loadFromFile(BG_PATH)){
		cerr << "back ground not found!\n";
		exit(-1);
	}
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(WIDTH / bg_sprite.getLocalBounds().width,
    HEIGHT / bg_sprite.getLocalBounds().height);
}

void System::run(){
	while(window.isOpen()){
		update();
		handleEvent();
		render();
	}
}

void System::update(){
}

void System::handleEvent(){
	Event event;
	while (window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void System::render(){
	window.clear();
	window.draw(bg_sprite);
	window.display();
}