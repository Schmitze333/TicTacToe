#pragma once

#include "TTTBoard.h"

class TTTChecker : public WinChecker
{
	const TTTBoard* mpBoard{ nullptr };

public:
	TTTChecker(const TTTBoard* apBoard) : mpBoard(apBoard) {}

	bool CheckWinForToken(const TTTBoard::Token aToken) const override;

private:
	bool CheckRowWinForToken(const TTTBoard::Token aToken) const;
	bool CheckRowNumber(const unsigned int aRow, const TTTBoard::Token aToken) const;
	bool CheckColWinForToken(const TTTBoard::Token aToken) const;
	bool CheckColNumber(const unsigned int aCol, const TTTBoard::Token aToken) const;
	bool CheckDiagonalWinForToken(const TTTBoard::Token aToken) const;
	bool CheckUpperDiagonal(const TTTBoard::Token aToken) const;
	bool CheckLowerDiagonal(const TTTBoard::Token aToken) const;
};

