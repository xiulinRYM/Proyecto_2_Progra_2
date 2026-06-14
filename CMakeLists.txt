cmake_minimum_required(VERSION 4.1.2)
project(Proyecto_2_Progra_2)
include_directories(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_2_Progra_2 main.cpp
        include/Events/Event.h
        include/Events/Fire.h
        src/events/Fire.cpp
        include/Events/MeteorStrike.h
        src/events/MeteorStrike.cpp
        include/Events/PowerFailure.h
        src/events/PowerFailure.cpp
        include/Events/OxygenLeak.h
        src/events/OxygenLeak.cpp
)
