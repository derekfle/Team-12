/*
* Implementation of MenuFactory class
*/

#include "GameManager.h"
#include "MenuFactory.h"

MenuFactory &MenuFactory::GetInstance()
{
	static MenuFactory instance;
	return instance;
}

Menu *MenuFactory::CreateMainMenu() const
{
	Menu *menu = new Menu();
	MenuItem *item;

	item = new MenuItem();
	item->SetText("Start Game");
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText("Toggle Audio");
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText("Quit Game");
	menu->AddMenuItem(item);

	menu->SetPosition(50, GameManager::GetInstance().GetResolution().y - menu->GetDimensions().y - 50);

	return menu;
}

Menu *MenuFactory::CreateTempStartMenu(const sf::Vector2f &primaryDimensions) const
{
	Menu *menu = new Menu();
	MenuItem *item;

	item = new MenuItem();
	item->SetText("Start Game");
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText("Back");
	menu->AddMenuItem(item);

	menu->SetPosition(75 + primaryDimensions.x, GameManager::GetInstance().GetResolution().y - menu->GetDimensions().y - 50);

	return menu;
}
