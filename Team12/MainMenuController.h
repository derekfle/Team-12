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
	~MainMenuController() {};

	/* START GameController interface */
public:
	virtual void Tick(sf::RenderWindow &window) override;
	virtual void HandleInput() override;
private:
	virtual void Draw(sf::RenderWindow &window) override;
	/* END GameController interface */
};

