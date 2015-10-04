/*
* Declaration of Menu class
* The Menu class creates an interactable menu that is composed of menu items
*/
#pragma once

#include "MenuItem.h"
#include <SFML\Graphics.hpp>
#include <vector>

class Menu
{
public:

	Menu();

	void Draw(sf::RenderWindow &window) const;
	void SetPosition(const sf::Vector2f &position);
	void AddMenuItem(const MenuItem &item);

private:

	void CreateCanvas(); // When the menu changes, it must be updated to fit the new items

	const float outlineThickness;
	const sf::Color outlineColor;
	const sf::Color color;

	sf::Vector2f dimensions; // Computed based on menu items
	sf::ConvexShape menuCanvas; // Using a convex shape so the corners can be rounded

	std::vector<MenuItem> items; // Collection of menu items
};