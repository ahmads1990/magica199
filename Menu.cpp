#include "Menu.h"

Menu::Menu()
{
	//timer section//

	// loading font
	if (!font.loadFromFile("Pixer.ttf"))
		cout << "Error loading font for menu";

	//Setting Text Details
	timeText.setFont(font);
	timeText.setCharacterSize(55);
	timeText.setFillColor(Color::White);
	timeText.setOutlineColor(Color::Red);
	timeText.setOutlineThickness(2);
	timeText.setPosition(1325, 20);
	timeText.setString(str);

	minutes = 0;	
}

void Menu::drawTime(RenderWindow& window,Clock clock)
{

	time = clock.getElapsedTime();
	seconds = time.asSeconds();
	//if the seconds is more than 60 reset the variable and increment minutes
	if (seconds >= 60)
	{
		minutes++;
		seconds = 00;
	}
	//if seconds less than 10 draw extra 0 to the side so it draw 0:01 instead of 0: 1
	if (seconds < 10)
	{
		str = "Time: " + to_string(minutes) + ":0" + to_string(seconds);
	}else
	    str = "Time: " + to_string(minutes) + ":" + to_string(seconds);
	//set the text to the new string
	timeText.setString(str);
	//draw at targeted window
	window.draw(timeText);
}
