
#pragma once
#include "GameObject.h"
//#include "GameState.h"

class Bullet : public Object
{
	float lifetime; // how long it lasts
public:
	Bullet(float a_x, float a_y, float dx, float lifespan)
	{
		x = a_x;
		y = a_y;

		velocity = dx;
		lifetime = lifespan;
		isActive = lifetime > 0;
		textureName = "Fireball";
		animationName = "bAni";

		width = getSubWidth(textureName, 5, 1);
		height = getSubHeight(textureName, 1, 1);
	}

	virtual void onCollision(Object &go, float distance);
	virtual void update();
	virtual void draw();
	
};