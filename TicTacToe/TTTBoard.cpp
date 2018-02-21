#include "TTTBoard.h"

#include <sstream>

TTTBoard::Token TTTBoard::TokenAt(const unsigned int aRow, const unsigned int aCol) const
{
	auto index = To1dCoordinate(aRow, aCol);
	return board[index];
}

std::string TTTBoard::TokenSymbolAt(const unsigned int aRow, const unsigned int aCol) const
{
	auto token = TokenAt(aRow, aCol);
	auto it = TOKEN_SYMBOLS.find(token);
	if (it != TOKEN_SYMBOLS.end())
		return it->second;

	return " ";
}

bool TTTBoard::IsEmpty(const unsigned int aRow, const unsigned int aCol) const
{
	auto index = To1dCoordinate(aRow, aCol);
	return board[index] == Token::empty;
}

bool TTTBoard::IsFull() const
{
	for (unsigned int i{ 0 }; i < FIELDS; ++i) {
		if (board[i] == Token::empty)
			return false;
	}

	return true;
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
	if (avTokens.size() != FIELDS)
		return false;

	for (int i{ 0 }; i < FIELDS; ++i) {
		board[i] = avTokens.at(i);
	}

	return true;
}

bool TTTBoard::CheckWinForToken(const Token aToken) const
{
	if (!checker) return false;

	return checker->CheckWinForToken(aToken);
}

std::string TTTBoard::Draw() const
{
	if (!drawer)
		return std::string();

	return drawer->Draw();
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

