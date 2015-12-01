#pragma once
#include "Button.h"
#include "Cursor.h"

enum STATE {MENU, GAME, CREDITS, QUIT};

class Button;

class MenuState
{
	Button start = Button("Start");
	Button credit = Button("Credits");
	Button quit = Button("Quit");
	Cursor mouse = Cursor("Mouse");

public:
	MenuState()
	{
		credit.y = 400;
		quit.y = 300;
	}

	STATE update();
	void draw();

	STATE creditUpdate();
	void creditDraw();
};