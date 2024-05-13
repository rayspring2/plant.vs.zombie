#ifndef GAME_INCLUDE
#define GAME_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"
#include "AttackPlant.hpp"
#include "PeaShooter.hpp"
#include "SnowPea.hpp"
#include "Ball.hpp"
#include "BallIcy.hpp"
#include "BallGreen.hpp"
#include "SunFlower.hpp"
#include "Zombie.hpp"
#include "HairMetal.hpp"
#include "NormalZombie.hpp"
#include "Walnut.hpp"
#include "Sun.hpp"
const int ZMOBIETYPESCNT = 2;
/////
const int ZOMBIE_START_X = 1000;
const int ZOMBIE_GENERATE_PERIOD = 10000;
const int SUN_FALLDOWN_SPEED = 10; 
const int SUN_GENERATE_PERIOD = 10000;
class Game{
public:
	Game();
	~Game(){};
	void update();
	void render(RenderWindow &window);
	void checkEating();
	Position play_ground_position[6][10];
protected:
	int money;
	Plant* play_ground[GROUNDROWS+1][GROUNDCOLUMNS+1];
private:
	Clock ball_clock;
	Clock sun_clock;
	vector<Zombie*> zombies;
	vector<Ball*> balls;
	vector<Sun*> suns;
	Clock clock;
	void genZombie();
	void deleteUnvalidBalls();
	void handleCollision(); //after you added zombies:))
	bool cellIsEmpty(Plant* p);
	void addAttackPlantBall(AttackPlant* attack_plant);
	void removeDeadZombies();
	void updatePlayGround();
	void deleteDeadPlants();
	void deleteDeadSuns();
	void addSunflowerSun(SunFlower* sun_flower);
	void genSun();
};


#endif