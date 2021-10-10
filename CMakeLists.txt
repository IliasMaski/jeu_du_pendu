cmake_minimum_required(VERSION 3.20)
project(jeu_du_pendu C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(jeu_du_pendu
        dico.c
        dico.h
        main.c)
