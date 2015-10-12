/*
* Declaration of the Skill abstract class.
* Class Skill contains the name and type of a particular skill. 
*/

#include <String>

class Skill
{
public: 

	enum class SkillType {Rock, Paper, Scissors};

	Skill(const std::string &n, const SkillType &t);
	~Skill() {}

	const std::string name;
	const SkillType type;
};