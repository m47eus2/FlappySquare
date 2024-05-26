#include "Player.h"

//Private functions
void Player::initVariables()
{
	this->speedx = 5.f;
	this->speedy = 0.f;
	this->gravityValue = 0.f;
	this->hold = false;

	this->points = 0;
	this->bounce = false;
}

void Player::initShape()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setPosition(575.f, 375.f);
	this->shape.setFillColor(sf::Color(125,225,121));
}

//Constructor destructor
Player::Player()
{
	this->initVariables();
	this->initShape();
}

Player::~Player()
{
}

void Player::gravity()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (this->hold == false)
		{
			this->gravityValue = -10;
			this->hold = true;
		}
	}
	else
		this->hold = false;

	this->speedy = this->gravityValue;
	this->gravityValue += 0.3;
}

void Player::checkCollision(sf::RenderWindow& window)
{
	this->bounce = false;
	//Collision with edges
	if (this->shape.getGlobalBounds().left <= 0)
	{
		this->speedx = fabs(speedx);
		this->points += 1;
		this->bounce = true;
	}
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().getSize().x >= window.getSize().x)
	{
		this->speedx = -fabs(speedx);
		this->points += 1;
		this->bounce = true;
	}

	//Collision with floor
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().getSize().y >= window.getSize().y)
	{
		this->shape.setPosition(this->shape.getPosition().x, window.getSize().y - this->shape.getGlobalBounds().getSize().y);
		this->gravityValue = fabs(this->gravityValue) * -0.5f;
	}

	//Collision with roof
	if (this->shape.getGlobalBounds().getPosition().y <= 0)
	{
		this->shape.setPosition(this->shape.getPosition().x, 0.f);
		this->gravityValue = fabs(this->gravityValue) * 0.5f;
	}
}

void Player::deform()
{
	this->shape.setScale(1.f, 1.f + (gravityValue/20));
}

int Player::getPoints()
{
	return this->points;
}

sf::FloatRect Player::getGlobalBounds()
{
	return this->shape.getGlobalBounds();
}

bool Player::getBounce()
{
	return this->bounce;
}

//Update
void Player::update(sf::RenderWindow &window)
{
	this->gravity();

	this->deform();

	this->checkCollision(window);

	//Move player
	this->shape.move(speedx, speedy);
}

//Render
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
