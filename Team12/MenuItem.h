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
	~MenuItem();

	/* START Actor interface */
	virtual void Draw(sf::RenderWindow &window) override;
	/* END Actor interface */

	/*
	* Sets the text to be displayed as the menu item
	*/
	void SetText(const std::string &text);

	/*
	* Gets the current text
	*/
	std::string GetText() const;

	/*
	* Toggles menu item selection
	*/
	void ToggleSelected();

	/*
	* Returns true if the item is selected
	*/
	bool IsSelected() const;

private:

	const unsigned _fontSize;

	sf::Font _font;
	sf::Text _text;
	sf::Color _color;

	bool _bIsSelected;
};