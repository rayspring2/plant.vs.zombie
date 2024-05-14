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
#include "Icon.hpp"
const int ZMOBIETYPESCNT = 2;
/////
const int ZOMBIE_START_X = 1000;
const int ZOMBIE_GENERATE_PERIOD = 10000;
const int SUN_FALLDOWN_SPEED = 10; 
const int SUN_GENERATE_PERIOD = 7000;
class Game{
public:
	Game();
	~Game(){};
	void update(RenderWindow &window);
	void render(RenderWindow &window);
	void checkEating();
	Position play_ground_position[6][10];
	Plant* moved_plant = nullptr;
	bool is_drag = false;
	bool inBackGround(Vector2i position);
	pair<int, int> findPlayGroundBlock(Vector2f plant_position);
	void plantRequest(RenderWindow &window);
	void createRequest(RenderWindow &window);
	bool is_dragging;
	PlantType selected_plant;
	bool isGameOver();
	Icon* icon;
protected:
	Plant* play_ground[GROUNDROWS+1][GROUNDCOLUMNS+1];
private:
	Clock ball_clock;
	Clock sun_clock;
	vector<Zombie*> zombies;
	vector<Ball*> balls;
	vector<Sun*> suns;
	LawnCleaner* lawncleaners[GROUNDROWS+1];
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
	void handleSunCollect(RenderWindow &window);
};


#endif