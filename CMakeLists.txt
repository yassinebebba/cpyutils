cmake_minimum_required(VERSION 3.20)
project(cpyutils C)

set(CMAKE_C_STANDARD 99)

add_executable(cpyutils main.c pystr.c builtins.c pyint.c)
