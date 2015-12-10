/*
* Implementation of MainMenuController class
*/

#include "AvatarSerializer.h"
#include "GameManager.h"
#include "InputManager.h"
#include "MainMenuController.h"
#include "MenuFactory.h"
#include "AIAvatar.h"

MainMenuController::MainMenuController() :
	GameController(),
	_curMenu(CurrentMenu::MainMenu)
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
	if (_secondaryMenu) _secondaryMenu->Draw(window);
}

/**
* Handles input from the user and navigates between primary and secondary menus. 
*/
void MainMenuController::HandleInput()
{
	bool bIsPrimaryMenu = _secondaryMenu ? false : true;

	if (InputManager::GetInstance().IsKeyReleased(std::vector<sf::Keyboard::Key> { sf::Keyboard::W, sf::Keyboard::Up }))
	{
		if (bIsPrimaryMenu)
		{
			_menu->MoveUp();
		}
		else
		{
			_secondaryMenu->MoveUp();
		}
	}
	else if (InputManager::GetInstance().IsKeyReleased(std::vector<sf::Keyboard::Key> { sf::Keyboard::S, sf::Keyboard::Down }))
	{
		if (bIsPrimaryMenu)
		{
			_menu->MoveDown();
		}
		else
		{
			_secondaryMenu->MoveDown();
		}
	}
	else if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::Return))
	{
		std::string selection = bIsPrimaryMenu ? _menu->GetSelection() : _secondaryMenu->GetSelection();

		// Main menu
		if (bIsPrimaryMenu)
		{
			if (selection == "Start Game")
			{
				_secondaryMenu = MenuFactory::GetInstance().CreateChooseClassMenu(_menu->GetDimensions());
				_curMenu = CurrentMenu::ChooseAvatar;
			}
			else if (selection == "Toggle Audio")
			{
				GameManager::GetInstance().ToggleAudio();
			}
			else if (selection == "Quit Game")
			{
				GameManager::GetInstance().SetGameState(GameManager::StateType::Quitting);
			}
		}
		else if (!bIsPrimaryMenu)
		{
			// Secondary menu (Class selection)
			if (_curMenu == CurrentMenu::ChooseAvatar)
			{
				if (selection == AvatarClass::GetClassName(ClassType::Warrior) ||
					selection == AvatarClass::GetClassName(ClassType::Rogue) ||
					selection == AvatarClass::GetClassName(ClassType::Mage))
				{
					if (!AvatarSerializer::GetInstance().LoadAvatar(selection))
					{
						// Create new avatar first
						AvatarSerializer::GetInstance().SaveAvatar(Avatar(selection, 1, AvatarClass::GetClassType(selection)));
						AvatarSerializer::GetInstance().LoadAvatar(selection);
					}
					delete _secondaryMenu;
					_secondaryMenu = MenuFactory::GetInstance().CreateChooseAIDifficultyMenu(_menu->GetDimensions());
					_curMenu = CurrentMenu::ChooseDifficulty;
				}
				else if (selection == "Back")
				{
					delete _secondaryMenu;
					_secondaryMenu = nullptr;
					_curMenu = CurrentMenu::MainMenu;
				}
			}
			else if (_curMenu == CurrentMenu::ChooseDifficulty)
			{
				if (AIAvatar::DifficultyMap.find(selection) != AIAvatar::DifficultyMap.end()) {
					GameManager::GetInstance().aiDifficulty = AIAvatar::DifficultyMap.at(selection);
					GameManager::GetInstance().SetGameState(GameManager::StateType::Battling);
				}
				else if (selection == "Back")
				{
					delete _secondaryMenu;
					_secondaryMenu = MenuFactory::GetInstance().CreateChooseClassMenu(_menu->GetDimensions());
				_curMenu = CurrentMenu::ChooseAvatar;
				}
			}
		}
	}
}
