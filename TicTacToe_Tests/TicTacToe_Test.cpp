// TicTacToe_Test.cpp : Defines the entry point for the console application.
//

#include "gmock/gmock.h"

#include "TTTBoard_Tests.hpp"
#include "TTTBot_Test.hpp"

int main(int argc, char** argv)
{
	::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

