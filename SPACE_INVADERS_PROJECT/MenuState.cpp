#include "MenuState.h"
#include "collisiontests.h"

STATE MenuState::update()
{
	mouse.update();
	float StartDistance = itest_AABB(mouse.x, mouse.y, mouse.width / 2, mouse.height / 2, start.x, start.y, start.width / 2, start.height / 2);
	float CreditDistance = itest_AABB(mouse.x, mouse.y, mouse.width / 2, mouse.height / 2, credit.x, credit.y, credit.width / 2, credit.height / 2);
	float QuitDistance = itest_AABB(mouse.x, mouse.y, mouse.width / 2, mouse.height / 2, quit.x, quit.y, quit.width / 2, quit.height / 2);


	if (StartDistance  > 0 && sfw::getMouseButton(MOUSE_BUTTON_LEFT))
	{
		return GAME;
	}
	else if (CreditDistance > 0 && sfw::getMouseButton(MOUSE_BUTTON_LEFT))
	{
		return CREDITS;
	}
	else if(QuitDistance > 0 && sfw::getMouseButton(MOUSE_BUTTON_LEFT))
	{
		return QUIT;
	}
	else
	{
		return MENU;
	}
}

void MenuState::draw()
{
	sfw::setBackgroundColor(BLACK);
	start.draw();
	credit.draw();
	quit.draw();
	mouse.draw();
}
