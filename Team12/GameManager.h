/**
* Declaration of GameManager class.
* The GameManager class is a singleton which manages the game controllers and several game options.
*/

#pragma once

#include "GameController.h"
#include <SFML\Graphics.hpp>

class GameManager
{
public:
	/** Deconstructor for the GameManager class. */
	~GameManager();

	/** Defines the state of the game. */
	enum StateType
	{
		MainMenu,
		Battling,
		Quitting
	};

	/**
	* Called each frame to advance gameplay.
	* 
	* @param window - a constant reference to a window
	*/
	void Tick(sf::RenderWindow &window);

	/**
	* Handles input events.
	*/
	void HandleInput();

	/**
	* Returns the GameManager instance.
	*
	* @return the instance of the GameManager
	*/
	static GameManager &GetInstance();

	/**
	* Returns the screen resolution.
	*
	*@return the screen resolution
	*/
	sf::Vector2f GetResolution() const;

	/**
	* Member function to toggle audio.
	*/
	void ToggleAudio();

	/**
	* Member function to check if audio is enabled.
	* @return a boolean value indicating whether audio is enabled. 
	*/
	bool IsAudioEnabled() const;

	/**
	* Gets the current game state.
	* @return the StateType of the game. 
	*/
	StateType GetGameState() const;

	/**
	* Changes the current game state, and updates the transition controller.
	* @param newState - a constant reference to the StateType of the game
	*/
	void SetGameState(const StateType &newState);

private:
	/** Constructor for the GameManager class. */
	GameManager();
	/** Delete the copy constructor so that it won't be used. */
	GameManager(GameManager const&) = delete;
	/** Delete the assignment operator so that it won't be used. */
	void operator=(GameManager const&) = delete;

	/**
	* The quit game member function handles quitting the game and acts accordingly based on current state.
	*/
	void QuitGame();

	/** The currently working controller. */
	GameController *_currentController;
	/** The controller to transition to. */
	GameController *_transitionController; 

	/** The window resolution. */
	sf::Vector2f _screenResolution;
	/** Current game state. */
	StateType _currentState;
	/** Boolean value indicating if audio is enabled. */
	bool _bIsAudioEnabled;
	/** Boolean value indicating if the game is transitioning from one screen to another. */
	bool _bIsTransitioning; 
};

