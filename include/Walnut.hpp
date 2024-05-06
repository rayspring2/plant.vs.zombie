#ifndef WALNUT_INCLUDE
#define WALNUT_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class Walnut : public Plant{
public:
	Walnut(int x, int y);
	~Walnut();
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
    int frames_position[70];
    int cur_rect = 0;
};

#endif