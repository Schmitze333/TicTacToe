// TicTacToe_Test.cpp : Defines the entry point for the console application.
//

#include "gmock/gmock.h"

TEST(it, works) {
	ASSERT_TRUE(true);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

