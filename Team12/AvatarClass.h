#pragma once

#include <string>

/** Defines allowed class types for Avatars. */
enum ClassType { Warrior, Rogue, Mage };

/**
* Defines the Skill and SkillType used in battle. 
*/
struct Skill {
	/** Defines types of skills. */
	enum SkillType {Rock, Paper, Scissors};
	/** Name of the Skill. */
	std::string name;
	/** The Skill's type. */
	SkillType type;

	/**
	* Base constructor for the Skill struct.
	*/
	Skill() {}
	/**
	* Constructor for the Skill struct that accepts a name and type.
	* 
	* @param n - the name of the skill
	* @param t - the type of the skill
	*/
	Skill(std::string n, SkillType t) : name(n), type(t) {}
};

/**
* Declaration of the AvatarClass class.
* AvatarClass defines class name and class type for an Avatar.
*/
class AvatarClass 
{
public:
	/**
	* The AvatarClass constructor which accepts a ClassType.
	* @param t - the ClassType of the Avatar.
	*/
	AvatarClass(const ClassType &t);
	/** Deconstructor for the AvatarClass. */
	~AvatarClass();

	/**
	* Static method that returns the name of the given ClassType.
	*
	* @param type - a constant reference to a ClassType
	* @return a string representation of the name
	*/
	static std::string GetClassName(const ClassType &type);

	/**
	* Static method that obtains the ClassType given the class name.
	*
	* @param className - a constant reference to the name of the class
	* @return the ClassType corresponding to the name
	*/
	static ClassType GetClassType(const std::string &className);

	/**
	* Returns the class name of the AvatarClass.
	*
	* @return the class name
	*/
	std::string GetClassName() const;

	/**
	* Returns the ClassType of the AvatarClass.
	*
	* @return the ClassType
	*/
	ClassType GetClassType() const;

	/**
	* Returns the rock Skill for the AvatarClass
	*
	* @return the rock Skill
	*/
	Skill GetRockSkill() const;

	/**
	* Returns the paper Skill for the AvatarClass
	*
	* @return the paper Skill
	*/
	Skill GetPaperSkill() const;
	
	/**
	* Returns the scissors Skill for the AvatarClass
	*
	* @return the scissors Skill
	*/
	Skill GetScissorsSkill() const;

	/**
	* Returns the skill for this class that has the given skill type
	*
	* @param t the type of the skill to get
	*
	* @return the skill of the given type for this class
	*/
	Skill GetSkillFromType(const Skill::SkillType& t) const;

private: 

	/** The constant ClassType of the AvatarClass. */
	const ClassType _classType;
	/** The rock Skill of the AvatarClass. */
	Skill _rock;
	/** The paper Skill of the AvatarClass. */
	Skill _paper;
	/** The scissors Skill of the AvatarClass. */
	Skill _scissors;
};