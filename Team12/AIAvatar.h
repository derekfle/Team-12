/**
* Declaration of the AIAvatar class.
* An AIAvatar extends Avatar. It contains AI difficulty.
*/

#include "Avatar.h"

class AIAvatar : public Avatar
{
public: 
	/** Defines how difficult it is to battle an AIAvatar. */
	enum class DifficultyType { Easy, Medium, Hard };

	/**
	* The constructor for the AIAvatar class, which accepts a name, level, ClassType, and DifficultyType.
	* 
	* @param n - a constant reference to the name of the AIAvatar
	* @param l - a constant reference to the level of the AIAvatar
	* @param t - a constant reference to the DifficultyType of the AIAvatar
	*/
	AIAvatar(const std::string &n, const unsigned &l, const ClassType &t, const DifficultyType &d);
	/** The deconstructor for the AIAvatar class. */
	~AIAvatar() {}

	/**
	* This method returns the DifficultyType of the AIAvatar.
	*
	* @return the DifficultyType of the AIAvatar
	*/
	DifficultyType GetDifficulty() const;
	
private:

	/** The DifficultyType of the AIAvatar which describes its difficulty setting. */
	const DifficultyType _difficulty;
};