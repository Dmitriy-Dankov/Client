cmake_minimum_required(VERSION 3.14)

project(Client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Client
  main.cpp
  Client.h Client.cpp
)
