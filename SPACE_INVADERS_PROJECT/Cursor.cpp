#include "Cursor.h"

void Cursor::update()
{
	x = sfw::getMouseX();
	y = sfw::getMouseY();
}

void Cursor::draw()
{
	sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, 1);
}
