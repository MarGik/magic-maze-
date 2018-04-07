cmake_minimum_required(VERSION 3.9)
project(MagicMaze)

set(CMAKE_CXX_STANDARD 11)

add_executable(MagicMaze
        Src/case.cpp
        Src/case.hpp
        Src/couleurs.cpp
        Src/couleurs.hpp
        Src/direction.cpp
        Src/direction.hpp
        Src/melangeur.cpp
        Src/melangeur.hpp
        Src/mur.cpp
        Src/mur.hpp
        Src/test_melangeur.cpp
        Src/tuile.cpp
        Src/tuile.hpp)
