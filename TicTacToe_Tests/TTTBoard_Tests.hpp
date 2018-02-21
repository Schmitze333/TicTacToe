#include "gmock/gmock.h"

#include "TTTBoard.h"
#include "TTTChecker.h"
#include "TTTDrawer.h"

using ::testing::Eq;

class ATTTBoard : public ::testing::Test
{
public:
	TTTBoard board;
	TTTBoard::Token X{ TTTBoard::Token::X };
	TTTBoard::Token O{ TTTBoard::Token::O };
	TTTBoard::Token E{ TTTBoard::Token::empty };

	void SetUp() {
		board.SetWinChecker(std::make_unique<TTTChecker>(&board));
		board.SetDrawStrategy(std::make_unique<TTTDrawer>(&board));
	}
};

TEST_F(ATTTBoard, IsEmptyOnCreation) {
	ASSERT_TRUE(board.IsEmpty(1, 1));
}

TEST_F(ATTTBoard, IsEmptyForAFieldWithTokenReturnsFalse) {
	board.SetToken(X, 1, 1);

	ASSERT_FALSE(board.IsEmpty(1, 1));
}

TEST_F(ATTTBoard, IsEmptyForAFieldWithoutTokenReturnsTrue) {
	board.SetToken(X, 1, 1);

	ASSERT_TRUE(board.IsEmpty(1, 2));
}

TEST_F(ATTTBoard, PlacingATokenOnANonEmptyFieldReturnsFalse) {
	board.SetToken(X, 1, 1);

	ASSERT_FALSE(board.SetToken(O, 1, 1));
}

TEST_F(ATTTBoard, IsXForAFieldWithAnXReturnsTrue)
{
	board.SetToken(X, 1, 1);

	ASSERT_TRUE(board.IsX(1, 1));
}

TEST_F(ATTTBoard, IsOForAFieldWithAnOReturnsTrue)
{
	board.SetToken(O, 1, 1);

	ASSERT_TRUE(board.IsO(1, 1));
}

TEST_F(ATTTBoard, SettingAWholeBoardConfiguration)
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

TEST_F(ATTTBoard, SetGameStateReturnsFalseForVectorsWithInappropiateSize)
{
	ASSERT_FALSE(board.SetGameState({ X, O }));
}

TEST_F(ATTTBoard, DeterminsANonWinSituation)
{
	board.SetGameState( {
		X, O, X,
		O, X, O,
		O, X, O
	} );

	ASSERT_FALSE(board.CheckWinForToken(X));
}

TEST_F(ATTTBoard, DeterminsWinForXWith1stRow)
{
	board.SetGameState({
		X, X, X,
		X, O, O,
		O, X, O
	});

	ASSERT_TRUE(board.CheckWinForToken(X));
}

TEST_F(ATTTBoard, DeterminsWinForXWith2ndRow)
{
	board.SetGameState({
		X, O, O,
		X, X, X,
		O, X, O
	});

	ASSERT_TRUE(board.CheckWinForToken(X));
}

TEST_F(ATTTBoard, DeterminsWinForOWith1stRow)
{
	board.SetGameState({
		O, O, O,
		X, O, X,
		O, X, X
	});

	ASSERT_TRUE(board.CheckWinForToken(O));
}

TEST_F(ATTTBoard, DeterminsWinForOWith3rdRow)
{
	board.SetGameState({
		X, O, X,
		O, X, X,
		O, O, O,
	});

	ASSERT_TRUE(board.CheckWinForToken(O));
}

TEST_F(ATTTBoard, DeterminsWinForXWith1stCol)
{
	board.SetGameState({
		X, O, X,
		X, O, X,
		X, X, O,
	});

	ASSERT_TRUE(board.CheckWinForToken(X));
}

TEST_F(ATTTBoard, DeterminsWinForOWith2ndCol)
{
	board.SetGameState({
		X, O, X,
		X, O, O,
		O, O, X,
	});

	ASSERT_TRUE(board.CheckWinForToken(O));
}

TEST_F(ATTTBoard, DeterminsWinForXWith3rdCol)
{
	board.SetGameState({
		X, O, X,
		O, O, X,
		O, X, X,
	});

	ASSERT_TRUE(board.CheckWinForToken(X));
}

TEST_F(ATTTBoard, DeterminsWinForXWithUpperDiagonal)
{
	board.SetGameState({
		X, O, X,
		O, X, O,
		O, X, X,
	});

	ASSERT_TRUE(board.CheckWinForToken(X));
}

TEST_F(ATTTBoard, DeterminsWinForXWithLowerDiagonal)
{
	board.SetGameState({
		X, O, X,
		O, X, O,
		X, O, O,
	});

	ASSERT_TRUE(board.CheckWinForToken(X));
}

TEST_F(ATTTBoard, DrawingAnEmptyBoard)
{
	std::string expected{
		"_|1_2_3\n"
		"1|- - -\n"
		"2|- - -\n"
		"3|- - -\n"
	};

	ASSERT_THAT(board.Draw(), Eq(expected));
}

TEST_F(ATTTBoard, DrawingABoardWithAToken)
{
	board.SetToken(X, 1, 1);
	std::string expected{
		"_|1_2_3\n"
		"1|X - -\n"
		"2|- - -\n"
		"3|- - -\n"
	};

	ASSERT_THAT(board.Draw(), Eq(expected));
}

TEST_F(ATTTBoard, IsFullReturnsTrueForACompletelyFullBoard)
{
	board.SetGameState({
		X, O, X,
		O, X, X,
		O, X, O
	});

	ASSERT_TRUE(board.IsFull());
}

TEST_F(ATTTBoard, IsFullReturnsFalseForANonFullBoard)
{
	board.SetGameState({
		X, E, X,
		O, E, E,
		E, X, E
	});

	ASSERT_FALSE(board.IsFull());
}
