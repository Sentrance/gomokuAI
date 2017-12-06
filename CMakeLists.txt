cmake_minimum_required(VERSION 3.8)
project(gomoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/ai/GomokuAi.cpp include/ai/GomokuAi.hpp include/ai/IGomokuAi.hpp include/ai/AGomokuAi.hpp src/ai/MiniMax.cpp include/ai/MiniMax.hpp src/ai/IterativeDeepening/IterativeDeepening.cpp include/ai/IterativeDeepening/IterativeDeepening.hpp src/ai/IterativeDeepening/IDThread.cpp include/ai/IterativeDeepening/IDThread.hpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable(pbrain-gomuko ${SOURCE_FILES})
