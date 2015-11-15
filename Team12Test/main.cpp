#include "AvatarSerializer.h"
#include "TestBattleController.h"
#include "GameManager.h"
#include "InputManager.h"
#include "gtest/gtest.h"

// Will write a test for avatar serializer when I am done with it!
// Marin, you will only need to write 3 tests :) - Thanks, man!
TEST(Test, Test)
{
	AvatarSerializer::GetInstance().SaveAvatar(Avatar("Warrior", 1, ClassType::Warrior));
	EXPECT_EQ(1, 1);
}

TEST_F(TestBattleController, TestDetermineWinner)
{
	const Avatar &player = GetPlayer();
	const Avatar &opponent = GetOpponent();
	Skill::SkillType *rock = new Skill::SkillType(Skill::SkillType::Rock);
	int startPHealth = player.GetHealth();
	int startOHealth = opponent.GetHealth();

	SetPlayerMove(rock);
	DetermineWinner(*rock);
	ASSERT_EQ(startPHealth, player.GetHealth());
	ASSERT_EQ(startOHealth, opponent.GetHealth());
	ASSERT_EQ(BattleController::BattleState::TieRound, GetBattleState());

	DetermineWinner(Skill::SkillType::Paper);
	ASSERT_EQ(startPHealth - 1, player.GetHealth());
	ASSERT_EQ(startOHealth, opponent.GetHealth());
	ASSERT_EQ(BattleController::BattleState::LoseRound, GetBattleState());

	DetermineWinner(Skill::SkillType::Scissors);
	ASSERT_EQ(startPHealth - 1, player.GetHealth());
	ASSERT_EQ(startOHealth - 1, opponent.GetHealth());
	ASSERT_EQ(BattleController::BattleState::WinRound, GetBattleState());
}

TEST_F(TestBattleController, TestUserInput)
{
	GameManager::GetInstance().ToggleAudio();
	sf::Event event;
	event.type = sf::Event::KeyReleased;
	event.key.code = sf::Keyboard::Key::Return;
	InputManager::GetInstance().Update(event);
	b.HandleInput();
	ASSERT_EQ(nullptr, GetCurrentMove());
	ASSERT_NE(nullptr, GetSecondaryMenu());
	
	b.HandleInput();
	ASSERT_NE(nullptr, GetCurrentMove());
}

TEST_F(TestBattleController, TestChangeStateToInBetween)
{
	SetBattleState(BattleController::BattleState::WinRound);
	SetPlayerMove(new Skill::SkillType(Skill::SkillType::Paper));
	EndRound();
	EXPECT_EQ(BattleController::BattleState::InBetween, GetBattleState());
	EXPECT_EQ(nullptr, GetCurrentMove());
}

TEST(TestGameManager, TestSetGameState)
{
	GameManager::StateType state = GameManager::StateType::Quitting;
	GameManager::GetInstance().SetGameState(state);
	ASSERT_EQ(GameManager::GetInstance().GetGameState(), state);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("PAUSE"); // Nasty...
}