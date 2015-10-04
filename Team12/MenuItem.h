/*
* Declaration of MenuItem class
* Contains all functionality required by menu items
*/
#pragma once

#include "Actor.h"

class MenuItem : public Actor
{
public:

	MenuItem();

	virtual void Draw(sf::RenderWindow &window) override;
	virtual void SetPosition(const sf::Vector2f &position) override;

	virtual sf::Vector2f GetDimensions() const override;
	void SetText(const std::string &text);

private:

	const unsigned _fontSize;

	sf::Font _font;
	sf::Text _text;
	sf::Color _color;
};