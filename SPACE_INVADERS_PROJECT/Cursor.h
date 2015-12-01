#pragma once
#include "GameObject.h"


class Cursor : public Object
{
public:
	Cursor(const std::string a_textName)
	{
		x = 0;
		y = 0;
		width = 50;
		height = 50;

		textureName = a_textName;
	}
	virtual void update();
	virtual void draw();
};