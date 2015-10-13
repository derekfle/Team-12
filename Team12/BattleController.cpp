/*
* Implementation of BattleController class
*/

#include "BattleController.h"
#include "GameManager.h"
#include "InputManager.h"
#include "MenuFactory.h"
#include <iostream>
#define TIMER_CONST 300

BattleController::BattleController(const Avatar &p) :
	_player(p), 
	_opponent(std::string("AI AVATAR"), p.GetLevel(), p.GetHealth(), ClassType::Warrior),
	_currentMove(nullptr),
	_timer(TIMER_CONST)
{
	_player.SetPosition(200, 400);
	_opponent.SetPosition(1000, 400);
	_menu = MenuFactory::GetInstance().CreateTempBattleMenu();
}

BattleController::~BattleController()
{
	delete _currentMove;
}

void BattleController::Tick(sf::RenderWindow &window)
{
	Draw(window);
	if (_currentMove != nullptr && _currentBattleState == BattleState::InBetween) 
	{
		PlayRound();
	}
}

void BattleController::Draw(sf::RenderWindow &window)
{
	_player.Draw(window);
	_opponent.Draw(window);
	_menu->Draw(window);
	if (_secondaryMenu) _secondaryMenu->Draw(window);

	// Set the text font and position
	sf::Font font;
	sf::Text text;
	font.loadFromFile("Resources/Chrono.ttf");
	text.setFont(font);
	text.setPosition(100, 100);

	// Display an informative message at the end of a round
	if (_currentBattleState == BattleState::TieRound) 
	{
		text.setString("You Have Tied With Your Opponent.");
		text.setColor(sf::Color::White); 
	}
	else if (_currentBattleState == BattleState::WinMatch)
	{
		text.setString("You Win the Match!!!");
		text.setColor(sf::Color::Blue);
	}
	else if (_currentBattleState == BattleState::WinRound)
	{
		text.setString("You Win the Round!");
		text.setColor(sf::Color::Blue);
	}
	else if (_currentBattleState == BattleState::LoseMatch)
	{
		text.setString("You Lost the Match. :(");
		text.setColor(sf::Color::Green);
	}
	else if (_currentBattleState == BattleState::LoseRound)
	{
		text.setString("You Lost the Round.");
		text.setColor(sf::Color::Green);
	}

	if (_currentBattleState != BattleState::InBetween)
	{
		window.draw(text);
		_timer--;
		
		if (_timer == 0)
		{
			if (_currentBattleState == BattleState::WinMatch || _currentBattleState == BattleState::LoseMatch)
			{
				GameManager::GetInstance().SetGameState(GameManager::StateType::MainMenu);
			}
			else
			{
				_currentMove = nullptr;
				_currentBattleState = BattleState::InBetween;
				_timer = TIMER_CONST;
			}
		}
	}
}

void BattleController::HandleInput()
{	
	bool bIsPrimaryMenu = _secondaryMenu ? false : true;

	// Create an array of the player's Skills in order to create the Skills menu
	AvatarClass classType = _player.GetClass();
	Skill skillsArray[3] = {classType.GetRockSkill(), classType.GetPaperSkill(), classType.GetScissorsSkill()};

	if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::W) || InputManager::GetInstance().IsKeyReleased(sf::Keyboard::Up))
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
	else if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::S) || InputManager::GetInstance().IsKeyReleased(sf::Keyboard::Down))
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

		// Battle menu
		if (bIsPrimaryMenu)
		{
			if (selection == "Choose Skill")
			{
				_secondaryMenu = MenuFactory::GetInstance().CreateTempSkillsMenu(_menu->GetDimensions(), skillsArray);
			}
			else if (selection == "Forfeit Match")
			{
				GameManager::GetInstance().SetGameState(GameManager::StateType::MainMenu);
			}
		}
		else if (!bIsPrimaryMenu)
		{
			// Skills menu
			if (selection == skillsArray[0].name)
			{
				_currentMove = new Skill::SkillType(skillsArray[0].type);
			}
			else if (selection == skillsArray[1].name)
			{
				_currentMove = new Skill::SkillType(skillsArray[1].type);
			}
			else if (selection == skillsArray[2].name)
			{
				_currentMove = new Skill::SkillType(skillsArray[2].type);
			}
			_secondaryMenu = nullptr;

		}
	}
}

void BattleController::PlayRound()
{
	// Determine AI Player's move
	Skill::SkillType move = Skill::SkillType(rand() % 3);

	// If the Avatars tie, then nothing happens
	if (*_currentMove == move)
	{
		_currentBattleState = BattleState::TieRound;
	} 
	// If the player's Avatar wins, then its opponent's health decreases
	else if ((*_currentMove == Skill::Rock && move == Skill::Scissors) || 
		(*_currentMove == Skill::Paper && move == Skill::Rock) || 
		(*_currentMove == Skill::Scissors && move == Skill::Paper))
	{
		_opponent.TakeDamage(1);

		// When an opponent's health is zero, the player wins the match
		if (_opponent.GetHealth() == 0) 
		{
			_currentBattleState = BattleState::WinMatch;
		}
		else
		{
			_currentBattleState = BattleState::WinRound;
		}
	}
	// If the player's Avatar loses, then its health decreases
	else 
	{
		_player.TakeDamage(1);

		// When a player's health is zero, they lose the match
		if (_player.GetHealth() == 0)
		{
			_currentBattleState = BattleState::LoseMatch;
		}
		else
		{
			_currentBattleState = BattleState::LoseRound;
		}
	}
}