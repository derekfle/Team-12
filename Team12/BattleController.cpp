/*
* Implementation of BattleController class
*/

#include "AvatarSerializer.h"
#include "BattleController.h"
#include "GameManager.h"
#include "InputManager.h"
#include "MenuFactory.h"
#include <iostream>
#include <sstream>
#define TIMER_CONST 180

BattleController::BattleController(const Avatar &p) :
	_player(p), 
	_opponent(std::string("AI AVATAR"), p.GetLevel(), ClassType::Warrior),
	_currentMove(nullptr),
	_opponentMove(Skill::SkillType(rand() % 3)),
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
	if (_timer == 0)
	{
		EndRound();
	}
	else if (_currentMove != nullptr && _currentBattleState == BattleState::InBetween) 
	{
		PlayRound();
	}
	Draw(window);
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
	_currentMove = nullptr;
	_currentBattleState = BattleState::InBetween;
	_timer = TIMER_CONST;
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
	
	sf::Text playerskillText;
	playerskillText.setFont(font);
	playerskillText.setPosition(200, 300);

	sf::Text opponentskillText;
	opponentskillText.setFont(font);
	opponentskillText.setPosition(800, 300);

	// Display an informative message at the end of a round

	if (_currentBattleState == BattleState::TieRound) 
	{
		playerskillText.setColor(sf::Color::Cyan);
		playerskillText.setString(GetPlayertSkillName());

		opponentskillText.setColor(sf::Color::Cyan);
		opponentskillText.setString(GetOpponentSkillName(_opponentMove));


		window.draw(playerskillText);
		window.draw(opponentskillText);
		text.setString("You Tied With Your Opponent.");
		text.setColor(sf::Color::White); 
	}
	else if (_currentBattleState == BattleState::WinMatch)
	{
			playerskillText.setColor(sf::Color::Cyan);
			playerskillText.setString(GetPlayertSkillName());

			opponentskillText.setColor(sf::Color::Cyan);
			opponentskillText.setString(GetOpponentSkillName(_opponentMove));


			window.draw(playerskillText);
			window.draw(opponentskillText);
		text.setString("You Won the Match!!!");
		text.setColor(sf::Color::Green);
	}
	else if (_currentBattleState == BattleState::WinRound)
	{
		playerskillText.setColor(sf::Color::Cyan);
		playerskillText.setString(GetPlayertSkillName());

		opponentskillText.setColor(sf::Color::Cyan);
		opponentskillText.setString(GetOpponentSkillName(_opponentMove));


		window.draw(playerskillText);
		window.draw(opponentskillText);
		text.setString("You Won the Round!");
		text.setColor(sf::Color::Green);
	}
	else if (_currentBattleState == BattleState::LoseMatch)
	{
		playerskillText.setColor(sf::Color::Cyan);
		playerskillText.setString(GetPlayertSkillName());

		opponentskillText.setColor(sf::Color::Cyan);
		opponentskillText.setString(GetOpponentSkillName(_opponentMove));


		window.draw(playerskillText);
		window.draw(opponentskillText);

		text.setString("You Lost the Match. :(");
		text.setColor(sf::Color::Yellow);
	}
	else if (_currentBattleState == BattleState::LoseRound)
	{
		playerskillText.setColor(sf::Color::Cyan);
		playerskillText.setString(GetPlayertSkillName());

		opponentskillText.setColor(sf::Color::Cyan);
		opponentskillText.setString(GetOpponentSkillName(_opponentMove));


		window.draw(playerskillText);
		window.draw(opponentskillText);
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

	// Draw player and AI health and level
	sf::RectangleShape container;
	container.setFillColor(sf::Color(59, 66, 79));
	container.setOutlineColor(sf::Color(204, 204, 204));
	container.setOutlineThickness(3);
	container.setSize(sf::Vector2f(_menu->GetDimensions().x, 50.f));

	container.setPosition(GameManager::GetInstance().GetResolution().x - 300, 15);
	window.draw(container);

	container.setPosition(_menu->GetPosition().x, _menu->GetPosition().y - 70);
	window.draw(container);

	sf::Text playerName;
	playerName.setFont(font);
	playerName.setPosition(_menu->GetPosition().x + 10, _menu->GetPosition().y - 75);
	playerName.setString(_player.GetName());
	window.draw(playerName);

	sf::Text playerInfo;
	playerInfo.setScale(0.70, 0.70);
	playerInfo.setFont(font);
	playerInfo.setPosition(_menu->GetPosition().x + 10, _menu->GetPosition().y - 50);
	std::stringstream pInfo;
	pInfo << "Level: " << _player.GetLevel() << " Health: " << _player.GetHealth() << "/" << _player.GetMaxHealth();
	playerInfo.setString(pInfo.str());
	window.draw(playerInfo);

	sf::Text opponentName;
	opponentName.setFont(font);
	opponentName.setPosition(GameManager::GetInstance().GetResolution().x - 290, 10);
	opponentName.setString(_opponent.GetName());
	window.draw(opponentName);

	sf::Text opponentInfo;
	opponentInfo.setScale(0.70, 0.70);
	opponentInfo.setFont(font);
	opponentInfo.setPosition(GameManager::GetInstance().GetResolution().x - 290, 35);
	std::stringstream oInfo;
	oInfo << "Level: " << _opponent.GetLevel() << " Health: " << _opponent.GetHealth() << "/" << _opponent.GetMaxHealth();
	opponentInfo.setString(oInfo.str());
	window.draw(opponentInfo);
}

std::string BattleController ::GetOpponentSkillName(Skill::SkillType &skill) {
	if (skill == Skill::Scissors)
		return "Opponent chose Scissors";
	else if (skill == Skill::Rock)
		return "Opponent chose Rock";
	else
		return "Opponent chose Paper";

}
std::string BattleController::GetPlayertSkillName() const{
	if (_currentMove == nullptr)
		return "";
	else if (*_currentMove == Skill::Rock)
		return "You chose Rock";
	else if (*_currentMove == Skill::Scissors)
		return "You chose Scissors";
	else
		return "You chose Paper";
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
				_player.IncrementLosses();
				_timer = 0;
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
	_opponentMove = Skill::SkillType(rand() % 3);
	
	DetermineWinner(_opponentMove);
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