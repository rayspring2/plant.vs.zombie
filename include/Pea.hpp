#ifndef PEA_INCLUDE
#define PEA_INCLUDE

#include "Global.hpp"
#include "AttackPlant.hpp"

const int PEA_MOUNTH_X = 30;
const int PEA_MOUNTH_Y = 15;

const string PEA_HEALTH = "health:";
const string PEA_DAMAGE = "damage:";
const string PEA_COOLDOWN = "cooldown:";
const string PEA_HIT_RATE = "hit_rate:";
const string PEA_SPEED = "speed:";

class Pea : public AttackPlant{
private:
public:
	Pea(int x, int y, string file_name);
	~Pea(){};
protected:
	void readSettingFile( string type);

};

#endif