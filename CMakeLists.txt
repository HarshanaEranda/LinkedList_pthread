cmake_minimum_required(VERSION 3.26)
project(Lab_Assignment C)

set(CMAKE_C_STANDARD 23)

add_executable(Lab_Assignment
        node.h
        operations.c
        operations.h
        arrayShuffle.c
        arrayShuffle.h
#        serial_program_for_Linked_list.c
        "parallel_program_for_Linked_list .c"

)
