#ifndef PEA_INCLUDE
#define PEA_INCLUDE

#include "Global.hpp"
#include "AttackPlant.hpp"

class Pea : public AttackPlant{
public:
	Pea(int x, int y);
	~Pea(){};
	void render(RenderWindow &window);
    void update();
    void handleMousePress(Vector2i pos);
    void handleMouseRelease(Vector2i pos);
    Vector2f get_projectile_pos();
protected:
    Clock clock;
	Texture texture;
    Sprite sprite;
    Vector2f pos;
    void fixedBasedPosition();
    int frames_position[70];
    int cur_rect = 0;
};

#endif