CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET(CMAKE_CXX_STANDARD 11)

project(CS170-A*)

ADD_EXECUTABLE(test
    src/main.cpp
    src/A*.cpp
    src/Problem.cpp
    src/Tree.cpp
    src/Node.cpp
)
