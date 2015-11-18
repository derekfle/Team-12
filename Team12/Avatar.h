/**
* Declaration of the Avatar class.
* An Avatar extends Actor. It contains character attributes that are used by human and AI players.
*/
#pragma once

#include "Actor.h"
#include "AvatarClass.h"

class Avatar : public Actor 
{
public:
	/**
	* Avatar class constructor which accepts a name, level, and ClassType specification.
	*
	* @param n - a constant reference to the Avatar's name
	* @param l - a constant reference to the Avatar's level
	* @param t - the ClassType of the Avatar
	*/
	Avatar(const std::string &n, const unsigned &l, const ClassType t);
	/**
	* Avatar class copy constructor which accepts an Avatar object.
	*
	* @param n - a constant reference to an Avatar object
	*/
	Avatar(const Avatar &a);
	/** Avatar class deconstructor. */
	~Avatar() {}

	/**
	* Returns the Avatar's name.
	*
	* @return the name of the Avatar
	*/
	std::string GetName() const;

	/**
	* Returns the Avatar's level.
	* 
	* @return the level of the Avatar, represented as an unsigned number
	*/
	unsigned GetLevel() const;

	/**
	* Returns the Avatar's health.
	* 
	* @return the health of the Avatar, represented as an unsigned number
	*/
	unsigned GetHealth() const;

	/**
	* Returns the Avatar's class object.
	*
	* @return the AvatarClass specification of the Avatar.
	*/
	AvatarClass GetClass() const;
	
	/**
	* Returns the Avatar's number of wins.
	* 
	* @return the number of times the Avatar has won
	*/
	unsigned Avatar::GetWins() const;
	
	/**
	* Returns the Avatar's number of Losses.
	* 
	* @return the number of times the Avatar has lost
	*/
	unsigned Avatar::GetLosses() const;
	
	/**
	* Updates the number of wins.
	* This method increments the number of wins for the Avatar.
	*/
	void Avatar::Incrementwins();

	/**
	* Updates the number of losses.
	* This method increments the number of losses for the Avatar.
	*/
	void Avatar::IncrementLosses();

	/**
	* Returns the Avatar's current XP.
	* 
	* @return the current XP (experience) that the Avatar has as an unsigned number
	*/
	unsigned Avatar::GetXp() const;

	/**
	* Updates the level.
	*/
	void Avatar::UpdateLevel();
	
	/**
	* Determines if the level needs to be updated.
	*
	* @return a boolean value indicating whether the Avatar can level up
	*/
	bool Avatar::GetLevelUp() const;

	/**
	* Deals damage taken while playing a round.
	*/
	void TakeDamage(const unsigned &damage);

	/**
	* Actor Interface: draws the Avatar.
	*/
	void Draw(sf::RenderWindow &window) override;

	/**
	* Actor Interface: specifies the position of the Avatar.
	*/
	void SetPosition(const float &xPosition, const float &yPosition) override;

protected:
	/** Name of the Avatar. */
	const std::string _name;
	/** The Avatar's current level. */
	unsigned _level;
	/** The amount of health that the Avatar has. */
	unsigned _health;
	/** The number of wins that the Avatar has achieved. */
	unsigned _numWins;
	/** The number of losses that the Avatar has suffered. */
	unsigned _numLosses;
	/** The amount XP (experience) that the Avatar currently has; cannot be less than zero. */
	unsigned _xp;
	/** Contains whether the Avatar has leveled up. */
	bool _levelup;
	/** The sprite that represents the Avatar. */
	sf::Sprite _sprite;
	/** The image used for the Avatar's sprite. */
	sf::Image _sprite_image;
	/** The texture that the Avatar's image uses. */
	sf::Texture _sprite_texture;
	/** The Avatar's class. */
	const AvatarClass _class;
};