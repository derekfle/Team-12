/*
* Implementation of InputManager class
*/

#include "InputManager.h"

InputManager &InputManager::GetInstance()
{
	static InputManager instance;
	return instance;
}

void InputManager::Update(const sf::Event &ev)
{
	this->_event = ev;
}

bool InputManager::IsKeyPressed(const sf::Keyboard::Key &key) const
{
	return (_event.type == sf::Event::KeyPressed && _event.key.code == key) ? true : false;
}

bool InputManager::IsKeyReleased(const sf::Keyboard::Key &key) const
{
	return (_event.type == sf::Event::KeyReleased && _event.key.code == key) ? true : false;
}

bool InputManager::IsKeyPressed(const std::vector<sf::Keyboard::Key> &keys) const
{
	for (const sf::Keyboard::Key &key : keys)
	{
		if (IsKeyPressed(key)) return true;
	}
	return false;
}

bool InputManager::IsKeyReleased(const std::vector<sf::Keyboard::Key> &keys) const
{
	for (const sf::Keyboard::Key &key : keys)
	{
		if (IsKeyReleased(key)) return true;
	}
	return false;
}
