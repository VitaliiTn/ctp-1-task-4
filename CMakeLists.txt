cmake_minimum_required(VERSION 3.10)
project(functions_practice)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add debug information and disable optimizations
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

# Add compiler flags for warnings
if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -O0")
endif()

# Add source files
add_library(functions src/functions.cpp)
target_include_directories(functions PUBLIC src)

# Add test executable
add_executable(tests test/test.cpp)
target_include_directories(tests PRIVATE test/include)
target_link_libraries(tests functions)