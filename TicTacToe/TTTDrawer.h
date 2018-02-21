#pragma once

#include "TTTBoard.h"

#include <string>

class TTTDrawer : public DrawStrategy
{
	std::string DrawHeader() const;
	std::string DrawRow(const unsigned int aRowNumber) const;
	std::string DrawTokenAt(const unsigned int aRowNumber, const unsigned int aColNumber) const;

	TTTBoard* mpBoard;

public:
	TTTDrawer(TTTBoard* aBoard) : mpBoard(aBoard) {}
	std::string Draw() const override;
};
