/**
* TestBattleController test fixture declaration. 
* This class is a test fixture used by the tests to access the BattleController class.
*/

#pragma once
#include "gtest\gtest.h"
#include "BattleController.h"

class TestBattleController : public ::testing::Test
{
public:
	/** The constructor for the TestBattleController class. */
	TestBattleController();
	/** The deconstructor for the TestBattleController class. */
	~TestBattleController() {}

	/**
	* This method wraps the private DetermineWinner method in the BattleController class.
	* @param opponentMove - the opponent's move
	*/
	void DetermineWinner(const Skill::SkillType &opponentMove);
	/**
	* This method wraps the private EndRound method in the BattleController class.
	*/
	void EndRound();
	/**
	* The following method sets the private _currentMove variable in the BattleController class.
	* @param playerMove - the skill that is the player's move
	*/
	void SetPlayerMove(Skill *playerMove);
	/**
	* The following method sets the private _currentBattleState variable in the BattleController class.
	* @param state - the current state of the battle
	*/
	void SetBattleState(BattleController::BattleState state);
	/**
	* Obtains the player's Avatar from the BattleController class.
	* @return a reference to the player's Avatar
	*/
	const Avatar& GetPlayer();
	/**
	* Obtains the opponent's Avatar from the BattleController class.
	* @return a constant reference to the opponent's Avatar
	*/
	const Avatar& GetOpponent();
	/**
	* Returns the player's current move from the BattleController class.
	* @return a constant pointer to player's current move
	*/
	const Skill* GetCurrentMove();
	/**
	* Returns the current state of the battle from the BattleController class.
	* @return a constant reference to the current BattleState of the battle
	*/
	const BattleController::BattleState& GetBattleState();
	/**
	* Returns a boolean value indicating whether the second menu is displayed.
	* @return a constant pointer to whether there is a secondary menu
	*/
	const Menu* GetSecondaryMenu();

	/** The instance of the BattleController. */
	BattleController b;
};

