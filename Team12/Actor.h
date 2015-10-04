/*
* Declaration of Actor abstract base class
* An Actor has common funcionality required by all things to be drawn in the window
*/

#include <SFML\Graphics.hpp>

class Actor
{
public:

	virtual void Draw(sf::RenderWindow &window) = 0;
	virtual void SetPosition(const sf::Vector2f &position) = 0;
	virtual sf::Vector2f GetDimensions() const = 0;
};