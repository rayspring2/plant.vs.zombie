#ifndef BALL_INCLUDE
#define BALL_INCLUDE
#include <Global.hpp>

const string _DAMAGE_VALUE = "damage_value:";
const string _BALL_SETTING_DAMAGE = "file currupted! damage_value not found\n";
const string _SPEED_VALUE = "speed:";
const string _BALL_SETTING_SPEED = "file currupted! speed not found\n";
const string _BALL_DID_NOT_LOAD = "faild to load blue ball\n";
class Ball{
private:
	int speed;
	bool is_collided = false;
	int row;
	Texture texture;
	Sprite sprite;
	Vector2f pos;
protected:
	int damage_value;
	void readSettingFile(string type);
public:
	Ball(Vector2f shooter_pos , string pic_path);
	~Ball(){};
	void update();
	void render(RenderWindow &window);
	bool isOut();
	FloatRect getRect();
	Vector2f getPos();
	bool isCollided();
	void collide();
	int getDamageValue();
	int getRow();
	virtual void myvirtualfunc(){};
};

#endif