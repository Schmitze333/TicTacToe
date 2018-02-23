#include "TTTBot.h"

#include <algorithm>

std::vector<int> TTTBot::RatingMatrix() const {
  std::vector<TTTBoard::Token> gameState = mBoard.GetGameState();
  std::vector<int> out;
  out.resize(gameState.size());

  std::transform(gameState.begin(), gameState.end(), out.begin(),
      [](TTTBoard::Token t) { return t != TTTBoard::Token::empty ? -1 : 0; }
      );

  return out;
}
