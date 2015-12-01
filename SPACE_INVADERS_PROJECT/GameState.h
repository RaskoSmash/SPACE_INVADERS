#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "MenuState.h"
#include <vector>
#include <iostream>

/*
GameState is the 'database' of the game.

It's a central hub to allow all of the objects
in the game communicate with one another.

It's also a good place to manage spawning new objects!
*/
const unsigned SCREEN_WIDTH = 800;
const unsigned SCREEN_HEIGHT = 600;

class Bullet;

class GameState
{
	Player player; 	// store all of our gameobjects
	std::vector<Bullet> bullets;
	std::vector<Enemy> enemies;


	vec2 cam;
	std::string backgroundName;

	unsigned int backWidth;
	unsigned int backHeight;

	float enemySpawnTimer;

public:

	// Parameters may match the constructor for the bullet
	void makeBullet(float x, float y, float dx, float lifespan);


	// Mimic the makeBullet pattern- 
	void makeExplosion();
	void makeEnemy(float x,float y,int health);


	// MUY IMPORTANTE!
	GameState() : enemySpawnTimer(5.f)
	{
		backgroundName = "Background";
		backWidth = getSubWidth(backgroundName, 1, 2);
		backHeight = getSubHeight(backgroundName, 1, 2);

		Object::gs() = this;
	}
	STATE update();

	void draw();
};