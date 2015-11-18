/**
* Declaration of MenuItem class.
* Contains all functionality required by menu items.
*/
#pragma once

#include "Actor.h"

class MenuItem : public Actor
{
public:

	/** Constructor for the MenuItem class. */
	MenuItem();
	/** Deonstructor for the MenuItem class. */
	~MenuItem();

	/** 
	* Actor Interface: draw the menu item.
	*
	* @param window - a constant reference to a window
	*/
	virtual void Draw(sf::RenderWindow &window) override;

	/**
	* Sets the text to be displayed as the menu item.
	*
	* @param text - a constant reference to the text to be displayed
	*/
	void SetText(const std::string &text);

	/**
	* Obtains the current text.
	*
	* @return the text that's displayed as the menu item
	*/
	std::string GetText() const;

	/**
	* Toggles menu item selection.
	*/
	void ToggleSelected();

	/**
	* Returns true if the item is selected.
	*
	* @return a boolean value indicating if the item has been selected
	*/
	bool IsSelected() const;

private:

	/** The font size, which is constant. */
	const unsigned _fontSize;

	/** The font used. */
	sf::Font _font;
	/** The text to display. */
	sf::Text _text;
	/** The the colour of the text to display. */
	sf::Color _color;

	/** Bolean value indicating whether the item has been selected. */
	bool _bIsSelected;
};