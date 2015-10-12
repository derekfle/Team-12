/*
* Implementation of the AIAvatar class.
*/

#include "AIAvatar.h"

AIAvatar::AIAvatar(const std::string &n, const unsigned &l, const unsigned &h, const sf::Sprite &s, const DifficultyType &d) : 
	Avatar(n, l, h, s),
	_difficulty(d)
{}