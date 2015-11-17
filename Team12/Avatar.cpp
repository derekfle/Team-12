/*
* Implementation of the Avatar class.
*/

#include "Avatar.h"

/*
* Base constructor for the Avatar class
*/
Avatar::Avatar(const std::string &n, const unsigned &l, const ClassType t) : 
	Actor(),
	_name(n),
	_level(l),
	_health(l * 3),
	_class(t),
	_numWins(0),
	_numLosses(0),
	_xp(0),
	_levelup(false)

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
* Returns the Avatar's number of wins
*/
unsigned Avatar::GetWins() const
{
	return _numWins;
}
/*
* Returns the Avatar's number of losses
*/
unsigned Avatar::GetLosses() const
{
	return _numLosses;
}
void Avatar::Incrementwins() 
{
	 _numWins+1;
	 _xp + 50;
	 UpdateLevel();
}

void Avatar::IncrementLosses() {
	_numLosses + 1;
	_xp - 25;
}

/*
* Returns the Avatar's current XP
*/
unsigned Avatar::GetXp() const{
	return _xp;
}
/*updates the current level of player*/
void Avatar::UpdateLevel(){
	unsigned CurrentXp = GetXp();
	unsigned CurrentLevel = GetLevel();
	if (CurrentXp >= (CurrentLevel*CurrentLevel) * 50){
		_level + 1;
		_health + 2;
		_levelup = true;
	}

}
bool Avatar::GetLevelUp() const{
	return _levelup;
}
void Avatar::ResetLevelUp(){
	_levelup = false;
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