cmake_minimum_required(VERSION 3.24)
project(demo1)

set(CMAKE_CXX_STANDARD 17)

add_executable(demo1 main.cpp)

add_executable(ch01 ch01/Sales_item.h ch01/ch01.cpp)

add_executable(ch02 ch02/ch02.cpp)

add_executable(ch03 ch03/ch03.cpp)

add_executable(ch04 ch04/ch04.cpp)

add_executable(ch06 ch06/ch06.cpp)

add_executable(ch07 ch07/ch07.cpp ch07/Person.cpp ch07/Person.h ch07/Sales_data.cpp ch07/Sales_data.h ch07/Screen.cpp ch07/Screen.h)
