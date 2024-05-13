
#include "System.hpp"
#include "Primary.hpp"

System::System(){
	window.create(VideoMode(WIDTH,HEIGHT),"Plants VS Zombies");
	window.setFramerateLimit(FRAME_RATE);
	if(!bg_texture.loadFromFile(BG_PATH)){
		cerr << "back ground not found!\n";
		exit(-1);
	}
	game = new Game();
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(WIDTH / bg_sprite.getLocalBounds().width,
    HEIGHT / bg_sprite.getLocalBounds().height);
}

void System::run(){
	while(window.isOpen() && game_state != EXIT){
		update();
		handleEvent();
		render();
	}
}

void System::update_gameover() {
	bg_sprite.setColor(sf::Color(255, 255, 255, 128));
}

void System::update(){
	switch (game_state) {
	case (IN_GAME): {
		game->update();
		if(game->checkGameOver()) game_state = GAMEOVER_SCREEN;
		break;
	}
	case (PAUSE_MENU):
		break;
	case (MAIN_MENU): {
		break;
	}
	case (VICTORY_SCREEN):
		break;
	case (GAMEOVER_SCREEN): {
		update_gameover();
		cout << "game over" << endl;
		break;
	}
	case(EXIT):
		break;
	}
}

void System::handleEvent(){
	Event event;
	while (window.pollEvent(event)){
		switch (event.type) {
			case (Event::Closed):
				// window.close();
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
	game->render(window);
	window.display();
}

void System::handleMousePress(Event ev){
	if(ev.mouseButton.button == Mouse::Right){
		return;
	}
	Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
	switch (game_state) {
	case (IN_GAME): {
		if(game->is_dragging) {
			game->plantRequest(window);
		}
		else {
			game->createRequest(window);
		}
		break;
	}
	case (PAUSE_MENU):
		break;
	case (MAIN_MENU): {
		break;
	}
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