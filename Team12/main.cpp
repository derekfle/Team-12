#include "InputManager.h"
#include "GameManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(GameManager::GetInstance().GetResolution().x, GameManager::GetInstance().GetResolution().y), "Project12");
	window.setVerticalSyncEnabled(true);

	// Game loop
	while (window.isOpen())
	{
		sf::Event event;
		window.clear(sf::Color(41, 46, 55));

		while (window.pollEvent(event))
		{
			switch(event.type)
			{
			case(sf::Event::Closed):
				GameManager::GetInstance().SetGameState(GameManager::StateType::Quitting);
				break;
			case(sf::Event::KeyPressed) :
			case(sf::Event::KeyReleased) :
				InputManager::GetInstance().Update(event);
				GameManager::GetInstance().HandleInput();
				break;
			default:
				break;
			}
		}

		if (GameManager::GetInstance().GetGameState() == GameManager::StateType::Quitting)
		{
			window.close();
		}

		GameManager::GetInstance().Tick(window);
		window.display();
	}
}