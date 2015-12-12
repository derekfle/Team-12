/*
* Implementation of the AvatarClass class.
*/

#include "AvatarClass.h"

/**
* The constructor initializes rock, paper, and scissors Skills for each ClassType.
*/
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

AvatarClass::~AvatarClass() {}

ClassType AvatarClass::GetClassType() const
{
	return _classType;
}

ClassType AvatarClass::GetClassType(const std::string &className)
{
	if (className == "Rogue") return ClassType::Rogue;
	else if (className == "Mage") return ClassType::Mage;

	return ClassType::Warrior;
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

Skill AvatarClass::GetSkillFromType(const Skill::SkillType& t) const {
	switch (t) {
		case Skill::SkillType::Rock:
			return _rock;
		case Skill::SkillType::Paper:
			return _paper;
		case Skill::SkillType::Scissors:
		default:
			return _scissors;
	}
}

std::string AvatarClass::GetClassName(const ClassType &type)
{
	if (type == ClassType::Rogue) return "Rogue";
	else if (type == ClassType::Mage) return "Mage";

	return "Warrior";
}

std::string AvatarClass::GetClassName() const
{
	return AvatarClass::GetClassName(_classType);
}