#ifndef NORMALZOMBIE_INCLUDE
#define NORMALZOMBIE_INCLUDE
#include "Global.hpp"
#include "Zombie.hpp"
const string NORMALEZOMBIE_SETTING_KEYWORD = "NORMALEZOMBIE";
class NormalZombie : public Zombie{
protected:
   
public:
    NormalZombie(int x, int y ,  int row);
};

#endif