/*
* Declaration of Menu class
* The Menu class creates an interactable menu that is composed of menu items
*/
#pragma once

#include "MenuItem.h"
#include <vector>

class Menu : public Actor
{
public:

	Menu();

	virtual void Draw(sf::RenderWindow &window) override;
	virtual void SetPosition(const sf::Vector2f &position) override;
	virtual sf::Vector2f GetDimensions() const override;

	void AddMenuItem(const MenuItem &item);

private:

	void UpdateCanvas(); // When the menu changes, it must be updated to fit the new items

	const float _outlineThickness;
	const sf::Color _outlineColor;
	const sf::Color _color;
	const unsigned _padding;

	sf::Vector2f _dimensions; // Computed based on menu items
	sf::ConvexShape _menuCanvas; // Using a convex shape so the corners can be rounded

	std::vector<MenuItem> _items; // Collection of menu items
};