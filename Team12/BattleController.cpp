/*
* Implementation of BattleController class
*/

#include "BattleController.h"
#include "GameManager.h"
#include "InputManager.h"

BattleController::BattleController(const Avatar &p) :
	_player(p), 
	_opponent(const std::string("AI AVATAR"), p.GetLevel(), p.GetHealth(), ClassType::Warrior)
{
	_player.SetPosition(200, 400);
	_opponent.SetPosition(1000, 400);
}

BattleController::~BattleController()
{}

void BattleController::Tick(sf::RenderWindow &window)
{
	Draw(window);
}

void BattleController::Draw(sf::RenderWindow &window)
{
	sf::Font font;
	sf::Text text;
	font.loadFromFile("Resources/Chrono.ttf");
	text.setString("Battling Test - Press ESC to return");
	text.setPosition(100, 100);
	text.setColor(sf::Color::White);
	text.setFont(font);
	window.draw(text);
	_player.Draw(window);
	_opponent.Draw(window);
}

void BattleController::HandleInput()
{
	if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::Escape))
	{
		GameManager::GetInstance().SetGameState(GameManager::StateType::MainMenu);
	}
}