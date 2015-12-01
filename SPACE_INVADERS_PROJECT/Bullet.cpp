#include "Bullet.h"

void Bullet::onCollision(Object &go, float distance)
{
	if (distance < go.width / 2)
	{
		isActive = false;
	}
}

void Bullet::update()
{
	Object::update(); // go ahead and update the base gameObject class
	lifetime -= sfw::getDeltaTime();
	isActive = lifetime > 0; // the bullet is no longer active when the lifetime reduces to 0

							 // Euler Integration to move our bullet
	x += velocity * sfw::getDeltaTime();
}
void Bullet::draw()
{
	sfw::drawTexture(getTexture(textureName), x, y, width * direction, height, 0, true, currentFrame);
}
