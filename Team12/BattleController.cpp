/*
* Implementation of BattleController class
*/

#include "BattleController.h"
#include "GameManager.h"
#include "InputManager.h"

BattleController::BattleController()
{
}


BattleController::~BattleController()
{}

void BattleController::Tick(sf::RenderWindow &window, const sf::Event &ev)
{
	HandleInput();
	Draw(window, ev);
}

void BattleController::Draw(sf::RenderWindow &window, const sf::Event &ev)
{
	sf::Font font;
	sf::Text text;
	font.loadFromFile("Resources/Chrono.ttf");
	text.setString("Battling Test - Press ESC to return");
	text.setPosition(100, 100);
	text.setColor(sf::Color::White);
	text.setFont(font);
	window.draw(text);
}

void BattleController::HandleInput()
{
	if (InputManager::GetInstance().IsKeyReleased(sf::Keyboard::Escape))
	{
		GameManager::GetInstance().SetGameState(GameManager::State::MainMenu);
	}
}