#include "Enemy.h"

void Enemy::update()
{
	Object::update();

	if (animTimer > getAnimationDuration(textureName, animationName))
	{
		animTimer = 0;
		textureName = "enemyIDLE";
		animationName = "eIDLE";
	}

}

void Enemy::draw(vec2 cam)
{
	sfw::drawTexture(getTexture(textureName), x + cam.x, y + cam.y, width * direction, height, 0, true, currentFrame);
}
