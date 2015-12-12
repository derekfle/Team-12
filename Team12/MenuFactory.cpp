/*
* Implementation of MenuFactory class
*/

#include "AIAvatar.h"
#include "AvatarClass.h"
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

Menu *MenuFactory::CreateChooseClassMenu(const sf::Vector2f &primaryDimensions) const
{
	Menu *menu = new Menu();
	MenuItem *item;

	item = new MenuItem();
	item->SetText(AvatarClass::GetClassName(ClassType::Warrior));
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText(AvatarClass::GetClassName(ClassType::Rogue));
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText(AvatarClass::GetClassName(ClassType::Mage));
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText("Back");
	menu->AddMenuItem(item);

	menu->SetPosition(75 + primaryDimensions.x, GameManager::GetInstance().GetResolution().y - menu->GetDimensions().y - 50);

	return menu;
}

Menu *MenuFactory::CreateChooseAIDifficultyMenu(const sf::Vector2f &primaryDimensions) const
{
	Menu *menu = new Menu();
	MenuItem *item;

	for (auto &name : AIAvatar::DifficultyNames)
	{
		item = new MenuItem();
		item->SetText(name);
		menu->AddMenuItem(item);
	}
	
	item = new MenuItem();
	item->SetText("Back");
	menu->AddMenuItem(item);

	menu->SetPosition(75 + primaryDimensions.x, GameManager::GetInstance().GetResolution().y - menu->GetDimensions().y - 50);

	return menu;
}

Menu *MenuFactory::CreateTempBattleMenu() const
{
	Menu *menu = new Menu();
	MenuItem *item;

	item = new MenuItem();
	item->SetText("Choose Skill");
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText("Forfeit Match");
	menu->AddMenuItem(item);

	menu->SetPosition(50, GameManager::GetInstance().GetResolution().y - menu->GetDimensions().y - 50);

	return menu;
}

Menu *MenuFactory::CreateTempSkillsMenu(const sf::Vector2f &battleDimensions, const Skill *skillArray) const
{
	Menu *menu = new Menu();
	MenuItem *item;

	item = new MenuItem();
	item->SetText(skillArray[0].name);
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText(skillArray[1].name);
	menu->AddMenuItem(item);

	item = new MenuItem();
	item->SetText(skillArray[2].name);
	menu->AddMenuItem(item);

	menu->SetPosition(75 + battleDimensions.x, GameManager::GetInstance().GetResolution().y - menu->GetDimensions().y - 50);

	return menu;
}
