#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

#include "Player.h"

class Game
{
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Font font;
	sf::Text pointsText;

	Player player;

	//Private functions
	void initFonts();
	void initPointsText();
	void updatePointsText();

	void initVariables();
	void initWindow();

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