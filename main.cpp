#include "constd.h"
#include "Splash.h"
#include "sfwdraw.h"
#include "Quit.h"
#include "MainMenu.h"




void main()
{
	sfw::initContext(800,600,"NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);

	Splash Splash;
	Quit quit;
	Main menu;

	Splash.init(font);
	quit.init(font);
	menu.init(font);

	APP_STATE state = ENTERSPLASH;

	bool quit1 = false;
	while (sfw::stepContext() && !quit1)
	{
		switch (state)
		{
		case ENTERSPLASH:
			Splash.play();
		case SPLASH:
			Splash.step();
			Splash.draw();
			state = Splash.next();
			break;
		case ENTERQUIT:
			quit.play();
		case QUIT:
			quit.step();
			quit.draw();
			state = quit.next();
			break;
		case ENTERMAINNENU:
			menu.play();
		case MAINMENU:
			menu.step();
			menu.draw();
			state = menu.next();
			break;
		case TERMINATE: quit1 = true;
		}
	}

	sfw::termContext();
}