/*
* Implementation of GameManager class
*/

#include "BattleController.h"
#include "GameManager.h"
#include "InputManager.h"
#include "MainMenuController.h"

GameManager::GameManager() :
	_screenResolution(1280, 720),
	_bIsAudioEnabled(true),
	_bIsTransitioning(true),
	_currentState(State::MainMenu)
{
	// Set the starting screen
	_transitionController = new MainMenuController();
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
	if (ev.type == sf::Event::Closed) QuitGame();
	else if (_bIsTransitioning)
	{
		if (_currentController) delete _currentController;
		_currentController = _transitionController;
		_transitionController = nullptr;
		_bIsTransitioning = false;
	}
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

GameManager::State GameManager::GetGameState() const
{
	return _currentState;
}

void GameManager::QuitGame()
{
	// What do to when quitting at certain states
	switch (_currentState)
	{
	case(State::MainMenu) :
		break;
	case(State::Battling) :
		break;
	}
}

void GameManager::SetGameState(const State &newState)
{
	// Handle the transitioning depending on new state
	switch (newState)
	{
	case(State::MainMenu) :
		_transitionController = new MainMenuController();
		_currentState = newState;
		_bIsTransitioning = true;
		break;
	case(State::Battling) :
		_transitionController = new BattleController();
		_currentState = newState;
		_bIsTransitioning = true;
		break;
	case(State::Quitting) :
		QuitGame();
		_currentState = newState;
		break;
	}
}