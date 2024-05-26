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

void Game::spawnSpike()
{
	float x;
	float y;
	Spike spike;
	bool rep = false;

	do
	{
		rep = false;
		int pos = rand() % 64;
		std::cout << pos << std::endl;
		for (auto& i : this->rands)
			if (pos == i) rep = true;

		if (rep == false)
		{
			//Top 
			if (pos <= 23)
			{
				spike.setPosition(sf::Vector2f(50.f * pos, 0.f));
			}
			//Right
			else if (pos <= 39)
			{
				spike.setPosition(sf::Vector2f(1200.f, 50.f * (pos - 24)));
				spike.rotate(90.f);
			}
			//Bottom
			else if (pos <= 63)
			{
				spike.setPosition(sf::Vector2f(1200.f - (pos - 40) * 50.f, 800.f));
				spike.rotate(180.f);
			}

			this->rands.push_back(pos);
		}
	} while (rep == true);

	this->spikes.push_back(spike);
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

void Game::SpikeCollisions()
{
	for (auto& i : this->spikes)
	{
		if (this->player.getGlobalBounds().intersects(i.getGobalBounds()))
			std::cout << "Collision" << std::endl;
	}
}

void Game::updateSpikes()
{
	if (this->player.getBounce())
		this->spawnSpike();
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

	this->SpikeCollisions();

	this->updateSpikes();

	this->updatePointsText();
}

//Render
void Game::render()
{
	this->window->clear(sf::Color(159, 239, 255));

	//Render spikes
	for (auto& i : this->spikes)
		i.render(*this->window);

	//Render points text
	this->window->draw(pointsText);

	//Render player
	this->player.render(*this->window);

	this->window->display();
}