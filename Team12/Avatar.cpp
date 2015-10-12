/*
* Implementation of the Avatar class.
*/

#include "Avatar.h"

Avatar::Avatar(const std::string &n, const unsigned &l, const unsigned &h, const sf::Sprite &s) : 
	Actor(),
	_name(n),
	_level(l),
	_health(h),
	_sprite(s) 
{}