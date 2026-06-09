cmake_minimum_required(VERSION 4.1.2)
project(Proyecto_2_Progra_2)
include_directories(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_2_Progra_2 main.cpp
        include/Event.h
        include/Fire.h
        src/Fire.cpp
        include/MeteorStrike.h
        src/MeteorStrike.cpp
        include/PowerFailure.h
        src/PowerFailure.cpp
        include/OxygenLeak.h
        src/OxygenLeak.cpp
)
