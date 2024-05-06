#ifndef PEASHOOTER_INCLUDE
#define PEASHOOTER_INCLUDE

#include "../include/Global.hpp"
#include "../include/AttackPlant.hpp"


class PeaShooter : public AttackPlant{
public:
	PeaShooter();
	~PeaShooter();
	void render(RenderWindow &window);
    void update(Vector2i mouse_pos);
    Vector2f get_projectile_pos();
private:
    void fixBasedPosition();
    int frames_position[70];
    int cur_rect = 0;
};

#endif