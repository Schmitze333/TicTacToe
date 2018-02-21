#pragma once

#include <vector>
#include <memory>

class WinChecker;
class TTTBoard
{
	enum Token;

	enum { BOARDSIZE = 3 };
	const unsigned int FIELDS{ BOARDSIZE * BOARDSIZE };
	Token board[BOARDSIZE * BOARDSIZE];
	std::unique_ptr<WinChecker> checker{ nullptr };

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
	bool IsToken(const unsigned int aRow, const unsigned int aCol, Token aToken) const;
	bool SetToken(enum Token aToken, const unsigned int aRow, const unsigned int aCol);

	bool SetGameState(std::vector<Token> avTokens);
	bool CheckWinForToken(const Token aToken) const;
	unsigned int getBoardSize() const { return BOARDSIZE; }
	void SetWinChecker(std::unique_ptr<WinChecker> apChecker) { checker = std::move(apChecker); }

private:
	unsigned int To1dCoordinate(const unsigned int aRow, const unsigned int aCol) const;
	void EmptyBoard();
};

class WinChecker
{
public:
	virtual bool CheckWinForToken(const TTTBoard::Token) const = 0;
};


