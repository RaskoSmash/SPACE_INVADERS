#include "GameState.h"

void GameState::makeBullet(float x, float y, float dx, float lifespan)
{
	for (unsigned int i = 0; i < bullets.size(); ++i)
	{
		if (!bullets[i].isActive) // Find an empty spot in our vector
		{
			bullets[i] = Bullet(x, y, dx, lifespan);
			return;
		}
	}
	// if there is no empty spot, generate a new bullet into the vector
	bullets.push_back(Bullet(x, y, dx, lifespan));
}

void GameState::makeEnemy(float x, float y, int health)
{
	for (unsigned int i = 0; i < enemies.size(); ++i)
	{
		if (!enemies[i].isActive) // Find an empty spot in our vector
		{
			enemies[i] = Enemy(x, y, health);
			return;
		}
	}
	// if there is no empty spot, generate a new bullet into the vector
	enemies.push_back(Enemy(x, y, health));
}

STATE GameState::update()
{
	cam = { player.x + 80, player.y + 300 };
	sfw::drawTexture(getTexture(backgroundName), 2150 - cam.x, 1100 - cam.y, backWidth, backHeight, 0, true, 1);

	int nEnemiesActive = 0;

	if (player.isActive)
		player.update(cam);
	
	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].isActive)
		{
			bullets[i].update();
			for (int j = 0; j < enemies.size(); ++j)
			{
				if (enemies[j].isActive)
				{
					doCollision(enemies[j], bullets[i]);
				}
			}
		}
	}
	//example useful for determining when to spawn a new wave of enemies.
	

	for (int i = 0; i < enemies.size(); ++i)
		if (enemies[i].isActive)
		{
			nEnemiesActive++;
			enemies[i].update();
		/*	doCollision(player, bullets[i]);*/
		}
		
		if (nEnemiesActive < 10 && enemySpawnTimer < 0)
		{
			makeEnemy(player.x, player.y, 50);
			enemySpawnTimer = 5.f;
		}
		enemySpawnTimer -= sfw::getDeltaTime();
	// Collision detection between two objects of the same type
	/*	for (int i = 0; i + 1 < bullets.size(); ++i)
	for (int j = i + 1; j < bullets.size(); ++j)
	{
	doCollision(bullets[i], bullets[j]);
	}*/
		std::cout << nEnemiesActive << std::endl;
		return GAME;
}

void GameState::draw()
{
	if (player.isActive)
		player.draw(cam);
//	player.CollisionBox(cam, BLACK);

	for (int i = 0; i < bullets.size(); ++i)
		if (bullets[i].isActive)
		{
			bullets[i].draw();
			//bullets[i].CollisionBox(BLACK);
		}
	for (int i = 0; i < enemies.size(); ++i)
		if (enemies[i].isActive)
		{
			enemies[i].draw(cam);
			//enemies[i].CollisionBox(BLACK);
		}

}