#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::RectangleShape shape;
	float speedx;
	float speedy;

	float gravityValue;
	bool hold;
	bool bounce;

	int points;

	void initVariables();
	void initShape();
public:
	Player();
	~Player();

	void gravity();
	void checkCollision(sf::RenderWindow& window);
	void deform();

	int getPoints();
	sf::FloatRect getGlobalBounds();
	bool getBounce();
	void update(sf::RenderWindow& window);
	void render(sf::RenderTarget &target);
};