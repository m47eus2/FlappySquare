#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

#include "Player.h"
#include "Spike.h"

class Game
{
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Font font;
	sf::Text pointsText;

	std::vector<Spike> spikes;
	std::vector<int> rands;

	Player player;

	//Private functions
	void initFonts();
	void initPointsText();
	void updatePointsText();
	void spawnSpike();

	void initVariables();
	void initWindow();

	void SpikeCollisions();
	void updateSpikes();

public:
	//Constructor destructor
	Game();
	virtual ~Game();

	//Getters
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};