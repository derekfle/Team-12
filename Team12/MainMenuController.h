/*
* MainMenuController declaration
* Handles all game logic when player is on the main menu screen
*/

#pragma once

#include "GameController.h"

class MainMenuController : public GameController
{
public:
	MainMenuController();
	~MainMenuController() {}

	/* START GameController interface */
public:
	virtual void Tick(sf::RenderWindow &window, const sf::Event &ev) override;
private:
	virtual void Draw(sf::RenderWindow &window, const sf::Event &ev) override;
	virtual void HandleInput() override;
	/* END GameController interface */
};

