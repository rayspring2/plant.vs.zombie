#ifndef GAME_INCLUDE
#define GAME_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"

class Game{
public:
	Game();
	~Game(){};
protected:
	int money;
	Plant* play_ground[5][9];
};

#endif