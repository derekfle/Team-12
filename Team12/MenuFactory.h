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

	Menu *CreateMainMenu() const;

private:
	MenuFactory() {};
	MenuFactory(MenuFactory const&) = delete;
	void operator=(MenuFactory const&) = delete;
};

