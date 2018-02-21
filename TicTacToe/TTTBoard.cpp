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
	//std::stringstream ss("");
	//ss << DrawHeader() << std::endl;

	//for (unsigned int row{ 1 }; row <= BOARDSIZE; ++row) {
	//	ss << DrawRow(row) << std::endl;
	//}

	//return ss.str();
}

std::string TTTBoard::DrawHeader() const
{
	std::stringstream ss("");
	ss << "_|";

	for (unsigned int i{ 1 }; i < BOARDSIZE; ++i) {
		ss << i << "_";
	}
	ss << BOARDSIZE;

	return ss.str();
}

std::string TTTBoard::DrawRow(const unsigned int aRowNumber) const
{
	std::stringstream ss("");
	ss << aRowNumber << "|";

	for (unsigned int col{ 1 }; col < BOARDSIZE; ++col) {
		ss << DrawTokenAt(aRowNumber, col) << " ";
	}

	ss << DrawTokenAt(aRowNumber, BOARDSIZE);

	return ss.str();
}

std::string TTTBoard::DrawTokenAt(const unsigned int aRowNumber, const unsigned int aColNumber) const
{
	auto token = TokenAt(aRowNumber, aColNumber);
	auto it = TOKEN_SYMBOLS.find(token);

	if (it != TOKEN_SYMBOLS.end())
		return it->second;

	return " ";
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

