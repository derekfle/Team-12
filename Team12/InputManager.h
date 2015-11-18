/**
* Declaration of InputManager class.
* Singleton class for handling game input.
*/

#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class InputManager
{
public:
	/** Deconstructor for the InputManager class. */
	~InputManager() {};

	/**
	* Returns the InputManager instance.
	*/
	static InputManager &GetInstance();

	/**
	* Updates the window and event for current frame.
	* @param ev a constant reference to an SFML event
	*/
	void Update(const sf::Event &ev);

	/**
	* Member function for determining if a key is pressed.
	* @param key a constant reference to a keyboard key
	*/
	bool IsKeyPressed(const sf::Keyboard::Key &key) const;
	/**
	* Member function for determining if a key is released.
	* @param key a constant reference to a keyboard key
	*/
	bool IsKeyReleased(const sf::Keyboard::Key &key) const;

	/**
	* Member function for determining if keys are pressed.
	* @param keys a constant reference to an array of keyboard keys
	*/
	bool IsKeyPressed(const std::vector<sf::Keyboard::Key> &keys) const;
	/**
	* Member function for determining if keys are released.
	* @param key a constant reference to an array of keyboard keys
	*/
	bool IsKeyReleased(const std::vector<sf::Keyboard::Key> &keys) const;

private:
	/** The constructor for the InputManager class. */
	InputManager() {};
	/** Delete the copy constructor so that it won't be used. */
	InputManager(InputManager const&) = delete;
	/** Delete the assignment operator so that it won't be used. */
	void operator=(InputManager const&) = delete;

	/** An SFML event. */
	sf::Event _event;
};

