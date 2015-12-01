#include "Player.h"

#include "GameState.h"

void Player::CollisionBox(const vec2 cam, unsigned int tint)
{
	sfw::drawLine((cam.x - x) - width / 2, (cam.y - y) - height / 2, (cam.x - x) - width / 2, (cam.y - y) + height / 2, tint);
	sfw::drawLine((cam.x - x) - width / 2, (cam.y - y) - height / 2, (cam.x - x) + width / 2, (cam.y - y) - height / 2, tint);

	sfw::drawLine((cam.x - x) + width / 2, (cam.y - y) + height / 2, (cam.x - x) + width / 2, (cam.y - y) - height / 2, tint);
	sfw::drawLine((cam.x - x) + width / 2, (cam.y - y) + height / 2, (cam.x - x) - width / 2, (cam.y - y) + height / 2, tint);
}

void Player::update(vec2 cam)
{
	Object::update();

	if (sfw::getKey(' ') && shootTimer < 0)
	{
		gs()->makeBullet(cam.x - x, cam.y - y, 300, 4.f);
		animTimer = 0;
		textureName = "playerSHOOT";
		animationName = "pSHOOT";
		shootTimer = 3.f;
	}

	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT) && hitTimer < 0)
	{
		shootTimer = 1.f;
		animTimer = 0;
		textureName = "playerHIT";
		animationName = "pHIT";
		hitTimer = 3.f;
	}

	velocity = sfw::getDeltaTime() * speed;
	if (sfw::getKey('A'))
	{
		velocity = -velocity;
		x += velocity;
		textureName = "playerRUN";
		animationName = "pRUN";
	}

	if (sfw::getKey('D'))
	{
		x += velocity;
		textureName = "playerRUN";
		animationName = "pRUN";
	}
	
	if (velocity < 0)
	{
		direction = -1;
	}
	if(velocity > 0)
	{
		direction = 1;
	}
		
	

	if (animTimer > getAnimationDuration(textureName, animationName))
	{
		animTimer = 0;
		textureName = "playerIDLE";
		animationName = "pIDLE";
	}

	if (shootTimer < -50) { shootTimer = -.1f; }
	shootTimer -= sfw::getDeltaTime();
	hitTimer -= sfw::getDeltaTime();
	
}
//if (sfw::getKey('A'))
//{
//	acceleration = -speed;
//	velocity += sfw::getDeltaTime() * acceleration;
//	x += velocity;
//}
//if (sfw::getKey('D'))
//{
//	acceleration = speed;
//	velocity += sfw::getDeltaTime() * acceleration;
//	x += velocity;
//}