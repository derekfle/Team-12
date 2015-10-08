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

	/*
	* Called each frame to advance gameplay
	*/
	void Tick(sf::RenderWindow &window, const sf::Event &ev);

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

private:
	GameManager();
	GameManager(GameManager const&) = delete;
	void operator=(GameManager const&) = delete;

	GameController *_currentController; // The currently working controller
	sf::Vector2f _screenResolution; // The window resolution

	bool _bIsAudioEnabled;
};

