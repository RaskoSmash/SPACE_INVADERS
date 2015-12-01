#pragma once
#include "sfwdraw.h"
#include "AssetLibrary.h"


struct vec2
{
	float x, y;
};

class GameState;

class Object
{
protected:
	float				animTimer;
	unsigned			currentFrame;
	int					health, direction; //if direction is -1 the object is facing left, if the direction is 1 the object is facing right
	bool				isGrounded;
	bool				canShoot;
	
public:
	float				x, y, speed, velocity;
	bool				isActive;
	float				width, height;
	std::string			textureName, animationName;

	Object() :	x(40), y(30), isActive(false),
				currentFrame(0), animTimer(0), health(0), 
				direction(1), speed(300), velocity(0)
	{
		/*textureName = "playerIDLE";
		animationName = "pIDLE";

		width = getSubWidth(textureName, 10, 5);
		height = getSubHeight(textureName, 1, 5);*/
	}

	int getHealth();
	
	void setHealth(int newHealth);

	virtual void CollisionBox(unsigned int tint);

	virtual void update();

	virtual void draw(vec2 cam);

	static GameState *&gs();

	virtual void onCollision(Object &go, float distance) { }
};

float doCollision(Object &go1, Object &go2);
