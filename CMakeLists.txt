cmake_minimum_required(VERSION 3.5) 
project(TicTacToe) 

include_directories(
  $ENV{GTEST_HOME}/googlemock/include 
  $ENV{GTEST_HOME}/googletest/include
  ./TicTacToe/header
  ./TicTacToe_Tests
  ./TicTacToeGame
)

link_directories(
  $ENV{GTEST_HOME}/mybuild/googlemock 
  $ENV{GTEST_HOME}/mybuild/googlemock/gtest
)

add_definitions(-std=c++14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb -Wall")


set(lib_sources
  TicTacToe/sources/TTTBoard.cpp
  TicTacToe/sources/TTTChecker.cpp
  TicTacToe/sources/TTTDrawer.cpp
  TicTacToe/sources/TTTBot.cpp
)

set(test_sources
  TicTacToe_Tests/TicTacToe_Test.cpp
)

set(game_sources
  TicTacToeGame/TicTacToeGame.cpp
  TicTacToeGame/TTTGameEngine.cpp
)

add_executable(TicTacToe_Test ${test_sources})
add_executable(TicTacToeGame ${game_sources})
add_library(TicTacToe ${lib_sources})

target_link_libraries(TicTacToe_Test pthread)
target_link_libraries(TicTacToe_Test gmock)
target_link_libraries(TicTacToe_Test gtest)
target_link_libraries(TicTacToe_Test TicTacToe)

target_link_libraries(TicTacToeGame TicTacToe)

