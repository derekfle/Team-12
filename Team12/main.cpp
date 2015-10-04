#include <SFML/Graphics.hpp>
#include "Menu.h"

int main()
{
	unsigned x = 1280, y = 720;
	sf::RenderWindow window(sf::VideoMode(x, y), "BattleSim");
	window.setFramerateLimit(60);

	Menu menu;
	menu.SetPosition(sf::Vector2f(400, 200));

	MenuItem item1;
	MenuItem item2;
	MenuItem item3;

	item1.SetText("Test");
	item2.SetText("TESTING");
	item3.SetText("LONG LONG LONG TESTING");

	menu.AddMenuItem(item1);
	menu.AddMenuItem(item2);
	menu.AddMenuItem(item3);

	while (window.isOpen())
	{
		window.clear(sf::Color(41, 46, 55));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		menu.Draw(window);
		window.display();
	}
}