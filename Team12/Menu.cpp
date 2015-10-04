/*
* Implementation of Menu class
*/

#include <cmath>
#include "Menu.h"

Menu::Menu() :
	outlineThickness(3),
	outlineColor(204, 204, 204),
	color(59, 66, 79)
{}

void Menu::Draw(sf::RenderWindow &window) const
{
	window.draw(menuCanvas);

	unsigned count = 0;
	for (MenuItem item : items)
	{
		item.Draw(window, sf::Vector2f(menuCanvas.getPosition().x + 5, menuCanvas.getPosition().y + (item.GetDimensions().y + 5) * count++));
	}
}

void Menu::SetPosition(const sf::Vector2f &position)
{
	menuCanvas.setPosition(position.x, position.y);
}

void Menu::CreateCanvas()
{
	// Create a rectangle with an outline
	menuCanvas.setPointCount(4);
	menuCanvas.setPoint(0, sf::Vector2f(0, 0));
	menuCanvas.setPoint(1, sf::Vector2f(0, dimensions.y));
	menuCanvas.setPoint(2, sf::Vector2f(dimensions.x, dimensions.y));
	menuCanvas.setPoint(3, sf::Vector2f(dimensions.x, 0));

	menuCanvas.setFillColor(color);
	menuCanvas.setOutlineColor(outlineColor);
	menuCanvas.setOutlineThickness(outlineThickness);
}

void Menu::AddMenuItem(const MenuItem &item)
{
	const unsigned padding = 5;

	items.push_back(item);
	dimensions.y += item.GetDimensions().y + 5 * 2;
	dimensions.x = std::max(dimensions.x, item.GetDimensions().x + 5 * 2);

	CreateCanvas();
}