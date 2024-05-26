#include "Spike.h"



void Spike::initShape()
{
	this->shape.setPointCount(3);
	this->shape.setPoint(0, sf::Vector2f(0.f, 0.f));
	this->shape.setPoint(1, sf::Vector2f(50.f, 0.f));
	this->shape.setPoint(2, sf::Vector2f(25.f, 0.866 * 50.f));
}

Spike::Spike()
{
	this->initShape();
}

Spike::~Spike()
{
}

void Spike::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

void Spike::setPosition(sf::Vector2f position)
{
	this->shape.setPosition(position);
}

void Spike::rotate(float degree)
{
	this->shape.rotate(degree);
}

sf::FloatRect Spike::getGobalBounds()
{
	return this->shape.getGlobalBounds();
}
