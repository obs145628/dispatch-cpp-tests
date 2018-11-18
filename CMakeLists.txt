cmake_minimum_required(VERSION 3.0.2)

add_definitions(-DUSE_AVX -DUSE_SSE -DUSE_GOD -DUSE_DEFAULT)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic -O0 -g3 -std=c++17")

set(SRC
  src/main.cc
  src/vector_ops.cc
)
add_executable(app ${SRC})
