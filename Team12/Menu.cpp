/*
* Implementation of Menu class
*/

#include <cmath>
#include "Menu.h"

Menu::Menu() :
	_outlineThickness(3),
	_outlineColor(204, 204, 204),
	_color(59, 66, 79),
	_padding(10)
{
	_menuCanvas.setFillColor(_color);
	_menuCanvas.setOutlineColor(_outlineColor);
	_menuCanvas.setOutlineThickness(_outlineThickness);
}

void Menu::Draw(sf::RenderWindow &window)
{
	window.draw(_menuCanvas);

	unsigned count = 0;
	for (MenuItem &item : _items)
	{
		item.SetPosition(sf::Vector2f(_menuCanvas.getPosition().x + _padding, (_menuCanvas.getPosition().y + _padding) + (item.GetDimensions().y + _padding) * count++));
		item.Draw(window);
	}
}

void Menu::SetPosition(const sf::Vector2f &position)
{
	_menuCanvas.setPosition(position.x, position.y);
}

sf::Vector2f Menu::GetDimensions() const
{
	return _dimensions;
}

void Menu::UpdateCanvas()
{
	// Create a rectangle with an outline
	_menuCanvas.setPointCount(4);
	_menuCanvas.setPoint(0, sf::Vector2f(0, 0));
	_menuCanvas.setPoint(1, sf::Vector2f(0, _dimensions.y));
	_menuCanvas.setPoint(2, sf::Vector2f(_dimensions.x, _dimensions.y));
	_menuCanvas.setPoint(3, sf::Vector2f(_dimensions.x, 0));
}

void Menu::AddMenuItem(const MenuItem &item)
{
	const unsigned padding = 5;

	_items.push_back(item);
	_dimensions.y += item.GetDimensions().y + _padding * 2;
	_dimensions.x = std::max(_dimensions.x, item.GetDimensions().x + _padding * 3);

	UpdateCanvas();
}