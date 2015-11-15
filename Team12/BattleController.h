/*
* BattleController declaration
* Handles all game logic when player is battling
*/
#pragma once

#include "Avatar.h"
#include "GameController.h"

class BattleController : public GameController
{
	friend class TestBattleController;

public:

	/* Determines the state of the battle */
	enum class BattleState 
	{
		InBetween,
		TieRound,
		WinMatch,
		WinRound, 
		LoseMatch,
		LoseRound
	};

	BattleController(const Avatar &p);
	~BattleController();

	/* START GameController interface */
public:
	virtual void Tick(sf::RenderWindow &window) override;
	virtual void HandleInput() override;

private:
	virtual void Draw(sf::RenderWindow &window) override;
	/* END GameController interface */

	void EndRound();
	void PlayRound();
	void DetermineWinner(const Skill::SkillType &opponentMove);

	Avatar _player;
	Avatar _opponent;
	Skill::SkillType* _currentMove;
	BattleState _currentBattleState;
	unsigned _timer;
	Skill _skillsArray[3];
};
