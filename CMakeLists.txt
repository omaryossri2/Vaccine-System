cmake_minimum_required(VERSION 3.22)
project(Vaccine_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Models)
include_directories(Models/Classes)
include_directories(Models/Headers)

add_executable(Vaccine_System
        Models/Classes/User.cpp
        Models/Classes/Vaccine.cpp
        Models/Headers/User.h
        Models/Headers/Vaccine.h
        application.cpp
        )
