/** @file Team12Test\main.cpp This file runs the tests for the game. */

#include "AvatarSerializer.h"
#include "TestBattleController.h"
#include "GameManager.h"
#include "InputManager.h"
#include "gtest/gtest.h"

/**
* Saves and then loads an Avatar, then ensures that the loaded Avatar matched the original.
*/
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

/**
* Simulates battles between a player and their opponent; this test ensures that the damage 
* that a player takes during a battle is correct according to whether they tie, lose, or win
* the round. 
*/
TEST_F(TestBattleController, TestDetermineWinner)
{
	// Create the player and their opponent
	const Avatar &player = GetPlayer();
	const Avatar &opponent = GetOpponent();
	Skill::SkillType *rock = new Skill::SkillType(Skill::SkillType::Rock);
	int startPHealth = player.GetHealth();
	int startOHealth = opponent.GetHealth();

	// Set the player's move and run the round so that the Avatars tie
	SetPlayerMove(rock);
	DetermineWinner(*rock);
	ASSERT_EQ(startPHealth, player.GetHealth());
	ASSERT_EQ(startOHealth, opponent.GetHealth());
	ASSERT_EQ(BattleController::BattleState::TieRound, GetBattleState());

	// Run the round so that the player loses
	DetermineWinner(Skill::SkillType::Paper);
	ASSERT_EQ(startPHealth - 1, player.GetHealth());
	ASSERT_EQ(startOHealth, opponent.GetHealth());
	ASSERT_EQ(BattleController::BattleState::LoseRound, GetBattleState());

	// Run the round so that the player wins
	DetermineWinner(Skill::SkillType::Scissors);
	ASSERT_EQ(startPHealth - 1, player.GetHealth());
	ASSERT_EQ(startOHealth - 1, opponent.GetHealth());
	ASSERT_EQ(BattleController::BattleState::WinRound, GetBattleState());
}

/**
* The following test simulates user input in the BattleController, validating menu
* choices made by the user.
*/
TEST_F(TestBattleController, TestUserInput)
{
	// Create an event to simulate a key being pressed
	GameManager::GetInstance().ToggleAudio();
	sf::Event event;
	event.type = sf::Event::KeyReleased;
	event.key.code = sf::Keyboard::Key::Return;
	InputManager::GetInstance().Update(event);

	// Ensure the secondary menu opens
	b.HandleInput();
	ASSERT_EQ(nullptr, GetCurrentMove());
	ASSERT_NE(nullptr, GetSecondaryMenu());
	
	// Ensure the current move gets set
	b.HandleInput();
	ASSERT_NE(nullptr, GetCurrentMove());
}

/**
* Tests that the state of the battle is set back to InBetween at the end of the round,
* if it is not the end of a match. 
*/
TEST_F(TestBattleController, TestChangeStateToInBetween)
{
	// Set the battle state
	SetBattleState(BattleController::BattleState::WinRound);
	SetPlayerMove(new Skill::SkillType(Skill::SkillType::Paper));
	// End the round and check that the battle state is set to InBetween
	EndRound();
	EXPECT_EQ(BattleController::BattleState::InBetween, GetBattleState());
	EXPECT_EQ(nullptr, GetCurrentMove());
}

/**
* This test validates that the game state is set properly.
*/
TEST(TestGameManager, TestSetGameState)
{
	// Ensure that the game state is set properly
	GameManager::StateType state = GameManager::StateType::Quitting;
	GameManager::GetInstance().SetGameState(state);
	ASSERT_EQ(GameManager::GetInstance().GetGameState(), state);
}

/**
* Entry point for the tests.
*/
int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("PAUSE"); 
}