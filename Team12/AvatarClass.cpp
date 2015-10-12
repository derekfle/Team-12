/*
* Implementation of the AvatarClass class.
*/

#include "AvatarClass.h"

AvatarClass::AvatarClass(const std::string &n, const ClassType &t) :
	_className(n),
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
			_rock = new Skill("Slash", Skill::SkillType::Rock);
			_paper = new Skill("Slash", Skill::SkillType::Paper);
			_scissors = new Skill("Slash", Skill::SkillType::Scissors);
			break;
	}
}