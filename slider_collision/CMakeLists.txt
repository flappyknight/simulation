cmake_minimum_required(VERSION 3.25)
project(simulation C)

set(CMAKE_C_STANDARD 11)

add_executable(slider_collision slider_collision.c ../utils.c ../queue.c)
