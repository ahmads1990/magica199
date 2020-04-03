#pragma once
#include"Player.h";

using namespace sf;
using namespace std;

class Menu
{
	//data
private:
	//timer section//
	Time time;
	Text timeText;
	String str;
	Font font;
	int minutes;
	int seconds;
public:
	//timer section//
	Menu();
	void drawTime(RenderWindow& window,Clock clock);
};

