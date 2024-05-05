#include "../include/System.hpp"
System::System(){
	window.create(VideoMode(1920,1080),"Plants VS Zombies");
	if(!bg_texture.loadFromFile("files/pic/bg1.png")){ ///a bug has laid here!!!!!!!!
		cerr<<"back ground not found!\n";
		exit(-1);
	}
	bg_sprite.setTexture(bg_texture);
	//bg_sprite.scale(1.7, 1.7);
	
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