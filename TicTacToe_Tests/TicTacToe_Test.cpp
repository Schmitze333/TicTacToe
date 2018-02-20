// TicTacToe_Test.cpp : Defines the entry point for the console application.
//

#include "gmock/gmock.h"
#include "TTTBoard.h"

class ATTTBoard : public ::testing::Test
{
public:
	TTTBoard board;
	TTTBoard::Token X{ TTTBoard::Token::X };
	TTTBoard::Token O{ TTTBoard::Token::O };
};

TEST_F(ATTTBoard, IsEmptyOnCreation) {
	ASSERT_TRUE(board.IsEmpty(1, 1));
}

TEST_F(ATTTBoard, IsEmptyForAFieldWithTokenReturnsFalse) {
	board.SetToken(TTTBoard::Token::X, 1, 1);

	ASSERT_FALSE(board.IsEmpty(1, 1));
}

TEST_F(ATTTBoard, IsEmptyForAFieldWithoutTokenReturnsTrue) {
	board.SetToken(TTTBoard::Token::X, 1, 1);

	ASSERT_TRUE(board.IsEmpty(1, 2));
}

TEST_F(ATTTBoard, PlacingATokenOnANonEmptyFieldReturnsFalse) {
	board.SetToken(TTTBoard::Token::X, 1, 1);

	ASSERT_FALSE(board.SetToken(TTTBoard::Token::O, 1, 1));
}

TEST_F(ATTTBoard, IsXForAFieldWithAnXReturnsTrue)
{
	board.SetToken(TTTBoard::Token::X, 1, 1);

	ASSERT_TRUE(board.IsX(1, 1));
}

TEST_F(ATTTBoard, IsOForAFieldWithAnOReturnsTrue)
{
	board.SetToken(TTTBoard::Token::O, 1, 1);

	ASSERT_TRUE(board.IsO(1, 1));
}

TEST_F(ATTTBoard, DISABLED_SettingAWholeBoardConfiguration)
{
	board.SetGameState({ X, X, X, O, O, O, O, O, O });
	EXPECT_TRUE(board.IsX(1, 1));
	EXPECT_TRUE(board.IsX(1, 2));
	EXPECT_TRUE(board.IsX(1, 3));
	EXPECT_TRUE(board.IsO(2, 1));
	EXPECT_TRUE(board.IsO(2, 2));
	EXPECT_TRUE(board.IsO(2, 3));
	EXPECT_TRUE(board.IsO(3, 1));
	EXPECT_TRUE(board.IsO(3, 2));
	EXPECT_TRUE(board.IsO(3, 3));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

