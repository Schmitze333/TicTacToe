#include "gmock/gmock.h"

#include "TTTBoard.h"
#include "TTTBot.h"

using ::testing::Eq;

class ATTTBot : public ::testing::Test
{
public:
  TTTBoard board;
  TTTBoard::Token X{ TTTBoard::Token::X };
  TTTBoard::Token O{ TTTBoard::Token::O };
  TTTBoard::Token E{ TTTBoard::Token::empty };
};

TEST_F(ATTTBot, RatingMatrixForFullSetBoardIsAllTaken)
{
  board.SetGameState({
      X, O, X,
      O, X, O,
      O, X, O
      });

  std::vector<int> expected({
      -1, -1, -1,
      -1, -1, -1,
      -1, -1, -1
  });

  TTTBot bot(board);
  ASSERT_THAT(bot.RatingMatrix(), Eq(expected));
}

TEST_F(ATTTBot, RatinMatrixSetsNonEmptyFieldToMinusOne)
{
  board.SetGameState({
      X, E, E,
      E, E, E,
      E, E, E
      });

  TTTBot bot(board);
  ASSERT_THAT(bot.RatingMatrix().at(0), Eq(-1));
  ASSERT_THAT(bot.RatingMatrix().at(1), ::testing::Ne(-1));
}
