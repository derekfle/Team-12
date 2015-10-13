/*
* Implementation of the AvatarClass class.
*/

#include "AvatarClass.h"

AvatarClass::AvatarClass(const ClassType &t) :
	_classType(t)
{
	switch (_classType) {
		case ClassType::Warrior:
			_rock = Skill("Shield Bash", Skill::SkillType::Rock);
			_paper = Skill("Hamstring", Skill::SkillType::Paper);
			_scissors = Skill("Heroic Strike", Skill::SkillType::Scissors);
			break;
		case ClassType::Rogue:
			_rock = Skill("Headcrack", Skill::SkillType::Rock);
			_paper = Skill("Eviscerate", Skill::SkillType::Paper);
			_scissors = Skill("Backstab", Skill::SkillType::Scissors);
			break;
		case ClassType::Mage:
			_rock = Skill("Cone of Cold", Skill::SkillType::Rock);
			_paper = Skill("Mirror Image", Skill::SkillType::Paper);
			_scissors = Skill("Arcane Missiles", Skill::SkillType::Scissors);
			break;
	}
}

AvatarClass::~AvatarClass()
{}

ClassType AvatarClass::GetClassType() const
{
	return _classType;
}

Skill AvatarClass::GetRockSkill() const 
{ 
	return _rock;
}

Skill AvatarClass::GetPaperSkill() const 
{
	return _paper;
}

Skill AvatarClass::GetScissorsSkill() const 
{
	return _scissors;
}