cmake_minimum_required(VERSION 3.17)
project(testLifeGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(testLifeGame main.cpp etat.cpp etat.h voisinage.h voisinage.cpp)