#pragma once

#include <vector>

class TTTBoard
{
	enum Token;

	enum { BOARDSIZE = 3 };
	const unsigned int FIELDS{ BOARDSIZE * BOARDSIZE };
	Token board[BOARDSIZE * BOARDSIZE];

public:
	enum Token {
		empty,
		X,
		O,
	};

	TTTBoard() { EmptyBoard(); }

	bool IsEmpty(const unsigned int aRow, const unsigned int aCol) const; 
	bool IsX(const unsigned int aRow, const unsigned int aCol) const;
	bool IsO(const unsigned int aRow, const unsigned int aCol) const;
	bool SetToken(enum Token aToken, const unsigned int aRow, const unsigned int aCol);

	bool SetGameState(std::vector<Token> avTokens);
	bool CheckWinForToken(const Token aToken) const;

private:
	unsigned int To1dCoordinate(const unsigned int aRow, const unsigned int aCol) const;
	bool IsToken(const unsigned int aRow, const unsigned int aCol, Token aToken) const;
	void EmptyBoard();

	bool CheckRowWinForToken(const Token aToken) const;
	bool CheckRowNumber(const unsigned int aRow, const Token aToken) const;
	bool CheckColWinForToken(const Token aToken) const;
	bool CheckColNumber(const unsigned int aCol, const Token aToken) const;
	bool CheckDiagonalWinForToken(const Token aToken) const;
	bool CheckUpperDiagonal(const Token aToken) const;
	bool CheckLowerDiagonal(const Token aToken) const;
};


