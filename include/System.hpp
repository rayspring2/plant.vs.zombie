#ifndef SYSTEM_INCLUDE
#define SYSTEM_INCLUDE

#include "Global.hpp"
#include "PeaShooter.hpp"
#include "Pea.hpp"
#include "SnowPea.hpp"
#include "SunFlower.hpp"
#include "Walnut.hpp"
#include "AttackPlant.hpp"
#include "Zombie.hpp"
#include "NormalZombie.hpp"
#include "KernelPult.hpp"
#include "HairMetal.hpp"
#include "Game.hpp"

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
	NormalZombie* peashooter;
	Texture bg_texture;
	Sprite bg_sprite;
	void update();
	void render();
	void handleEvent();
	void handleMousePress(Event ev);
	void handleMouseRelease(Event ev);
public:
	RenderWindow window;
	Game game;
	void run();
	System();
};

#endif