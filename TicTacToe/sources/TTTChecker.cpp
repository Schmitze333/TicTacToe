#include "TTTChecker.h"

bool TTTChecker::CheckWinForToken(const TTTBoard::Token aToken) const
{
	return CheckRowWinForToken(aToken) || CheckColWinForToken(aToken) || CheckDiagonalWinForToken(aToken);
}

bool TTTChecker::CheckRowWinForToken(const TTTBoard::Token aToken) const
{
	bool is_win{ false };

	for (unsigned int row{ 1 }; row <= mpBoard->getBoardSize(); ++row) {
		is_win = is_win || CheckRowNumber(row, aToken);
	}

	return is_win;
}

bool TTTChecker::CheckRowNumber(const unsigned int aRow, const TTTBoard::Token aToken) const
{
	bool has_row{ true };
	for (unsigned int col{ 1 }; col <= mpBoard->getBoardSize(); ++col) {
		has_row = has_row && mpBoard->IsToken(aRow, col, aToken);
	}
	return has_row;
}

bool TTTChecker::CheckColWinForToken(const TTTBoard::Token aToken) const
{
	bool is_win{ false };

	for (unsigned int col{ 1 }; col <= mpBoard->getBoardSize(); ++col) {
		is_win = is_win || CheckColNumber(col, aToken);
	}

	return is_win;
}

bool TTTChecker::CheckColNumber(const unsigned int aCol, const TTTBoard::Token aToken) const
{
	bool has_col{ true };

	for (unsigned int row{ 1 }; row <= mpBoard->getBoardSize(); ++row) {
		has_col = has_col && mpBoard->IsToken(row, aCol, aToken);
	}

	return has_col;
}

bool TTTChecker::CheckDiagonalWinForToken(const TTTBoard::Token aToken) const
{
	return CheckUpperDiagonal(aToken) || CheckLowerDiagonal(aToken);
}

bool TTTChecker::CheckUpperDiagonal(const TTTBoard::Token aToken) const
{
	bool has_diagonal{ true };

	for (unsigned int index{ 1 }; index <= mpBoard->getBoardSize(); ++index) {
		has_diagonal = has_diagonal && mpBoard->IsToken(index, index, aToken);
	}

	return has_diagonal;
}

bool TTTChecker::CheckLowerDiagonal(const TTTBoard::Token aToken) const
{
	bool has_diagonal{ true };
	unsigned int row_index{ 1 };
	unsigned int col_index{ mpBoard->getBoardSize() };
	for (; row_index <= mpBoard->getBoardSize() && col_index >= 1; ++row_index, --col_index) {
		has_diagonal = has_diagonal && mpBoard->IsToken(row_index, col_index, aToken);
	}

	return has_diagonal;
}
