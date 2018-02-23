#include "TTTDrawer.h"

#include <sstream>

std::string TTTDrawer::DrawHeader() const
{
	std::stringstream ss("");
	ss << "_|";

	for (unsigned int i{ 1 }; i < mpBoard->getBoardSize(); ++i) {
		ss << i << "_";
	}
	ss << mpBoard->getBoardSize();

	return ss.str();
}

std::string TTTDrawer::DrawRow(const unsigned int aRowNumber) const
{
	std::stringstream ss("");
	ss << aRowNumber << "|";

	for (unsigned int col{ 1 }; col < mpBoard->getBoardSize(); ++col) {
		ss << DrawTokenAt(aRowNumber, col) << " ";
	}

	ss << DrawTokenAt(aRowNumber, mpBoard->getBoardSize());

	return ss.str();
}

std::string TTTDrawer::DrawTokenAt(const unsigned int aRowNumber, const unsigned int aColNumber) const
{
	return mpBoard->TokenSymbolAt(aRowNumber, aColNumber);
}

std::string TTTDrawer::Draw() const
{
	std::stringstream ss("");
	ss << DrawHeader() << std::endl;

	for (unsigned int row{ 1 }; row <= mpBoard->getBoardSize(); ++row) {
		ss << DrawRow(row) << std::endl;
	}

	return ss.str();
}
