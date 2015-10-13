/*
* Implementation of the Avatar class.
*/

#include "Avatar.h"

/*
* Base constructor for the Avatar class
*/
Avatar::Avatar(const std::string &n, const unsigned int &l, const unsigned int &h, const ClassType t) : 
	Actor(),
	_name(n),
	_level(l),
	_health(h),
	_class(t)
{
	_sprite_image.create(10, 10, sf::Color::Red);
	_sprite_texture.loadFromImage(_sprite_image);
	_sprite = sf::Sprite(_sprite_texture);
}

/*
* Copy constructor for the Avatar class
*/
Avatar::Avatar(const Avatar &a) :
	Actor(),
	_name(a.GetName()),
	_level(a.GetLevel()),
	_health(a.GetHealth()),
	_class(a.GetClass()),
	_sprite_image(a._sprite_image)
{
	_sprite_texture.loadFromImage(_sprite_image);
	_sprite = sf::Sprite(_sprite_texture);
}

/*
* Returns the Avatar's name
*/
std::string Avatar::GetName() const
{
	return _name;
}

/*
* Returns the Avatar's level
*/
unsigned Avatar::GetLevel() const
{
	return _level;
}

/*
* Returns the Avatar's health
*/
unsigned Avatar::GetHealth() const
{
	return _health; 
}

/* 
* Returns the Avatar's class
*/
AvatarClass Avatar::GetClass() const
{
	return _class;
}

/*
* Deals damage taken while in match
*/
void Avatar::TakeDamage(const unsigned &damage)
{
	if (damage > _health)
	{
		_health = 0;
	}
	else
	{
		_health = _health - damage;
	}
}

/*
* Position override that also sets the sprite position.
*/
void Avatar::SetPosition(const float &xPosition, const float &yPosition)
{ 
	sf::Vector2f pos(xPosition, yPosition);
	_position = pos;
	_sprite.setPosition(pos);
};

/*
* The draw implementation for the Avatar class. Draws the Avatar's sprite.
*/
void Avatar::Draw(sf::RenderWindow &window)
{
	window.draw(_sprite);
}