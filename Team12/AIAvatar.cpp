/*
* Implementation of the AIAvatar class.
*/

#include "AIAvatar.h"

/** Declare the names of the difficulties for an AIAvatar. */
const std::string AIAvatar::DifficultyNames[3] = { "Easy", "Medium", "Hard" };
const std::map<std::string, AIAvatar::DifficultyType> AIAvatar::DifficultyMap = { 
	{ "Easy", AIAvatar::DifficultyType::Easy }, 
	{ "Medium", AIAvatar::DifficultyType::Medium },
	{ "Hard", AIAvatar::DifficultyType::Hard }
};

AIAvatar::AIAvatar(const std::string &n, const unsigned &l, const ClassType &t, const DifficultyType &d) : 
	Avatar(n, l, t),
	_difficulty(d)
{}

AIAvatar::AIAvatar(const AIAvatar &a) :
	Avatar(a),
	_difficulty(a._difficulty)
{}

AIAvatar::AIAvatar(const unsigned &l, const AIAvatar::DifficultyType &d) :
	Avatar("AI Avatar", l, ClassType(rand() % 3)),
	_difficulty(d)
{}

/** 
* Do not delete _lastPlayerMove because it will be cleaned up elsewhere.
*/
AIAvatar::~AIAvatar()
{}

AIAvatar::DifficultyType AIAvatar::GetDifficulty() const
{
	return _difficulty;
}

Skill AIAvatar::GetWinningMove(const Skill* toBeat) const {
	switch ((*toBeat).type) {
		case Skill::SkillType::Paper:
			return _class.GetScissorsSkill();
		case Skill::SkillType::Rock:
			return _class.GetPaperSkill();
		case Skill::SkillType::Scissors:
		default:
			return _class.GetRockSkill();
	}
}

Skill AIAvatar::GetLosingMove(const Skill* toBeat) const {
	switch ((*toBeat).type) {
	case Skill::SkillType::Paper:
		return _class.GetRockSkill();
	case Skill::SkillType::Rock:
		return _class.GetScissorsSkill();
	case Skill::SkillType::Scissors:
	default:
		return _class.GetPaperSkill();
	}
}

Skill AIAvatar::GetNextMove(Skill* nextPlayerMove)
{
	Skill toReturnOnHard;
	int randNum = rand() % 4;
	switch (_difficulty)
	{
		case DifficultyType::Easy:
			// Lower chance to choose winning move
			// 25% chance to win. 25% chance to draw. 50% chance to lose.
			if (randNum == 0) {
				// Win
				return GetWinningMove(nextPlayerMove);
			}
			else if (randNum == 1) {
				// Draw
				return _class.GetSkillFromType(nextPlayerMove->type);
			}
			else {
				// Lose
				return GetLosingMove(nextPlayerMove); 
			}
			break;
		case DifficultyType::Hard:
			// If we do not know the players last move, then choose randomly.
			// Otherwise, apply a "winning" strategy for rock paper scissors.
			// Strategy: If won last round, then next move should be the players last move.
			//			 If lost last round, then the next move should be what beats the players last move.
			if (_lastPlayerMove == nullptr) {
				// 100% random
				toReturnOnHard = _class.GetSkillFromType(Skill::SkillType(rand() % 3));
			}
			else if (_wonLastRound) {
				// Choose the same move as the players last move.
				toReturnOnHard = _class.GetSkillFromType(_lastPlayerMove->type);
			}
			else {
				// Choose the move that beats the players last move
				toReturnOnHard = GetWinningMove(_lastPlayerMove);
			}

			// Update the last player move
			_lastPlayerMove = nextPlayerMove;
			return toReturnOnHard;
		case DifficultyType::Medium:
		default:
			// 100% random choice of move.
			// 33% chance to win. 33% chance to draw. 33% chance to lose.
			return _class.GetSkillFromType(Skill::SkillType(rand() % 3));
	}	
}

void AIAvatar::DrawRound()
{
	_wonLastRound = false;
}

void AIAvatar::LoseRound(const unsigned& damage)
{
	Avatar::LoseRound(damage);
	_wonLastRound = false;
}

void AIAvatar::WinRound()
{
	Avatar::WinRound();
	_wonLastRound = true;
}