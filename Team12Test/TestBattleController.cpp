#include "TestBattleController.h"


TestBattleController::TestBattleController() : b(Avatar("Warrior", 1, ClassType::Warrior)) {}

void TestBattleController::DetermineWinner(const Skill::SkillType &opponentMove)
{
	b.DetermineWinner(opponentMove);
}

void TestBattleController::EndRound()
{
	b.EndRound();
}

void TestBattleController::SetPlayerMove(Skill::SkillType *playerMove)
{
	b._currentMove = playerMove;
}

void TestBattleController::SetBattleState(BattleController::BattleState state)
{
	b._currentBattleState = state;
}

const Avatar& TestBattleController::GetPlayer()
{
	return b._player;
}

const Avatar& TestBattleController::GetOpponent()
{
	return b._opponent;
}

const Skill::SkillType* TestBattleController::GetCurrentMove()
{
	return b._currentMove;
}

const BattleController::BattleState& TestBattleController::GetBattleState()
{
	return b._currentBattleState;
}

const Menu* TestBattleController::GetSecondaryMenu()
{
	return b._secondaryMenu;
}