/*
* Declaration of MenuFactory class
* Singleton class that creates the various game menus
*/

#include "Menu.h"

#pragma once

class MenuFactory
{
public:
	~MenuFactory() {}

	/*
	* Returns the MenuFactory instance
	*/
	static MenuFactory &GetInstance();

	/*
	* Primary menus
	*/
	Menu *CreateMainMenu() const;

	/*
	* Secondary menus
	*/
	Menu *CreateTempStartMenu(const sf::Vector2f &primaryDimensions) const; // TO BE REMOVED

private:
	MenuFactory() {};
	MenuFactory(MenuFactory const&) = delete;
	void operator=(MenuFactory const&) = delete;
};

