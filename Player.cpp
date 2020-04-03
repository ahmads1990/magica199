#include "Player.h"

Player::Player() :player(texture, source),source1(50)
{ 
	//load the running animation
	if (!texture.loadFromFile("running4.png"))
	cout << "Error loading player image";
	player.setScale(3, 3);
	positon.y = 300;
	player.setPosition(200, positon.y);
	direction = 0;
	ifIdle = 0;
	//rtest
	grav = 2;
	velocity.y = 0;
	onGround = true;


}

Player::~Player()
{
}
//note fix the broken animation
void Player::walk()
{ 
	if (isAnyKeyPressed())
		ifIdle = 1;
	else
	    ifIdle = 0;
	
	if (clock.getElapsedTime().asSeconds() > 0.1f)
	{       
		
			if (onGround)
			{
				if (source1 == 300)
					source1 = 50;

				else
					source1 += 50;
			}
			else
			{
				if (source1 >= 200)
					source1 = 200;	
			}
			
			
		
		/*
		cout << source1<<"\n";*/
		player.setTextureRect(IntRect (source1 *ifIdle, 50 * direction, 50, 50));
		clock.restart();
	}


}



Sprite Player::returnSprite()
{
	return player;
}




void Player::move(Sprite &ground)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
	   player.move(0.f, -10.f);
	   walk();
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player.move(-10.f, 0.f);
		direction = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
		player.move(0.f, 10.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player.move(10.f, 0.f);
		direction = 0;
		walk();
	}
	//jump
	if (Keyboard::isKeyPressed(Keyboard::E) && onGround)
	{
		velocity.y = -20;
		direction = 2;
		onGround = false;
	}
	
	if ( (player.getPosition().y + player.getGlobalBounds().height < ground.getPosition().y )
		&& player.getPosition().x + player.getGlobalBounds().width >= ground.getPosition().x
		&& player.getPosition().x + player.getGlobalBounds().width <= ground.getPosition().x + ground.getGlobalBounds().width)
	{
		velocity.y += grav;
		cout << "h";
	}
	else
	{
		player.setPosition(player.getPosition().x, ground.getPosition().y - player.getGlobalBounds().height );
		onGround =true;
	}
	
	player.move(0, velocity.y);

	
}






void Player::boundary()
{
	if (player.getPosition().x + player.getGlobalBounds().width >= 1600) //right
		player.setPosition(Vector2f(1600.f - player.getGlobalBounds().width, player.getPosition().y));
	if (player.getPosition().y <= 0) //top
		player.setPosition(Vector2f(player.getPosition().x, 0));
	if (player.getPosition().x <= 0) //left
		player.setPosition(Vector2f(0.f, player.getPosition().y));
	//if (mario.getPosition().y >= 1600-mario.getGlobalBounds().height) //bottom
	//	mario.setPosition(Vector2f(mario.getPosition().x,1600-mario.getGlobalBounds().height));
}



bool Player::isAnyKeyPressed()
{
	for (int k = -1; k < Keyboard::KeyCount; ++k)
	{
		if (Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
			return true;	
	}
	
	return false;
}
