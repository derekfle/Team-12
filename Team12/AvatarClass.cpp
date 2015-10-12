/*
* Implementation of the AvatarClass class.
*/

#include "AvatarClass.h"

AvatarClass::AvatarClass(const ClassType &t) :
	_classType(t)
{
	switch (_classType) {
		case ClassType::Warrior:
			_rock = new Skill("Shield Bash", Skill::SkillType::Rock);
			_paper = new Skill("Hamstring", Skill::SkillType::Paper);
			_scissors = new Skill("Heroic Strike", Skill::SkillType::Scissors);
			break;
		case ClassType::Rogue:
			_rock = new Skill("Headcrack", Skill::SkillType::Rock);
			_paper = new Skill("Eviscerate", Skill::SkillType::Paper);
			_scissors = new Skill("Backstab", Skill::SkillType::Scissors);
			break;
		case ClassType::Mage:
			_rock = new Skill("Cone of Cold", Skill::SkillType::Rock);
			_paper = new Skill("Mirror Image", Skill::SkillType::Paper);
			_scissors = new Skill("Arcane Missiles", Skill::SkillType::Scissors);
			break;
	}
}

AvatarClass::~AvatarClass()
{
	delete _rock;
	delete _paper;
	delete _scissors;
}

ClassType AvatarClass::GetClassType() const
{
	return _classType;
}

Skill* AvatarClass::GetRockSkill() const 
{ 
	return _rock;
}

Skill* AvatarClass::GetPaperSkill() const 
{
	return _paper;
}

Skill* AvatarClass::GetScissorsSkill() const 
{
	return _scissors;
}