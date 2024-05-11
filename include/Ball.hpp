#ifndef BALL_INCLUDE
#define BALL_INCLUDE
#include <Global.hpp>

class Ball{
private:
	const int speed = 4;
	bool is_collided = 0 ;
	Texture texture;
	Sprite sprite;
	Vector2f pos;
	int damage_value;
public:
	Ball(Vector2f shooter_pos , string pic_path , int damage_value);
	~Ball(){};
	void update();
	void render(RenderWindow &window);
	bool isOut();
	FloatRect getRect();
	Vector2f getPos();
	bool isCollided();
	void collide();
	int getDamageValue();
};

#endif