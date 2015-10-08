/*
* Implementation of GameManager class
*/

#include "GameManager.h"
#include "InputManager.h"
#include "MainMenuController.h"

GameManager::GameManager() :
	_screenResolution(1280, 720),
	_bIsAudioEnabled(true)
{
	// Set the starting screen
	_currentController = new MainMenuController();
}

GameManager::~GameManager() 
{
	if (_currentController)
	{
		delete _currentController;
		_currentController = nullptr;
	}
};

void GameManager::Tick(sf::RenderWindow &window, const sf::Event &ev)
{
	if (ev.type == sf::Event::Closed) window.close();
	else if (_currentController)
	{
		InputManager::GetInstance().Update(ev);
		_currentController->Tick(window, ev);
	}
}

GameManager &GameManager::GetInstance()
{
	static GameManager instance;
	return instance;
}

sf::Vector2f GameManager::GetResolution() const
{
	return _screenResolution;
}

void GameManager::ToggleAudio()
{
	_bIsAudioEnabled = !_bIsAudioEnabled;
}
bool GameManager::IsAudioEnabled() const
{
	return _bIsAudioEnabled;
}