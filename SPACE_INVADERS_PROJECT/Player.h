#pragma once
#include "GameObject.h"


class Player : public Object
{
private:
	int mana;
	int defense;
	float shootTimer;
	bool meleeAtk;
	bool rangedAtk;

	float hitTimer;
//	float bulletStartX, bulletStartY;

public:

	Player() : mana(0), defense(0), meleeAtk(false), rangedAtk(false), shootTimer(3.f), hitTimer(1.f)
	{
		isActive = true;

		textureName = "playerIDLE";
		animationName = "pIDLE";

		width = getSubWidth(textureName, 10, 5);
		height = getSubHeight(textureName, 1, 5);
	}


	virtual void CollisionBox(const vec2 cam, unsigned int tint);
	virtual void update(vec2 cam);
//	virtual void drawMe();
};

//class Player : public GameGameObject
//{
//public:
//	float speed;
//	Player() : speed(100) { width = 200; height = 200; }
//
//	virtual void update()
//	{
//		
//	}
//};