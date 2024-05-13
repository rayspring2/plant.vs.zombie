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
#include "Icon.hpp"

class Game{
public:
	Game();
	~Game(){};
	PlantType selected_plant;
	void deleteUnvalidBalls(){};
	void update();
	void render(RenderWindow &window);
	Icon* icon;
	void checkEating();
	Position play_ground_position[6][10];
	pair<int, int> findPlayGroundBlock(Vector2f plant_position);
	bool inBackGround(Vector2i position);
	void plantRequest(RenderWindow &window);
	Plant* moved_plant;
	bool is_dragging;
	bool checkGameOver();
	void createRequest(RenderWindow &window);
	void deleteOutBalls();
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