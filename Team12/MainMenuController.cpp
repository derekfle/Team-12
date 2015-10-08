/*
* Implementation of MainMenuController class
*/

#include "InputManager.h"
#include "MainMenuController.h"
#include "MenuFactory.h"

#include <iostream>

MainMenuController::MainMenuController() :
	GameController()
{
	// Initialize menu to the main menu
	_menu = MenuFactory::GetInstance().CreateMainMenu();
}

void MainMenuController::Tick(sf::RenderWindow &window, const sf::Event &ev)
{
	HandleInput();
	Draw(window, ev);
}

void MainMenuController::Draw(sf::RenderWindow &window, const sf::Event &ev)
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
}
