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
#include "LawnCleaner.hpp"
const int ZMOBIETYPESCNT = 2;
const int HAIRMETAL_OFFSET_Y_POSITION = 40;
const string GAME_SETTING_KEYWORD = "GAME";
/////
class Game{
private:
	int ZOMBIE_START_X;
	int ZOMBIE_GENERATE_PERIOD;
	int SUN_FALLDOWN_SPEED; 
	int SUN_GENERATE_PERIOD;
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
	LawnCleaner* lawncleaners[GROUNDROWS+1];
	Clock clock;
	void readSettingFile();
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