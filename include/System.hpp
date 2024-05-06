#ifndef SYSTEM_INCLUDE
#define SYSTEM_INCLUDE

#include "Global.hpp"
#include "PeaShooter.hpp"

enum State {
  IN_GAME,
  PAUSE_MENU,
  MAIN_MENU,
  VICTORY_SCREEN,
  GAMEOVER_SCREEN,
  EXIT
};

class System{
private:
	State game_state = IN_GAME;
	PeaShooter* peashooter;
	Texture bg_texture;
	Sprite bg_sprite;
	void update();
	void render();
	void handleEvent();
	void handleMousePress(Event ev);
	void handleMouseRelease(Event ev);
public:
	RenderWindow window;
	void run();
	System();
};

#endif