cmake_minimum_required(VERSION 3.15)

project(simpleTCP VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(server-x86 ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_include_directories(server-x86 PUBLIC
			"${CMAKE_SOURCE_DIR}/include")


