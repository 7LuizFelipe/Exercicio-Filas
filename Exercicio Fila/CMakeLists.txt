cmake_minimum_required(VERSION 3.29)
project(Pilha_e_Fila)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pilha_e_Fila main.cpp
        Pilha.cpp
        Pilha.h
        Fila.cpp
        Fila.h
)
