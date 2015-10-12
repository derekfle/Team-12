/*
* Declaration of the Avatar class.
* An Avatar extends Actor. It contains character attributes that are used by human and AI players.
*/

#include "Actor.h"
#include "AvatarClass.h"

class Avatar : public Actor 
{
public:

	Avatar(const std::string &n, const unsigned int &l, const unsigned int &h, const ClassType t);
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
	const AvatarClass _class;
};