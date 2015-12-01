#include "Button.h"

void Button::update()
{

}

void Button::draw()
{
	sfw::drawTexture(getTexture(textureName), x, y, width, height, 0, true, 1);
}

void Button::doCollision(Object & go, float distance)
{

}
