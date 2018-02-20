#include "TTTBoard.h"

bool TTTBoard::IsEmpty(const unsigned int aRow, const unsigned int aCol) const
{
	auto index = To1dCoordinate(aRow, aCol);
	return board[index] == Token::empty;
}

bool TTTBoard::IsX(const unsigned int aRow, const unsigned int aCol) const
{
	return IsToken(aRow, aCol, Token::X);
}

bool TTTBoard::IsO(const unsigned int aRow, const unsigned int aCol) const
{
	return IsToken(aRow, aCol, Token::O);
}

bool TTTBoard::IsToken(const unsigned int aRow, const unsigned int aCol, Token aToken) const
{
	auto index = To1dCoordinate(aRow, aCol);
	return board[index] == aToken;
}

bool TTTBoard::SetToken(TTTBoard::Token aToken, const unsigned int aRow, const unsigned int aCol)
{
	if (!IsEmpty(aRow, aCol))
		return false;

	auto index = To1dCoordinate(aRow, aCol);
	board[index] = aToken;
	return true;
}

bool TTTBoard::SetGameState(std::vector<Token> avTokens)
{
	board[0] = Token::X;

	return true;
}

unsigned int TTTBoard::To1dCoordinate(const unsigned int aRow, const unsigned int aCol) const
{
	/*
	  1 2 3
	1 0 1 2 || (row - 1) * Boardsize + (col - 1)
	2 3 4 5
	3 6 7 8
	*/
	return (aRow - 1) * BOARDSIZE + (aCol - 1);
}

void TTTBoard::EmptyBoard()
{
	for (int i{ 0 }; i < FIELDS; ++i) {
		board[i] = Token::empty;
	}
}
