/*
* GameController declaration
* Abstract base class to be used as a generalization for all types of game controller
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"

class GameController
{
public:
	GameController();
	~GameController();

	/*
	* Called each frame to advance gameplay
	*/
	virtual void Tick(sf::RenderWindow &window, const sf::Event &ev) = 0;

protected:

	/*
	* Draws a new frame
	*/
	virtual void Draw(sf::RenderWindow &window, const sf::Event &ev) = 0;

	/*
	* Handles any player input
	*/
	virtual void HandleInput() = 0;

	/*
	* The current menu to be displayed on screen (if any)
	*/
	Menu *_menu;
};

