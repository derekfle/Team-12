/*
* Declaration of MenuItem class
* Contains all functionality required by menu items
*/
#pragma once

#include <SFML/Graphics.hpp>

class MenuItem
{
public:

	MenuItem();
	void Draw(sf::RenderWindow &window, const sf::Vector2f &position);
	sf::Vector2f GetDimensions() const;
	void SetText(const std::string &text);

private:

	sf::Font font;
	sf::Text text;
};