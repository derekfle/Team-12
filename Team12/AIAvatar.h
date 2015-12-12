/**
* Declaration of the AIAvatar class.
* An AIAvatar extends Avatar. It contains AI difficulty.
*/
#pragma once

#include "Avatar.h"

class AIAvatar : public Avatar
{
public: 
	/** Defines how difficult it is to battle an AIAvatar. */
	enum class DifficultyType { Easy, Medium, Hard };
	/* Declared in AIAvatar.cpp */
	static const std::string DifficultyNames[3];
	static const std::map<std::string, DifficultyType> DifficultyMap;

	/**
	* The constructor for the AIAvatar class, which accepts a name, level, ClassType, and DifficultyType.
	* 
	* @param n - a constant reference to the name of the AIAvatar
	* @param l - a constant reference to the level of the AIAvatar
	* @param t - a constant reference to the DifficultyType of the AIAvatar
	*/
	AIAvatar(const std::string &n, const unsigned &l, const ClassType &t, const DifficultyType &d);
	/** 
	* Copy constructor for AIAvatar
	*/
	AIAvatar(const AIAvatar &a);
	/**
	* Constructor that creates a AIAvatar with a random class and the given difficulty and level.
	* @param l the level to give to the AIAvatar
	* @param d the difficulty for the AIAvatar
	*/
	AIAvatar(const unsigned &l, const AIAvatar::DifficultyType &d);
	/** The deconstructor for the AIAvatar class. */
	~AIAvatar();

	/**
	* This method returns the DifficultyType of the AIAvatar.
	*
	* @return the DifficultyType of the AIAvatar
	*/
	DifficultyType GetDifficulty() const;

	/**
	* This method returns the 
	*/
	Skill GetNextMove(Skill* nextPlayerMove);

	/*
	* AVATAR INTERFACE STARTS HERE
	*/

	/**
	* Deals damage to an Avatar after losing a round and updates the internal variables to reflect that.
	*
	* @param damage the amount of damage to deal to the Avatar for losing.
	*/
	void LoseRound(const unsigned& damage);
	/**
	* Updates the internal variables to reflect that this Avatar won the last round.
	*/
	void WinRound();
	/**
	* Updates the internal variables to reflect that this Avatar drew the last round.
	*/
	void DrawRound();
private:
	/** 
	* Gets the losing skill for this AIAvatar if the opponent chose toLoseTo
	* @param toLoseto the skill that should be lost to
	* @return the losing skill
	*/
	Skill GetLosingMove(const Skill* toLoseTo) const;
	/**
	* Gets the winning skill for this AIAvatar if the opponent chose toBeat
	* @param toBeat the skill that should be beaten
	* @return the winning skill
	*/
	Skill GetWinningMove(const Skill* toBeat) const;

	/** The DifficultyType of the AIAvatar which describes its difficulty setting. */
	const DifficultyType _difficulty;
	
	/** Whether or not the AI won the last round. */
	bool _wonLastRound;
	/** The last move that the player made. Only used when on hard difficulty.*/
	Skill* _lastPlayerMove;
};