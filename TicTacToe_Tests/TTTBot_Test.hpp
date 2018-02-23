#include "gmock/gmock.h"

#include "TTTBoard.h"

class TTTBot
{
  TTTBoard& mBoard;

public:
  TTTBot(TTTBoard& aBoard) : mBoard(aBoard) {}

  std::vector<int> RatingMatrix() const {
    return std::vector<int>(10, -1);
  }
};

using ::testing::ElementsAreArray;

class ATTTBot : public ::testing::Test
{
public:
  TTTBoard board;
  TTTBoard::Token X{ TTTBoard::Token::X };
  TTTBoard::Token O{ TTTBoard::Token::O };
};

TEST_F(ATTTBot, RatingMatrixForFullSetBoardIsAllTaken)
{
  board.SetGameState({
      X, O, X,
      O, X, O,
      O, X, O
      });

  TTTBot bot(board);
  ASSERT_THAT(bot.RatingMatrix(), ElementsAreArray({-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}));
}
