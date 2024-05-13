#ifndef PEA_INCLUDE
#define PEA_INCLUDE

#include "Global.hpp"
#include "AttackPlant.hpp"

const int PEA_MOUNTH_X = 30;
const int PEA_MOUNTH_Y = 15;

class Pea : public AttackPlant{
public:
	Pea(int x, int y, string file_name);
	~Pea(){};
protected:

};

#endif