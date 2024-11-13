
cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(AetherSouls)

# Generate compile_commands.json
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()


# Dependencies
set(SDL_VERSION 2.30.9)
find_package(sdl ${SDL_VERSION} QUIET) # QUIET or REQUIRED
if (NOT sdl_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    sdl
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/libsdl-org/SDL/archive/refs/tags/release-2.30.9.tar.gz  )
  FetchContent_GetProperties(sdl)
  if (NOT sdl_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sdl)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${sdl_SOURCE_DIR} ${sdl_BINARY_DIR})
  endif()
endif()

add_executable(${PROJECT_NAME} src/main.cpp
src/Game.cpp
src/Window.cpp
)

target_link_libraries(${PROJECT_NAME} SDL2)


execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        src/compile_commands.json
        compile_commands.json
)
