/*
* Implementation of the Skill class.
*/

#include <String>
#include "Skill.h"

Skill::Skill(const std::string &n, const SkillType &t) :
	name(n),
	type(t)
{}