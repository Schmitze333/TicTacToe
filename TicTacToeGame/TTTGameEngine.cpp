#include "TTTGameEngine.h"

#include <iostream>
#include <memory>
#include <sstream>

#include "TTTBoard.h"
#include "TTTDrawer.h"
#include "TTTChecker.h"

void TTTGameEngine::Setup()
{
	board.SetDrawStrategy(std::make_unique<TTTDrawer>(&board));
	board.SetWinChecker(std::make_unique<TTTChecker>(&board));
	currentPlayer = Player{1, TTTBoard::Token::X};
}

void TTTGameEngine::DrawBoard() const
{
	std::cout << std::endl << std::endl;
	std::cout << board.Draw();
	std::cout << std::endl << std::endl;
}

void TTTGameEngine::AskForInputAndSet()
{
	unsigned int ui_row, ui_col;
	bool is_set{ false };

	while (!is_set)
	{
		QueryForInput();
		while (!ObtainInput(ui_row, ui_col)) {
			std::cout << "Wrong input! Try again..." << std::endl << std::endl;
			QueryForInput();
		}

		is_set = board.SetToken(currentPlayer.token, ui_row, ui_col);

		if (!is_set)
			std::cout << "This field is not empty...! Try again" << std::endl;
	}
}

void TTTGameEngine::QueryForInput() const
{
	std::cout << "Player " << currentPlayer.number << " - set (row col): ";
}

bool TTTGameEngine::ObtainInput(unsigned int & auiRow, unsigned int & auiCol) const
{
	auiRow = 0;
	auiCol = 0;

	std::string input;
	std::getline(std::cin, input);

	std::istringstream iss(input);
	iss >> auiRow;
	iss >> auiCol;

	return CheckInput(auiRow, auiCol);
}

bool TTTGameEngine::CheckInput(const unsigned int & auiRow, const unsigned int & auiCol) const
{
	return auiRow > 0 && auiCol > 0 && auiRow <= board.getBoardSize() && auiCol <= board.getBoardSize();
}

void TTTGameEngine::GetWinnerOrSwitchPlayer()
{
	if (board.CheckWinForToken(currentPlayer.token))
		CongratulateAndFinish();
	else if (board.IsFull())
		MessageADraw();
	else
		SwitchPlayer();
}

void TTTGameEngine::CongratulateAndFinish()
{
	std::cout << std::endl << std::endl;
	std::cout << "CONGRATULATION Player " << currentPlayer.number << "!" << std::endl;
	std::cout << "You Won!!!" << std::endl << std::endl;

	finishGame = true;
}

void TTTGameEngine::MessageADraw()
{
	std::cout << std::endl << std::endl;
	std::cout << "Nobody won... IT'S A DRAW!" << std::endl;

	finishGame = true;
}

void TTTGameEngine::SwitchPlayer()
{
	if (currentPlayer.number == 1)
		currentPlayer = Player{ 2, TTTBoard::Token::O };
	else
		currentPlayer = Player{ 1, TTTBoard::Token::X };
}

int TTTGameEngine::run()
{
	Setup();

	std::cout << "Welcome to TicTacToe!";

	while (!finishGame) {
		DrawBoard();
		AskForInputAndSet();
		GetWinnerOrSwitchPlayer();
	}

	return 0;
}
