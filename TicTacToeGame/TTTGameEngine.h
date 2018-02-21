#pragma once

#include "TTTBoard.h"

class TTTGameEngine
{
	struct Player {
		unsigned int number;
		TTTBoard::Token token;
	};

	TTTBoard board;
	Player currentPlayer;
	bool finishGame{ false };

	void Setup();
	void DrawBoard() const;
	void AskForInputAndSet();
	void QueryForInput() const;
	bool ObtainInput(unsigned int& auiRow, unsigned int& auiCol) const;
	bool CheckInput(const unsigned int& auiRow, const unsigned int& auiCol) const;

	void GetWinnerOrSwitchPlayer();
	void CongratulateAndFinish();
	void MessageADraw();

	void SwitchPlayer();
public:
	int run();
};
