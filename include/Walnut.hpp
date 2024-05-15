#ifndef WALNUT_INCLUDE
#define WALNUT_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"
const string WALNUT_SETTING_KEYWORD = "WALNUT";
const string WALNUT_PATH = "files/pic/walnut_all.png";
const int WALNUT_FRAME = 3;
const int WALNUT_ANIMATION= 100;
const string WALNUT_HEALTH = "health:";
const string WALNUT_COOLDOWN = "cooldown:";
const int THREE = 3;


class Walnut : public Plant{
private:
	void readSettingFile();
public:
	Walnut(int x, int y);
	void update() override;
protected:
    int default_health;
};

#endif