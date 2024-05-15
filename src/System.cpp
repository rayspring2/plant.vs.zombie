#include "System.hpp"
#include "Primary.hpp"

System::System(){
	window.create(VideoMode(WIDTH,HEIGHT), TITLE);
	window.setFramerateLimit(FRAME_RATE);
	if(!bg_texture.loadFromFile(BG_PATH)){
		cerr << PIC_NOT_FOUND;
		exit(-1);
	}
	if(!zombie_texture.loadFromFile(ZM_PATH)){
		cerr << PIC_NOT_FOUND;
		exit(-1);
	}
	game = new Game();
	zombie_sprite.setTexture(zombie_texture);
	zombie_sprite.setScale(ZOMBIE_SCALE, ZOMBIE_SCALE);

	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(WIDTH / bg_sprite.getLocalBounds().width,
    HEIGHT / bg_sprite.getLocalBounds().height);
	if(!font.loadFromFile(FONT_PATH)) {
        cout << FONT_NOT_FOUND;
        exit(0);
    }
	text.setFont(font);
    text.setColor(Color :: Red);
    text.setCharacterSize(FONT_SIZE_TEXT);

	Vector2f zom_pos = {bg_sprite.getPosition().x + ZOM_POS_X, bg_sprite.getPosition().y + ZOM_POS_Y};
    zombie_sprite.setPosition(zom_pos);
    Vector2f text_pos = {bg_sprite.getPosition().x + SYSTEM_TEXT_POS_X, bg_sprite.getPosition().y + SYSTEM_TEXT_POS_Y};
    text.setPosition(text_pos);
	text.setString(GAME_OVER_TEXT);
	if(!music.openFromFile(MUSIC_PATH)){
		cerr << FILE_ERROR;
		exit(-1);
	}
	music.setLoop(true);
	music.play();
}

void System::run(){
	while(window.isOpen() and game_state != EXIT){
		update();
		handleEvent();
		render();
	}
}

void System :: updateOverGame() {

}

void System::update(){
	switch (game_state) {
	case (IN_GAME): {
		if(game->isGameOver()) {
			updateOverGame();
			bg_sprite.setColor(TRANS_BACK);
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
		if(game->getDragStatus()) {
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