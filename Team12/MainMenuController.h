/**
* MainMenuController declaration.
* Handles all game logic when player is on the main menu screen.
*/

#pragma once

#include "GameController.h"

class MainMenuController : public GameController
{
public:
	/** Enum for tracking which menu is displayed. */
	enum CurrentMenu { MainMenu, ChooseAvatar, ChooseDifficulty };
	
	/** Constructor for the MainMenuController class. */
	MainMenuController();
	/** Deconstructor for the MainMenuController class. */
	~MainMenuController() {};

	/**
	* Avatar Interace: calls functions to be run every frame.
	* @param a reference to a window 
	*/
	virtual void Tick(sf::RenderWindow &window) override;
	/**
	* Avatar Interace: manages input.
	*/
	virtual void HandleInput() override;
private:
	/**
	* Avatar Interace: draws the main menu.
	*/
	virtual void Draw(sf::RenderWindow &window) override;

	/** Tracks the state of the menu. IE which menu is being displayed. */
	CurrentMenu _curMenu;
};

