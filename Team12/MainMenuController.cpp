/*
* Implementation of MainMenuController class
*/

#include "GameManager.h"
#include "InputManager.h"
#include "MainMenuController.h"
#include "MenuFactory.h"

MainMenuController::MainMenuController() :
	GameController()
{
	// Initialize menu to the main menu
	_menu = MenuFactory::GetInstance().CreateMainMenu();
}

void MainMenuController::Tick(sf::RenderWindow &window)
{
	Draw(window);
}

void MainMenuController::Draw(sf::RenderWindow &window)
{
	_menu->Draw(window);
}

void MainMenuController::HandleInput()
{
	if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::W))
	{
		_menu->MoveUp();
	}
	else if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::S))
	{
		_menu->MoveDown();
	}
	else if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::Return))
	{
		// Revisit this... I am not quite happy with how I handle this with hard coded strings
		if (_menu->GetSelection() == "Start Game")
		{
			GameManager::GetInstance().SetGameState(GameManager::State::Battling);
		}
		else if (_menu->GetSelection() == "Toggle Audio")
		{
			GameManager::GetInstance().ToggleAudio();
		}
		else if (_menu->GetSelection() == "Quit Game")
		{
			GameManager::GetInstance().SetGameState(GameManager::State::Quitting);
		}
	}
}
