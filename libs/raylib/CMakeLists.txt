cmake_minimum_required(VERSION 3.5)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib
        GIT_TAG        5.5
)

FetchContent_MakeAvailable(raylib)