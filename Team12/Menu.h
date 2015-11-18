/**
* Declaration of Menu class
* The Menu class creates an interactable menu that is composed of menu items
*/
#pragma once

#include "MenuItem.h"
#include <SFML\Audio.hpp>
#include <vector>

class Menu : public Actor
{
public:
	/** The constructor for the Menu class. */
	Menu();
	/** The deconstructor for the Menu class. */
	~Menu();

	/** 
	* Actor Interface: draws the menu. 
	*
	* @param window - a reference to a window to display
	*/
	virtual void Draw(sf::RenderWindow &window) override;

	/**
	* Sets the position of the menu in the window.
	*
	* @param xPosition - a constant reference to a floating point value which represents
	* the x coordinate position of the menu
	* @param yPosition - a constant reference to a floating point value which represents
	* the x coordinate position of the menu
	*/
	virtual void SetPosition(const float &xPosition, const float &yPosition) override;

	/**
	* Adds a MenuItem to the Menu.
	* 
	* @param item a pointer to a MenuItem
	*/
	void AddMenuItem(MenuItem *item);

	/**
	* Member function to switch up in item selection.
	*/
	void MoveUp();
	/**
	* Member function to switch down in item selection.
	*/
	void MoveDown();

	/**
	* Returns the current selection text and plays the selection sound.
	* 
	* @return a string representation of the selection
	*/
	std::string GetSelection();

private:

	/** Indicates menu changes, so that it may be updated to fit the new items. */
	void UpdateCanvas();  

	/** The outline thickness of the menu canvas. */
	const float _outlineThickness;
	/** The outline colour of the menu canvas. */
	const sf::Color _outlineColor;
	/** The fill colour on the menu canvas. */
	const sf::Color _color;
	/** The padding between menu items. */
	const unsigned _padding;

	/** The sound selection when changing menu items. */
	sf::Sound _selectionChangeSound;
	/** Contains the sound binary used for changing menu items. */
	sf::SoundBuffer _selectionChangeSoundBuffer;

	/** The sound selection when selecting menu items. */
	sf::Sound _selectSound;
	/** Contains the sound binary used for selecting menu items. */
	sf::SoundBuffer _selectSoundBuffer;

	/** The menu canvas, which uses a convex shape so the corners can be rounded. */
	sf::ConvexShape _menuCanvas; 
	/** Collection of menu items */
	std::vector<MenuItem*> _items; 

	/** The current selection ID */
	unsigned _currentSelectionIdx;
};