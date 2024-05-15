#ifndef SNOWPEA_INCLUDE
#define SNOWPEA_INCLUDE

#include "Global.hpp"
#include "Pea.hpp"
#include "BallIcy.hpp"
const string SNOWPEA_PATH = "files/pic/snowpea.png";
const string SNOWPEA_SETTING_KEYWORD = "SNOWPEA";
class SnowPea : public Pea{
public:
	SnowPea(int x, int y);
	~SnowPea() {};
	Ball* addBall() override;
private:
};

#endif