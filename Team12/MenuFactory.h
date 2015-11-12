/*
* Declaration of MenuFactory class
* Singleton class that creates the various game menus
*/

#include "Menu.h"
#include "AvatarClass.h"

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
	Menu *CreateChooseClassMenu(const sf::Vector2f &primaryDimensions) const;

	/*
	* Battle menu to be shown during a player's turn
	*/
	Menu *CreateTempBattleMenu() const; 

	/*
	* Skills menu to be shown when a player chooses the "Choose Skill" option in the battle menu
	*/
	Menu *CreateTempSkillsMenu(const sf::Vector2f &battleDimensions, const Skill *skillArray) const;

private:
	MenuFactory() {};
	MenuFactory(MenuFactory const&) = delete;
	void operator=(MenuFactory const&) = delete;
};

