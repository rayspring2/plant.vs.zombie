#ifndef GAME_INCLUDE
#define GAME_INCLUDE
#include "Global.hpp"
#include "Plant.hpp"
#include "AttackPlant.hpp"
#include "PeaShooter.hpp"
#include "SnowPea.hpp"
#include "Ball.hpp"
#include "Zombie.hpp"
#include "Walnut.hpp"
#include "SunFlower.hpp"
#include "Icon.hpp"

class Game{
public:
	Game();
	~Game(){};
	void update();
	void render(RenderWindow &window);
	void handler();
	vector<Zombie*> zombies;
	pair<int, int> findPlayGroundBlock(Vector2f plant_position);
	Position play_ground_position[6][10];
	Plant* moved_plant = nullptr;
	bool is_drag = false;
	bool inBackGround(Vector2i position);
	int getIsValid() {return is_valid;}
	void plantRequest(RenderWindow &window);
	void createRequest(RenderWindow &window);
	bool is_dragging;
	PlantType selected_plant;
protected:
	int money;
	Icon* icon;
	Plant* play_ground[GROUNDROWS+1][GROUNDCOLUMNS+1];
private:
	Clock ball_clock;
	vector<Ball*> balls;
	int is_valid = 0;
	void deleteOutBalls();
	void handleCollision(); //after you added zombies:))
	bool cellIsEmpty(Plant* p);
	void addAttackPlantBall(AttackPlant* attack_plant);
};


#endif