#include "System.hpp"
#include "Primary.hpp"

System::System(){
	window.create(VideoMode(WIDTH,HEIGHT),"Plants VS Zombies");
	window.setFramerateLimit(FRAME_RATE);

	peashooter = new NormalZombie(1000, 100);

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
	Vector2i pos = Mouse::getPosition(window);
	//peashooter->update();
	game.update();
}

void System::handleEvent(){
	Event event;
	while (window.pollEvent(event)){
	switch (event.type) {
    case (Event::Closed):
    	window.close();
    	game_state = EXIT;
    	break;
    case (Event::MouseButtonPressed):
    	handleMousePress(event);
    	break;
    case (Event::MouseButtonReleased):
    	handleMouseRelease(event);
    	break;
    default:
    	break;
    }
	}
}

void System::render(){
	window.clear();
	window.draw(bg_sprite);
	peashooter->render(window); 
	game.render(window);
	window.display();
}

void System::handleMousePress(Event ev){
	if(ev.mouseButton.button == Mouse::Right){
		return;
	}
	Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
	switch (game_state) {
	case (IN_GAME):
		//peashooter->handleMousePress(pos);
		break;
	case (PAUSE_MENU):
		break;
	case (MAIN_MENU):
		break;
	case (VICTORY_SCREEN):
		break;
	case (GAMEOVER_SCREEN):
		break;
	case(EXIT):
		break;
  }
}
void System::handleMouseRelease(Event ev){
	if (ev.mouseButton.button == Mouse::Right)
    	return;
  Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
  switch (game_state) {
	case (IN_GAME):
		//peashooter->handleMouseRelease(/*pos*/);
		break;
	case (PAUSE_MENU):
		break;
	case (MAIN_MENU):
		break;
	case (VICTORY_SCREEN):
		break;
	case (GAMEOVER_SCREEN):
    	break;
	case(EXIT):
		break;

  }
}