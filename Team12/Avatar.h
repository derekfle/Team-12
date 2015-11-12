/*
* Declaration of the Avatar class.
* An Avatar extends Actor. It contains character attributes that are used by human and AI players.
*/
#pragma once

#include "Actor.h"
#include "AvatarClass.h"

class Avatar : public Actor 
{
public:

	Avatar(const std::string &n, const unsigned &l, const ClassType t);
	Avatar(const Avatar &a);
	~Avatar() {}

	/*
	* Returns the Avatar's name
	*/
	std::string GetName() const;

	/*
	* Returns the Avatar's level
	*/
	unsigned GetLevel() const;

	/*
	* Returns the Avatar's health
	*/
	unsigned GetHealth() const;

	/*
	* Returns the Avatar's class object
	*/
	AvatarClass GetClass() const;

	/*
	* Deals damage taken while in match
	*/
	void TakeDamage(const unsigned &damage);

	/*
	* Start Actor Interface
	*/
	void Draw(sf::RenderWindow &window) override;

	void SetPosition(const float &xPosition, const float &yPosition) override;
	/*
	* End Actor Interface
	*/

protected:

	const std::string _name;
	unsigned _level;
	unsigned _health;
	sf::Sprite _sprite;
	sf::Image _sprite_image;
	sf::Texture _sprite_texture;
	const AvatarClass _class;
};