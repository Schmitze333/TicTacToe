// TicTacToe_Test.cpp : Defines the entry point for the console application.
//

#include "gmock/gmock.h"

class TTTBoard
{
	bool mbEmpty{ true };
public:
	enum Token {
		X,
		O,
	};

	bool IsEmpty() const {
		return mbEmpty;
	}

	void SetToken(enum Token, unsigned int aRow, unsigned int aCol) {
		mbEmpty = false;
	}
};

class ATTTBoard : public ::testing::Test
{
public:
	TTTBoard board;
};

TEST_F(ATTTBoard, IsEmptyOnCreation) {
	ASSERT_TRUE(board.IsEmpty());
}

TEST_F(ATTTBoard, PlaceTokenXOnBoardFillsBoard) {
	board.SetToken(TTTBoard::Token::X, 1, 1);

	ASSERT_FALSE(board.IsEmpty());
}

int main(int argc, char** argv)
{
	::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

