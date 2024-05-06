#ifndef PEASHOOTER_INCLUDE
#define PEASHOOTER_INCLUDE

#include "../include/Global.hpp"
#include "../include/AttackPlant.hpp"

class PeaShooter : public AttackPlant{
public:
	PeaShooter(int x, int y);
	~PeaShooter();
	void render(RenderWindow &window);
    void update();
    void handleMousePress(Vector2i pos);
    void handleMouseRelease(Vector2i pos);
    Vector2f get_projectile_pos();
private:
    Clock clock;
	Texture texture;
    Sprite sprite;
    Vector2f pos;
    void fixedBasedPosition();
    int frames_position[7] = {0, 29, 59, 90, 120, 149, 182};
    int cur_rect = 0;
};

#endif