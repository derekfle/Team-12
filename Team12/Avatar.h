/*
* Declaration of the Avatar abstract class.
* An Avatar extends Actor. It contains character attributes that are used by human and AI players.
*/

#include "Actor.h"

class Avatar : public Actor 
{
public:

	Avatar(const std::string &n, const unsigned &l, const unsigned &h, const sf::Sprite &s);
	~Avatar() {}

	/*
	* Returns the Avatar's name
	*/
	std::string GetName() const { return _name; }

	/*
	* Returns the Avatar's level
	*/
	unsigned GetLevel() const { return _level; }

	/*
	* Returns the Avatar's health
	*/
	unsigned GetHealth() const { return _health; }

	/*
	* Deals damage taken while in match
	*/
	void TakeDamage(const unsigned &damage) 
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

protected:

	const std::string _name;
	unsigned _level;
	unsigned _health;
	const sf::Sprite _sprite;
};