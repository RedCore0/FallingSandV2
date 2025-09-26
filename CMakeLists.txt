cmake_minimum_required(VERSION 3.16)
project(FallingSandV2 CXX)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

# --- raylib ---
FetchContent_Declare(raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
        GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raylib)

# 👇 --- raygui (separate repo) ---
FetchContent_Declare(raygui
        GIT_REPOSITORY https://github.com/raysan5/raygui.git
        GIT_TAG        4.0   # or a newer tag if you prefer
        GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raygui)

# 👇 Make raygui headers visible
# raygui.h lives under <repo>/src
set(RAYGUI_INCLUDE_DIR ${raygui_SOURCE_DIR}/src)

# Create executable
add_executable(${PROJECT_NAME}
        main.cpp
        Game.cpp
        Game.h
        Board/Board.cpp
        Board/Board.h
        Board/Cell.cpp
        Board/Cell.h
        Board/Elements/Air.cpp
        Board/Elements/Air.h
        Board/Elements/Sand.cpp
        Board/Elements/Sand.h
        GUI/gui.cpp
        GUI/gui.h
        Board/Elements/Dirt.cpp
        Board/Elements/Dirt.h
        Board/Elements/Clay.cpp
        Board/Elements/Clay.h
        Board/Elements/Stone.cpp
        Board/Elements/Stone.h
)

# 👇 Add include paths for raygui (and raylib if you need it)
target_include_directories(${PROJECT_NAME} PRIVATE
        ${RAYGUI_INCLUDE_DIR}
)

# Link raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Linux system deps for raylib
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE m pthread dl rt X11)
endif()

