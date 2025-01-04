cmake_minimum_required(VERSION 3.0)
project(test0 C CXX)

set(CMAKE_CXX_STANDARD 17)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(CUSTOMIZE_BUILD ON CACHE BOOL "" FORCE)

add_subdirectory(libs/raylib)

FILE(GLOB cSources src/*.cpp src/screen/*.cpp)
FILE(GLOB cHeaders src/*.h src/screen/*.h)

add_executable(${PROJECT_NAME} ${cSources} ${cHeaders})

set(INCLUDE_DIRECTORIES src)

if (PLATFORM MATCHES "Web")
    list(APPEND INCLUDE_DIRECTORIES "${EMSDK}/upstream/emscripten/system/include")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif ()

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRECTORIES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release mode
