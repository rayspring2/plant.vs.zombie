#include "System.hpp"
#include "Primary.hpp"

System::System(){
	window.create(VideoMode(WIDTH,HEIGHT),"Plants VS Zombies");
	window.setFramerateLimit(FRAME_RATE);
	if(!bg_texture.loadFromFile(BG_PATH)){
		cerr << "back ground not found!\n";
		exit(-1);
	}
	if(!zombie_texture.loadFromFile(ZM_PATH)){
		cerr << "back ground not found!\n";
		exit(-1);
	}
	game = new Game();
	zombie_sprite.setTexture(zombie_texture);
	zombie_sprite.setScale(0.1, 0.1);

	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(WIDTH / bg_sprite.getLocalBounds().width,
    HEIGHT / bg_sprite.getLocalBounds().height);
	if(!font.loadFromFile("files/font/HouseofTerrorRegular.otf")) {
        cout << "font can not load";
        exit(0);
    }
	text.setFont(font);
    text.setColor(Color :: Red);
    text.setCharacterSize(100);

	Vector2f zom_pos = {bg_sprite.getPosition().x + 550, bg_sprite.getPosition().y + 140};
    zombie_sprite.setPosition(zom_pos);
    Vector2f text_pos = {bg_sprite.getPosition().x + 100, bg_sprite.getPosition().y + 50};
    text.setPosition(text_pos);
	text.setString("THE ZOMBIES ATE YOUR BRAINS!");
}

void System::run(){
	while(window.isOpen()){
		update();
		handleEvent();
		render();
	}
}

void System :: updateOverGame() {
	bg_sprite.setColor(sf::Color(255, 255, 255, 128));

}

void System::update(){
	switch (game_state) {
	case (IN_GAME): {
		if(game->isGameOver()) {
			updateOverGame();
			game_state = GAMEOVER_SCREEN;
		}
		else {
			game->update(window);
		}
	}
	case (PAUSE_MENU):
		break;
	case (MAIN_MENU):
		break;
	case (VICTORY_SCREEN):
		break;
	case (GAMEOVER_SCREEN): {
		updateOverGame();
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
	switch (game_state) {
	case (IN_GAME): {
		window.draw(bg_sprite);
		game->render(window);
		break;
	}
	case (PAUSE_MENU):
		break;
	case (MAIN_MENU):
		break;
	case (VICTORY_SCREEN):
		break;
	case (GAMEOVER_SCREEN):{
		window.draw(bg_sprite);
		window.draw(text);
		window.draw(zombie_sprite);
		break;
	}
	case(EXIT):
		break;
  	}
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