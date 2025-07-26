cmake_minimum_required(VERSION 3.16)
project(FallingSandV2 CXX)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

# Fetch raylib from GitHub
FetchContent_Declare(raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
        GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raylib)

# Create executable
add_executable(${PROJECT_NAME} main.cpp
        Game.cpp
        Game.h
)

# Link raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
