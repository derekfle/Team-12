/**
* Declaration of MenuFactory class
* Singleton class that creates the various game menus
*/

#pragma once

#include "Menu.h"
#include "AvatarClass.h"

class MenuFactory
{
public:
	/** The deconstructor for the MenuFactory class. */
	~MenuFactory() {}

	/**
	* Returns the MenuFactory instance.
	*
	* @return the MenuFactory instance
	*/
	static MenuFactory &GetInstance();

	/**
	* Creates the primary menu.
	*
	* @return a pointer to the primary menu
	*/
	Menu *CreateMainMenu() const;

	/**
	* Creates secondary menus.
	*
	* @param primaryDimensions - a constant reference to a 2D vector representing the dimensions of the primary Menu
	* @return a pointer to a secondary menu
	*/
	Menu *CreateChooseClassMenu(const sf::Vector2f &primaryDimensions) const;

	/**
	* Battle menu to be shown during a player's turn.
	*
	* @return a pointer to a battle menu
	*/
	Menu *CreateTempBattleMenu() const; 

	/**
	* Skills menu to be shown when a player chooses the "Choose Skill" option in the battle menu.
	*
	* @param battleDimensions - a constant reference to a 2D vector representing the dimensions of the Battle Menu
	* @param skillArray - a constant pointr to an array of skills representing the player's class
	* @return a pointer to a secondary battle menu
	*/
	Menu *CreateTempSkillsMenu(const sf::Vector2f &battleDimensions, const Skill *skillArray) const;


private:

	/** The MenuFactory constructor. */
	MenuFactory() {};
	/** Delete the copy constructor so that it won't be used. */
	MenuFactory(MenuFactory const&) = delete;
	/** Delete the assignment operator so that it won't be used. */
	void operator=(MenuFactory const&) = delete;
};

