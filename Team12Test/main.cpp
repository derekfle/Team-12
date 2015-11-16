#include "AvatarSerializer.h"
#include "TestBattleController.h"
#include "GameManager.h"
#include "InputManager.h"
#include "gtest/gtest.h"

TEST(TestAvatarSerializer, TestSaveAndLoad)
{
	// Create the new avatar
	Avatar avatar("SomeCreativeNameHere", 23, ClassType::Mage);

	// Save the avatar to disk
	AvatarSerializer::GetInstance().SaveAvatar(avatar);

	// Load the avatar
	ASSERT_TRUE(AvatarSerializer::GetInstance().LoadAvatar("SomeCreativeNameHere"));

	// Make sure the loaded avatar matches our original
	Avatar *loadedAvatar = AvatarSerializer::GetInstance().GetPlayer();
	EXPECT_EQ(avatar.GetName(), loadedAvatar->GetName());
	EXPECT_EQ(avatar.GetLevel(), loadedAvatar->GetLevel());
	EXPECT_EQ(avatar.GetClass().GetClassType(), loadedAvatar->GetClass().GetClassType());

	std::remove("SomeCreativeNameHere.dat"); // Remove the saved avatar
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