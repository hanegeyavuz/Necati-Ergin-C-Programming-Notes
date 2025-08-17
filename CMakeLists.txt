cmake_minimum_required(VERSION 3.16)
project(NECATI-ERGIN-C-PROGRAMMING-NOTES C)  

# C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Header files
include_directories(libs/Inc)

# C Source Files
file(GLOB LIB_C_SRC "libs/Src/*.c")

# Generate Executable
add_executable(main ${LIB_C_SRC})
