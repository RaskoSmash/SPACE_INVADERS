#pragma once
#include "GameObject.h"

class Button : public Object
{
public:
	Button(const std::string a_textName)
	{
		x = 400;
		y = 500;
		textureName = a_textName;

		width = getSubWidth(textureName, 1, 1);
		height = getSubHeight(textureName, 1, 1);

	}

	virtual void update();
	virtual void draw();
	virtual void doCollision(Object &go, float distance);
};