/*
* Implementation of BattleController class
*/

#include "AvatarSerializer.h"
#include "BattleController.h"
#include "GameManager.h"
#include "InputManager.h"
#include "MenuFactory.h"
#include <iostream>
#define TIMER_CONST 120

BattleController::BattleController(const Avatar &p) :
	_player(p), 
	_opponent(std::string("AI AVATAR"), p.GetLevel(), ClassType::Warrior),
	_currentMove(nullptr),
	_currentBattleState(BattleState::InBetween),
	_timer(TIMER_CONST)
{
	// Create an array of the player's Skills in order to create the Skills menu
	// Is there a better way to do this?
	AvatarClass classType = _player.GetClass();
	_skillsArray[0] = classType.GetRockSkill();
	_skillsArray[1] = classType.GetPaperSkill();
	_skillsArray[2] = classType.GetScissorsSkill();

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
	if (_timer == 0)
	{
		EndRound();
	}
	if (_currentMove != nullptr && _currentBattleState == BattleState::InBetween) 
	{
		PlayRound();
	}
}

/**
* This method saves the player's Avatar if the match is over, then returns to the main menu; otherwise, 
* it resets the BattleState to InBetween.
*/
void BattleController::EndRound()
{
	if (_currentBattleState == BattleState::WinMatch || _currentBattleState == BattleState::LoseMatch)
	{
		AvatarSerializer::GetInstance().SaveAvatar(_player);
		GameManager::GetInstance().SetGameState(GameManager::StateType::MainMenu);
	}
	else
	{
		_currentMove = nullptr;
		_currentBattleState = BattleState::InBetween;
		_timer = TIMER_CONST;
	}
}

/** This method also displays text that informs the user as to the result of the round. */
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
		text.setString("You Tied With Your Opponent.");
		text.setColor(sf::Color::White); 
	}
	else if (_currentBattleState == BattleState::WinMatch)
	{
		text.setString("You Won the Match!!!");
		text.setColor(sf::Color::Green);
	}
	else if (_currentBattleState == BattleState::WinRound)
	{
		text.setString("You Won the Round!");
		text.setColor(sf::Color::Green);
	}
	else if (_currentBattleState == BattleState::LoseMatch)
	{
		text.setString("You Lost the Match. :(");
		text.setColor(sf::Color::Yellow);
	}
	else if (_currentBattleState == BattleState::LoseRound)
	{
		text.setString("You Lost the Round.");
		text.setColor(sf::Color::Yellow);
	}
	 if (_player.GetLevelUp()){
		sf::Text levelUpText;

		levelUpText.setFont(font);
		levelUpText.setPosition(100, 75);
		levelUpText.setColor(sf::Color::Cyan);
		levelUpText.setString("You Levelled up!! ^_^");

		window.draw(levelUpText);
	}

	if (_currentBattleState != BattleState::InBetween)
	{
		window.draw(text);
		_timer--;
	}
}

void BattleController::HandleInput()
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
	else if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::Return) && (_currentBattleState == BattleState::InBetween))
	{
		std::string selection = bIsPrimaryMenu ? _menu->GetSelection() : _secondaryMenu->GetSelection();

		// Battle menu
		if (bIsPrimaryMenu)
		{
			if (selection == "Choose Skill")
			{
				_secondaryMenu = MenuFactory::GetInstance().CreateTempSkillsMenu(_menu->GetDimensions(), _skillsArray);
			}
			else if (selection == "Forfeit Match")
			{
				_currentBattleState = BattleState::LoseMatch;
			}
		}
		else if (!bIsPrimaryMenu)
		{
			// Skills menu
			if (selection == _skillsArray[0].name)
			{
				_currentMove = new Skill::SkillType(_skillsArray[0].type);
			}
			else if (selection == _skillsArray[1].name)
			{
				_currentMove = new Skill::SkillType(_skillsArray[1].type);
			}
			else if (selection == _skillsArray[2].name)
			{
				_currentMove = new Skill::SkillType(_skillsArray[2].type);
			}
			delete _secondaryMenu;
			_secondaryMenu = nullptr;

		}
	}
}

void BattleController::PlayRound()
{
	// Determine AI Player's move
	Skill::SkillType opponentMove = Skill::SkillType(rand() % 3);
	
	DetermineWinner(opponentMove);
}

/**
* This method compares the player's move and their opponent's move to determine a winner.
* The player's XP and level are adjusted accordingly. 
*/
void BattleController::DetermineWinner(const Skill::SkillType &opponentMove)
{
	// If the Avatars tie, then nothing happens
	if (*_currentMove == opponentMove)
	{
		_currentBattleState = BattleState::TieRound;
	}
	// If the player's Avatar wins, then its opponent's health decreases
	else if ((*_currentMove == Skill::Rock && opponentMove == Skill::Scissors) ||
		(*_currentMove == Skill::Paper && opponentMove == Skill::Rock) ||
		(*_currentMove == Skill::Scissors && opponentMove == Skill::Paper))
	{
		_opponent.TakeDamage(1);

		// When an opponent's health is zero, the player wins the match
		if (_opponent.GetHealth() == 0)
		{
			_currentBattleState = BattleState::WinMatch;
			_player.Incrementwins();
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
			_player.IncrementLosses();
		}
		else
		{
			_currentBattleState = BattleState::LoseRound;
		}
	}
}