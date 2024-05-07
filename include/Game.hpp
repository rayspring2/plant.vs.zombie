#ifndef GAME_INCLUDE
#define GAME_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"
#include "Zombie.hpp"

class Game{
public:
	Game();
	~Game(){};
protected:
	int money;
	Plant* play_ground[5][9];
	vector<Zombie*> zombies[5];
};

#endif