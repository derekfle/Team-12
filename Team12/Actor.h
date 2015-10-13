/*
* Declaration of Actor abstract base class
* An Actor has common funcionality required by all things to be drawn in the window
*/
#pragma once

#include <SFML\Graphics.hpp>

class Actor
{
public:

	Actor() {}
	~Actor() {}

	/*
	* Draws a new frame
	*/
	virtual void Draw(sf::RenderWindow &window) = 0;

	/*
	* Sets the actors position on the screen
	*/
	virtual void SetPosition(const float &xPosition, const float &yPosition) { _position = sf::Vector2f(xPosition, yPosition); };

	/*
	* Returns the actor's dimensions
	*/
	sf::Vector2f GetDimensions() const { return _dimensions; }

protected:

	/*
	* The position and dimensions of the actor
	*/
	sf::Vector2f _dimensions;
	sf::Vector2f _position;
};