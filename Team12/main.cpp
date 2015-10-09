#include "GameManager.h"
#include "AvatarSerializer.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(GameManager::GetInstance().GetResolution().x, GameManager::GetInstance().GetResolution().y), "Project12");
	window.setVerticalSyncEnabled(true);

	/* Avatar Serializer Test */
	AvatarData data;
	data.level = 10;
	data.name = "Derek";

	AvatarSerializer::GetInstance().SaveAvatarData(data);

	AvatarData loaded = AvatarSerializer::GetInstance().LoadAvatarData(data.name);
	std::cout << loaded.name << std::endl;
	std::cout << loaded.level << std::endl;
	/* End Avatar Serializer Test */

	// Game loop
	while (window.isOpen())
	{
		sf::Event event;
		// FOR NOW THIS WORKS
		//	For example, if animations are added, the game loops needs to be more advanced...
		while (window.pollEvent(event))
		{
			window.clear(sf::Color(41, 46, 55));
			GameManager::GetInstance().Tick(window, event);
			window.display();
		}
	}
}