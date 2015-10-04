/*
* Implementation of MenuItem class
*/

#include <iostream>
#include "MenuItem.h"
#include <string>

MenuItem::MenuItem()
{
	if (!font.loadFromFile("SourceCodePro-Semibold.ttf"))
	{
		std::cerr << "Error: Could not load font from file.";
	}
	else
	{
		text.setFont(font);
		text.setColor(sf::Color::White);
		text.setCharacterSize(24);
	}
}

void MenuItem::Draw(sf::RenderWindow &window, const sf::Vector2f &position)
{
	text.setPosition(position);
	window.draw(text);
}

sf::Vector2f MenuItem::GetDimensions() const
{
	return sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
}

void MenuItem::SetText(const std::string &text)
{
	this->text.setString(text);
}
