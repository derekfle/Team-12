/*
* Implementation of the Avatar class.
*/

#include "Avatar.h"

Avatar::Avatar(const std::string &n, const unsigned int &l, const unsigned int &h, const ClassType t) : 
	Actor(),
	_name(n),
	_level(l),
	_health(h),
	_class(t)
{
	sf::Image* opImg = new sf::Image();
	opImg->create(10, 10, sf::Color::Red);
	sf::Texture* opTex = new sf::Texture();
	opTex->loadFromImage(*opImg);
	_sprite = *(new sf::Sprite(*opTex));
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

void Avatar::SetPosition(const float &xPosition, const float &yPosition)
{ 
	sf::Vector2f pos(xPosition, yPosition);
	_position = pos;
	if (&_sprite)
	{
		_sprite.setPosition(pos);
	}
};

void Avatar::Draw(sf::RenderWindow &window)
{
	window.draw(_sprite);
}