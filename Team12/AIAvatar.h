/*
* Declaration of the AIAvatar class.
* An AIAvatar extends Avatar. It contains AI difficulty.
*/

#include "Avatar.h"

class AIAvatar : public Avatar
{
public: 
	enum class DifficultyType { Easy, Medium, Hard };

	AIAvatar(const std::string &n, const unsigned &l, const ClassType &t, const DifficultyType &d);
	~AIAvatar() {}

	DifficultyType GetDifficulty() const;
	
private:

	const DifficultyType _difficulty;
};