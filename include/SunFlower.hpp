#ifndef SUNFLOWER_INCLUDE
#define SUNFLOWER_INCLUDE

#include "Global.hpp"
#include "Plant.hpp"

class SunFlower : public Plant{
public:
	SunFlower(int x, int y);
	~SunFlower();
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