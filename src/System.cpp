#include "System.hpp"
#include "Primary.hpp"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
	while(window.isOpen()){
		update();
		handleEvent();
		render();
	}
}

void System::gen_zombie(){
	Time elapsed = clock.getElapsedTime();
	if(elapsed.asSeconds() >= 1) {
		clock.restart();
		int x = rng() % 5;
		int zombie_row_position = game->play_ground_position[x + 1][1].up;
		int type_of_zombie = rng() % 2;
		if(type_of_zombie) {
			HairMetal* zm = new HairMetal(1000, zombie_row_position);
			game->zombies.push_back(zm);
		}
		else {
			NormalZombie* zm = new NormalZombie(1000, zombie_row_position);
			game->zombies.push_back(zm);
		}
	}
}

void System::update(){
//	gen_zombie();
	for(int i = 0; i < game->zombies.size(); i++) game->zombies[i]->update();
	game->update(window);

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
	game->render(window);
	for(int i = 0; i < game->zombies.size(); i++) game->zombies[i]->render(window);
	window.display();
}

void System::handleMousePress(Event ev){
	if(ev.mouseButton.button == Mouse::Right){
		return;
	}
	Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
	switch (game_state) {
	case (IN_GAME):{
		game->plantRequeset(window);
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
	//	if(game->moved_plant != nullptr and game->is_drag == true) game->moved_plant->handleMouseRelease();
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