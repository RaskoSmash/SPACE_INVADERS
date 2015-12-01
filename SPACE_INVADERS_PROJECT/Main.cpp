#include "sfwdraw.h"
#include "cstring"
#include <sstream>
#include <iostream>
#include "AssetLibrary.h"
#include "GameState.h"
#include "MenuState.h"


int main()
{
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "NSFW Draw");
		

	loadTexture("Background","./Textures/background.png", 1, 1);

	loadTexture("Start",   "./Textures/GameButton.png", 1, 1);
	loadTexture("Credits", "./Textures/CreditsButton.png", 1, 1);
	loadTexture("Quit",    "./Textures/QuitButton.png", 1, 1);
	loadTexture("Mouse",   "./Textures/mouse.jpg", 1, 1);

	loadTexture("Fireball", "./Textures/Player/newFireball.png", 5, 1);

	loadTexture("playerIDLE", "./Textures/Player/playerIDLE.png", 6, 1);
	loadTexture("playerHIT", "./Textures/Player/playerHIT.png", 6, 1);
	loadTexture("playerRUN", "./Textures/Player/playerRUN.png", 8, 1);
	loadTexture("playerSHOOT", "./Textures/Player/playerShoot.png", 6, 1);

	loadTexture("enemyIDLE", "./Textures/Enemy/enemyIDLE.png", 6, 1);
	loadTexture("enemyHIT", "./Textures/Enemy/enemyHIT.png", 8, 1);
	loadTexture("enemyWALK", "./Textures/Enemy/enemyWALK.png", 8, 1);
	loadTexture("enemySPAWN", "./Textures/Enemy/enemySPAWN.png", 10, 1);
	loadTexture("enemyDIE", "./Textures/Enemy/enemyDIE.png", 8, 1);

	addAnimation("Fireball", "bAni", { 0,1,2,3,4 }, 12);

	addAnimation("playerIDLE", "pIDLE", { 0,1,2,3,4,5}, 12);
	addAnimation("playerHIT", "pHIT", { 0,1,2,3,4,5 }, 12);
	addAnimation("playerRUN", "pRUN", { 0,1,2,3,4,5,6,7 }, 12);
	addAnimation("playerSHOOT", "pSHOOT", { 0,1,2,3,4,5 }, 12);

	addAnimation("enemyIDLE", "eIDLE", { 0,1,2,3,4,5 }, 12);
	addAnimation("enemyHIT", "eHIT", { 0,1,2,3,4,5,6,7 }, 12);
	addAnimation("enemyWALK", "eWALK", { 0,1,2,3,4,5,6,7 }, 12);
	addAnimation("enemySPAWN", "eSPAWN", { 0,1,2,3,4,5,6,7,8,9 }, 12);
	addAnimation("enemyDIE", "eDIE", { 0,1,2,3,4,5,6,7 }, 12);

	GameState game;
	MenuState menu;

	STATE current = MENU;

	while (sfw::stepContext())
	{
		
		switch (current)
		{
		case MENU:
			current = menu.update();
			menu.draw();
			break;
		case GAME:
			current = game.update();
			game.draw(); 
			break;
		case CREDITS:
			break;
		case QUIT:
			return 0;
		}
		
		
		//dinosaur.CollisionBox(CLEAR);
 
	}

	sfw::termContext();
}


//	bool lastState[128];
//	memset(lastState, 0, sizeof(bool) * 128);
//for (int i = 0; i < 350; i++)
//		{
//			bool state = sfw::getKey(i);
//			if (state && !lastState[i])
//			{
//				switch (i)
//				{
//				case 257:
//				case 259: 
//					if (str.length() > 0)
//						str.erase(str.length() - 1, 1); break;
//				default: str += i;
//				}
//			}
//			lastState[i] = state;
//		}