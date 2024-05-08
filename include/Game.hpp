#ifndef GAME_INCLUDE
#define GAME_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"
#include "Zombie.hpp"

class Game{
public:
	Game();
	~Game(){};
	void handler();
	Position play_ground_position[6][10];
	vector<Zombie*> zombies;
protected:
	int money;
	Plant* play_ground[6][10];
	//Position play_ground_position[6][10];
	
};

#endif