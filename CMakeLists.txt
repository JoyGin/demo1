cmake_minimum_required(VERSION 3.23.2)
project(demo1)

set(CMAKE_CXX_STANDARD 17)

# 为整个项目添加地址清洗器选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

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

add_executable(ch11 ch01/Sales_item.h ch11/cn11.cpp ch11/Sales_data.h ch11/Sales_data.cpp)

add_executable(ch12 ch12/ch12.cpp ch12/StrBlob.cpp ch12/StrBlob.h ch12/TextQuery.cpp ch12/TextQuery.h)

add_executable(other other/other.cpp)

add_executable(testfork fork/testfork.cpp)

add_executable(testptrace ptrace/testptrace.cpp)

add_executable(testsignal signal/testsignal.cpp)

add_executable(testAttrCtor attr_constructor/testAttrCtor.cpp)

add_executable(ch13 ch13/ch13.cpp ch13/Message.cpp ch13/Message.h ch13/StrVec.cpp ch13/StrVec.h ch13/String.cpp ch13/String.h)