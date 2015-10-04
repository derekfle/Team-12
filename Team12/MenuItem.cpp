/*
* Implementation of MenuItem class
*/

#include <iostream>
#include "MenuItem.h"
#include <string>

MenuItem::MenuItem() :
	_fontSize(24),
	_color(sf::Color::White)
{
	// Load font from file then set the text
	if (!_font.loadFromFile("SourceCodePro-Semibold.ttf"))
	{
		std::cerr << "Error: Could not load font from file.";
	}
	else
	{
		_text.setFont(_font);
		_text.setColor(sf::Color::White);
		_text.setCharacterSize(_fontSize);
	}
}

void MenuItem::SetPosition(const sf::Vector2f &position)
{
	_text.setPosition(position);
}

void MenuItem::Draw(sf::RenderWindow &window)
{
	window.draw(_text);
}

sf::Vector2f MenuItem::GetDimensions() const
{
	return sf::Vector2f(_text.getLocalBounds().width, _text.getLocalBounds().height);
}

void MenuItem::SetText(const std::string &text)
{
	this->_text.setString(text);
}
