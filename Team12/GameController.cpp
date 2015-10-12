/*
* Implementation of GameController class
*/

#include "GameController.h"

GameController::GameController() :
	_menu(nullptr),
	_secondaryMenu(nullptr)
{}


GameController::~GameController()
{
	if (_menu) delete _menu;
	if (_secondaryMenu) delete _secondaryMenu;
}

