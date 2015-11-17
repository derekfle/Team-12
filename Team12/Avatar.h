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
	* Returns the Avatar's number of wins
	*/
	unsigned Avatar::GetWins() const;
	
	/*
	* Returns the Avatar's number of Losses
	*/
	unsigned Avatar::GetLosses() const;
	
	/*
	* updates wins
	*/
	void Avatar::Incrementwins() ;

	/*
	* updates Losses
	*/
	void Avatar::IncrementLosses() ;

	/*
	* Returns the Avatar's current XP
	*/
	unsigned Avatar::GetXp() const;

	void Avatar::UpdateLevel();
	
	bool Avatar::GetLevelUp() const;

	void Avatar::ResetLevelUp();

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
	unsigned _numWins;
	unsigned _numLosses;
	unsigned _xp;
	bool _levelup;
	sf::Sprite _sprite;
	sf::Image _sprite_image;
	sf::Texture _sprite_texture;
	const AvatarClass _class;
};