#pragma once

#include "constd.h"

class Main
{
	int font;
	float timer;
	int select;
public:
	void init(int a_font);
	void play();
	void draw();
	void step();

	APP_STATE next();

};