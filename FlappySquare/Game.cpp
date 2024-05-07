#include "Game.h"

void Game::initFonts()
{
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
}

void Game::initPointsText()
{
	this->pointsText.setFont(this->font);
	this->pointsText.setCharacterSize(120);
	this->pointsText.setFillColor(sf::Color::White);
	this->pointsText.setPosition(sf::Vector2f(600.f - (this->pointsText.getGlobalBounds().width / 2), 300.f));
}

void Game::updatePointsText()
{
	std::stringstream ss;
	ss << this->player.getPoints();
	this->pointsText.setString(ss.str());
	this->pointsText.setPosition(sf::Vector2f(600.f - (this->pointsText.getGlobalBounds().width / 2), 300.f));
}

void Game::initVariables()
{
	this->window = nullptr;
}

//Private functions
void Game::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 1200;

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

//Constructor destructor
Game::Game()
{
	this->initFonts();
	this->initPointsText();
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Getters
const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

//Update
void Game::update()
{
	this->pollEvents();

	this->player.update(*this->window);

	this->updatePointsText();
}

//Render
void Game::render()
{
	this->window->clear(sf::Color(159, 239, 255));

	this->window->draw(pointsText);

	this->player.render(*this->window);

	this->window->display();
}