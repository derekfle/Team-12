/*
* Declaration of GameManager class
* The GameManager class is a singleton which manages the game controllers and several game options
*/

#pragma once

#include "GameController.h"
#include <SFML\Graphics.hpp>

class GameManager
{
public:
	~GameManager();

	enum StateType
	{
		MainMenu,
		Battling,
		Quitting
	};

	/*
	* Called each frame to advance gameplay
	*/
	void Tick(sf::RenderWindow &window);

	/*
	* Handles input events
	*/
	void HandleInput();

	/*
	* Returns the GameManager instance
	*/
	static GameManager &GetInstance();

	/*
	* Returns the screen resolution
	*/
	sf::Vector2f GetResolution() const;

	/*
	* Member functions to toggling audio and checking is audio is enabled
	*/
	void ToggleAudio();
	bool IsAudioEnabled() const;

	/*
	* Gets the current game state
	*/
	StateType GetGameState() const;

	/*
	* Changes the current game state, and updates the trnasition controller controller
	*/
	void SetGameState(const StateType &newState);

private:
	GameManager();
	GameManager(GameManager const&) = delete;
	void operator=(GameManager const&) = delete;

	/*
	* The quit game member functions handles quitting the game and acts accordingly based on current state
	*/
	void QuitGame();

	GameController *_currentController; // The currently working controller
	GameController *_transitionController; // The controller to transition to

	sf::Vector2f _screenResolution; // The window resolution
	StateType _currentState; // Current game state
	bool _bIsAudioEnabled;
	bool _bIsTransitioning; // Are we transitioning from one screen to the next?
};

