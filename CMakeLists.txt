cmake_minimum_required(VERSION 3.12)
project(aplicatie_biblioteca CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(biblioteca ${SOURCES})
target_include_directories(biblioteca PRIVATE include)