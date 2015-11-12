/*
* Implementation of the AIAvatar class.
*/

#include "AIAvatar.h"

AIAvatar::AIAvatar(const std::string &n, const unsigned &l, const ClassType &t, const DifficultyType &d) : 
	Avatar(n, l, t),
	_difficulty(d)
{}

AIAvatar::DifficultyType AIAvatar::GetDifficulty() const
{
	return _difficulty;
}