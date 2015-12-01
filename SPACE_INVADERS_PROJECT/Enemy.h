#pragma once
#include "GameObject.h"

class Enemy : public Object
{
public:
	Enemy(float a_x, float a_y, float a_health)
	{
		x = a_x;
		y = a_y;
		health = a_health;
		isActive = true;
		textureName = "enemySPAWN";
		animationName = "eSPAWN";

		width = getSubWidth(textureName, 10, 1);
		height = getSubHeight(textureName, 1, 1);
	}


	void takeDamage();
	virtual void update();
	virtual void draw(vec2 cam);
};