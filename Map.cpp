#include "Map.h"

Map::Map():counter(0)
{
	if (!jewe.loadFromFile("jewel.png"))
		cout << "Failed to load jewel";


	if (!font.loadFromFile("Pixer.ttf"))
		cout << "Failed to load the font";

	jewel.setTexture(jewe);
	jewel.setPosition(400, 480);
	
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(1200, 50);
	
}



