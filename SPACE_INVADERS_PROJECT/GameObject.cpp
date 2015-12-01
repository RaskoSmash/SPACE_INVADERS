#include "GameObject.h"
#include "sfwdraw.h"

#include "GameState.h"

//GameState  Object::*&gs()
//{
//	static GameState *game;
//	return game;
//}

void Object::CollisionBox(unsigned int tint)
{
	sfw::drawLine(x - width / 2, y - height / 2, x - width / 2, y + height / 2, tint);
	sfw::drawLine(x - width / 2, y - height / 2, x + width / 2, y - height / 2, tint);

	sfw::drawLine(x + width / 2, y + height / 2, x + width / 2, y - height / 2, tint);
	sfw::drawLine(x + width / 2, y + height / 2, x - width / 2, y + height / 2, tint);
}

void Object::update()
{
	animTimer += sfw::getDeltaTime();
	currentFrame = sampleAnimation(textureName, animationName, animTimer);
}

void Object::draw(vec2 cam)
{
	sfw::drawTexture(getTexture(textureName), cam.x - x, cam.y - y, width * direction, height, 0, true, currentFrame);
}

GameState *& Object::gs()
{
	static GameState *game;
	return game;
}
