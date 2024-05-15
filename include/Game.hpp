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
const int HAIRMETAL_OFFSET_Y_POSITION = 40;
const string GAME_SETTING_KEYWORD = "GAME";
const string MENU_SETTING_KEYWORD = "MENU";
const int TEMP_POSITION = 200;
const pair<int, int> INVALID_POSITION = pair<int, int>(-1, -1);
const int SPEED_COOLDOWN = 100;
const string GAME_ZOMBIE_START_X = "ZOMBIE_START_X:";
const string GAME_ZOMBIE_GENERATE_PERIOD = "ZOMBIE_GENERATE_PERIOD:";
const string GAME_SUN_FALLDOWN_SPEED = "SUN_FALLDOWN_SPEED:";
const string GAME_SUN_GENERATE_PERIOD = "SUN_GENERATE_PERIOD:";
const string GAME_HAS_PEASHOOTER = "PEASHOOTER:";
const string GAME_HAS_SNOWPEA = "SNOWPEA:";
const string GAME_HAS_WALNUT = "WALNUT:";
const string GAME_HAS_SUNFLOWER = "SUNFLOWER:";
const string GAME_PEASHOOTER_COOLDOWN = "PEASHOOTER_COOLDOWN:";
const string GAME_SNOWPEA_COOLDOWN = "SNOWPEA_COOLDOWN:";
const string GAME_WALNUT_COOLDOWN = "SUNFLOWER_COOLDOWN:";
const string GAME_SUNFLOWER_COOLDOWN = "WALNUT_COOLDOWN:";
const int LEFT_OF_PLAYGROUND = 216;
const int RIGHT_OF_PLAYGROUND = 954;
const int UP_OF_PLAYGROUND = 53;
const int DOWN_OF_PLAYGROUND = 523;
const string PEASHOOTER_MENU_PATH = "files/pic/PeashooterMenu.png";
const string SNOWPEA_MENU_PATH = "files/pic/SnowpeaMenu.png";
const string SUNFLOWER_MENU_PATH =  "files/pic/SunflowerMenu.png";
const string WALNUT_MENU_PATH = "files/pic/WalnutMenu.png";
const string PRICE_PEASHOOTER = "PRICE_PEASHOOTER:";
const string PRICE_SNOWPEA = "PRICE_SNOWPEA:";
const string PRICE_SUNFLOWER = "PRICE_SUNFLOWER:";
const string PRICE_WALNUT = "PRICE_WALNUT:";
const int HALF = 2;

/////
class Game{
private:
	int ZOMBIE_START_X;
	int ZOMBIE_GENERATE_PERIOD;
	int SUN_FALLDOWN_SPEED;
	int SUN_GENERATE_PERIOD;
	int hasPeashooter = 0, hasSnowpea = 0, hasWalnut = 0, hasSunflower = 0;
	int peashooterCooldown, snowpeaCooldown, sunflowerCooldown, walnutCooldown;
	int peashooterPrice, snowpeaPrice, sunflowerPrice, walnutPrice;
public:
	Game();
	~Game(){};
	void update(RenderWindow &window);
	void render(RenderWindow &window);
	void checkEating();
	Position play_ground_position[6][10];
	Plant* moved_plant = nullptr;
	bool inBackGround(Vector2i position);
	pair<int, int> findPlayGroundBlock(Vector2f plant_position);
	void plantRequest(RenderWindow &window);
	void createRequest(RenderWindow &window);
	PlantType selected_plant;
	bool isGameOver();
	bool getDragStatus() {return is_dragging;}
protected:
	Plant* play_ground[GROUNDROWS+1][GROUNDCOLUMNS+1];
private:
	void hasPlant();
	Icon* icon;
	Clock ball_clock;
	Clock sun_clock;
	bool is_dragging;
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
	void handleSunCollect(RenderWindow &window);
};


#endif