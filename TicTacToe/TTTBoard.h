#pragma once

#include <vector>
#include <unordered_map>
#include <memory>

class WinChecker;
class DrawStrategy;

class TTTBoard
{
	enum Token;

	enum { BOARDSIZE = 3 };
	const unsigned int FIELDS{ BOARDSIZE * BOARDSIZE };
	Token board[BOARDSIZE * BOARDSIZE];
	std::unique_ptr<WinChecker> checker{ nullptr };
	std::unique_ptr<DrawStrategy> drawer{ nullptr };

public:
	enum Token {
		empty,
		X,
		O,
	};

	const std::unordered_map<Token, std::string> TOKEN_SYMBOLS{
		{empty, "-"},
		{X, "X"},
		{O, "O"}
	};

	TTTBoard() { EmptyBoard(); }

	Token TokenAt(const unsigned int aRow, const unsigned int aCol) const;
	std::string TokenSymbolAt(const unsigned int aRow, const unsigned int aCol) const;

	bool IsEmpty(const unsigned int aRow, const unsigned int aCol) const; 
	bool IsFull() const;
	bool IsX(const unsigned int aRow, const unsigned int aCol) const;
	bool IsO(const unsigned int aRow, const unsigned int aCol) const;
	bool IsToken(const unsigned int aRow, const unsigned int aCol, Token aToken) const;
	bool SetToken(enum Token aToken, const unsigned int aRow, const unsigned int aCol);

	bool SetGameState(std::vector<Token> avTokens);
	bool CheckWinForToken(const Token aToken) const;
	unsigned int getBoardSize() const { return BOARDSIZE; }
	void SetWinChecker(std::unique_ptr<WinChecker> apChecker) { checker = std::move(apChecker); }
	void SetDrawStrategy(std::unique_ptr<DrawStrategy> apDrawer) { drawer = std::move(apDrawer); }

	std::string Draw() const;

private:
	unsigned int To1dCoordinate(const unsigned int aRow, const unsigned int aCol) const;
	void EmptyBoard();
};

class WinChecker
{
public:
	virtual bool CheckWinForToken(const TTTBoard::Token) const = 0;
};

class DrawStrategy
{
public:
	virtual std::string Draw() const = 0;
};


