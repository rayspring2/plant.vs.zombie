#ifndef BALL_INCLUDE
#define BALL_INCLUDE
#include <Global.hpp>

class Ball{
private:
	const int speed = 4;
	Texture texture;
	Sprite sprite;
	Vector2f pos;
public:
	Ball(Vector2f shooter_pos , string pic_path);
	~Ball(){};
	void update();
	void render(RenderWindow &window);
	bool isOut();
	FloatRect getRect();
	Vector2f getPos();
	
};

#endif