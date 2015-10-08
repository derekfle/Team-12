/*
* Implementation of MenuItem class
*/

#include <iostream>
#include "MenuItem.h"
#include <string>

MenuItem::MenuItem() :
	Actor(),
	_fontSize(32),
	_color(sf::Color::White),
	_bIsSelected(false)
{
	// Load font from file then set the text
	if (!_font.loadFromFile("Resources/Chrono.ttf"))
	{
		std::cerr << "Error: Could not load font from file.";
	}
	else
	{
		_text.setFont(_font);
		_text.setCharacterSize(_fontSize);
	}
}

MenuItem::~MenuItem()
{}

void MenuItem::SetPosition(const float &xPosition, const float &yPosition)
{
	_text.setPosition(xPosition, yPosition);
}

void MenuItem::Draw(sf::RenderWindow &window)
{
	if (_bIsSelected)
	{
		_text.setColor(sf::Color::Red);
		window.draw(_text);
	}
	else
	{
		_text.setColor(sf::Color::White);
		window.draw(_text);
	}
}

void MenuItem::SetText(const std::string &text)
{
	this->_text.setString(text);
	_dimensions.x = _text.getLocalBounds().width;
	_dimensions.y = _fontSize;
}

void MenuItem::ToggleSelected()
{
	_bIsSelected = !_bIsSelected;
}

bool MenuItem::IsSelected() const
{
	return _bIsSelected;
}

std::string MenuItem::GetText() const
{
	return _text.getString();
}
