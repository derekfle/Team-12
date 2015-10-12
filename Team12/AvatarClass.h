/*
* Declaration of the AvatarClass class.
* AvatarClass defines class name and class type for an Avatar.
*/

#include <String>

enum ClassType { Warrior, Rogue, Mage };

struct Skill {
	enum SkillType {Rock, Paper, Scissors};
	std::string name;
	SkillType type;

	Skill(std::string n, SkillType t) : name(n), type(t) {}
};

class AvatarClass 
{
public: 

	AvatarClass(const ClassType &t);
	~AvatarClass();

	std::string GetClassName() const;

	ClassType GetClassType() const;

	Skill* GetRockSkill() const;

	Skill* GetPaperSkill() const;
	
	Skill* GetScissorsSkill() const;

private: 

	const ClassType _classType;
	Skill* _rock;
	Skill* _paper;
	Skill* _scissors;
};