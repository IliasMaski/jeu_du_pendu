cmake_minimum_required(VERSION 3.20)
project(pendu_game C)

set(CMAKE_C_STANDARD 99)

add_executable(pendu_game main.c dico.c dico.h)
