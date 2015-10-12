/*
* Declaration of the AvatarClass abstract class.
* AvatarClass defines class name and class type for an Avatar.
*/

#include <String>
#include "Skill.h"

class AvatarClass 
{
public: 

	enum class ClassType {Warrior, Rogue, Mage};

	AvatarClass(const std::string &n, const ClassType &t);
	~AvatarClass() {}

	std::string GetClassName() const { return _className; }

	ClassType GetClassType() const { return _classType; }

	Skill* GetRockSkill() const { return _rock; }

	Skill* GetPaperSkill() const { return _paper;  }
	
	Skill* GetScissorsSkill() const { return _scissors; }

private: 

	const std::string _className;
	const ClassType _classType;
	Skill *_rock;
	Skill *_paper;
	Skill *_scissors;
};