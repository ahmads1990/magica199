#include "Player.h"
#include "Rewards.h"
#include "Menu.h"
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(1600, 900), "mario");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	Player mario;
	Rewards jewel;
	RectangleShape ground;
	ground.setPosition(0.f, 500.f);
	ground.setSize(Vector2f(1600.f,540.f));
	ground.setFillColor(Color::Blue);


	Texture g2;
	g2.loadFromFile("tile2.png");
	Sprite ground2;
	ground2.setTexture(g2);
	
	Texture  back;
	back.loadFromFile("back.png");
	Sprite backGround;
	backGround.setTexture(back);
	backGround.setScale(1, 1.7);
	/*Texture j;
	j.loadFromFile("jewel.png");
	Sprite jewel;
	jewel.setTexture(j);
	int counter = 0;
	Text text;
	
	Font font;
	font.loadFromFile("Pixer.ttf");
	text.setFont(font);
	
	text.setCharacterSize(50);
	text.setPosition(200, 200);*/

	Clock clock;
	Menu menuu;
	bool getcoin = false;
	
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
				window.close();
			if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
			
		}
		//player movment

		//coll
		mario.boundary();


	
		window.clear();

		


		
		/*for (int i = 0; i < 10; i++)
		{
			backGround.setPosition(512 * i, 0);
			window.draw(backGround);
		}*/

		getcoin = mario.player.getGlobalBounds().intersects(jewel.jewel.getGlobalBounds());
		if (getcoin)
	    {	
			string str = to_string(jewel.counter);
			cout << str;
			jewel.counter++;
			jewel.text.setString(str);
		}else
			window.draw(jewel.jewel);

		
		for (int i = 0; i < 10; i++)
		{
			ground2.setPosition(160*i, 530  );
			window.draw(ground2);
		}
		ground2.setPosition(300 , 300);
		window.draw(ground2);
	
		
		menuu.drawTime(window, clock);
			mario.move(ground2);
			mario.walk();
		    window.draw(mario.returnSprite());
			window.draw(jewel.text);
	    
		window.display();
		
	}
}