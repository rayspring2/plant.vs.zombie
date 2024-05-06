#ifndef SNOWPEA_INCLUDE
#define SNOWPEA_INCLUDE

#include "../include/Global.hpp"
#include "../include/AttackPlant.hpp"

class SnowPea : public AttackPlant{
public:
	SnowPea(int x, int y);
	~SnowPea();
	void update();
    void render(RenderWindow &window);
    void handleMousePress(Vector2i pos);
    void handleMouseRelease(Vector2i pos);
    Vector2f get_projectile_pos();
private:
    Clock clock;
	Texture texture;
    Sprite sprite;
    Vector2f pos;
    void fixedBasedPosition();
    int frames_position[70];
    int cur_rect = 0;
};

#endif