cmake_minimum_required(VERSION 3.8)
project(gomoku)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/ai/GomokuAi.cpp include/ai/GomokuAi.hpp include/ai/IGomokuAi.hpp include/ai/AGomokuAi.hpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable(pbrain-gomuko ${SOURCE_FILES})
