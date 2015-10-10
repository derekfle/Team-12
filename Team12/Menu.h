/*
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

	Menu();
	~Menu();

	/* START Actor interface */
	virtual void Draw(sf::RenderWindow &window) override;
	virtual void SetPosition(const float &xPosition, const float &yPosition) override;
	/* END Actor interface */

	/*
	* Adds a menu items to the menu
	*/
	void AddMenuItem(MenuItem *item);

	/*
	* Member functions to change item selection
	*/
	void MoveUp();
	void MoveDown();

	/*
	* Returns the current selection text and plays the selection sound
	*/
	std::string GetSelection();

private:

	void UpdateCanvas(); // When the menu changes, it must be updated to fit the new items

	const float _outlineThickness;
	const sf::Color _outlineColor;
	const sf::Color _color;
	const unsigned _padding;

	sf::Sound _selectionChangeSound;
	sf::SoundBuffer _selectionChangeSoundBuffer;

	sf::Sound _selectSound;
	sf::SoundBuffer _selectSoundBuffer;

	sf::ConvexShape _menuCanvas; // Using a convex shape so the corners can be rounded
	std::vector<MenuItem*> _items; // Collection of menu items

	unsigned _currentSelectionIdx;
};