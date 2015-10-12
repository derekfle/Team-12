/*
* Declaration of the AIAvatar abstract class.
* An AIAvatar extends Avatar. It contains AI difficulty.
*/

#include "Avatar.h"

class AIAvatar : public Avatar
{
public: 
	enum class DifficultyType { Easy, Medium, Hard };

	AIAvatar(const std::string &n, const unsigned &l, const unsigned &h, const sf::Sprite &s, const DifficultyType &d);
	~AIAvatar() {}

	DifficultyType GetDifficulty() const { return _difficulty; }
	
private:

	const DifficultyType _difficulty;
};