cmake_minimum_required(VERSION 3.23.2)
project(demo1)

set(CMAKE_CXX_STANDARD 17)

add_executable(demo1 main.cpp)

add_executable(ch01 ch01/Sales_item.h ch01/ch01.cpp)

add_executable(ch02 ch02/ch02.cpp)

add_executable(ch03 ch03/ch03.cpp)

add_executable(ch04 ch04/ch04.cpp)

add_executable(ch06 ch06/ch06.cpp)

add_executable(ch07 ch07/ch07.cpp ch07/Person.cpp ch07/Person.h ch07/Sales_data.cpp ch07/Sales_data.h ch07/Screen.cpp ch07/Screen.h ch07/Debug.h ch07/Example.cpp ch07/Example.h ch07/Account.cpp ch07/Account.h)

add_executable(ch08 ch08/ch08.cpp ch07/Sales_data.cpp ch07/Sales_data.h)

add_executable(ch09 ch09/ch09.cpp)

add_executable(ch10 ch10/ch10.cpp ch10/Sales_data.h ch10/Sales_data.cpp ch10/Sales_item.h)