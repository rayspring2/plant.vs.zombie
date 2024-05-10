#ifndef NORMALZOMBIE_INCLUDE
#define NORMALZOMBIE_INCLUDE
#include "Global.hpp"
#include "Zombie.hpp"

class NormalZombie : public Zombie{
protected:

public:
    NormalZombie(int x, int y);
    ~NormalZombie() {};
};

#endif