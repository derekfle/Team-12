/*
* Implementation of GameController class
*/

#include "GameController.h"

GameController::GameController() :
	_menu(nullptr)
{}


GameController::~GameController()
{
	if (_menu) delete _menu;
}

