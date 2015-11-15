#pragma once
#include "gtest\gtest.h"
#include "BattleController.h"

class TestBattleController : public ::testing::Test
{
public:
	TestBattleController();
	~TestBattleController() {}

	void DetermineWinner(const Skill::SkillType &opponentMove);
	void EndRound();
	void SetPlayerMove(Skill::SkillType *playerMove);
	void SetBattleState(BattleController::BattleState state);
	const Avatar& GetPlayer();
	const Avatar& GetOpponent();
	const Skill::SkillType* GetCurrentMove();
	const BattleController::BattleState& GetBattleState();
	const Menu* GetSecondaryMenu();

	BattleController b;
};

