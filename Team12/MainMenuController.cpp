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

void MainMenuController::Tick(sf::RenderWindow &window, const sf::Event &ev)
{
	HandleInput(window);
	Draw(window, ev);
}

void MainMenuController::Draw(sf::RenderWindow &window, const sf::Event &ev)
{
	_menu->Draw(window);
}

void MainMenuController::HandleInput(sf::RenderWindow &window)
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
