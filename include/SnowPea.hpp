#ifndef SNOWPEA_INCLUDE
#define SNOWPEA_INCLUDE

#include "Global.hpp"
#include "Pea.hpp"
#include "BallIcy.hpp"

class SnowPea : public Pea{
public:
	SnowPea(int x, int y);
	~SnowPea() {};
	Ball* addBall() override;
private:
};

#endif