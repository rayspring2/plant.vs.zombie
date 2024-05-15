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
#include "HairMetal.hpp"
#include "Game.hpp"

const string TITLE = "Plants VS Zombies";
const string GAME_OVER_TEXT = "THE ZOMBIES ATE YOUR BRAINS!";
const float ZOMBIE_SCALE = 0.1;
const int FONT_SIZE_TEXT = 100;
const int ZOM_POS_X = 550;
const int ZOM_POS_Y = 140;
const int SYSTEM_TEXT_POS_X = 100;
const int SYSTEM_TEXT_POS_Y = 50;
const sf::Color TRANS_BACK = sf::Color(255, 255, 255, 128);
const string MUSIC_PATH = "files/mainmusic.ogg";

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
	Texture bg_texture;
	Sprite bg_sprite;
	Texture zombie_texture;
	Sprite zombie_sprite;
	Text text;
	Font font;
	Game* game;
	RenderWindow window;
	void update();
	void pdateOverGame();
	void render();
	void handleEvent();
	void handleMousePress(Event ev);
	void handleMouseRelease(Event ev);
	void updateOverGame();
	Music music;
public:
	void run();
	System();
};

#endif