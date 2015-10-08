/*
* Declaration of Actor abstract base class
* An Actor has common funcionality required by all things to be drawn in the window
*/

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
	virtual void SetPosition(const float &xPosition, const float &yPosition) = 0;

	/*
	* Returns the actors dimensions
	*/
	sf::Vector2f GetDimensions() const { return _dimensions; }

protected:

	sf::Vector2f _dimensions;
};