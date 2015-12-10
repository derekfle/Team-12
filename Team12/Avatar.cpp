/*
* Implementation of the Avatar class.
*/

#include "Avatar.h"

/*
* Base constructor for the Avatar class
*/
Avatar::Avatar(const std::string &n, const unsigned &l, const ClassType t, const unsigned &xp) :
	Actor(),
	_name(n),
	_level(l),
	_health(3 + (l - 1) * 2),
	_maxHealth(3 + (l - 1) * 2),
	_class(t),
	_numWins(0),
	_numLosses(0),
	_xp(xp),
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
	_maxHealth(a.GetMaxHealth()),
	_class(a.GetClass()),
	_sprite_image(a._sprite_image),
	_numWins(a.GetWins()),
	_numLosses(a.GetLosses()),
	_xp(a.GetXp()),
	_levelup(a.GetLevelUp())
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
* Returns the Avatar's max health
*/
unsigned Avatar::GetMaxHealth() const
{
	return _maxHealth;
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

/**
* This method also increases the XP by 50 and updates the Avatar's level.
*/
void Avatar::Incrementwins() 
{
	 _numWins++;
	 _xp += 50;
	 UpdateLevel();
}

/**
* This method also decreases XP by 25 or sets it to zero.
*/
void Avatar::IncrementLosses() {
	_numLosses++;
	if (_xp > 25) {
		_xp -= 25;
	}
	else {
		_xp = 0;
	}
}

/*
* Returns the Avatar's current XP.
*/
unsigned Avatar::GetXp() const{
	return _xp;
}

/*
* Updates the current level of player.
*/
void Avatar::UpdateLevel(){
	if (_xp >= (_level*_level) * 50)
	{
		_level++;
		_levelup = true;
	}

}

bool Avatar::GetLevelUp() const{
	return _levelup;
}

void Avatar::LoseRound(const unsigned& damage)
{
	TakeDamage(damage);
}

/*
* Deals damage taken while in match.
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

/**
* Position override that also sets the sprite position.
*/
void Avatar::SetPosition(const float &xPosition, const float &yPosition)
{ 
	sf::Vector2f pos(xPosition, yPosition);
	_position = pos;
	_sprite.setPosition(pos);
};

/**
* The Draw implementation for the Avatar class which draws the Avatar's sprite.
*/
void Avatar::Draw(sf::RenderWindow &window)
{
	window.draw(_sprite);
}
