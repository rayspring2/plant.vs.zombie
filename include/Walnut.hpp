#ifndef WALNUT_INCLUDE
#define WALNUT_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"
const string WALNUT_SETTING_KEYWORD = "WALNUT";
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