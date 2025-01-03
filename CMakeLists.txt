cmake_minimum_required(VERSION 3.0)
project(test0 C CXX)

set(CMAKE_CXX_STANDARD 17)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/raylib)

FILE(GLOB cSources src/*.c src/*.cpp)

add_executable(${PROJECT_NAME} src/main.cpp ${cSources})
if (PLATFORM MATCHES "Web")
    target_include_directories(${PROJECT_NAME} PUBLIC "${EMSDK}/upstream/emscripten/system/include")
endif ()
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release mode
