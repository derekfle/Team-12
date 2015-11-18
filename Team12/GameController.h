/**
* GameController declaration.
* Abstract base class to be used as a generalization for all types of game controller.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"

class GameController
{
public:
	/** Constructor for the GameController class. */
	GameController();
	/** Deconstructor for the GameController class. */
	~GameController();

	/**
	* Called each frame to advance gameplay.
	* @param a reference to a window
	*/
	virtual void Tick(sf::RenderWindow &window) = 0;

	/**
	* Handles any player input.
	*/
	virtual void HandleInput() = 0;

protected:

	/**
	* Draws a new frame.
	* @param a reference to a window
	*/
	virtual void Draw(sf::RenderWindow &window) = 0;

	/**
	* The current menu to be displayed on screen (if any).
	*/
	Menu *_menu;

	/*
	* A secondary menu that is displayed next to the current menu
	*/
	Menu *_secondaryMenu;
};

