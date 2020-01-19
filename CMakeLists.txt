cmake_minimum_required(VERSION 3.15)
project(Generala)

set(CMAKE_CXX_STANDARD 17)

add_executable(Generala main.cpp models/die.cpp models/die.h models/player.cpp models/player.h game_logic/game.cpp game_logic/game.h game_logic/scoring.cpp game_logic/scoring.h)