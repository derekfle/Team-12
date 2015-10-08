/*
* Declaration of InputManager class
* Singleton class for handling game input
*/

#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class InputManager
{
public:
	~InputManager() {};

	/*
	* Returns the InputManager instance
	*/
	static InputManager &GetInstance();

	/*
	* Updates the window and event for current frame
	*/
	void Update(const sf::Event &ev);

	/*
	* Various member functions for determining key presses
	*/
	bool IsKeyPressed(const sf::Keyboard::Key &key) const;
	bool IsKeyReleased(const sf::Keyboard::Key &key) const;

	bool IsKeyPressed(const std::vector<sf::Keyboard::Key> &keys) const;
	bool IsKeyReleased(const std::vector<sf::Keyboard::Key> &keys) const;

private:
	InputManager() {};
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;

	sf::Event _event;
};

