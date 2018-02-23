#include "TTTBoard.h"

class TTTBot
{
  TTTBoard& mBoard;

public:
  TTTBot(TTTBoard& aBoard) : mBoard(aBoard) {}
  std::vector<int> RatingMatrix() const;
};


