#include "MainMenu.h"
#include "Splash.h"
#include "sfwdraw.h"
#include "constd.h"
#include <cstdio>

void Main::init(int a_font)
{
	font = a_font;
}

void Main::play()
{
	select = 0;
	timer = 3.f;
}

void Main::draw()
{
	sfw::drawString(font, "GOTO SPLASH!", 100, 100, 16, 16, 0, 0, select == 1?MAGENTA:WHITE);
	sfw::drawString(font, "GOTO QUIT!", 100, 100, 16, 16,0,0, select == 0?MAGENTA:WHITE);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 3.f), 80);
}

void Main::step()
{
	timer -= sfw::getDeltaTime();
	if (timer < 0)
	{
		timer = 1.f;
		select = 1 - select;
	}
}

APP_STATE Main::next()
{
	if (sfw::getKey(KEY_ENTER))
	{
		if (select == 0)
			return ENTERQUIT;
		if (select == 1)
			return ENTERSPLASH;
	}

	return MAINMENU;
}
