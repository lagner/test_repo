project(test)

cmake_minimum_required(VERSION 2.8)

## C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -march=native -Wall -std=c++11 -Wl,--no-as-needed")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -flto -funroll-loops -DNDEBUG")

## C
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c11")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

aux_source_directory(. SRC_LIST)

include_directories(src)

add_executable(${PROJECT_NAME} ${SRC_LIST})
