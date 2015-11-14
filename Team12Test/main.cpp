#include "AvatarSerializer.h"
#include "gtest/gtest.h"

// Will write a test for avatar serializer when I am done with it!
// Marin, you will only need to write 3 tests :)
TEST(Test, Test)
{
	AvatarSerializer::GetInstance().SaveAvatar(Avatar("Warrior", 1, ClassType::Warrior));
	EXPECT_EQ(1, 1);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("PAUSE"); // Nasty...
}