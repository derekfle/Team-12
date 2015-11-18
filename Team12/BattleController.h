/**
* BattleController declaration.
* Handles all game logic when player is battling.
*/
#pragma once

#include "Avatar.h"
#include "GameController.h"

class BattleController : public GameController
{
	friend class TestBattleController;

public:

	/** Determines the state of the battle. */
	enum class BattleState 
	{
		InBetween,
		TieRound,
		WinMatch,
		WinRound, 
		LoseMatch,
		LoseRound
	};

	/**
	* Constructor for the BattleController class.
	* @param p a constant reference
	*/
	BattleController(const Avatar &p);
	/**
	* Deconstructor for the BattleController class.
	*/
	~BattleController();

public:
	/**
	* Avatar Interace: calls functions to be run every frame.
	* @param a reference to a window
	*/
	virtual void Tick(sf::RenderWindow &window) override;
	/**
	* Avatar Interace: manages input.
	*/
	virtual void HandleInput() override;

private:
	/**
	* Avatar Interace: draws the battle menu. 
	* @param a reference to a window
	*/
	virtual void Draw(sf::RenderWindow &window) override;

	/** Implements the functionality that occurs at the end of a round. */
	void EndRound();
	/** This method includes the logic that occurs during a round. */
	void PlayRound();
	/**
	* This method determines the winner of the round.
	* @param opponentMove - the SkillType that is the opponents move 
	*/
	void DetermineWinner(const Skill::SkillType &opponentMove);

	/** The player Avater. */
	Avatar _player;
	/** The player's opponent. */
	Avatar _opponent;
	/** The player's current move. */
	Skill::SkillType* _currentMove;
	/** The current state of the battle. */
	BattleState _currentBattleState;
	/** Timer that determines how long text appears on the screen. */
	unsigned _timer;
	/** An array of the player's skills. */
	Skill _skillsArray[3];
};
