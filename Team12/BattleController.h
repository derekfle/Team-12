/*
* BattleController declaration
* Handles all game logic when player is battling
*/
#pragma once

#include "GameController.h"

class BattleController : public GameController
{
public:
	BattleController();
	~BattleController();

	/* START GameController interface */
public:
	virtual void Tick(sf::RenderWindow &window) override;
	virtual void HandleInput() override;
private:
	virtual void Draw(sf::RenderWindow &window) override;
	/* END GameController interface */
};

