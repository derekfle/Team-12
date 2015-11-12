/*
* Declaration of the AvatarClass class.
* AvatarClass defines class name and class type for an Avatar.
*/
#pragma once

#include <string>

enum ClassType { Warrior, Rogue, Mage };

struct Skill {
	enum SkillType {Rock, Paper, Scissors};
	std::string name;
	SkillType type;

	Skill() {}
	Skill(std::string n, SkillType t) : name(n), type(t) {}
};

class AvatarClass 
{
public: 

	AvatarClass(const ClassType &t);
	~AvatarClass();

	static std::string GetClassName(const ClassType &type);

	static ClassType GetClassType(const std::string &className);

	std::string GetClassName() const;

	ClassType GetClassType() const;

	Skill GetRockSkill() const;

	Skill GetPaperSkill() const;
	
	Skill GetScissorsSkill() const;

private: 

	const ClassType _classType;
	Skill _rock;
	Skill _paper;
	Skill _scissors;
};