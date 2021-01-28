cmake_minimum_required(VERSION 3.16.3)

project( Lab6 )

include_directories( ./include ./src )

add_executable(wynik ./src/main.cpp ./src/employee.cpp ./src/hrms.cpp)
