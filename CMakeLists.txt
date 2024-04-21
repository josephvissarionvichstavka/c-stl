cmake_minimum_required(VERSION 3.19)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(assert.h assert.c ctype.h ctype.c xctype.c main.c xtolower.c xtoupper.c errno.c errno.h)