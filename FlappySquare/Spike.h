#pragma once
#include <SFML/Graphics.hpp>

class Spike
{
private:
	sf::ConvexShape shape;

	float x;
	float y;
	float a;

	void initShape();
public:
	Spike();
	~Spike();

	void render(sf::RenderTarget& target);
	void setPosition(sf::Vector2f position);
	void rotate(float degree);

	sf::FloatRect getGobalBounds();
};