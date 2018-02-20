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
	if (avTokens.size() != FIELDS)
		return false;

	for (int i{ 0 }; i < FIELDS; ++i) {
		board[i] = avTokens.at(i);
	}

	return true;
}

bool TTTBoard::CheckWinForToken(const Token aToken) const
{
	return CheckRowWinForToken(aToken) || CheckColWinForToken(aToken) || CheckDiagonalWinForToken(aToken);
}

bool TTTBoard::CheckRowWinForToken(const Token aToken) const
{
	bool is_win{ false };

	for (unsigned int row{ 1 }; row <= BOARDSIZE; ++row) {
		is_win = is_win || CheckRowNumber(row, aToken);
	}

	return is_win;
}

bool TTTBoard::CheckRowNumber(const unsigned int aRow, const Token aToken) const
{
	bool has_row{ true };
	for (unsigned int col{ 1 }; col <= BOARDSIZE; ++col) {
		has_row = has_row && IsToken(aRow, col, aToken);
	}
	return has_row;
}

bool TTTBoard::CheckColWinForToken(const Token aToken) const
{
	bool is_win{ false };

	for (unsigned int col{ 1 }; col <= BOARDSIZE; ++col) {
		is_win = is_win || CheckColNumber(col, aToken);
	}

	return is_win;
}

bool TTTBoard::CheckColNumber(const unsigned int aCol, const Token aToken) const
{
	bool has_col{ true };

	for (unsigned int row{ 1 }; row <= BOARDSIZE; ++row) {
		has_col = has_col && IsToken(row, aCol, aToken);
	}

	return has_col;
}

bool TTTBoard::CheckDiagonalWinForToken(const Token aToken) const
{
	return CheckUpperDiagonal(aToken) || CheckLowerDiagonal(aToken);
}

bool TTTBoard::CheckUpperDiagonal(const Token aToken) const
{
	bool has_diagonal{ true };

	for (unsigned int index{ 1 }; index <= BOARDSIZE; ++index) {
		has_diagonal = has_diagonal && IsToken(index, index, aToken);
	}

	return has_diagonal;
}

bool TTTBoard::CheckLowerDiagonal(const Token aToken) const
{
	bool has_diagonal{ true };
	unsigned int row_index{ 1 };
	unsigned int col_index{ BOARDSIZE };
	for (; row_index <= BOARDSIZE && col_index >= 1; ++row_index, --col_index) {
		has_diagonal = has_diagonal && IsToken(row_index, col_index, aToken);
	}

	return has_diagonal;
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

