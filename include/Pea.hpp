#ifndef PEA_INCLUDE
#define PEA_INCLUDE

#include "Global.hpp"
#include "AttackPlant.hpp"

class Pea : public AttackPlant{
public:
	Pea(int x, int y, string file_name);
	~Pea(){};
protected:

};

#endif