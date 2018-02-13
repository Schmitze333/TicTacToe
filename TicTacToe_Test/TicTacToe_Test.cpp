// TicTacToe_Test.cpp : Defines the entry point for the console application.
//

#include "gmock/gmock.h"

class TTTBoard
{
	bool mbEmpty{ true };
public:
	enum Token {
		empty,
		X,
		O,
	};

	TTTBoard() {
		EmptyBoard();
	}

	bool IsEmpty(const unsigned int aRow, const unsigned int aCol) const {
		auto index = To1dCoordinate(aRow, aCol);
		return board[index] == Token::empty;
	}

	void SetToken(enum Token aToken, const unsigned int aRow, const unsigned int aCol) {
		auto index = To1dCoordinate(aRow, aCol);
		board[index] = aToken;
	}
private:
	const unsigned int BOARD_SIZE{ 3 };
	Token board[9];

	unsigned int To1dCoordinate(const unsigned int aRow, const unsigned int aCol) const {
		return (aRow - 1) * BOARD_SIZE + (aCol - 1);
	}

	void EmptyBoard() {
		for (int i{ 0 }; i < 9; ++i) {
			board[i] = Token::empty;
		}
	}
};

/*
  1 2 3
1 0 1 2 || (row - 1) * Boardsize + (col - 1)
2 3 4 5
3 6 7 8
*/

class ATTTBoard : public ::testing::Test
{
public:
	TTTBoard board;
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

int main(int argc, char** argv)
{
	::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

