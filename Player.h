#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
class Player
{
public:
	Texture texture;
	IntRect source;
	Sprite player;
	Clock clock;
	int direction;
	int source1;
	int ifIdle;
	//physics
	Vector2f positon;
	Vector2f velocity;
	bool onGround;
	float grav;
public:
	Player();
	~Player();
    void  walk();
	Sprite returnSprite();
	void move(Sprite &ground);
	void boundary();
	bool isAnyKeyPressed();
	
};

