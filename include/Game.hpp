#ifndef GAME_INCLUDE
#define GAME_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"
#include "AttackPlant.hpp"
#include "PeaShooter.hpp"
#include "SnowPea.hpp"
#include "Ball.hpp"
#include "Zombie.hpp"

class Game{
public:
	Game();
	~Game(){};
	void update();
	void render(RenderWindow &window);
	void handler();
	vector<Zombie*> zombies;
	Position play_ground_position[6][10];
protected:
	int money;
	Plant* play_ground[GROUNDROWS][GROUNDCOLUMNS];
private:
	Clock ball_clock;
	vector<Ball*> balls;
	void deleteOutBalls();
	void handleCollision(); //after you added zombies:))
	bool cellIsEmpty(Plant* p);
	void addAttackPlantBall(AttackPlant* attack_plant);
};


#endif